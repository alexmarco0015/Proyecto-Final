#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

void crearResultado(char resultado[])
{
    char seguro;
    do{
        printf("Inserte el resultado de la practica:\n");
        fflush(stdin);
        gets(resultado);
        printf("\nEse sera el resultado final, esta seguro?\n");
        fflush(stdin);
        scanf("%c", &seguro);
        system("cls");
        if(strlen(resultado)>40 || strlen(resultado)<10){//verificamos que no se exceda de la cantidad de caracteres ni le falten
            printf("se ha excedido o le ha faltado en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 40 y mas de 10..\n");
            seguro='n';
            system("pause");
            system("cls");
        }
    }while(seguro!='s' && seguro!='S');
}

int nroPractica(char archivoPracticas[], int numeroIngreso)
{
    int i=0;
    FILE*buffer=fopen(archivoPracticas, "rb");
    pracXingreso aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(pracXingreso), 1, buffer)>0)
        {
            if(numeroIngreso == aux.nroIngreso){
                i++;
            }
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

pracXingreso crearPractica(char archivoPracticas[], pracXingreso pXi, int numeroIngreso)
{
    pXi.nroIngreso=numeroIngreso;
    pXi.nroPractica=nroPractica(archivoPracticas, numeroIngreso);
    crearResultado(pXi.resultado);

    return pXi;
}

void cargaPractica(char archivoPractica[], int ingreso)
{
    FILE*buffer=fopen(archivoPractica, "ab");
    char continuar='s';
    pracXingreso practiquita;

    if(buffer)
    {
        while(continuar=='s')
        {
            practiquita=crearPractica(archivoPractica, practiquita,ingreso);

            fwrite(&practiquita, sizeof(pracXingreso), 1, buffer);

            printf("Desea continuar cargando practicas? s/n\n");
            fflush(stdin);
            scanf("%c", &continuar);
        }


        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }


}

nodoPractXingreso * inicListapracXingresos()
{
    return NULL;
}

nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso){

    nodoPractXingreso*nuevo=(nodoPractXingreso*)malloc(sizeof(nodoPractXingreso));

    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    strcpy(nuevo->ingreso.resultado, ingreso.resultado);
    nuevo->ingreso.nroPractica=ingreso.nroPractica;

    nuevo->siguiente=NULL;

    return nuevo;
}

nodoPractXingreso* agregarPrincipioPracXingresos(nodoPractXingreso * nuevoNodo, nodoPractXingreso * lista)
{

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

nodoPractXingreso * pasarArchiAlistaPracXingresos(nodoPractXingreso * lista, char archivoPracXingresos[], int ingreso)
{
    pracXingreso practica;
    FILE *archi=fopen(archivoPracXingresos, "rb");
    if(archi!=NULL)
    {
        while(fread(&practica, sizeof(pracXingreso), 1, archi)>0)
        {
            if(practica.nroIngreso==ingreso)
            {
                lista=agregarPrincipioPracXingresos(crearNodoListaPracXingresos(practica), lista);
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

void muestraPracXingreso(pracXingreso dato)
{
    printf("\n******************\n");
    printf("Numero de Practica: %d\n", dato.nroPractica);
    printf("Resultado: \n%s\n", dato.resultado);
    printf("*******************\n");
}
void menuModPracticasxIngreso(char archivo[],int nroIngreso){
  int opcion=1000;
    char seguro='n';
    do{
        printf("Menu de modificaciones de una practica\n");
        printf("1-Modificar resultado\n2-Modificar numero de ingreso\n3-salir del menu\n");
        printf("Elija una opcion.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';
        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Seguro que desea cambiar el resultado? UNA VEZ ESCOJA SI, NO HAY VUELTA ATRAS.. (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){
                    modificarResultadoPractica(archivo,nroIngreso);
                }
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 2:
                system("cls");
                printf("Seguro que desea cambiar el numero de practica? UNA VEZ ESCOJA SI, NO HAY VUELTA ATRAS.. (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){
                modificarNrodePracticaxIngreso(archivo,nroIngreso);
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
    }while(opcion!=0);
}
void modificarResultadoPractica(char archivo[], int nroIngreso){
    FILE*archi=fopen(archivo,"r+b");
    int pos;
    pracXingreso practica;
    if(archi){
        while(fread(&practica, sizeof(pracXingreso),1,archi)>0){
            if(practica.nroIngreso==nroIngreso){

                crearResultado(practica.resultado);
                    pos=ftell(archi)-sizeof(pracXingreso);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&practica, sizeof(pracXingreso), 1, archi);
            }
        }
        fclose(archi);
    }else{
        system("cls");
        printf("ERROR AL ABRIR EL ARCHIVO...\n");
        system("pause");
        system("cls");
    }


}
int pedirNum(){
    int num;
    printf("por  favor, ingrese el numero de la practica\n");
    fflush(stdin);
    scanf("%i", &num);
    system("pause");
    system("cls");

    return num;
}
void modificarNrodePracticaxIngreso(char archivo[], int nroIngreso){
        FILE*archi=fopen(archivo, "r+b");
        int pos;
        pracXingreso practica;
        if(archi){
            while(fread(&practica,sizeof(pracXingreso),1,archi)>0){
                if(practica.nroIngreso==nroIngreso){

                    practica.nroPractica=pedirNum();

                     pos=ftell(archi)-sizeof(pracXingreso);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&practica, sizeof(pracXingreso), 1, archi);
                }
            }
            fclose( archi);

        }else{
            system("cls");
                printf("ERROR AL ABRIR EL ARCHIVO");
            system("pause");
            system("cls");
        }
}
///FALTA BAJA DE PRACTICA POR INGRESOS, NO TIENE INT ELIMINADO.
