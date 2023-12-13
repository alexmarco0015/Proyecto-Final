#ifndef PRACXINGRESOS_H_INCLUDED
#define PRACXINGRESOS_H_INCLUDED
#include "prototipados.h"

void crearResultado(char resultado[]);
int nroPractica(nodoPractXingreso*lista);
pracXingreso crearPractica(int nroIngreso, int nropract);
nodoPractXingreso * inicListapracXingresos();
nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso);
nodoPractXingreso* agregarPrincipioPracXingresos(nodoPractXingreso * nuevoNodo, nodoPractXingreso * lista);
nodoArbol*agregarPracticaAlArbol(nodoArbol*arbol, int nroIngreso);
void muestraPracXingreso(pracXingreso dato);
void modificarResultadoPractica(int nroPract, nodoPractXingreso*lista);
int pedirNum();
void modificarNrodePracticaxIngreso(int nroPract, nodoPractXingreso*lista);
void bajaPracticaxIngreso(int nroPract, nodoPractXingreso * lista);
nodoPractXingreso * insertarListaPracXingresoEnIngresos(nodoPractXingreso * lista, nodoPractXingreso *nuevoNodo);
nodoArbol*archivoPracXingresoIngresoToArbol(char archivopracXingr[], nodoArbol * arbol);
nodoPractXingreso* buscarListaPracXingresoEnArbol(nodoArbol *raiz, int nroIngreso);
int estaLaPract(int practiquita,nodoPractXingreso * lista);
void guardarListasDelArbolRecursivo2(nodoArbol *arbol, FILE *archivo);
void guardarListaPractXingreso(nodoPractXingreso *lista, FILE *archivo);
void guardarListaPractXingresoEnArchivoRecursivo(nodoListaIngresos *lista, FILE *archivo);
void pasarListaPXIToArchi(nodoArbol*arbol, char archivoPXI[]);
void recorroListaYcuentoPract(nodoPractXingreso * lista, int *i);
void recorroListaIngrYcuentoPract(nodoListaIngresos * lista, int *i);
void ultPract(nodoArbol * arbol, int *i);
#endif // PRACXINGRESOS_H_INCLUDED
