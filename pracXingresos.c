#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"
/***
typedef struct{
    int nroIngreso;
    int nroPractica;
    char resultado[40];
}pracXingreso;
***/

void crearResultado(char resultado[])
{
    char seguro;
    do{
        printf("Inserte el resultado de la practica:\n");
        fflush(stdin);
        gets(resultado);
        printf("\nEse sera el resultado final, esta seguro?\n");
        fflush(stdin);
        scanf("%c", &seguro);
        system("cls");
        if(strlen(resultado)>40 || strlen(resultado)<10){//verificamos que no se exceda de la cantidad de caracteres ni le falten
            printf("se ha excedido o le ha faltado en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 40 y mas de 10..\n");
            seguro='n';
            system("pause");
            system("cls");
        }
    }while(seguro!='s' && seguro!='S');
}

int nroPractica(char archivoPracticas[], int numeroIngreso)
{
    int i=0;
    FILE*buffer=fopen(archivoPracticas, "rb");
    pracXingreso aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(pracXingreso), 1, buffer)>0)
        {
            if(numeroIngreso == aux.nroIngreso){
                i++;
            }
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }

    return i+1;
}

pracXingreso crearPractica(char archivoPracticas[], pracXingreso pXi, int numeroIngreso)
{
    pXi.nroIngreso=numeroIngreso;
    pXi.nroPractica=nroPractica(archivoPracticas, numeroIngreso);
    crearResultado(pXi.resultado);

    return pXi;
}

nodoPractXingreso * inicListapracXingresos()
{
    return NULL;
}

nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso){

    nodoPractXingreso*nuevo=(nodoPractXingreso*)malloc(sizeof(nodoPractXingreso));

    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    strcpy(nuevo->ingreso.resultado, ingreso.resultado);
    nuevo->ingreso.nroPractica=ingreso.nroPractica;

    nuevo->siguiente=NULL;

    return nuevo;
}

nodoPractXingreso* agregarPrincipioPracXingresos(nodoPractXingreso * nuevoNodo, nodoPractXingreso * lista)
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

nodoPractXingreso * pasarArchiAlistaPracXingresos(nodoPractXingreso * lista, char archivoPracXingresos[], int ingreso)
{
    pracXingreso practica;
    FILE *archi=fopen(archivoPracXingresos, "rb");
    if(archi!=NULL)
    {
        while(fread(&practica, sizeof(pracXingreso), 1, archi)>0)
        {
            if(practica.nroIngreso==ingreso)
            {
                lista=agregarPrincipioPracXingresos(crearNodoListaPracXingresos(practica), lista);
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

void muestraPracXingreso(pracXingreso dato)
{
    printf("\n******************\n");
    printf("Numero de Practica: %d\n", dato.nroPractica);
    printf("Resultado: \n%s\n", dato.resultado);
    printf("*******************\n");
}
