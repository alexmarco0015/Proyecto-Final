#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

///Comentarios:
//    la estructurta practica debe ser como en el campus por el archivo.bin
//    Agregar el archivo.bin a la carpeta del tp: "lasPracticas.bin"
//    en prototipados.h, #endif va luego del codigo
//    trabaje con un arreglo de los datos del archivo
//    baja_practica: COMPLETAR CON VALIDACION "solo si no fue incluida en ningún ingreso"


///Estructura:

/*
typedef struct
{
     int nroPractica;
    char nombrePractica[30];
    int eliminado;
} Practica;

*/


///Prototipados:

void leer_arch_practicas(practicas arreglo[], int * validos);
void alta_practica (practicas arreglo[], int* validos,char nombre_practica[]);
void modificar_nombre_practica(practicas arreglo[], int* validos,char nombre_practica[]);
void baja_practica(practicas arreglo[], int* validos,char nombre_practica[]);
void sobreescribir_arch_practicas(practicas arreglo[], int * validos);


///Funciones:

/*
1)Alta_de_practica
2)Modificacion_de_practica: solo su nombre
3)Baja_de_practica: solo si no fue incluida en ningún ingreso
*/

void leer_arch_practicas(practicas arreglo[], int* validos)
{
    FILE * arch=fopen("lasPracticas.bin","rb");
    int contador=0;
    practicas registro;

    if(arch!=NULL)
        {
            while (!feof(arch))
            {
                if(fread(&registro,sizeof(practicas),1,arch)>0)
                {
                    arreglo[contador]=registro;
                }
                contador++;
            }
            fclose(arch);
        }
    else
        {
        printf("Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
        }

    (*validos)=contador;

}


void alta_practica (practicas arreglo[], int* validos,char nombre_practica[])
{

    for (int i=0;i<(*validos);i++)
    {
        if(strcmpi(arreglo[i].nombrePractica,nombre_practica)==0)
        {
            arreglo[i].eliminado=0;
        }
    }
}

void modificar_nombre_practica (practicas arreglo[], int* validos,char nombre_practica[])
{
    char nuevo_nombre[30];
    printf("Introduzca el nuevo nombre de la practica: \n");
    fflush(stdin);
    gets(nuevo_nombre);

    for (int i=0;i<(*validos);i++)
    {
        if(strcmp(arreglo[i].nombrePractica,nombre_practica)==0)
        {
            strcpy(arreglo[i].nombrePractica,nuevo_nombre);
        }
    }
}


//COMPLETAR CON VALIDACION: solo si no fue incluida en ningún ingreso
void baja_practica(practicas arreglo[], int* validos,char nombre_practica[])
{
    for (int i=0;i<(*validos);i++)
    {
        if(strcmp(arreglo[i].nombrePractica,nombre_practica)==0)
        {
            arreglo[i].eliminado=1;
        }
    }
}

void sobreescribir_arch_practicas(practicas arreglo[], int* validos)
{
    FILE * arch=fopen("lasPracticas.bin","wb");

    if(arch!=NULL)
        {
            for(int i=0;i<*validos;i++)
            {
                fwrite(&arreglo[i],sizeof(practicas),1,arch);
            }
            fclose(arch);
        }
    else
        {
        printf("Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
        }
}
