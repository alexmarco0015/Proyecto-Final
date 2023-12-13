#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"
#include "pracXingresos.h"
#include "pacientes.h"
#include "ingresos.h"
///el usuario inserta el tipo de resultado que ha generado dicha practica
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
        if(strlen(resultado)>100 || strlen(resultado)<10){//verificamos que no se exceda de la cantidad de caracteres ni le falten
            printf("se ha excedido o le ha faltado en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 100 y mas de 10..\n");
            seguro='n';
            system("pause");
            system("cls");
        }
    }while(seguro!='s' && seguro!='S');
}
///nro de practica que se genera automaticamente.
int nroPractica(nodoPractXingreso*lista)
{
  nodoPractXingreso*aux=lista;
   int i=0;

   while(aux){
        aux=aux->siguiente;
        i++;
   }
   return i;
}
///crea la practica con ayuda de las anteriores funciones.
pracXingreso crearPractica(int nroIngreso, int nropract){
    pracXingreso practiquita;
    practiquita.nroIngreso=nroIngreso;
    practiquita.nroPractica=nropract+1;
    crearResultado(practiquita.resultado);
    practiquita.eliminado=0;

    return practiquita;
}
///inicializacion de un nodo de tipo lista
nodoPractXingreso * inicListapracXingresos()
{
    return NULL;
}
///creacion de un nodo de tipo lista
nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso){

    nodoPractXingreso*nuevo=(nodoPractXingreso*)malloc(sizeof(nodoPractXingreso));

    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    strcpy(nuevo->ingreso.resultado, ingreso.resultado);
    nuevo->ingreso.nroPractica=ingreso.nroPractica;
    nuevo->ingreso.eliminado=ingreso.eliminado;

    nuevo->siguiente=NULL;

    return nuevo;
}
///un agregar al principio de tipo nodolista de toda la vida
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
///agregamos una practica al arbol si es que no existe se inserta, sino la agrega al principio.
nodoArbol*agregarPracticaAlArbol(nodoArbol*arbol, int nroIngreso){
        nodoListaIngresos*aux=buscarIngresoArbol(arbol, nroIngreso);

        if(aux!=NULL)
        {
            int i=0;
            ultPract(arbol, &i);
            pracXingreso nuevaPractica=crearPractica(nroIngreso, i);
            nodoPractXingreso *nuevoNodo=crearNodoListaPracXingresos(nuevaPractica);
            aux->lista=agregarPrincipioPracXingresos(nuevoNodo, aux->lista);
        }
        return arbol;
}


///mostramos una pracXingreso, sirve para nodos, registros y demás
void muestraPracXingreso(pracXingreso dato)
{
    printf("\n******************\n");
    printf("Numero de Practica: %d\n", dato.nroPractica);
    printf("Resultado: \n%s\n", dato.resultado);
    printf("*******************\n");
}
///modificacion de un resultado de practica desde la estructura compuesta
void modificarResultadoPractica(int nroPract, nodoPractXingreso*lista){

    while(lista!=NULL && nroPract !=lista->ingreso.nroPractica)
    {
        lista=lista->siguiente;
    }

    if(lista)
    {
        printf("Pasando a modificar El resultado de la practica..\n");
        crearResultado(lista->ingreso.resultado);
    }

}
///pedimos el numero de la practica en cuestion, para poder acceder a ella más tarde
int pedirNum(){
    int num;
    printf("por  favor, ingrese el numero de la practica\n");
    fflush(stdin);
    scanf("%i", &num);
    system("pause");
    system("cls");

    return num;
}
///modificacion de una parctica desde la estructura compuesta
void modificarNrodePracticaxIngreso(int nroPract, nodoPractXingreso*lista){

    while(lista!=NULL && nroPract !=lista->ingreso.nroPractica)
    {
        lista=lista->siguiente;
    }

    if(lista)
    {
        printf("Pasando a modificar El numero de la practica..\n");
        lista->ingreso.nroPractica=pedirNum();
    }
}
///baja de una parctXingreso a través de los nodos.
void bajaPracticaxIngreso(int nroPract, nodoPractXingreso * lista){

    while(lista!=NULL && nroPract !=lista->ingreso.nroPractica)
    {
        lista=lista->siguiente;
    }
    if(lista)
    {
        printf("Pasando a modificar El numero de la practica..\n");
        if(lista->ingreso.eliminado==0){
            lista->ingreso.eliminado=1;
        }
        else{
            lista->ingreso.eliminado=0;
        }
    }

}
///insertamos la practica en el ultimo lugar de la lista, si no existe la lista, se inserta al inicio.
nodoPractXingreso * insertarListaPracXingresoEnIngresos(nodoPractXingreso * lista, nodoPractXingreso *nuevoNodo) {

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

nodoPractXingreso* buscarListaPracXingresoEnArbol(nodoArbol *raiz, int nroIngreso) {

    // Buscar la lista de ingresos correspondiente en el árbol
    nodoListaIngresos *listaIngresos = buscarIngresoArbol(raiz, nroIngreso);

    // Buscar la lista de pracXingreso dentro de la lista de ingresos
    if (listaIngresos != NULL) {
        return listaIngresos->lista;
    }

    return NULL;  // Lista de ingresos no encontrada
}
nodoPractXingreso*agregarppioparaArchi(nodoPractXingreso*lista, nodoPractXingreso*nuevoNodo)
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
///se agregan todas las practicas del archivo al arbol de listas de listas..
nodoArbol* archivoPracXingresoIngresoToArbol(char archivopracXingr[], nodoArbol *arbol) {
    FILE *buffer = fopen(archivopracXingr, "rb");
    pracXingreso dato;

    if (buffer) {
        while (fread(&dato, sizeof(pracXingreso), 1, buffer) > 0) {

            nodoListaIngresos *listaIngresos =buscarIngresoArbol(arbol, dato.nroIngreso);

            if (listaIngresos != NULL) {
                nodoPractXingreso*nuevoNodo=crearNodoListaPracXingresos(dato);
                listaIngresos->lista = agregarppioparaArchi(listaIngresos->lista, nuevoNodo);
            } else {
                printf("No se encontró la lista de ingresos para el nroIngreso %d en el árbol.\n", dato.nroIngreso);
            }
        }

        fclose(buffer);
    } else {
        printf("Error al abrir el archivo de prácticas por ingreso.\n");
    }

    return arbol;
}
void pasarListaPXIToArchi(nodoArbol*arbol, char archivoPXI[]){
        FILE*archi=fopen(archivoPXI,"wb");

        if(archi){
                guardarListasDelArbolRecursivo2(arbol,archi);
        fclose(archi);

        }else{
            printf("ERROR AL ABRIR\n");
        }
}

void guardarListasDelArbolRecursivo2(nodoArbol *arbol, FILE *archivo) {
    if (arbol != NULL) {
        guardarListaPractXingresoEnArchivoRecursivo(arbol->lista, archivo);

        guardarListasDelArbolRecursivo2(arbol->izq, archivo);
        guardarListasDelArbolRecursivo2(arbol->der, archivo);
    }
}

void guardarListaPractXingresoEnArchivoRecursivo(nodoListaIngresos *lista, FILE *archivo) {
    while (lista != NULL) {
        guardarListaPractXingreso(lista->lista, archivo);
        lista = lista->siguiente;
    }
}

void guardarListaPractXingreso(nodoPractXingreso *lista, FILE *archivo) {
    while (lista != NULL) {
        fwrite(&(lista->ingreso), sizeof(pracXingreso), 1, archivo);
        lista = lista->siguiente;
    }
}
int estaLaPract(int practiquita,nodoPractXingreso * lista)
{
    int flag=0;
    nodoPractXingreso * aux=lista;

    while(aux)
    {
        if(practiquita==aux->ingreso.nroPractica)
        {
            flag=1;
            break;
        }
        aux=aux->siguiente;
    }

    return flag;
}
void recorroListaYcuentoPract(nodoPractXingreso * lista, int *i)
{
    if(lista)
    {
        *i=*i+1;
        recorroListaYcuentoPract(lista->siguiente, i);
    }
}
void recorroListaIngrYcuentoPract(nodoListaIngresos * lista, int *i)
{
    if(lista)
    {
        recorroListaYcuentoPract(lista->lista, i);
        recorroListaIngrYcuentoPract(lista->siguiente, i);
    }
}
void ultPract(nodoArbol * arbol, int *i)
{
    if(arbol)
    {
        recorroListaIngrYcuentoPract(arbol->lista, i);
        ultPract(arbol->izq, i);
        ultPract(arbol->der, i);
    }
}
