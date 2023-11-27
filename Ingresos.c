#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

//typedef struct{
//    int nroIngreso;
//    char fechaIngreso[10];
//    char fechaRetiro[10];
//    int dniPaciente;
//    int matriculaProfesional;
//    int eliminado;//0 para no eliminado o 1 para eliminado
//
//}ingresos;


//Listado general de ingresos (sin detalle de prácticas), con detalles del paciente y
//posibilidad de filtrar por “fecha desde” y “fecha hasta”. Es decir que la fecha del ingreso,
//este incluido en ese rango. Ordenado de manera descendente por fecha de ingreso.
//o Consulta de 1 ingreso en particular incluyendo las practicas del mismo con sus
//respectivos nombres y los resultados obtenidos. El ingreso debe poder ser filtrado por
//nro de ingreso, fecha de ingreso o por dni del paciente.


nodoListaIngresos * inicListaIngresos()
{
    return NULL;
}

nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso){

    nodoListaIngresos *nuevo=(nodoListaIngresos*)malloc(sizeof(nodoListaIngresos));

    //nuevo->ingreso=inicListaIngresos();

    nuevo->ingreso.dniPaciente=ingreso.dniPaciente;
    strcpy(nuevo->ingreso.fechaIngreso, ingreso.fechaIngreso);
    strcpy(nuevo->ingreso.fechaRetiro, ingreso.fechaRetiro);
    nuevo->ingreso.matriculaProfesional=ingreso.matriculaProfesional;
    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    nuevo->ingreso.eliminado=ingreso.eliminado;

    nuevo->siguiente=NULL;

    return nuevo;
}

nodoListaIngresos* agregarPrincipio(nodoListaIngresos * nuevoNodo, nodoListaIngresos * lista)
{

    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    return lista;
}

nodoListaIngresos * pasarArchiAlista(nodoListaIngresos * lista, char archivo[])
{
    ingresos ingreso;
    FILE *archi=fopen(archivo, "rb");
    if(archi!=NULL)
    {
        while(fread(&ingreso, sizeof(ingreso), 1, archi)>0)
        {
            if(ingreso.eliminado!=0){///si es distinto de 0 es agregado a la lista, sino no se agrega.
                lista=agregarPrincipio(crearNodoListaIngresos(ingreso), lista);
            }
        }
        fclose(archi);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
    return lista;
}
//este arreglo es para ver todos los registros, tanto los eliminados como los que no lo fueron.
int pasarArchiaArreglo(char archivo[], ingresos arreglo[], int validos)
{
    FILE * buffer=fopen(archivo, "rb");
    int i=0;
    ingresos ingreso;

    if(buffer){

        while(fread(&ingreso, sizeof(ingresos), 1, buffer)>0){
            arreglo[i]=ingreso;
            i++;
        }

        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
    validos=i;
    return validos;
}

