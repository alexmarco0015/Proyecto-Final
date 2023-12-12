#ifndef INGRESOS_H_INCLUDED
#define INGRESOS_H_INCLUDED

int pasarArchiaArreglo(char archivo[], ingresos arreglo[], int validos);
void recorroListaYcuento(nodoListaIngresos * lista, int *i);
void ultIngreso(nodoArbol * arbol, int *i);
void fechaIngreso(char fecha[10]);
void fechaRetiro(char fecha[10], char fechaAnt[10]);
int matriculaSolicitante(int matri);
int dia(int diaMes);
int mes(int mesMes);
int anio(int anioMes);
ingresos crearIngresos(ingresos ingresoPaciente, nodoArbol * arbol, int dni);
void cargaIngreso(char archivoIngresos[], char archivoPacientes[], ingresos ingresito);
nodoListaIngresos * inicListaIngresos();
nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso);
nodoListaIngresos* agregarPrincipio(nodoListaIngresos*lista,nodoArbol * arbol, int dni);
nodoListaIngresos *agregarAlista(nodoListaIngresos *lista, ingresos nuevoIngreso);
nodoArbol* archivoIngresosToArbol(char archivoIngresos[], nodoArbol * arbol);
nodoArbol*cargarIngresoenArbol(nodoArbol*arbol, int dni);
void pasarListaToArchi(nodoArbol*arbol, char archivoIngresos[]);
void guardarListasDelArbolRecursivo(nodoArbol *arbol, FILE *archivo);
void guardarListaEnArchivoRecursivo(nodoListaIngresos *lista, FILE*archivo);
void muestraIngreso(ingresos dato);
void modificarMatricula(int nroIngreso, nodoListaIngresos*lista);
void modificarFechaIngreso(int nroIngreso, nodoListaIngresos*lista);
void modificarFechaRetiro(int nroIngreso, nodoListaIngresos*lista);
void eliminarIngreso(int numIngreso, char archivo[]);
#endif // INGRESOS_H_INCLUDED
