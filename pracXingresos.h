#ifndef PRACXINGRESOS_H_INCLUDED
#define PRACXINGRESOS_H_INCLUDED
#include "prototipados.h"

void crearResultado(char resultado[]);
int nroPractica(nodoPractXingreso*lista);
pracXingreso crearPractica(int nroIngreso, int nropract);
nodoPractXingreso * inicListapracXingresos();
nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso);
nodoPractXingreso* agregarPrincipioPracXingresos(nodoPractXingreso * nuevoNodo, nodoPractXingreso * lista);
nodoArbol*agregarPracticaAlArbol(nodoArbol*arbol, ingresos ingresito,char archivoIngresos[]);
void muestraPracXingreso(pracXingreso dato);
void menuModPracticasxIngreso(char archivo[],int nroIngreso);
void modificarResultadoPractica(int nroPract, nodoPractXingreso*lista);
int pedirNum();
void modificarNrodePracticaxIngreso(int nroPract, nodoPractXingreso*lista);
void bajaPracticaxIngreso(int nroPract, nodoPractXingreso * lista);
nodoPractXingreso * insertarListaPracXingresoEnIngresos(nodoPractXingreso * lista, nodoPractXingreso *nuevoNodo);
void archivoPracXingresoIngresoToArbol(char archivopracXingr[], nodoArbol * arbol);
nodoPractXingreso* buscarListaPracXingresoEnArbol(nodoArbol *raiz, int nroIngreso);
#endif // PRACXINGRESOS_H_INCLUDED
