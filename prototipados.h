#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED
#endif  //PROTOTIPADOS_H_INCLUDED


typedef struct{
    int nroIngreso;
    char fechaIngreso[10];
    char fechaRetiro[10];
    int dniPaciente;
    int matriculaProfesional;
    int eliminado;//0 para no eliminado o 1 para eliminado

}ingresos;

typedef struct{

    ingresos ingreso;

    struct nodoListaIngresos*siguiente;

}nodoListaIngresos;

typedef struct{
    int nroPractica;
    char nombrePractica[30];
    int eliminado;
}practicas;

typedef struct{
    char apeYnombre[40];
    int edad;
    int dni;
    char direccion[30];
    char telefono[15];
    int eliminado;
}pacientes;

typedef struct nodoArbol {

pacientes persona;

struct nodoArbol * izq;
struct nodoArbol * der;

} nodoArbol;

typedef struct{
    int dni;
    char apeYnombre[40];
    char usuario[20];
    char contrasenia[20];
    int perfil;//preguntar si se puede cambiar por enteros;
    int eliminado;//preguntar si se puede hacer un apartado de eliminados para dar de vaja empleados y que queden en el registro

}empleados_laboratorio;

typedef struct{
    int nroIngreso;
    int nroPractica;
    char resultado[40];
    //faltan punteros;

}pracXingreso;

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
void cargaPaciente(char archivo[], nodoArbol*arbol);
nodoArbol*inicArbol();nodoArbol*crearNodo(pacientes registro);
nodoArbol *insertarNodoPaciente(nodoArbol* arbolPaciente, pacientes registro);
nodoArbol*pasarArchiToArbol(nodoArbol *arbol, char archivo[]);
void mostrarArbol(nodoArbol*arbol);
void mostrarNodo(pacientes persona);
int existeEnElArbol(nodoArbol*raiz, int dni);
nodoArbol*buscarPorDNI(nodoArbol*raiz, int dni);
void mostrarArreglo(pacientes arreglo[], int val);
int pasarArchivoToArreglo(char archivo[], int dim, pacientes arreglo[]);
void ordenarPacientesPorName(pacientes arreglo[], int tamano);


///prototipados de librería "crearUsuario":
void nombreUsuario(char usuario[], int tamanio);
void contraseniaUsuario(char contrasenia[], int tamanio);
int dniUsuario(int dni);
void nombreYapellidoUsuario(char nombre[], int tamanio);
int crearPerfil(int perfil);
empleados_laboratorio crearCuenta(empleados_laboratorio usuario);
void crearusuario(char archivo[], empleados_laboratorio arreglo[], int validos);
int plasmarEnArreglo(char archivo[], empleados_laboratorio arreglo[], int validos);
int verificarEmpleado(int dniEmpleado, empleados_laboratorio arreglo[], int validos);

///prototipados de librería "Menues":
void menuADMIN();
void menuAdministrativo();
void menuLaboratorio();
void menuGeneral();

