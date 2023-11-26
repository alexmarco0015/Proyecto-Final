#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

int validarEdad(int edad)
{
    int flag=0;
    if(edad<1 || edad>20)
    {
        flag=1;
    }
    return flag;
}
int validarDni(int dniBuscado)
{
    int contador = 0;
    int temp = dniBuscado;

    while (temp > 0)
    {
        temp /= 10;
        contador++;
    }

    if (contador == 8)
    {
        return 0;  // DNI válido
    }
    else
    {
        return 1;  // DNI inválido
    }
}

int buscaPaciente(char archivo[], int dniBuscado)
{

    FILE*archi=fopen(archivo, "rb");

    pacientes persona;

    int flag=0;

    if(archi)
    {
        while(fread(&persona, sizeof(pacientes), 1, archi)&& flag!=1)
        {
            if(persona.dni==dniBuscado)
            {
                flag=1;
            }
            fclose(archi);
        }
    }
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO...");
    }
    return flag;
}

int dniPaciente(int dni)
{
    int flag=0;
            while(!flag)
            {
                printf("ingrese el dni: sin puntos ni espacios...\n");
                fflush(stdin);
                scanf("%i", &dni);

                flag=validarDni(dni);

                if(flag==1)
                {
                    printf("EL DNI INGRESADO ES ERRONEO, INTENTE NUEVAMENTE...\n");

                    flag=0;

                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    flag=1;
                }
            }
            return dni;
}

void nombrePaciente(char nombre[40], int tamanio)
{
    char seguro;
    do{
            printf("Inserte nombre y apellido del Paciente:\n");
            fflush(stdin);
            gets(nombre);
            printf("\nSeguro que desea ese nombre y apellido? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(nombre)>tamanio){//verificamos que no se exceda de la cantidad de caracteres
                printf("se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 40..\n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');
}

int edadPaciente(int edad)
{
    do{
        printf("ingrese edad: \n");
        scanf("%i", &edad);

        if(validarEdad(edad)==1)
        {
            printf("ERROR AL INGRESAR EDAD, INTENTE NUEVAMENTE...\n");

            printf("ingrese edad: \n");
            scanf("%i", &edad);
        }
    }while(validarEdad(edad)==1);

    return edad;
}

void direccionPaciente(char direccion[30], int tamanio)
{
        char seguro;
        do{
            printf("ingrese la direccion del domicilio: \n");
            fflush(stdin);
            gets(direccion);
            printf("\nSeguro que desea esa direccion? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(direccion)>tamanio){//verificamos que no se exceda de la cantidad de caracteres
                printf("se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de %d..\n", tamanio);
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');
}

void telPaciente(char celular[15], int tamanio)
{
    ///falta validar que sean solo numeros lo que el usuario ingrese, de momento puede ingresar hasta letras...
    char seguro;
    do{
        printf("ingrese su numero de telefono/celular: \n");
        fflush(stdin);
        gets(celular);
        printf("\nSeguro que desea ese celular? 's' para si y 'n' para no\n");
        fflush(stdin);
        scanf("%c", &seguro);
        system("cls");
        if(strlen(celular)>tamanio){//verificamos que no se exceda de la cantidad de caracteres
            printf("se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de %d..\n", tamanio);
            seguro='n';
            system("pause");
            system("cls");
        }
    }while(seguro!='s' && seguro!='S');
}

pacientes crearPaciente(pacientes paciente)
{
    int tamaniocel=sizeof(char)*15;
    int tamanioNombre=sizeof(char)*40;
    int tamanioDire=sizeof(char)*30;
    char cel[15];
    char direccion[30];
    char nombre[40];

    nombrePaciente(nombre, tamanioNombre);
    strcpy(paciente.apeYnombre, nombre);

    paciente.edad=edadPaciente(paciente.edad);

    direccionPaciente(direccion, tamanioDire);
    strcpy(paciente.direccion, direccion);

    telPaciente(cel, tamaniocel);
    strcpy(paciente.telefono, cel);

    paciente.eliminado=0; ///es por defecto 0, nunca fue eliminado.

    return paciente;
}

void cargaPaciente(char archivo[])
{
    FILE *archi=fopen(archivo, "ab");

    pacientes persona;

    char cont='s';

    if(archi)
    {
        while(cont=='s')
        {

            persona.dni=dniPaciente(persona.dni);

            if(buscaPaciente(archivo, persona.dni)==1)
            {
                printf("El paciente ya existe en el sistema...\n");
                break;
            }
            persona=crearPaciente(persona);

            fwrite(&persona, sizeof(pacientes), 1, archi);


            printf("¿Desea ingresar otro paciente? (s/n): ");
            fflush(stdin);
            scanf(" %c", &cont);
            system("cls");
        }
    }
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO...");
        system("pause");
        system("cls");
    }
    fclose(archi);
}
nodoArbol*inicArbol(){

    return NULL;
}

nodoArbol*crearNodo(pacientes registro){

    nodoArbol *nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->persona.dni=registro.dni;
    strcpy(nuevo->persona.apeYnombre, registro.apeYnombre);
    nuevo->persona.edad=registro.edad;
    strcpy(nuevo->persona.direccion, registro.direccion);
    strcpy(nuevo->persona.telefono, registro.telefono);


    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;

}
nodoArbol *insertarNodoPaciente(nodoArbol* arbolPaciente, pacientes registro){

    if(arbolPaciente==NULL){

        arbolPaciente=crearNodo(registro);
    }
        if(registro.dni<arbolPaciente->persona.dni){
            arbolPaciente->izq=insertarNodoPaciente(arbolPaciente->izq, registro);
            }else if(registro.dni>arbolPaciente->persona.dni){
                arbolPaciente->der=insertarNodoPaciente(arbolPaciente->der, registro);
        }


return arbolPaciente;
}


nodoArbol*pasarArchiToArbol(nodoArbol *arbol, char archivo[]){

    FILE *archi=fopen(archivo, "rb");

    pacientes registro;

    if(archi){

        while(fread(&registro, sizeof(pacientes), 1, archi)>0){

                arbol=insertarNodoPaciente(arbol, registro);
        }
    }else{
        printf("ERROR AL ABRIR EL ARCHIVO\n");
    }

    fclose(archi);

    return arbol;
}
void mostrarArbol(nodoArbol*arbol){

    if(arbol){

        mostrarArbol(arbol->izq);

        mostrarNodo(arbol->persona);

        mostrarArbol(arbol->der);
    }
}

///CAMBIAR Y ORDENAR POR NOMBRE
void ordenarPacientesPorName(pacientes arreglo[], int tamano) {
    int i, j;
    pacientes temp;

   for (i = 0; i < tamano; i++) {
        for (j = 0; j < tamano - i-1 ; j++) {

            if (strcmp(arreglo[j].apeYnombre, arreglo[j + 1].apeYnombre) > 0) {

                temp=arreglo[j];
                arreglo[j]=arreglo[j + 1];
                arreglo[j + 1]=temp;
            }
        }
    }
}
void mostrarArreglo(pacientes arreglo[], int val) {

    for (int i = 0; i < val; i++) {
        printf("-----------------------------\n");
        printf("Nombre: %s\n", arreglo[i].apeYnombre);
        printf("Edad: %d\n", arreglo[i].edad);
        printf("DNI: %d\n", arreglo[i].dni);
        printf("Direccion: %s\n", arreglo[i].direccion);
        printf("Teléfono: %s\n", arreglo[i].telefono);
        printf("\n");
    }
}
int existeEnElArbol(nodoArbol*raiz, int dni){

    if (raiz == NULL) {
        return 0;
    }

    if (dni == raiz->persona.dni) {
        return 1;
    }

    if (dni < raiz->persona.dni) {
        return buscarPorDNI(raiz->izq, dni);
    }

    return buscarPorDNI(raiz->der, dni);
}
nodoArbol*buscarPorDNI(nodoArbol*raiz, int dni){

    if (raiz == NULL ) {
        return NULL;
    }
    if(raiz->persona.dni == dni){
        return raiz;
    }

    if (dni < raiz->persona.dni) {
        return buscarPorDNI(raiz->izq, dni);
    }

    return buscarPorDNI(raiz->der, dni);
}

void mostrarNodo(pacientes persona){

        printf("\n");
        printf("DNI: %i \n",persona.dni);
        printf("NOMBRE Y APELLIDO: %s \n",persona.apeYnombre);
        printf("EDAD: %i \n",persona.edad);
        printf("DIRECCION: %s \n",persona.direccion);
        printf("TELEFONO: %s \n",persona.telefono);

}
int pasarArchivoToArreglo(char archivo[], int dim, pacientes arreglo[]){

    FILE*archi=fopen(archivo, "rb");

    int i=0;

    pacientes persona;

    if(archi){
        while(fread(&persona, sizeof(pacientes), 1, archi)>0 && i<dim){

            arreglo[i]=persona;

            i++;
        }

        fclose(archi);
    }else{
            printf("ERROR AL ABRIR EL ARCHIVO...\n");
    }
        return i;
}

void modificarPaciente(char archivo[], int dni){

    FILE*archi=fopen(archivo, "ab");

    if(archi){


    }
}
///MODIFICAR PACIENTE BUSCADO-->VER FUNCIONES Y RETORNOS DE BUSCAR POR DNI
///DAR DE BAJA EN ARBOL Y MODIFICAR SU INT ELIMINADO EN EL ARCHIVO.




