#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED
#endif // PROTOTIPADOS_H_INCLUDED


typedef struct{
    int nroIngreso;
    char fechaIngreso[10];
    char fechaRetiro[10];
    int dniPaciente;
    int matriculaProfesional;
    int eliminado=0;//0 para no eliminado o 1 para eliminado
}ingresos;

typedef struct{
    int nroPractica;
    char nombrePractica[30];
    int eliminado=0;
}practicas;

typedef struct{
    char apeYnombre[40];
    int edad;
    int dni;
    char direccion[30];
    char telefono[15];
    int eliminado=0;
    //faltan punteros
}pacientes;

typedef struct{
    int dni;
    char apeYnombre[40];
    char usuario[20];
    char contrasenia[20];
    char perfil[20];//preguntar si se puede cambiar por enteros;

}empleados_laboratorio;

typedef struct{
    int nroIngreso;
    int nroPractica;
    char resultado[40];
    //faltan punteros;

}pracXingreso;





