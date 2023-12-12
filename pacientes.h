#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
///prototipados de librería "pacientes":
int validarEdad(int edad);
int validarDni(int dniBuscado);
int buscaPaciente(char archivo[], int dniBuscado);
int dniPaciente(int dni);
void nombrePaciente(char nombre[40], int tamanio);
int edadPaciente(int edad);
void direccionPaciente(char direccion[30], int tamanio);
void telPaciente(char celular[15], int tamanio);

pacientes crearPaciente(pacientes paciente);
nodoArbol*inicArbol();nodoArbol*crearNodo(pacientes registro);
nodoArbol *insertarNodoPaciente(nodoArbol* arbolPaciente, pacientes persona);
nodoArbol*pasarArchiToArbol(nodoArbol *arbol, char archivo[]);
void mostrarArbol(nodoArbol*arbol);
int pasarArchivoToArreglo(char archivo[], int dim, pacientes arreglo[]);
void ordenarPacientesPorName(pacientes arreglo[], int tamano);
void mostrarArreglo(pacientes arreglo[], int val);
int existeEnElArbol(nodoArbol*raiz, int dni);
nodoArbol*buscarPorDNI(nodoArbol*raiz, int dni);
void mostrarNodo(pacientes persona);
void bajaPaciente(char archivo[], nodoArbol*arbol, int dni);
nodoArbol * altaPaciente(nodoArbol * arbol, pacientes persona, ingresos ingreso, pracXingreso practica);
void ordenarEmpleadosPorName(empleados_laboratorio arreglo[], int tamano);
void pasarArbolAlArchivo(nodoArbol*arbol, char archivo[]);
void escribirEnElArchi(FILE*archi, nodoArbol*arbol);
pacientes cargaPaciente(nodoArbol*arbol);
nodoArbol * modificarDniArbol(int dniNuevo, int dniActual, nodoArbol*arbol);
nodoArbol* modificarNombreYApellidoArbol(nodoArbol*arbol, int dni, char nuevoNombre[]);
nodoArbol* modificarDireccionArbol(nodoArbol*arbol, int dni, char nuevaDireccion[]);
nodoArbol* modificarTelefonoArbol(nodoArbol*arbol, int dni, char nuevoTelefono[]);
nodoArbol* modificarEdadArbol(nodoArbol*arbol, int dni, int nuevaEdad);
void cargarArbolAArchivo(nodoArbol* arbol, char archivoIngresos[]) ;
void cargarNodosDelArbolRecursivo(nodoArbol* arbol, FILE* archivo);
nodoArbol* eliminarNodo(nodoArbol* arbol, int dni);
nodoArbol*modificarDniArbol(int dniNuevo, int dniActual, nodoArbol*arbol);


#endif // PACIENTES_H_INCLUDED
