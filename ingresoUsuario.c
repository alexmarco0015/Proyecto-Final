#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

///cargamos el arreglo de empleados del laboratorio
int cargarArregloUsuarios(const char archivo[], empleados_laboratorio arreglo[])
{
    FILE * buffer=fopen(archivo, "rb");
    empleados_laboratorio usuario;
    int i=0;

    if(buffer!=NULL){
        while(fread(&usuario, sizeof(empleados_laboratorio), 1, buffer)>0){
            arreglo[i]=usuario;

            i++;
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
    }

    return i;
}
///analiza si un perfil es 1 o 2, este es para el menu principal.
int analizaPerfil(char usuario[], char contrasenia[], empleados_laboratorio arreglo[], int validos)
{
    int perfil=-1, i=0;
    while(i<validos && perfil==-1){
        if(strcmp(usuario, arreglo[i].usuario)==0){
            if(strcmp(contrasenia, arreglo[i].contrasenia)==0){
                perfil=arreglo[i].perfil;
            }
        }
        i++;
    }
    return perfil;
}
///pregunta usuario y contraseña, para verificar el tipo de perfil que el usuario tiene.
void ingresoUsuario(char usuario[], char contrasenia[])
{
    printf("ingrese su nombre de usuario: \n");
    fflush(stdin);
    gets(usuario);

    printf("ingrese su contrasenia: \n");
    fflush(stdin);
    gets(contrasenia);
}
///esta funcion en particular, verifica si el administrador ha puesto bien sus datos, para acceder a un menu "especial"
int analizasiEsAdmin(char usuario[], char contrasenia[], int perfil)
{
    char admin[]="administrador";
    char contraAdmin[]="123456";

    if(strcmp(admin, usuario)==0){
        if(strcmp(contraAdmin, contrasenia)==0){
            perfil=3;///este es perfil de admin;
        }
    }
    return perfil;
}
///funcion que con ayuda de las anteriores, verificamos que tipo de perfil es el usuario y contraseña.
int ingresoPerfil(empleados_laboratorio arreglo[], int validos,const char archivo[])
{
    int perfil;
    char usuario[20];
    char contrasenia[20];

    validos=cargarArregloUsuarios(archivo, arreglo);

    int i=0;

    do{
        if(i==3)
        {
            system("cls");
            printf("Ha ingresado incorrectamente los datos mas de 3 veces, volviendo al menu....\n");
            system("pause");
            system("cls");
            break;
        }
        ingresoUsuario(usuario, contrasenia);
        perfil=analizasiEsAdmin(usuario, contrasenia, perfil);
        if(perfil!=3){
            perfil=analizaPerfil(usuario, contrasenia, arreglo, validos);
        }

        i++;
        if(perfil==-1 && i<3)
        {
            system("cls");
            printf("Ha ingresado mal los datos o su cuenta no existe, por favor, vuelva a ingresar..\n");
            system("pause");
            system("cls");
        }
    }while(perfil==-1 && i!=4);

    return perfil;
}
