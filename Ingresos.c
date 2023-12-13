#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"
#include "pracXingresos.h"
#include "ingresos.h"
#include "pacientes.h"

///pasamos todos los registros de tipo ingreso a un arreglo de ingresos
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
///con esta funcion nos encargamos de automatizar la cantidad de ingresos en toda la clinica
void recorroListaYcuento(nodoListaIngresos * lista, int *i)
{
    if(lista)
    {
        *i=*i+1;
        recorroListaYcuento(lista->siguiente, i);
    }
}
void ultIngreso(nodoArbol * arbol, int *i)
{
    if(arbol)
    {
        recorroListaYcuento(arbol->lista, i);
        ultIngreso(arbol->izq, i);
        ultIngreso(arbol->der, i);
    }
}

///funcion en la que el usuario se encarga de ingresar la fecha, tal cual se le indica en el printf
void fechaIngreso(char fecha[10])
{
    int dias=0, meses=0, anios=0;
    dias=dia(dias);
    meses=mes(meses);
    anios=anio(anios);
    fflush(stdin);
    snprintf(fecha, 11, "%02d-%02d-%02d", dias, meses, anios);

}
void fechaRetiro(char fecha[10], char fechaAnt[10])
{
    int dias=0, meses=0, anios=0;
    printf("Ingrese la fecha de retiro, debe ser mayor o igual a la de ingreso..(%s)\n",fechaAnt);
    dias=dia(dias);
    printf("fecha ingreso: (%s)\n", fechaAnt);
    meses=mes(meses);
    printf("fecha ingreso: (%s)\n", fechaAnt);
    anios=anio(anios);
    fflush(stdin);
    snprintf(fecha, 11, "%02d-%02d-%02d", dias, meses, anios);

}
///preguntamos cual es la matricula del solicitante, lo ingresamos de forma manual porq no sabiamos de que otra forma podría ser
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
int dia(int diaMes)
{
        do{
            printf("Ingrese el dia:\n");
            fflush(stdin);
            scanf("%d", &diaMes);
            system("cls");

            if(diaMes>32 || diaMes<1)
            {
                printf("Ingreso un día erroneo..\n");
                system("pause");
                system("cls");
            }
        }while(diaMes>32 || diaMes<1);

    return diaMes;
}
int mes(int mesMes)
{
        do{
            printf("Ingrese el mes:\n");
            fflush(stdin);
            scanf("%d", &mesMes);
            system("cls");
            if(mesMes>12 || mesMes<1)
            {
                printf("Ingreso un mes erroneo..\n");
                system("pause");
                system("cls");
            }
        }while(mesMes>12 || mesMes<1);

    return mesMes;
}
int anio(int anioMes)
{

        do{
            printf("Ingrese el anio:(Los ultimos 2 digitos)\n");
            fflush(stdin);
            scanf("%d", &anioMes);
            system("cls");
            if(anioMes>24 || anioMes<03)
            {
                printf("Ingreso un anio erroneo..\n");
                system("pause");
                system("cls");
            }
        }while(anioMes>24 || anioMes<03);

    return anioMes;
}
///función para prototipar la carga de un ingreso al archivo..
ingresos crearIngresos(ingresos ingresoPaciente, nodoArbol * arbol, int dni)
{
    int i=0;
    printf("Ingrese la fecha de INGRESO del paciente..\n");
    fechaIngreso(ingresoPaciente.fechaIngreso);
    printf("Ingrese la fecha de RETIRO del paciente..\n");
    fechaRetiro(ingresoPaciente.fechaRetiro, ingresoPaciente.fechaIngreso);
    ingresoPaciente.matriculaProfesional=matriculaSolicitante(ingresoPaciente.matriculaProfesional);
    ingresoPaciente.eliminado=0;
    ingresoPaciente.dniPaciente=dni;
    ultIngreso(arbol, &i);
    ingresoPaciente.nroIngreso=i;
    return ingresoPaciente;
}

///cargamos los ingresos en el archivo, para luego ingresarlos a una lista
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
///inicializamos la lista de ingresos en null
nodoListaIngresos * inicListaIngresos()
{
    return NULL;
}
///creamos el nodo de una lista de listas.
nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso)
{

    nodoListaIngresos *nuevo=(nodoListaIngresos*)malloc(sizeof(nodoListaIngresos));

    strcpy(nuevo->ingreso.fechaIngreso, ingreso.fechaIngreso);
    strcpy(nuevo->ingreso.fechaRetiro, ingreso.fechaRetiro);
    nuevo->ingreso.matriculaProfesional=ingreso.matriculaProfesional;
    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    nuevo->ingreso.eliminado=ingreso.eliminado;
    nuevo->ingreso.dniPaciente=ingreso.dniPaciente;

    nuevo->lista=inicListapracXingresos();

    nuevo->siguiente=NULL;

    return nuevo;
}
///agregamos al principio de la lista los nodos creados en la funcion anterior
nodoListaIngresos* agregarPrincipio(nodoListaIngresos*lista,nodoArbol * arbol, int dni)
{
        ingresos ingresito=crearIngresos(ingresito,arbol, dni);

        nodoListaIngresos*nuevoNodo=inicListaIngresos();
        nuevoNodo=crearNodoListaIngresos(ingresito);
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

nodoListaIngresos *agregarAlista(nodoListaIngresos *lista, ingresos nuevoIngreso)
 {
///CREE ESTA FUNCION PARA AGREGAR SIN PEDIR DATOS. ES PARA ARCHIVOS
    nodoListaIngresos *nuevoNodo = crearNodoListaIngresos(nuevoIngreso);


    if (lista == NULL) {
        return nuevoNodo;
    }


    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;

    return lista;
}
///pasamos el archivo de ingresos al arbol de pacientes y les insertamos todos los ingresos de cada paciente.
nodoArbol* archivoIngresosToArbol(char archivoIngresos[], nodoArbol * arbol)
{
    FILE*buffer=fopen(archivoIngresos, "rb");
    ingresos ingresito;

    if(buffer)
    {
        while(fread(&ingresito, sizeof(ingresos), 1, buffer)>0)
        {
//            nodoListaIngresos*nuevoNodo=inicListaIngresos();
//            nuevoNodo=crearNodoListaIngresos(ingresito);
//            insertarNodoEnArbol(arbol, nuevoNodo);

            nodoArbol *nodoPaciente = buscarPorDNI(arbol, ingresito.dniPaciente);
        ///BUSCO EL PACIENTE Y CARGO EL INGRESO EN SU NODO
            if (nodoPaciente != NULL)
            {
                nodoPaciente->lista = agregarAlista(nodoPaciente->lista, ingresito);
        }
    }
        fclose(buffer);
    }
    else{
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }
    return arbol;
}

nodoArbol*cargarIngresoenArbol(nodoArbol*arbol, int dni)
{

            nodoArbol*aux=buscarPorDNI(arbol, dni);

            if(aux==NULL){
                printf("LA PERSONA BUSCADA NO EXISTE...\n");
                return arbol;
            }
            aux->lista=agregarPrincipio(aux->lista,arbol, dni);

          return arbol;
}

void pasarListaToArchi(nodoArbol*arbol, char archivoIngresos[])
{
        FILE*archi=fopen(archivoIngresos,"wb");
        if(archi){
                guardarListasDelArbolRecursivo(arbol,archi);
        fclose(archi);

        }else{
            printf("ERROR AL ABRIR\n");
        }
}

void guardarListasDelArbolRecursivo(nodoArbol *arbol, FILE *archivo)
{
    if (arbol != NULL) {

        guardarListaEnArchivoRecursivo(arbol->lista, archivo);

        guardarListasDelArbolRecursivo(arbol->izq, archivo);
        guardarListasDelArbolRecursivo(arbol->der, archivo);
    }
}
void guardarListaEnArchivoRecursivo(nodoListaIngresos *lista, FILE*archivo)
{

    while (lista != NULL) {

        fwrite(&(lista->ingreso), sizeof(ingresos), 1, archivo);

        lista = lista->siguiente;
    }
}

///mostramos un ingreso en particular, se puede usar en varias funciones
void muestraIngreso(ingresos dato)
{
    printf("\n///////////////////////////////\n");
    printf("Fecha de Ingreso: %s\n", dato.fechaIngreso);
    printf("Fecha de Retiro: %s\n", dato.fechaRetiro);
    printf("Matricula del profesional: %d\n", dato.matriculaProfesional);
    printf("Numero de Ingreso: %d\n", dato.nroIngreso);
    printf("DNI paciente: %d\n", dato.dniPaciente);
    printf("///////////////////////////////\n");
}

void modificarMatricula(int nroIngreso, nodoListaIngresos*lista)
{
    while(lista!=NULL && nroIngreso !=lista->ingreso.nroIngreso)
    {
        lista=lista->siguiente;
    }
    if(lista)
    {
        printf("Pasando a modificar la matricula del profesional solicitante..\n");
        lista->ingreso.matriculaProfesional=matriculaSolicitante(lista->ingreso.matriculaProfesional);
    }
}

void modificarFechaIngreso(int nroIngreso, nodoListaIngresos*lista)
{
    while(lista!=NULL && nroIngreso !=lista->ingreso.nroIngreso)
    {
        lista=lista->siguiente;
    }
    if(lista)
    {
        printf("Pasando a modificar la fecha de ingreso..\n");
        fechaIngreso(lista->ingreso.fechaIngreso);
    }
}
void modificarFechaRetiro(int nroIngreso, nodoListaIngresos*lista)
{
    while(lista!=NULL && nroIngreso !=lista->ingreso.nroIngreso)
    {
        lista=lista->siguiente;
    }
    if(lista)
    {
        printf("Pasando a modificar la fecha de ingreso..\n");
        fechaRetiro(lista->ingreso.fechaRetiro, lista->ingreso.fechaIngreso);
    }
}
///cambia el ingreso por 0 o por 1, dependiendo lo que elija el usuario.
void eliminarIngreso(int numIngreso, char archivo[])
{
    FILE*buffer=fopen(archivo, "r+b");
    int pos;
    char cont='s';
    pracXingreso ingresito;
    if(buffer)
    {
        while(fread(&ingresito, sizeof(ingresos),1,buffer)>0){
            if(ingresito.nroIngreso==numIngreso){
                printf("Desea eliminar por completo este ingreso?\n");
                fflush(stdin);
                scanf("%c", &cont);
                if(cont=='s')
                {
                    ingresito.eliminado=1;
                }
                else{
                    ingresito.eliminado=0;
                }
                pos=ftell(buffer)-sizeof(ingresos);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&ingresito, sizeof(ingresos), 1, buffer);
                break;
                }
            }
        fclose(buffer);
    }
    else{
        printf("Error al abrir el archivo..\n");
    }
}
