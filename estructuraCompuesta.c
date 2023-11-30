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
    nodoListaIngresos*aux=lista;
    pracXingreso dato;
    ///REVISAR
    if(buffer)
    {
        while(fread(&dato, sizeof(pracXingreso), 1, buffer)>0)
        {
            while(aux){
                if(aux->ingreso.nroIngreso==dato.nroIngreso)
                {
                    aux=agregarListaPracticas(lista, dato);
                }
                aux=aux->siguiente;
        }
        aux=lista;
        }

        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }
    lista=aux;

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

void recorrerYmostrarEstructuraCompuestaInOrder(nodoArbol * arbol)
{

    if(arbol)
    {
        recorrerYmostrarEstructuraCompuestaInOrder(arbol->izq);
        printf("\n=============================\n");
        mostrarNodo(arbol->persona);
        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
        printf("\n=============================\n");
        recorrerYmostrarEstructuraCompuestaInOrder(arbol->der);
    }
}
void recorrerYmostrarEstructuraCompuestaPreOrder(nodoArbol * arbol)
{

    if(arbol)
    {
        printf("\n=============================\n");
        mostrarNodo(arbol->persona);
        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
        printf("\n=============================\n");
        recorrerYmostrarEstructuraCompuestaPreOrder(arbol->izq);
        recorrerYmostrarEstructuraCompuestaPreOrder(arbol->der);
    }
}

void recorrerYmostrarEstructuraCompuestaPosOrder(nodoArbol * arbol)
{

    if(arbol)
    {
        recorrerYmostrarEstructuraCompuestaPosOrder(arbol->izq);
        recorrerYmostrarEstructuraCompuestaPosOrder(arbol->der);
        printf("\n=============================\n");
        mostrarNodo(arbol->persona);
        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
        printf("\n=============================\n");
    }
}
void contarPacientes(int *num, nodoArbol*arbol)
{
    if(arbol)
    {
        if(arbol->persona.eliminado!=0)
        {
            *num=*num+1;
        }
        contarPacientes(num, arbol->izq);
        contarPacientes(num, arbol->der);
    }
}

nodoListaIngresos * recorrerYmostrarsinPracticas(nodoListaIngresos * lista)
{
    nodoListaIngresos * aux=lista;

    while(aux)
    {
        muestraIngreso(aux->ingreso);
        aux=aux->siguiente;
    }

    return lista;
}

void inOrderSinPracticas(nodoArbol * arbol)
{

    if(arbol)
    {
        inOrderSinPracticas(arbol->izq);
        printf("\n=============================\n");
        mostrarNodo(arbol->persona);
        arbol->lista=recorrerYmostrarsinPracticas(arbol->lista);
        printf("\n=============================\n");
        inOrderSinPracticas(arbol->der);
    }
}
