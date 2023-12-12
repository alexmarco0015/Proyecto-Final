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
pacientes cargaPaciente(nodoArbol*arbol);
nodoArbol*inicArbol();
nodoArbol*crearNodo(pacientes registro);
nodoArbol *insertarNodoPaciente(nodoArbol* arbolPaciente, pacientes persona);
nodoArbol*pasarArchiToArbol(nodoArbol *arbol, char archivo[]);
void pasarArbolAlArchivo(nodoArbol*arbol, char archivo[]);
void escribirEnElArchi(FILE*archi, nodoArbol*arbol);
void mostrarArbol(nodoArbol*arbol);
void ordenarPacientesPorName(pacientes arreglo[], int tamano);
void mostrarArreglo(pacientes arreglo[], int val);
int existeEnElArbol(nodoArbol*raiz, int dni);
nodoArbol*buscarPorDNI(nodoArbol*raiz, int dni);
void mostrarNodo(pacientes persona);
int pasarArchivoToArreglo(char archivo[], int dim, pacientes arreglo[]);
void modificarTelefono(char archivo[], int dni);
void modificarDireccion(char archivo[], int dni);
void modificarEdad(char archivo[], int dni);
void modificarNombreYApellido(char archivo[], int dni);
void modificarPacienteDni(char archivo[], int dni, int dniNuevo);
void bajaPaciente(char archivo[], nodoArbol*arbol, int dni);
void modificarDNIlista(nodoListaIngresos * lista, int dniNuevo);
nodoArbol*modificarDniArbol(int dniNuevo, int dniActual, nodoArbol*arbol);
nodoArbol* modificarNombreYApellidoArbol(nodoArbol*arbol, int dni, char nuevoNombre[]);
nodoArbol* modificarTelefonoArbol(nodoArbol*arbol, int dni, char nuevoTelefono[]);
nodoArbol* modificarEdadArbol(nodoArbol*arbol, int dni, int nuevaEdad);
nodoArbol* buscarDniMenor(nodoArbol* arbol);
nodoArbol* eliminarNodo(nodoArbol* arbol, int dni);
void cargarArbolAArchivo(nodoArbol* arbol, char archivoIngresos[]);
void cargarNodosDelArbolRecursivo(nodoArbol* arbol, FILE* archivo);


#endif // PACIENTES_H_INCLUDED
