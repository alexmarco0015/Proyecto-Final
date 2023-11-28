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

int ultimoIngreso(char archivoIngresos[], int dni)
{
    FILE * buffer=fopen(archivoIngresos, "rb");

    int i=0;
    ingresos paciente;

    if(buffer)
    {
        while(fread(&paciente, sizeof(ingresos), 1, buffer)>0)
        {
                i++;
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

void fechaIngreso(char fecha[])
{
    char seguro;
    do{
            printf("Inserte la fecha de ingreso del paciente:\n");
            fflush(stdin);
            gets(fecha);
            printf("\nSeguro que desea esa fecha? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(fecha)!=10){//verificamos que no se exceda de la cantidad de caracteres
                printf("No ha insertado la fecha correctamente.. Inserte fecha con ceros y barras '/' \n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');

}

void fechaRetiro(char fecha[])
{
    char seguro;
    do{
            printf("Inserte la fecha de retiro de la practica:\n");
            fflush(stdin);
            gets(fecha);
            printf("\nSeguro que desea esa fecha? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(fecha)!=10){//verificamos que no se exceda de la cantidad de caracteres
                printf("No ha insertado la fecha correctamente.. Inserte fecha con ceros y barras '/' \n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');

}

int matriculaSolicitante(int matri)
{
    do{
        printf("ingrese la matricula del solicitante..\n");
        fflush(stdin);
        scanf("%d", &matri);

        if(matri<1)
        {
            system("cls");
            printf("Ha ingresado una matricula incorrecta..\n\n");
            system("pause");
            system("cls");
        }
    }while(matri<1);

    return matri;
}

ingresos crearIngresos(ingresos ingresoPaciente, char archivoIngresos[], int dni)
{
    ingresoPaciente.dniPaciente=dni;
    ingresoPaciente.nroIngreso=ultimoIngreso(archivoIngresos, dni);
    fechaIngreso(ingresoPaciente.fechaIngreso);
    fechaRetiro(ingresoPaciente.fechaRetiro);
    ingresoPaciente.matriculaProfesional=matriculaSolicitante(ingresoPaciente.matriculaProfesional);
    ingresoPaciente.eliminado=0;

    return ingresoPaciente;
}

void cargaIngreso(char archivoIngresos[], char archivoPacientes[], int dni)
{
    FILE *buffer=fopen(archivoIngresos, "ab");
    ingresos ingresoPaciente;
    char cont='s';

    if(buffer){

        while(cont=='s')
        {
            ingresoPaciente=crearIngresos(ingresoPaciente, archivoIngresos, dni);

            fwrite(&ingresoPaciente, sizeof(ingresos), 1, buffer);

            printf("¿Desea agregar otro ingreso? (s/n): ");
            fflush(stdin);
            scanf(" %c", &cont);
            system("cls");
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
    }
}

nodoListaIngresos * inicListaIngresos()
{
    return NULL;
}

nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso){

    nodoListaIngresos *nuevo=(nodoListaIngresos*)malloc(sizeof(nodoListaIngresos));

    nuevo->ingreso.dniPaciente=ingreso.dniPaciente;
    strcpy(nuevo->ingreso.fechaIngreso, ingreso.fechaIngreso);
    strcpy(nuevo->ingreso.fechaRetiro, ingreso.fechaRetiro);
    nuevo->ingreso.matriculaProfesional=ingreso.matriculaProfesional;
    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    nuevo->ingreso.eliminado=ingreso.eliminado;

    nuevo->lista=inicListapracXingresos();

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

nodoListaIngresos * pasarArchiAlista(nodoListaIngresos * lista, char archivoIngresos[], int dni)
{
    ingresos ingreso;
    FILE *archi=fopen(archivoIngresos, "rb");
    if(archi!=NULL)
    {
        while(fread(&ingreso, sizeof(ingreso), 1, archi)>0)
        {
            if(ingreso.eliminado!=0 && dni==ingreso.dniPaciente){///si es distinto de 0 es agregado a la lista, sino no se agrega.
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



