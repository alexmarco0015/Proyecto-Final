#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED


typedef struct{
    int nroIngreso;
    int nroPractica;
    char resultado[100];
    int eliminado;

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

typedef struct nodoArbol{
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


///prototipados de librería "crearUsuario":
void nombreUsuario(char usuario[], int tamanio);
void contraseniaUsuario(char contrasenia[], int tamanio);
void nombreYapellidoUsuario(char nombre[], int tamanio);
int crearPerfil(int perfil);
empleados_laboratorio crearCuenta(empleados_laboratorio usuario);
void crearusuario(const char archivo[], empleados_laboratorio arreglo[], int validos);
int plasmarEnArreglo(const char archivo[], empleados_laboratorio arreglo[], int validos);
void mostrarArregloEmpleados(empleados_laboratorio arreglo[], int validos);
int verificarEmpleado(int dniEmpleado, empleados_laboratorio arreglo[], int validos);
void modDni(const char archivo[], int dni, int dniNuevo);
void modApeYnombre(const char archivo[], int dni);
void modUsername(const char archivo[], int dni);
void modContrasenia(const char archivo[], int dni);
void modTipoPerfil(const char archivo[], int dni);
void darDeBajaEmpleado(const char archivoEmpleados[], int dni);
void chequearEmpleadoAdmin(empleados_laboratorio arregloEmpleados[], int validosEmpleados, int dni);
void chequearEmpleadoAdministrativo(empleados_laboratorio arregloEmpleados[], int validosEmpleados, int dni);
void ordenarEmpleadosPorName(empleados_laboratorio arreglo[], int tamano);

///prototipados librería ingresoUsuario
int cargarArregloUsuarios(const char archivo[], empleados_laboratorio arreglo[]);
int analizaPerfil(char usuario[], char contrasenia[], empleados_laboratorio arreglo[], int validos);
void ingresoUsuario(char usuario[], char contrasenia[]);
int analizasiEsAdmin(char usuario[], char contrasenia[], int perfil);
int ingresoPerfil(empleados_laboratorio arreglo[], int validos,const char archivo[]);

///prototipados estructuraCompuesta.c:
nodoListaIngresos * buscarIngreso(nodoListaIngresos * lista, int ingreso);
nodoListaIngresos * agregarListaPracticas(nodoListaIngresos* lista);
nodoListaIngresos*buscarIngresoArbol(nodoArbol*arbol, int nroIngreso);
void mostrarListaIngresos(nodoListaIngresos*lista);
nodoPractXingreso * recorrerYmostrarListaPrac(nodoPractXingreso * lista);
nodoListaIngresos * recorrerYmostrarListaIngresos(nodoListaIngresos * lista);
nodoListaIngresos * recorrerYmostrarsinPracticas(nodoListaIngresos * lista);
void inOrderSinPracticas(nodoArbol * arbol);
int  existeIngreso(nodoListaIngresos * lista, int ingreso);
int existeIngresoArbol(nodoArbol*arbol, int nroIngreso);


///Prototipados practicas:

void leer_arch_practicas(practicas arreglo[], int * validos);
void alta_practica (practicas arreglo[], int* validos,char nombre_practica[]);
void modificar_nombre_practica(practicas arreglo[], int* validos,char nombre_practica[]);
void baja_practica(practicas arreglo[], int* validos,char nombre_practica[]);
void sobreescribir_arch_practicas(practicas arreglo[], int * validos);

#endif  //PROTOTIPADOS_H_INCLUDED
