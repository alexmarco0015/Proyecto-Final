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


//nodoListaIngresos * agregarListaPracticas(nodoListaIngresos* lista, pracXingreso dato)
//{
//    nodoListaIngresos * aux = buscarIngreso(lista, dato.nroIngreso);
//
//    nodoPractXingreso * nuevoNodo = crearNodoListaPracXingresos(dato);
//
//    if (aux == NULL) {
//        aux = crearNodoListaIngresos(aux->ingreso);
//        aux->siguiente = lista;
//        lista = aux;
//    }
//
//    aux->lista = agregarPrincipioPracXingresos(nuevoNodo, aux->lista);
//
//    return lista;
//}
//
//
//
//nodoListaIngresos * leerArchivoPracticas(char archivoPracticas[], nodoListaIngresos * lista)
//{
//    FILE*buffer=fopen(archivoPracticas, "rb");
//    nodoListaIngresos*aux=lista;
//    pracXingreso dato;
//    ///REVISAR
//    if(buffer)
//    {
//        while(fread(&dato, sizeof(pracXingreso), 1, buffer)>0)
//        {
//            while(aux){
//                if(aux->ingreso.nroIngreso==dato.nroIngreso)
//                {
//                    aux=agregarListaPracticas(lista, dato);
//                }
//                aux=aux->siguiente;
//        }
//        aux=lista;
//        }
//
//        fclose(buffer);
//    }
//    else{
//        system("cls");
//        printf("Error al abrir el archivo..\n\n");
//        system("pause");
//        system("cls");
//    }
//    lista=aux;
//
//    return lista;
//}
//
//void recorrerArbolYagregarPracticasxIngreso(nodoArbol * arbol, char archivoPracticas[])
//{
//
//    if(arbol)
//    {
//        recorrerArbolYagregarPracticasxIngreso(arbol->izq, archivoPracticas);
//        arbol->lista=leerArchivoPracticas(archivoPracticas, arbol->lista);
//        recorrerArbolYagregarPracticasxIngreso(arbol->der, archivoPracticas);
//    }
//
//}
//
//
//nodoArbol * agregarListaIngresos(nodoArbol * arbol, ingresos dato)
//{
//    nodoArbol * aux=buscarPorDNI(arbol, dato.dniPaciente);
//
//    if(aux!=NULL)
//    {
//    nodoListaIngresos * nuevoNodo=inicListaIngresos();
//     nuevoNodo=crearNodoListaIngresos(dato);
//       arbol->lista=agregarPrincipio(nuevoNodo, aux->lista);
//    }
//
//    return arbol;
//}
//
//nodoListaIngresos* leerArchivoIngresos(nodoListaIngresos * lista, int dni, char archivoIngresos[])
//{
//
//    FILE * buffer=fopen(archivoIngresos, "rb");
//    nodoListaIngresos * nuevoNodo=inicListaIngresos();
//    ingresos dato;
//
//    if(buffer)
//    {
//        while(fread(&dato, sizeof(ingresos), 1, buffer)>0)
//        {
//            if(dni==dato.dniPaciente)
//            {
//                nuevoNodo=crearNodoListaIngresos(dato);
//                lista=agregarPrincipio(nuevoNodo, lista);
//            }
//        }
//
//        fclose(buffer);
//    }
//    else{
//        system("cls");
//        printf("Error al abrir el archivo..\n\n");
//        system("pause");
//        system("cls");
//    }
//
//    return lista;
//}
void mostrarListaIngresos(nodoListaIngresos*lista){
    nodoListaIngresos*aux=lista;

    while(aux){

        muestraIngreso(aux->ingreso);

        aux=aux->siguiente;

    }
}

//void mostrarArchivoIngresos(char archivoIngresos[]) {
//    FILE *buffer = fopen(archivoIngresos, "rb");
//    ingresos dato;
//
//    if (buffer) {
//
//        while (fread(&dato, sizeof(ingresos), 1, buffer) > 0) {
//
//            muestraIngreso(dato);
//            printf("---------------------------------\n");
//        }
//
//        fclose(buffer);
//    } else {
//        printf("Error al abrir el archivo de ingresos.\n");
//    }
//}
//void mostrarArchivoPracticas(char archivopracticas[]) {
//    FILE *buffer = fopen(archivopracticas, "rb");
// pracXingreso dato;
//
//    if (buffer) {
//
//        while (fread(&dato, sizeof(pracXingreso), 1, buffer) > 0) {
//
//           muestraPracXingreso(dato);
//            printf("---------------------------------\n");
//        }
//
//        fclose(buffer);
//    } else {
//        printf("Error al abrir el archivo de ingresos.\n");
//    }
//}
//void mostrarArchivoIngresosConPracticas(char archivoIngresos[], char archivopracticas[]) {
//    FILE *bufferIngresos = fopen(archivoIngresos, "rb");
//    FILE *bufferPracticas = fopen(archivopracticas, "rb");
//
//    ingresos ingresoDato;
//    pracXingreso practicaDato;
//
//    if (bufferIngresos && bufferPracticas) {
//        while (fread(&ingresoDato, sizeof(ingresos), 1, bufferIngresos) > 0) {
//            muestraIngreso(ingresoDato);
//            printf("---------------------------------\n");
//
//
//            fseek(bufferPracticas, 0, SEEK_SET);
//            while (fread(&practicaDato, sizeof(pracXingreso), 1, bufferPracticas) > 0) {
//                if (practicaDato.nroIngreso == ingresoDato.nroIngreso) {
//                    muestraPracXingreso(practicaDato);
//                    printf("    *****************************\n");
//                }
//            }
//
//            printf("=================================\n");
//        }
//
//        fclose(bufferIngresos);
//        fclose(bufferPracticas);
//    } else {
//        printf("Error al abrir uno de los archivos.\n");
//    }
//}
//nodoPractXingreso * recorrerYmostrarListaPrac(nodoPractXingreso * lista)
//{
//    nodoPractXingreso * aux=lista;
//
//    while(aux)
//    {
//        muestraPracXingreso(aux->ingreso);
//        aux=aux->siguiente;
//    }
//
//    return lista;
//}
//
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
//void recorrerYmostrarEstructuraCompuestaInOrder(nodoArbol * arbol)
//{
//
//    if(arbol)
//    {
//        recorrerYmostrarEstructuraCompuestaInOrder(arbol->izq);
//        printf("\n=============================\n");
//        mostrarNodo(arbol->persona);
//        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
//        printf("\n=============================\n");
//        recorrerYmostrarEstructuraCompuestaInOrder(arbol->der);
//    }
//}
//void recorrerYmostrarEstructuraCompuestaPreOrder(nodoArbol * arbol)
//{
//
//    if(arbol)
//    {
//        printf("\n=============================\n");
//        mostrarNodo(arbol->persona);
//        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
//        printf("\n=============================\n");
//        recorrerYmostrarEstructuraCompuestaPreOrder(arbol->izq);
//        recorrerYmostrarEstructuraCompuestaPreOrder(arbol->der);
//    }
//}
//
//void recorrerYmostrarEstructuraCompuestaPosOrder(nodoArbol * arbol)
//{
//
//    if(arbol)
//    {
//        recorrerYmostrarEstructuraCompuestaPosOrder(arbol->izq);
//        recorrerYmostrarEstructuraCompuestaPosOrder(arbol->der);
//        printf("\n=============================\n");
//        mostrarNodo(arbol->persona);
//        arbol->lista=recorrerYmostrarListaIngresos(arbol->lista);
//        printf("\n=============================\n");
//    }
//}
//void contarPacientes(int *num, nodoArbol*arbol)
//{
//    if(arbol)
//    {
//        if(arbol->persona.eliminado!=0)
//        {
//            *num=*num+1;
//        }
//        contarPacientes(num, arbol->izq);
//        contarPacientes(num, arbol->der);
//    }
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
