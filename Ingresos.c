#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

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
            printf("Inserte la fecha de ingreso del paciente: (00/00/0000)ejemplo \n");
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
            printf("Inserte la fecha de retiro de la practica: (00/00/0000)ejemplo \n");
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
        printf("\n");

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

void cargaIngreso(char archivoIngresos[], char archivoPacientes[], ingresos ingresito)
{
    FILE *buffer=fopen(archivoIngresos, "ab");

    if(buffer){

        fwrite(&ingresito, sizeof(ingresos), 1, buffer);

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

void muestraIngreso(ingresos dato)
{
    printf("\n///////////////////////////////\n");
    printf("Fecha de Ingreso: %s\n", dato.fechaIngreso);
    printf("Fecha de Retiro: %s\n", dato.fechaRetiro);
    printf("Matricula del profesional: %d\n", dato.matriculaProfesional);
    printf("Numero de Ingreso: %d\n", dato.nroIngreso);
    printf("///////////////////////////////\n");
}
