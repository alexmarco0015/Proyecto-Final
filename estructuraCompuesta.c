#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

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

nodoListaIngresos * agregarListaPracticas(nodoListaIngresos* lista, pracXingreso dato)
{
    nodoListaIngresos * aux=buscarIngreso(lista, dato.nroIngreso);

    nodoPractXingreso * nuevoNodo=crearNodoListaPracXingresos(dato);

    aux->lista=agregarPrincipioPracXingresos(nuevoNodo, aux->lista);

    return lista;
}



nodoListaIngresos * leerArchivoPracticas(char archivoPracticas[], nodoListaIngresos * lista)
{
    FILE*buffer=fopen(archivoPracticas, "rb");

    pracXingreso dato;

    if(buffer)
    {
        while(fread(&dato, sizeof(pracXingreso), 1, buffer)>0)
        {
            if(lista->ingreso.nroIngreso==dato.nroIngreso)
            {
                lista=agregarListaPracticas(lista, dato);
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

    return lista;
}

void recorrerArbolYagregarPracticasxIngreso(nodoArbol * arbol, char archivoPracticas[])
{

    if(arbol)
    {
        recorrerArbolYagregarPracticasxIngreso(arbol->izq, archivoPracticas);
        arbol->lista=leerArchivoPracticas(archivoPracticas, arbol->lista);
        recorrerArbolYagregarPracticasxIngreso(arbol->der, archivoPracticas);
    }

}


nodoArbol * agregarListaIngresos(nodoArbol * arbol, ingresos dato)
{
    nodoArbol * aux=buscarPorDNI(arbol, dato.dniPaciente);
    nodoListaIngresos * nuevoNodo=inicListaIngresos();
    nuevoNodo=crearNodoListaIngresos(dato);

    aux->lista=agregarPrincipio(nuevoNodo, aux->lista);

    return arbol;
}

nodoArbol* leerArchivoIngresos(nodoArbol * arbol, char archivoIngresos[])
{

    FILE*buffer=fopen(archivoIngresos, "rb");
    ingresos dato;

    if(buffer)
    {
        while(fread(&dato, sizeof(ingresos), 1, buffer)>0)
        {
            arbol=agregarListaIngresos(arbol, dato);
        }

        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }

    return arbol;
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

nodoListaIngresos * recorrerYmostrarListaIngresos(nodoListaIngresos * lista)
{
    nodoListaIngresos * aux=lista;

    while(aux)
    {
        muestraIngreso(aux->ingreso);
        aux->lista=recorrerYmostrarListaPrac(aux->lista);
        aux=aux->siguiente;
    }

    return lista;
}

void recorrerYmostrarEstructuraCompuesta(nodoArbol * arbol)
{

    if(arbol)
    {
        recorrerYmostrarEstructuraCompuesta(arbol->izq);
        printf("\n----------------------------\n");
        mostrarNodo(arbol->persona);
        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
        printf("\n--------------------------------\n");
        recorrerYmostrarEstructuraCompuesta(arbol->der);
    }
}
