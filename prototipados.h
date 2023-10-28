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

void cargaPaciente(char archivo[]);
int buscaPaciente(char archivo[], int dniBuscado);
int validarDni(int dniBuscado);
int validarEdad(int edad);

