#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

///prototipados:
int cargarArregloUsuarios(char archivo[], empleados_laboratorio arreglo[], int validos);


///funciones:
int cargarArregloUsuarios(char archivo[], empleados_laboratorio arreglo[], int validos)
{
    FILE * buffer=fopen(archivo, "rb");
    empleados_laboratorio usuario;

    if(buffer!=NULL){
        while(fread(&usuario, sizeof(empleados_laboratorio), 1, buffer)>0){
            arreglo[validos]=usuario;

            validos++;
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
    }

    return validos;
}

int analizaPerfil(char usuario[], char contrasenia[], empleados_laboratorio arreglo[], int validos)
{
    int perfil=-1, i=0;
    while(i<validos && perfil==-1){
        if(strcmp(usuario, arreglo[i].usuario)>0){
            if(contrasenia, arreglo[i].contrasenia){
                perfil=arreglo[i].perfil;
            }
        }
        i++;
    }
    return perfil;
}
