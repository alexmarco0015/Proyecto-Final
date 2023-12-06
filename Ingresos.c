#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"
///pasamos todos los registros de tipo ingreso a un arreglo de ingresos
int pasarArchiaArreglo(char archivo[], ingresos arreglo[], int validos)
{
    FILE * buffer=fopen(archivo, "rb");
    int i=0;
    ingresos ingreso;

    if(buffer){

        while(fread(&ingreso, sizeof(ingresos), 1, buffer)>0){
            arreglo[i]=ingreso;
            i++;
        }

        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
    validos=i;
    return validos;
}
///con esta funcion nos encargamos de automatizar la cantidad de ingresos en toda la clinica
int ultimoIngreso(char archivoIngresos[], int dni)
{
    FILE * buffer=fopen(archivoIngresos, "rb");

    int i=0;
    ingresos paciente;

    if(buffer)
    {
        while(fread(&paciente, sizeof(ingresos), 1, buffer)>0)
        {
                i++;
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }
    return i+1;
}
///funcion en la que el usuario se encarga de ingresar la fecha, tal cual se le indica en el printf
void fechaIngreso(char fecha[])
{
    char seguro;
    do{
            printf("Inserte la fecha de ingreso del paciente: (00/00/0000)ejemplo \n");
            fflush(stdin);
            gets(fecha);
            printf("\nSeguro que desea esa fecha? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(fecha)!=10){//verificamos que no se exceda de la cantidad de caracteres
                printf("No ha insertado la fecha correctamente.. Inserte fecha con ceros y barras '/' \n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');

}
///lo mismo que la funcion de arriba pero para la fecha de retiro
void fechaRetiro(char fecha[])
{
    char seguro;
    do{
            printf("Inserte la fecha de retiro de la practica: (00/00/0000)ejemplo \n");
            fflush(stdin);
           gets(fecha);
            printf("\nSeguro que desea esa fecha? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(fecha)!=10){//verificamos que no se exceda de la cantidad de caracteres
                printf("No ha insertado la fecha correctamente.. Inserte fecha con ceros y barras '/' \n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');

}
///preguntamos cual es la matricula del solicitante, lo ingresamos de forma manual porq no sabiamos de que otra forma podría ser
int matriculaSolicitante(int matri)

{
    do{
        printf("ingrese la matricula del solicitante..\n");
        fflush(stdin);
        scanf("%d", &matri);
        printf("\n");

        if(matri<1)
        {
            system("cls");
            printf("Ha ingresado una matricula incorrecta..\n\n");
            system("pause");
            system("cls");
        }
    }while(matri<1);

    return matri;
}
///función para prototipar la carga de un ingreso al archivo..
ingresos crearIngresos(ingresos ingresoPaciente, char archivoIngresos[], int dni)
{
    ingresoPaciente.nroIngreso=ultimoIngreso(archivoIngresos, dni);
    fechaIngreso(ingresoPaciente.fechaIngreso);
    fechaRetiro(ingresoPaciente.fechaRetiro);
    ingresoPaciente.matriculaProfesional=matriculaSolicitante(ingresoPaciente.matriculaProfesional);
    ingresoPaciente.eliminado=0;
    ingresoPaciente.dniPaciente=dni;

    return ingresoPaciente;
}

///cargamos los ingresos en el archivo, para luego ingresarlos a una lista
void cargaIngreso(char archivoIngresos[], char archivoPacientes[], ingresos ingresito)
{
    FILE *buffer=fopen(archivoIngresos, "ab");

    if(buffer){

        fwrite(&ingresito, sizeof(ingresos), 1, buffer);

        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo...\n\n");
        system("pause");
        system("cls");
    }
}
///inicializamos la lista de ingresos en null
nodoListaIngresos * inicListaIngresos()
{
    return NULL;
}
///creamos el nodo de una lista de listas.
nodoListaIngresos * crearNodoListaIngresos(ingresos ingreso){

    nodoListaIngresos *nuevo=(nodoListaIngresos*)malloc(sizeof(nodoListaIngresos));

    strcpy(nuevo->ingreso.fechaIngreso, ingreso.fechaIngreso);
    strcpy(nuevo->ingreso.fechaRetiro, ingreso.fechaRetiro);
    nuevo->ingreso.matriculaProfesional=ingreso.matriculaProfesional;
    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    nuevo->ingreso.eliminado=ingreso.eliminado;
    nuevo->ingreso.dniPaciente=ingreso.dniPaciente;

    nuevo->lista=inicListapracXingresos();

    nuevo->siguiente=NULL;

    return nuevo;
}
///agregamos al principio de la lista los nodos creados en la funcion anterior
nodoListaIngresos* agregarPrincipio(nodoListaIngresos*lista,char archivoIngresos[])
{
        ingresos ingresito=crearIngresos(ingresito,archivoIngresos, ingresito.dniPaciente);

        nodoListaIngresos*nuevoNodo=inicListaIngresos();
        nuevoNodo->ingreso=ingresito;

    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;

    }
    return lista;
}
nodoArbol*cargarIngresoenArbol(nodoArbol*arbol, int dni,FILE*archivoIngresos){

            nodoArbol*aux=buscarPorDNI(arbol, dni);

            if(aux==NULL){
                printf("LA PERSONA BUSCADA NO EXISTE...\n");
                return arbol;
            }
            aux->lista=agregarPrincipio(aux->lista,archivoIngresos);

          return arbol;
}

void pasarListaToArchi(nodoArbol*arbol, char archivoIngresos[]){
        FILE*archi=fopen(archivoIngresos,"wb");
        ingresos ingresito;
        if(archi){

        }
}

void guardarListasDelArbolRecursivo(nodoArbol *arbol, FILE *archivo) {
    if (arbol != NULL) {

        guardarListaEnArchivoRecursivo(arbol->lista, archivo);

        guardarListasDelArbolRecursivo(arbol->izq, archivo);
        guardarListasDelArbolRecursivo(arbol->der, archivo);
    }
}
void guardarListaEnArchivoRecursivo(nodoListaIngresos*lista, FILE*archivo){

    while (lista != NULL) {

        fwrite(&(lista->ingreso), sizeof(ingresos), 1, archivo);

        lista = lista->siguiente;
    }
}

///con esto pasamos todos los registros del archivo a la lista de listas..
nodoListaIngresos * pasarArchiAlista(nodoListaIngresos * lista, char archivoIngresos[], int dni)
{
    ///REVISAR
    ingresos ingreso;
    FILE *archi=fopen(archivoIngresos, "rb");
    if(archi!=NULL)
    {
        while(fread(&ingreso, sizeof(ingreso), 1, archi)>0)
        {
            if(ingreso.eliminado!=0 && dni==ingreso.dniPaciente){///si es distinto de 0 es agregado a la lista, sino no se agrega.
                lista=agregarPrincipio(crearNodoListaIngresos(ingreso), lista);
            }
        }
        fclose(archi);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
    return lista;
}
///mostramos un ingreso en particular, se puede usar en varias funciones
void muestraIngreso(ingresos dato)
{
    printf("\n///////////////////////////////\n");
    printf("Fecha de Ingreso: %s\n", dato.fechaIngreso);
    printf("Fecha de Retiro: %s\n", dato.fechaRetiro);
    printf("Matricula del profesional: %d\n", dato.matriculaProfesional);
    printf("Numero de Ingreso: %d\n", dato.nroIngreso);
    printf("DNI paciente: %d\n", dato.dniPaciente);
    printf("///////////////////////////////\n");
}

///menu de modificaciones de ingresos..
void modificarIngresoMenu(int ingreso,char archivo[], nodoArbol*arbol){
    int opcion=1000;
    char seguro='n';
    do{
        printf("Menu de modificaciones del ingreso\n");
        printf("1-Modificar matricula\n2-Modificar fecha\n3-salir del menu\n");
        printf("Elija una opcion.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';
        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Seguro que desea cambiar la matricula? UNA VEZ ESCOJA SI, NO HAY VUELTA ATRAS.. (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){
                    modificarMatricula(ingreso,archivo);

                }
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 2:
                system("cls");
                printf("Seguro que desea cambiar la fecha? UNA VEZ ESCOJA SI, NO HAY VUELTA ATRAS.. (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){
                modificarFecha(ingreso, archivo);
                }
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 3:
                system("cls");
                    printf("ha seleccionado salir del menu...");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un dato incorrecto o un caracter... Vuelva a introducir un digito correcto..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=3);
}

///el titulo describe todo
void modificarMatricula(int numIngreso, char archivo[]){
        FILE*archi=fopen(archivo, "r+b");
        ingresos ingresito;
        int pos;
        if(archi){
            while(fread(&ingresito, sizeof(ingresos),1,archi)>0){
                if(ingresito.nroIngreso==numIngreso){
                    matriculaSolicitante(ingresito.matriculaProfesional);
                     pos=ftell(archi)-sizeof(ingresos);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&ingresito, sizeof(ingresos), 1, archi);
                    break;
                }
            }
            fclose(archi);
        }else{
            printf("ERROR AL ABRIR EL ARCHIVO...\n");
        }
}

void modificarFecha(int numIngreso, char archivo[]){
    FILE*archi=fopen(archivo, "r+b");
    ingresos ingresito;
        int pos;
    if(archi){
            while(fread(&ingresito, sizeof(ingresos),1,archi)>0){
                if(ingresito.nroIngreso==numIngreso){
                    fechaIngreso(ingresito.fechaIngreso);
                    fechaRetiro(ingresito.fechaRetiro);
                     pos=ftell(archi)-sizeof(ingresos);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&ingresito, sizeof(ingresos), 1, archi);
                }
            }
            fclose(archi);
        }else{
            printf("ERROR AL ABRIR EL ARCHIVO...\n");
        }
}
///cambia el ingreso por 0 o por 1, dependiendo lo que elija el usuario.
void eliminarIngreso(int numIngreso, char archivo[])
{
    FILE*buffer=fopen(archivo, "r+b");
    int pos;
    char cont='s';
    pracXingreso ingresito;
    if(buffer)
    {
        while(fread(&ingresito, sizeof(ingresos),1,buffer)>0){
            if(ingresito.nroIngreso==numIngreso){
                printf("Desea eliminar por completo este ingreso?\n");
                fflush(stdin);
                scanf("%c", &cont);
                if(cont=='s')
                {
                    ingresito.eliminado=1;
                }
                else{
                    ingresito.eliminado=0;
                }
                pos=ftell(buffer)-sizeof(ingresos);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&ingresito, sizeof(ingresos), 1, buffer);
                break;
                }
            }


        fclose(buffer);
    }
    else{
        printf("Error al abrir el archivo..\n");
    }
}
