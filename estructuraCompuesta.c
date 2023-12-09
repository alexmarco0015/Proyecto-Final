#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "pracXingresos.h"

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


nodoListaIngresos * agregarListaPracticas(nodoListaIngresos* lista)
{
    nodoPractXingreso * auxPract=lista->lista;
    int nro=0;
    nro=nroPractica(auxPract);
    pracXingreso dato=crearPractica(lista->ingreso.nroIngreso, nro);

    nodoPractXingreso * nuevoNodo = inicListapracXingresos();
    nuevoNodo=crearNodoListaPracXingresos(dato);

//    if (aux == NULL) {
//        aux = crearNodoListaIngresos(aux->ingreso);
//        aux->siguiente = lista;
//        lista = aux;
//    }

    lista->lista = agregarPrincipioPracXingresos(nuevoNodo, lista->lista);

    return lista;
}
nodoListaIngresos*buscarIngresoArbol(nodoArbol*arbol, int nroIngreso){
    if (arbol == NULL) {
        return NULL;
    }

    nodoListaIngresos* encontrado = buscarIngreso(arbol->lista, nroIngreso);

    if (encontrado != NULL) {
        return encontrado;
    }

    return buscarIngresoArbol(arbol->izq, nroIngreso);
    return  buscarIngresoArbol(arbol->der, nroIngreso);


}

void mostrarListaIngresos(nodoListaIngresos*lista){
    nodoListaIngresos*aux=lista;

    while(aux){

        muestraIngreso(aux->ingreso);

        aux=aux->siguiente;

    }
}

nodoPractXingreso * recorrerYmostrarListaPrac(nodoPractXingreso * lista)
{
    nodoPractXingreso * aux=lista;

    while(aux)
    {
        muestraPracXingreso(aux->ingreso);
        aux=aux->siguiente;
    }

    return lista;
}

//nodoListaIngresos * recorrerYmostrarListaIngresos(nodoListaIngresos * lista)
//{
//    nodoListaIngresos * aux=lista;
//
//    while(aux)
//    {
//        muestraIngreso(aux->ingreso);
//        aux->lista=recorrerYmostrarListaPrac(aux->lista);
//        aux=aux->siguiente;
//    }
//
//    return lista;
//}
//


//nodoListaIngresos * recorrerYmostrarsinPracticas(nodoListaIngresos * lista)
//{
//    nodoListaIngresos * aux=lista;
//
//    while(aux!=NULL)
//    {
//        printf("----------------\n");
//        muestraIngreso(aux->ingreso);
//        printf("------------------\n");
//        aux=aux->siguiente;
//    }
//
//    return lista;
//}
//
//void inOrderSinPracticas(nodoArbol * arbol)
//{
//
//    if(arbol)
//    {
//        inOrderSinPracticas(arbol->izq);
//        if(arbol->persona.eliminado==0){
//            printf("\n=============================\n");
//            mostrarNodo(arbol->persona);
//            if (arbol->lista != NULL) {
//                arbol->lista = recorrerYmostrarsinPracticas(arbol->lista->siguiente);
//            }
//            printf("\n=============================\n");
//        }
//        inOrderSinPracticas(arbol->der);
//    }
//}
