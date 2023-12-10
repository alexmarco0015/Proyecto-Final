#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"
///el usuario inserta el tipo de resultado que ha generado dicha practica
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
        if(strlen(resultado)>100 || strlen(resultado)<10){//verificamos que no se exceda de la cantidad de caracteres ni le falten
            printf("se ha excedido o le ha faltado en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 100 y mas de 10..\n");
            seguro='n';
            system("pause");
            system("cls");
        }
    }while(seguro!='s' && seguro!='S');
}
///nro de practica que se genera automaticamente.
int nroPractica(nodoPractXingreso*lista)
{
  nodoPractXingreso*aux=lista;
   int i=0;

   while(aux){
        aux=aux->siguiente;
        i++;
   }
   return i;
}
///crea la practica con ayuda de las anteriores funciones.
pracXingreso crearPractica(int nroIngreso, int nropract){
    pracXingreso practiquita;
    practiquita.nroIngreso=nroIngreso;
    practiquita.nroPractica=nropract+1;
    crearResultado(practiquita.resultado);
    practiquita.eliminado=0;

    return practiquita;
}

///carga la practicaxIngreso al archivo.
//void cargaPractica(char archivoPractica[], int ingreso)
//{
//    FILE*buffer=fopen(archivoPractica, "ab");
//    char continuar='s';
//    pracXingreso practiquita;
//
//    if(buffer)
//    {
//        while(continuar=='s')
//        {
//            practiquita=crearPractica(archivoPractica, practiquita,ingreso);
//
//            fwrite(&practiquita, sizeof(pracXingreso), 1, buffer);
//
//            printf("Desea continuar cargando practicas? s/n\n");
//            fflush(stdin);
//            scanf("%c", &continuar);
//        }
//        fclose(buffer);
//    }
//    else{
//        system("cls");
//        printf("Error al abrir el archivo..\n\n");
//        system("pause");
//        system("cls");
//    }
//}
///inicializacion de un nodo de tipo lista
nodoPractXingreso * inicListapracXingresos()
{
    return NULL;
}
///creacion de un nodo de tipo lista
nodoPractXingreso * crearNodoListaPracXingresos(pracXingreso ingreso){

    nodoPractXingreso*nuevo=(nodoPractXingreso*)malloc(sizeof(nodoPractXingreso));

    nuevo->ingreso.nroIngreso=ingreso.nroIngreso;
    strcpy(nuevo->ingreso.resultado, ingreso.resultado);
    nuevo->ingreso.nroPractica=ingreso.nroPractica;

    nuevo->siguiente=NULL;

    return nuevo;
}
///un agregar al principio de tipo nodolista de toda la vida
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

nodoArbol*agregarPracticaAlArbol(nodoArbol*arbol, ingresos ingresito,char archivoIngresos[]){

           nodoArbol*aux=inicArbol();
           aux->lista=buscarIngresoArbol(arbol,ingresito.nroIngreso);

            if(aux->lista==NULL){

                arbol=cargarIngresoenArbol(arbol,ingresito.dniPaciente,archivoIngresos);
                aux->lista=buscarIngresoArbol(arbol, ingresito.nroIngreso);

            }

            aux->lista=agregarListaPracticas(aux->lista);

            return arbol;
}


///mostramos una pracXingreso, sirve para nodos, registros y demás
void muestraPracXingreso(pracXingreso dato)
{
    printf("\n******************\n");
    printf("Numero de Practica: %d\n", dato.nroPractica);
    printf("Resultado: \n%s\n", dato.resultado);
    printf("*******************\n");
}
///menú para modificaciones del archivo de pracXingresos.
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
///pedimos el numero de la practica en cuestion, para poder acceder a ella más tarde
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
///baja de una parctXingreso a través de los nodos.
nodoPractXingreso * bajaPracticaxIngreso(int nroPractica, nodoPractXingreso * lista){
 nodoPractXingreso* seg;
   nodoPractXingreso * ante;

   if((lista != NULL) && (lista->ingreso.nroPractica==nroPractica )) {

      nodoPractXingreso * aux = lista;
      lista = lista->siguiente;
      free(aux);
   }else {
      seg = lista;
      while((seg != NULL) && (seg->ingreso.nroPractica!=nroPractica )) {
         ante = seg;
         seg = seg->siguiente;
      }

      if(seg!=NULL) {
         ante->siguiente = seg->siguiente;

         free(seg);

      }
   }
   return lista;

}
void guardarListaPractXingresoEnArchivo(nodoPractXingreso* lista, char archivoPXI[])
 {
    FILE* archi = fopen(archivoPXI, "ab");

    if (archi == NULL) {
        printf("Error al abrir el archivo de prácticas por ingreso.\n");
        return;
    }

    while (lista != NULL) {
        fwrite(&(lista->ingreso), sizeof(pracXingreso), 1, archi);
        lista = lista->siguiente;
    }

    fclose(archi);
}
