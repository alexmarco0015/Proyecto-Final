#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

///prototipados:
void ingresoUsuario(char archivo[], empleados_laboratorio arreglo[], int validos);


///funciones:
void ingresoUsuario(char archivo[], empleados_laboratorio arreglo[], int validos)
{
    FILE * buffer=fopen(archivo, "rb");
    empleados_laboratorio usuario;

    if(buffer!=NULL){




        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
    }


}
