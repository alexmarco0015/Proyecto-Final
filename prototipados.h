#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED


typedef struct{
    int nroIngreso;
    int nroPractica;
    char resultado[100];
    //faltan punteros;

}pracXingreso;

typedef struct ingresos{
    int nroIngreso;
    char fechaIngreso[10];
    char fechaRetiro[10];
    int dniPaciente;
    int matriculaProfesional;
    int eliminado;//0 para no eliminado o 1 para eliminado

}ingresos;

typedef struct nodoPractXingreso{

     pracXingreso ingreso;
    struct nodoPractXingreso*siguiente;

}nodoPractXingreso;

typedef struct nodoListaIngresos{

    ingresos ingreso;
    nodoPractXingreso * lista;
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
    nodoListaIngresos * lista;
} nodoArbol;

typedef struct{
    int dni;
    char apeYnombre[40];
    char usuario[20];
    char contrasenia[20];
    int perfil;// 1 para profesional laboratorio, 2 para adminis.
    int eliminado;//preguntar si se puede hacer un apartado de eliminados para dar de vaja empleados y que queden en el registro
}empleados_laboratorio;



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
void cargaPaciente(char archivo[]);
nodoArbol*inicArbol();nodoArbol*crearNodo(pacientes registro);
nodoArbol *insertarNodoPaciente(nodoArbol* arbolPaciente, pacientes registro);
nodoArbol*pasarArchiToArbol(nodoArbol *arbol, char archivo[]);
void mostrarArbol(nodoArbol*arbol);
void ordenarPacientesPorName(pacientes arreglo[], int tamano);
void mostrarArreglo(pacientes arreglo[], int val);
int existeEnElArbol(nodoArbol*raiz, int dni);
nodoArbol*buscarPorDNI(nodoArbol*raiz, int dni);
void mostrarNodo(pacientes persona);
int pasarArchivoToArreglo(char archivo[], int dim, pacientes arreglo[]);
void menuPaciente(char archivo[], int dni, nodoArbol*arbol);
void modificarPacienteDni(char archivo[], int dni, int dniNuevo);
void modificarTelefono(char archivo[], int dni);
void modificarDireccion(char archivo[], int dni);
void modificarEdad(char archivo[], int dni);
void modificarNombreYApellido(char archivo[], int dni);
void modificarPacienteDni(char archivo[], int dni, int dniNuevo);
void bajaPaciente(char archivo[], nodoArbol*arbol);
nodoArbol * altaPaciente(nodoArbol * arbol, pacientes persona, ingresos ingreso, pracXingreso practica);

///prototipados de librería "crearUsuario":
void nombreUsuario(char usuario[], int tamanio);
void contraseniaUsuario(char contrasenia[], int tamanio);
int dniUsuario(int dni);
void nombreYapellidoUsuario(char nombre[], int tamanio);
int crearPerfil(int perfil);
empleados_laboratorio crearCuenta(empleados_laboratorio usuario);
void crearusuario(const char archivo[], empleados_laboratorio arreglo[], int validos);
int plasmarEnArreglo(const char archivo[], empleados_laboratorio arreglo[], int validos);
int verificarEmpleado(int dniEmpleado, empleados_laboratorio arreglo[], int validos);
void mostrarArregloEmpleados(empleados_laboratorio arreglo[], int validos);
void modDni(const char archivo[], int dni, int dniNuevo);
void modApeYnombre(const char archivo[], int dni);
void modUsername(const char archivo[], int dni);
void modContrasenia(const char archivo[], int dni);
void modTipoPerfil(const char archivo[], int dni);
void darDeBajaEmpleado(const char archivoEmpleados[], int dni);
void chequearEmpleadoAdministrativo(empleados_laboratorio arregloEmpleados[], int validosEmpleados, int dni);
void chequearEmpleadoAdmin(empleados_laboratorio arregloEmpleados[], int validosEmpleados, int dni);

///prototipados de librería "Menues":
void menuADMIN(empleados_laboratorio arregloEmpleados[], int validosEmpleados, const char archivoEmpleados[], char archivoPacientes[], char archivoPractXingresos[], char archivoIngresos[], nodoArbol * arbol, pacientes arregloPacientes[], int validosPacientes);
void menuAdminEmpleados(empleados_laboratorio arreglo[], int validosEmpleados, const char archivoEmpleados[]);
void modificarEmpleadoMenu(int dni, empleados_laboratorio arreglo[], int validosEmpleados, const char archivoEmpleados[]);
void menuAdministrativo(char archivoPacientes[], empleados_laboratorio arregloEmpleados[], int validosEmpleados, nodoArbol * arbol, pacientes arregloPacientes[], int validosPacientes);
void menuLaboratorio(char archivoPaciente[], char archivoPractXingresos[], char archivoIngresos[], nodoArbol * arbol);

///prototipados librería ingresoUsuario
int cargarArregloUsuarios(const char archivo[], empleados_laboratorio arreglo[]);
int analizaPerfil(char usuario[], char contrasenia[], empleados_laboratorio arreglo[], int validos);
void ingresoUsuario(char usuario[], char contrasenia[]);
int analizasiEsAdmin(char usuario[], char contrasenia[], int perfil);
int ingresoPerfil(empleados_laboratorio arreglo[], int validos,const char archivo[]);


///prototipados ingresos.c:
int pasarArchiaArreglo(char archivo[], ingresos arreglo[], int validos);
int ultimoIngreso(char archivoIngresos[], int dni);
void fechaIngreso(char fecha[]);
void fechaRetiro(char fecha[]);
int matriculaSolicitante(int matri);
ingresos crearIngresos(ingresos ingresoPaciente, char archivoIngresos[], int dni);
void cargaIngreso(char archivoIngresos[], char archivoPacientes[], ingresos ingresito);
nodoListaIngresos * inicListaIngresos();
nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso);
nodoListaIngresos* agregarPrincipio(nodoListaIngresos * nuevoNodo, nodoListaIngresos * lista);
nodoListaIngresos * pasarArchiAlista(nodoListaIngresos * lista, char archivoIngresos[], int dni);
void muestraIngreso(ingresos dato);


///prototipados pracXingresos.c:
void crearResultado(char resultado[]);
int nroPractica(char archivoPracticas[], int numeroIngreso);
pracXingreso crearPractica(char archivoPracticas[], pracXingreso pXi, int numeroIngreso);
nodoPractXingreso * inicListapracXingresos();
nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso);
nodoPractXingreso* agregarPrincipioPracXingresos(nodoPractXingreso * nuevoNodo, nodoPractXingreso * lista);
nodoPractXingreso * pasarArchiAlistaPracXingresos(nodoPractXingreso * lista, char archivoPracXingresos[], int ingreso);
void muestraPracXingreso(pracXingreso dato);
void cargaPractica(char archivoPractica[], int ingreso);


///prototipados estructuraCompuesta.c:
nodoListaIngresos * buscarIngreso(nodoListaIngresos * lista, int ingreso);
nodoListaIngresos * agregarListaPracticas(nodoListaIngresos* lista, pracXingreso dato);
nodoListaIngresos * leerArchivoPracticas(char archivoPracticas[], nodoListaIngresos * lista);
void recorrerArbolYagregarPracticasxIngreso(nodoArbol * arbol, char archivoPracticas[]);
nodoArbol * agregarListaIngresos(nodoArbol * arbol, ingresos dato);
nodoArbol* leerArchivoIngresos(nodoArbol * arbol, char archivoIngresos[]);
nodoPractXingreso * recorrerYmostrarListaPrac(nodoPractXingreso * lista);
nodoListaIngresos * recorrerYmostrarListaIngresos(nodoListaIngresos * lista);
void recorrerYmostrarEstructuraCompuestaInOrder(nodoArbol * arbol);
void recorrerYmostrarEstructuraCompuestaPreOrder(nodoArbol * arbol);
void recorrerYmostrarEstructuraCompuestaPosOrder(nodoArbol * arbol);
void contarPacientes(int *num, nodoArbol*arbol);
nodoListaIngresos * recorrerYmostrarsinPracticas(nodoListaIngresos * lista);
void inOrderSinPracticas(nodoArbol * arbol);

#endif  //PROTOTIPADOS_H_INCLUDED
