#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#define digitosDNI 999
#include "prototipados.h"

///prototipados:
void crearusuario(char archivo[], empleados_laboratorio arreglo[], int validos);
empleados_laboratorio crearCuenta(empleados_laboratorio usuario);
int verificarEmpleado(int dniEmpleado, empleados_laboratorio arreglo[], int validos);

void nombreUsuario(char usuario[], int tamanio)
{
    char seguro;
    do{
            printf("Inserte nombre usuario:\n");
            fflush(stdin);
            gets(usuario);
            printf("\nSeguro que desea ese nombre de usuario? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(usuario)>tamanio){
                printf("se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 20..\n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');

}

void contraseniaUsuario(char contrasenia[], int tamanio)
{
    char contra[20];
    do{
            printf("Ahora ingrese su contrasenia:\n");
            fflush(stdin);
            gets(contrasenia);
            system("cls");
            printf("Ingrese de nuevo su contrasenia para continuar..\n");
            fflush(stdin);
            gets(contra);
            if(strcmp(contra, contrasenia)<0){
                printf("La contrasenia que usted ha ingresado no es la misma");
                system("pause");
                system("cls");
            }
            if(strlen(contra)>tamanio && strlen(contrasenia)>tamanio){
                printf("La contrasenia ha excedido la cantidad de caracteres..\n");
                system("pause");
                system("cls");
            }

        }while(strcmp(contra, contrasenia)<0 || strlen(contra)>tamanio);

}

int dniUsuario(int dni)
{
    do{
        printf("Ingrese su dni:\n");
        fflush(stdin);
        scanf("%d", &dni);

        if(dni>digitosDNI){
            printf("Ha seleccionado una cantidad de digitos demasiado alta..\n");
            system("pause");
            system("cls");
        }
        if(dni<1){
            printf("Ha ingresado un dni invalido\n");
            system("pause");
            system("cls");
        }

    }while(dni>digitosDNI || dni<1);

    return dni;
}

void nombreYapellidoUsuario(char nombre[], int tamanio)
{
    char seguro;
    do{
            printf("Inserte nombre y apellido:\n");
            fflush(stdin);
            gets(nombre);
            printf("\nSeguro que desea ese nombre y apellido? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(nombre)>tamanio){
                printf("se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 40..\n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');
}

int crearPerfil(int perfil)
{
    do{
            printf("Es de tipo 1:ADMIN, 2:ADMINISTRATIVO, 3:LABORATORIO\n");
            fflush(stdin);
            scanf("%d", &perfil);
            if(perfil!=1 && perfil!=2 && perfil!=3){
                printf("Ha ingresado un dato incorrecto, intentelo nuevamente.\n");
                system("pause");
                system("cls");
            }
        }while(perfil!=1 && perfil!=2 && perfil!=3);

    return perfil;
}

empleados_laboratorio crearCuenta(empleados_laboratorio usuario)
{
    int tamanio=sizeof(char)*20;
    int tamanioNombre=sizeof(char)*40;
    char contrasenia[20];
    char nickName[20];
    char nombre[40];

    nombreUsuario(nickName, tamanio);
    strcpy(usuario.usuario, nickName);

    contraseniaUsuario(contrasenia, tamanio);
    strcpy(usuario.contrasenia, contrasenia);

    usuario.dni=dniUsuario(usuario.dni);

    nombreYapellidoUsuario(nombre, tamanioNombre);
    strcpy(usuario.apeYnombre, nombre);

    usuario.perfil=crearPerfil(usuario.perfil);
    return usuario;
}

void crearusuario(char archivo[], empleados_laboratorio arreglo[], int validos)
{
    FILE *buffer=fopen(archivo, "ab");
    empleados_laboratorio usuario;
    int verificacion;


    if(buffer){
        usuario=crearCuenta(usuario);
        verificacion=verificarEmpleado(usuario.dni, arreglo, validos);
        if(verificacion==0){
            fwrite(&usuario, sizeof(empleados_laboratorio), 1, buffer);
        }
        else{
            system("cls");
            printf("\nUsted ya está registrado en el programa..\n");
            system("pause");
            system("cls");
        }

        fclose(buffer);
    }
    else{
        printf("Error al abrir el archivo..\n");
        system("pause");
    }
}
///ahora a verificar si existe el empleado ya en el sitema.

int plasmarEnArreglo(char archivo[], empleados_laboratorio arreglo[], int validos)
{
    int i=validos;
    FILE *buffer=fopen(archivo, "rb");
    empleados_laboratorio usuario;

    if(buffer){
        while(fread(&usuario, sizeof(empleados_laboratorio), 1, buffer)>0){
            arreglo[i]=usuario;
            i++;
        }
        fclose(buffer);
    }

   return validos;
}

int verificarEmpleado(int dniEmpleado, empleados_laboratorio arreglo[], int validos)
{
   int flag=0, i=0;

    while(flag!=1 && i<validos){
        if(dniEmpleado==arreglo[i].dni){
            flag=1;
        }
        i++;
    }

    return flag;
}

void menuGeneral()
{
    int opcion=1000;


   do{
        printf("Bienvenidos a NOMBREEMPRESA\n");
        printf("1-ingresar\n0-Salir\n");
        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del programa..\n NOS VEMOS!!\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    } while(opcion!=0);

}

void menuADMIN()
{
    int opcion=1000;
    do{

        printf("Bienvenido/a USUARIO ADMIN\n");
        printf("1-Registrar paciente\n2-Registrar orden\n3-Ver resultados\n4-Buscar pacientes\n5-Cargar resultados LAB\n6-Buscar Pacientes\n7-Eliminar Cuentas\n8-Ver historial Pacientes\n0-Salir");

        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del programa..\n NOS VEMOS!!\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=0);
}

void menuAdministrativo()
{
    int opcion=1000;
    do{

        printf("Bienvenido al MENU USUARIO\n");
        printf("1-Registrar Pacientes\n2-Registrar Orden\n3-Ver Resultados\n-4-Buscar Paciente\n0-Salir\n");

        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del programa..\n NOS VEMOS!!\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=0);
}

void menuLaboratorio()
{
    int opcion;
    do{
        printf("  Menu INVITADO\n");
        printf("1-Cargar Resultados\n2-Buscar pacientes\n3-\n0-Salir\n");

        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del programa..\n NOS VEMOS!!\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=0);
}
