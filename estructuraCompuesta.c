#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "pracXingresos.h"
#include "pacientes.h"
#include "ingresos.h"

nodoListaIngresos * buscarIngreso(nodoListaIngresos * lista, int ingreso)
{
    nodoListaIngresos * aux=lista;

    while(aux!=NULL)
    {
        if(aux->ingreso.nroIngreso==ingreso)
        {
            return aux;
        }
        aux=aux->siguiente;
    }

    return NULL;
}

int  existeIngreso(nodoListaIngresos * lista, int ingreso)
{
    nodoListaIngresos * aux=lista;

    while(aux!=NULL)
    {
        if(aux->ingreso.nroIngreso==ingreso)
        {
            return 1;
        }
        aux=aux->siguiente;
    }

    return 0;
}
int existeIngresoArbol(nodoArbol*arbol, int nroIngreso)
{
    if (arbol == NULL) {
        return 0;
    }

    int encontrado = existeIngreso(arbol->lista, nroIngreso);

    if (encontrado != 0) {
        return encontrado;
    }
    if(arbol->izq!=NULL)
    {
        return existeEnElArbol(arbol->izq, nroIngreso);

    }
    else{
        return existeEnElArbol(arbol->der, nroIngreso);
    }
}

nodoListaIngresos * agregarListaPracticas(nodoListaIngresos* lista, nodoArbol *arbol)
{
    int nro=0;
    ultPract(arbol, &nro);
    pracXingreso dato=crearPractica(lista->ingreso.nroIngreso, nro);
    nodoPractXingreso * nuevoNodo = crearNodoListaPracXingresos(dato);
    lista->lista = agregarPrincipioPracXingresos(nuevoNodo, lista->lista);
    return lista;
}

nodoListaIngresos*buscarIngresoArbol(nodoArbol*arbol, int nroIngreso)
{

    if (arbol == NULL) {
        return NULL;
    }
    nodoListaIngresos* encontrado = buscarIngreso(arbol->lista, nroIngreso);

    if (encontrado != NULL) {
        return encontrado;
    }
    if(arbol->izq!=NULL)
    {
        return buscarIngresoArbol(arbol->izq, nroIngreso);

    }

    return buscarIngresoArbol(arbol->der, nroIngreso);
}

void mostrarListaIngresos(nodoListaIngresos*lista)
{
    nodoListaIngresos*aux=lista;

    while(aux){

        muestraIngreso(aux->ingreso);

        aux=aux->siguiente;

    }
}

void recorrerYmostrarListaPrac(nodoPractXingreso * lista)
{
    if(lista)
    {
        muestraPracXingreso(lista->ingreso);
        recorrerYmostrarListaPrac(lista->siguiente);
    }
}

void recorrerYmostrarListaIngresos(nodoListaIngresos * lista)
{
    if(lista)
    {
        muestraIngreso(lista->ingreso);
        recorrerYmostrarListaPrac(lista->lista);
        recorrerYmostrarListaIngresos(lista->siguiente);
    }
}



void recorrerYmostrarsinPracticas(nodoListaIngresos * lista)
{
    if(lista){
        printf("----------------\n");
        muestraIngreso(lista->ingreso);
        printf("------------------\n");
        recorrerYmostrarsinPracticas(lista->siguiente);
    }
}

void inOrderSinPracticas(nodoArbol * arbol)
{

    if(arbol)
    {
        inOrderSinPracticas(arbol->izq);
        if(arbol->persona.eliminado==0){
            printf("\n=============================\n");
            mostrarNodo(arbol->persona);
            if (arbol->lista != NULL) {
                recorrerYmostrarsinPracticas(arbol->lista);
            }
            printf("\n=============================\n");
        }
        inOrderSinPracticas(arbol->der);
    }
}

void inOrden(nodoArbol *arbol)
{
    if(arbol)
    {
        inOrden(arbol->izq);
        if(arbol->persona.eliminado==0){
            printf("\n=============================\n");
            mostrarNodo(arbol->persona);
            if (arbol->lista != NULL) {
                recorrerYmostrarListaIngresos(arbol->lista);
            }
            printf("\n=============================\n");
        }
        inOrden(arbol->der);
    }
}
