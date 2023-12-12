#ifndef INGRESOS_H_INCLUDED
#define INGRESOS_H_INCLUDED

void eliminarIngreso(int numIngreso, char archivo[]);
int pasarArchiaArreglo(char archivo[], ingresos arreglo[], int validos);
int ultimoIngreso(char archivoIngresos[], int dni);
int dia(int diaMes);
int mes(int mesMes);
int anio(int anioMes);
void fechaIngreso(char fecha[]);
void fechaIngreso(char fecha[10]);
int matriculaSolicitante(int matri);
ingresos crearIngresos(ingresos ingresoPaciente, char archivoIngresos[], int dni);
void cargaIngreso(char archivoIngresos[], char archivoPacientes[], ingresos ingresito);
nodoListaIngresos * inicListaIngresos();
nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso);
nodoListaIngresos* agregarPrincipio(nodoListaIngresos*lista,char archivoIngresos[], int dni);
nodoListaIngresos * pasarArchiAlista(nodoListaIngresos * lista, char archivoIngresos[], int dni);
void muestraIngreso(ingresos dato);
void modificarIngresoMenu(int ingreso,char archivo[], nodoArbol*arbol);
void modificarMatricula(int nroIngreso, nodoListaIngresos*lista);
void modificarFecha(int numIngreso, char archivo[]);
void mostrarArchivoIngresos(char archivoIngresos[]);
void mostrarIngresosPorPaciente(nodoArbol*arbol, char archivoIngresos[]);
void guardarListaEnArchivoRecursivo(nodoListaIngresos*lista, FILE*archivo);
void guardarListasDelArbolRecursivo(nodoArbol *arbol, FILE *archivo);
void pasarListaToArchi(nodoArbol*arbol, char archivoIngresos[]);
nodoArbol*cargarIngresoenArbol(nodoArbol*arbol, int dni,char archivoIngresos[]);
void insertarNodoEnArbol(nodoArbol*arbol, nodoListaIngresos*nodoLista);
nodoArbol* archivoIngresosToArbol(char archivoIngresos[], nodoArbol * arbol);
nodoListaIngresos *agregarAlista(nodoListaIngresos *lista, ingresos nuevoIngreso);

#endif // INGRESOS_H_INCLUDED
