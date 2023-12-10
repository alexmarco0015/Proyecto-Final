#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"

///valida la edad del paciente, devuelve 1 si es valido, 0 si es invalido
int validarEdad(int edad)
{
    int flag=0;
    if(edad<1 || edad>20)
    {
        flag=1;
    }
    return flag;
}
///valida el dni de un paciente, devuelve 0 si es valido, 1 si es invalido
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
///busca un paciente por el archivo, a través del dni, si este se encuentra, devuelve 1, sino 0
int buscaPaciente(char archivo[], int dniBuscado)
{

    FILE*archi=fopen(archivo, "rb");

    pacientes persona;

    int flag=0;

    if(archi)
    {
        while(fread(&persona, sizeof(pacientes), 1, archi)>0 && flag!=1)
        {
            if(persona.dni==dniBuscado)
            {
                flag=1;

            }

        }
            fclose(archi);
    }
    else
    {
        printf("                    ERROR AL ABRIR EL ARCHIVO...");
    }
    return flag;
}
///con este hacemos un scanf del dni del paciente. Si el dni no es valido, le vuelve a insistir
int dniPaciente(int dni)
{
    int flag=0;
            while(!flag)
            {
                printf("  ingrese el dni: sin puntos ni espacios...\n");
                fflush(stdin);
                scanf("  %i", &dni);

                flag=validarDni(dni);

                if(flag==1)
                {
                    printf("  EL DNI INGRESADO ES ERRONEO, INTENTE NUEVAMENTE...\n");

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
///escaneamos el nombre del paciente, para evitar comprobaciones complicadas, preguntamos si está seguro de insertar x nombre
void nombrePaciente(char nombre[40], int tamanio)
{
    char seguro;
    do{
            printf("  Inserte nombre y apellido del Paciente:\n");
            fflush(stdin);
            gets(nombre);
            printf("\n  Seguro que desea ese nombre y apellido? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("  %c", &seguro);
            system("  cls");
            if(strlen(nombre)>tamanio){//verificamos que no se exceda de la cantidad de caracteres
                printf("  se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 40..\n");
                seguro='n';
                system("  pause");
                system("  cls");
            }
        }while(seguro!='s' && seguro!='S');
}
///preguntamos la edad del paciente, si se excede de la edad de "niño" le decimos que es un error..
int edadPaciente(int edad)
{
    do{
        printf("  ingrese edad: \n");
        scanf("  %i", &edad);
        system("cls");
        if(validarEdad(edad)==1)
        {
            printf("  ERROR AL INGRESAR EDAD, INTENTE NUEVAMENTE...\n");

            printf("  ingrese edad: \n");
            scanf("  %i", &edad);
            system("cls");
        }
    }while(validarEdad(edad)==1);

    return edad;
}
///le preguntamos la direccion del paciente, para evitar comprobaciones complejas, le preguntamos si está seguro, confiamos en el usuario
void direccionPaciente(char direccion[30], int tamanio)
{
        char seguro;
        do{
            printf("  ingrese la direccion del domicilio: \n");
            fflush(stdin);
            gets(direccion);
            printf("\n  Seguro que desea esa direccion? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("  %c", &seguro);
            system("cls");
            if(strlen(direccion)>tamanio){//verificamos que no se exceda de la cantidad de caracteres
                printf("  se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de %d..\n", tamanio);
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');
}
///preguntamos su numero telefonico, confiamos en que el usuario solo ingrese numeros y no letras.
void telPaciente(char celular[15], int tamanio)
{

    char seguro;
    do{
        printf("  ingrese su numero de telefono del padre/tutor: \n");
        fflush(stdin);
        gets(celular);
        printf("\n  Seguro que desea ese celular? 's' para si y 'n' para no\n");
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
///funcion que acompañada de todas las anteriores, creamos un paciente para luego insertarlo en el archivo
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

    return paciente;
}
///carga una persona, si el dni ya existia, le dice q es imposible registrar a ese usuario..

pacientes cargaPaciente(nodoArbol*arbol)
{
    pacientes persona;

    char cont='s';

        while(cont=='s')
        {

            persona.dni=dniPaciente(persona.dni);

            if(buscarPorDNI(arbol,persona.dni))
            {
                printf("El paciente ya existe en el sistema...\n");
                break;
            }
            persona=crearPaciente(persona);
            persona.eliminado=0;


            printf("¿Desea ingresar otro paciente? (s/n): ");
            fflush(stdin);
            scanf(" %c", &cont);
            system("cls");
        }

        return persona;

}
///inicializamos un arbol
nodoArbol*inicArbol(){

    return NULL;
}
///creamos un nodo de tipo arbol, con ayuda de los registros PACIENTE
nodoArbol*crearNodo(pacientes registro){

    nodoArbol *nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->persona.dni=registro.dni;
    strcpy(nuevo->persona.apeYnombre, registro.apeYnombre);
    nuevo->persona.edad=registro.edad;
    strcpy(nuevo->persona.direccion, registro.direccion);
    strcpy(nuevo->persona.telefono, registro.telefono);
    nuevo->persona.eliminado=registro.eliminado;
    nuevo->lista=NULL;


    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;

}
///insertamos el nodo previamente creado en el arbol
nodoArbol *insertarNodoPaciente(nodoArbol* arbolPaciente, pacientes persona){

    if(arbolPaciente==NULL){

        arbolPaciente=crearNodo(persona);
    }
        if(persona.dni<arbolPaciente->persona.dni){

            arbolPaciente->izq=insertarNodoPaciente(arbolPaciente->izq, persona);

            }else if(persona.dni>arbolPaciente->persona.dni){

                arbolPaciente->der=insertarNodoPaciente(arbolPaciente->der, persona);
        }


return arbolPaciente;
}
///leemos el archivo y este lo pasa al arbol, inserta dato a dato.
nodoArbol*pasarArchiToArbol(nodoArbol *arbol, char archivo[]){

    FILE *archi=fopen(archivo, "rb");

    pacientes registro;

    if(archi){

        while(fread(&registro, sizeof(pacientes), 1, archi)>0){

                arbol=insertarNodoPaciente(arbol,registro);
        }
    }else{
        printf("ERROR AL ABRIR EL ARCHIVO\n");
    }

    fclose(archi);

    return arbol;
}

void pasarArbolAlArchivo(nodoArbol*arbol, char archivo[]){

        FILE*archi=fopen(archivo,"wb");

        if(archi){
           escribirEnElArchi(archi, arbol);
           fclose(archi);
        }else {
        printf("Error al abrir el archivo para escritura.\n");
    }

}

void escribirEnElArchi(FILE*archi, nodoArbol*arbol){
    if(arbol){
        fwrite(&arbol->persona,sizeof(pacientes),1,archi);
        escribirEnElArchi(archi,arbol->izq);
        escribirEnElArchi(archi,arbol->der);
    }


}
///funcion que permite mostrar el arbol de pacientes.
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
///funcion que muestra el arreglo de tipo pacientes.
void mostrarArreglo(pacientes arreglo[], int val) {

    for (int i = 0; i < val; i++) {
            if(arreglo[i].eliminado==0){

        printf("                 -------------------------------------\n");
        printf("                    Nombre: %s\n", arreglo[i].apeYnombre);
        printf("                    Edad: %d\n", arreglo[i].edad);
        printf("                    DNI: %d\n", arreglo[i].dni);
        printf("                    Direccion: %s\n", arreglo[i].direccion);
        printf("                    Teléfono: %s\n", arreglo[i].telefono);
        printf("\n");
            }
    }
}
///corrobora si un nodo existe en el arbol a través del DNI, si existe devuelve 1, sino 0
int existeEnElArbol(nodoArbol*raiz, int dni){

    if (raiz == NULL) {
        return 0;
    }

    if (dni == raiz->persona.dni) {
        return 1;
    }

    if (dni < raiz->persona.dni) {
        return existeEnElArbol(raiz->izq, dni);
    }

    return existeEnElArbol(raiz->der, dni);
}
///busca por el arbol a través del dni, si existe, devuelve el nodo del arbol donde se encuentre el dni
nodoArbol*buscarPorDNI(nodoArbol*raiz, int dni){
 if (raiz == NULL) {
        return NULL; // Árbol vacío o final de la rama
    }

    if (dni == raiz->persona.dni) {
        return raiz;
    }

    if (dni < raiz->persona.dni) {
        return buscarPorDNI(raiz->izq, dni);
    } else {
        return buscarPorDNI(raiz->der, dni);
    }
}
///con esta funcion podemos mostrar un nodo del arbol o de un arreglo o lista
void mostrarNodo(pacientes persona){

        printf("\n");
        printf("                    DNI: %i \n",persona.dni);
        printf("                    NOMBRE Y APELLIDO: %s \n",persona.apeYnombre);
        printf("                    EDAD: %i \n",persona.edad);
        printf("                    DIRECCION: %s \n",persona.direccion);
        printf("                    TELEFONO: %s \n",persona.telefono);
        printf("                    eliminado: %d\n",persona.eliminado);

}
///pasamos el archivo de pacientes a un arreglo de pacientes
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
            printf("                    ERROR AL ABRIR EL ARCHIVO...\n");
    }
        return i;
}
///menu de modificaciones pacientes..
void menuPaciente(char archivo[], int dni, nodoArbol*arbol){
    ///PEDIR DNI CUANDO SE LLAME A ESTE MENU
    int opcion=1000;
    int verificado;
    char seguro='n';
    int dniNuevo;
    do{
        printf("                    Menu de modificaciones del paciente\n");
        printf("                    1-Modificar dni\n");
        printf("                    2-Modificar nombre y apellido\n");
        printf("                    3-Modoficar edad\n");
        printf("                    4-Modificar direccion\n");
        printf("                    5-Telefono\n");
        printf("                    0-salir del menu\n");
        printf("                    Elija una opcion.. \n");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';

        switch(opcion){

        case 1:
                system("cls");
                printf("Seguro que desea cambiar el dni? NO PODRA VOLVER ATRAS... (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){

                        do{
                        dniNuevo=dniPaciente(dniNuevo);
                        verificado=existeEnElArbol(arbol,dniNuevo);
                        if(verificado!=0){
                            printf("Ha ingresado un dni que ya existe en el sistema, NO SE PUEDEN REPETIR DNI.\n");
                        }
                    }while(verificado!=0);

                    modificarPacienteDni(archivo,dni, dniNuevo);
                }
                system("pause");
                system("cls");

                    opcion=0;
            break;
        case 2:
                system("cls");
                printf("Seguro que desea cambiar el nombre? NO PODRA VOLVER ATRAS... (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){

                    modificarNombreYApellido(archivo, dni);

                    }

                system("pause");
                system("cls");

                    opcion=0;

            break;
        case 3:
            system("cls");
                printf("Seguro que desea cambiar la edad? NO PODRA VOLVER ATRAS... (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){

                   modificarEdad(archivo,dni);

                    }

                system("pause");
                system("cls");

                    opcion=0;

            break;
        case 4:
             system("cls");
                printf("Seguro que desea cambiar la direccion? NO PODRA VOLVER ATRAS... (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){

                   modificarDireccion(archivo, dni);

                    }

                system("pause");
                system("cls");

                    opcion=0;

            break;
        case 5:
            system("cls");
                printf("Seguro que desea cambiar el telefono? NO PODRA VOLVER ATRAS... (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){

                   modificarTelefono(archivo,dni);

                    }

                system("pause");
                system("cls");

                    opcion=0;

            break;
        case 0:

                    printf("Ha seleccionado salir...\n");
            break;
        default :
                    printf("HA INGRESADO UNA OPCION INCORRECTA...\n");
            break;


            }
            }while(seguro!='n');

}
///funcion que a través del dni del paciente, se le modifica su telefono celular
void modificarTelefono(char archivo[], int dni)
{
    ///revisar puede ingresar letras
FILE*archi=fopen(archivo,"r+b");
    int tamanio=sizeof(char)*40;
    pacientes persona;
    int pos;
    if(archi){
        while(fread(&persona, sizeof(pacientes), 1,archi)>0){
            if(persona.dni==dni){
                telPaciente(persona.telefono, tamanio);
                pos=ftell(archi)-sizeof(pacientes);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&persona, sizeof(pacientes), 1, archi);
            }
        }
        fclose(archi);
    }else{
                    printf("ERROR AL ABRIR EL ARCHIVO...");
    }

}
///Funcion que a través del dni del paciente se modifica la direccion del paciente.
void modificarDireccion(char archivo[], int dni)
{
    FILE*archi=fopen(archivo,"r+b");
    int tamanio=sizeof(char)*40;
    pacientes persona;
    int pos;
    if(archi){
        while(fread(&persona, sizeof(pacientes),1,archi)>0){
            if(persona.dni==dni){
                direccionPaciente(persona.direccion, tamanio);
                  pos=ftell(archi)-sizeof(pacientes);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&persona, sizeof(pacientes), 1, archi);
            }
        }
                fclose(archi);
    }else{
                    printf("ERROR AL ABRIR EL ARCHIVO...");
    }
}
///funcion que a través del dni del paciente se modifica en el archivo la edad del paciente.
void modificarEdad(char archivo[], int dni)
{
    FILE*archi=fopen(archivo,"r+b");
    pacientes persona;
    int pos;
    if(archi){
        while(fread(&persona, sizeof(pacientes),1,archi)>0){
                if(persona.dni==dni){
                    int edad=edadPaciente(edad);
                    persona.edad=edad;
                    pos=ftell(archi)-sizeof(pacientes);
                    fseek(archi, pos, SEEK_SET);
                    fwrite(&persona, sizeof(pacientes), 1, archi);
                }
        }
                fclose(archi);
    }else{
                    printf("ERROR AL ABRIR EL ARCHIVO...");
    }
}
///modifica en el archivo el nombre y apellido del paciente con ayuda del dni
void modificarNombreYApellido(char archivo[], int dni)
{
    FILE *archi=fopen(archivo, "r+b");
    pacientes persona;
    int pos;
        int tamanio=sizeof(char)*40;

    if(archi){
            while(fread(&persona, sizeof(pacientes), 1, archi)>0){
                    if(persona.dni==dni){
                        printf("Este es el nombre y apellido actual: %s", persona.apeYnombre);
                        printf("Pasamos a modificar su nombre...\n");
                        system("pause");
                        system("cls");
                        nombrePaciente(persona.apeYnombre, tamanio);
                        pos=ftell(archi)-sizeof(pacientes);
                        fseek(archi, pos, SEEK_SET);
                        fwrite(&persona, sizeof(pacientes), 1, archi);
            }
    }
            fclose(archi);

    }
    else{
            printf("ERROR AL ABRIR EL ARCHIVO...");
    }



}
///con esta funcion modificaremos el dni del paciente en cuestion, le pasamos 2 dni, el que usamos para encontrarlo y el
///nuevo que será el que lo cambie
void modificarPacienteDni(char archivo[], int dni, int dniNuevo)
{

    FILE*archi=fopen(archivo, "r+b");

        pacientes persona;
        int pos;

    if(archi){

            while(fread(&persona, sizeof(pacientes), 1, archi)>0){

                if(persona.dni==dni){

                printf("Pasando a ingresar un DNI nuevo: \n");
                system("pause");
                system("cls");

                persona.dni=dniNuevo;
                pos=ftell(archi)-sizeof(pacientes);
                fseek(archi, pos, SEEK_SET);
                fwrite(&persona, sizeof(pacientes), 1, archi);
                break;

                }
            }
            fclose( archi);

    }
                 else{
        system("cls");
        printf("\n ERROR AL ABRIR EL ARCHIVO\n");
        system("pause");
        system("cls");
    }
}

void bajaPaciente(char archivo[], nodoArbol*arbol, int dni){
///ESTA FUNCION MODIFICA EL INT ELIMINADO EN EL ARCHIVO.
   FILE*archi=fopen(archivo, "rb");
   pacientes persona;
   nodoArbol*buscado=buscarPorDNI(arbol,dni);
   if(buscado==NULL){
                printf("la persona que desea buscar no existe...");
               }
   if(archi){
               if(buscado->lista!=NULL){

                printf("no puede borrar a este paciente porque posee un ingreso!!!!\n");
                system("pause");
                system("cls");

               }else if(buscado->lista==NULL){

                        while(fread(&persona,sizeof(archi), 1,archi)>0){

                            if(persona.dni==dni){

                                persona.eliminado=1;
                                printf("Paciente eliminado... (s/n) \n");
                                mostrarNodo(persona);
                                    system("pause");
                                    system("cls");
                            }
                        }
                        eliminarNodo(buscado,dni);

                    }

        fclose(archi);

   }else{
    printf("ERROR AL ABRIR EL ARCHIVO...\n");
        system("pause");
        system("cls");
   }
}

///funciones de arboles de listas:


//nodoArbol * altaPaciente(nodoArbol * arbol, pacientes persona, ingresos ingreso, pracXingreso practica)
//{
//    nodoArbol * aux=buscarPorDNI(arbol, persona.dni);
//    nodoListaIngresos * nuevoNodo=inicListaIngresos();
//
//    if(aux==NULL)
//    {
//        arbol=insertarNodoPaciente(arbol, persona);
//        aux=buscarPorDNI(arbol, persona.dni);
//    }
//
//    nuevoNodo=crearNodoListaIngresos(ingreso);
//    aux->lista=agregarPrincipio(nuevoNodo,aux->lista);
//
//    return arbol;
//}
nodoArbol*modificarDniArbol(int dniNuevo, int dniActual, nodoArbol*arbol){

        nodoArbol*nodoBuscar=buscarPorDNI(arbol, dniActual);

        if(nodoBuscar==NULL){
            printf("EL DNI INGRESADO NO SE ENCUENTRA EN EL SISTEMA!!!\n");
            return arbol;
        }
        printf("         MODIFICAR...\n");
        dniNuevo=dniPaciente(dniNuevo);
        nodoBuscar->persona.dni=dniNuevo;
         printf("Datos modificados con éxito en el arbol.\n");



         if(nodoBuscar->lista){
                nodoListaIngresos*seg=nodoBuscar->lista;
            while(seg){
                if(seg->ingreso.dniPaciente==dniActual){
                    seg->ingreso.dniPaciente=dniNuevo;
                }
                seg=seg->siguiente;
            }
            nodoBuscar->lista=seg;

         printf("Datos modificados con exito en la lista.\n");
         }

        return arbol;
}
nodoArbol* modificarNombreYApellidoArbol(nodoArbol*arbol, int dni, char nuevoNombre[])
{
     nodoArbol*nodoBuscar=buscarPorDNI(arbol, dni);
        int tamanioNombre=sizeof(char)*40;

        if(nodoBuscar==NULL){
            printf("LA PERSONA NO SE ENCUENTRA EN EL SISTEMA!!!\n");
            return arbol;
        }
        nombrePaciente(nuevoNombre,tamanioNombre);

        strcpy(nodoBuscar->persona.apeYnombre, nuevoNombre);


         printf("Datos modificados con exito en el arbol.\n");

return arbol;

}

nodoArbol* modificarTelefonoArbol(nodoArbol*arbol, int dni, char nuevoTelefono[])
{
     nodoArbol*nodoBuscar=buscarPorDNI(arbol, dni);
        int tamanioTelefono=sizeof(char)*40;

        if(nodoBuscar==NULL){
            printf("LA PERSONA  NO SE ENCUENTRA EN EL SISTEMA!!!\n");
            return arbol;
        }
        telPaciente(nuevoTelefono,tamanioTelefono);

        strcpy(nodoBuscar->persona.telefono,nuevoTelefono);


         printf("Datos modificados con exito en el arbol.\n");

return arbol;

}
nodoArbol* modificarEdadArbol(nodoArbol*arbol, int dni, int nuevaEdad)
{
     nodoArbol*nodoBuscar=buscarPorDNI(arbol, dni);

        if(nodoBuscar==NULL){
            printf("LA PERSONA  NO SE ENCUENTRA EN EL SISTEMA!!!\n");
            return arbol;
        }

        printf("         MODIFICAR...\n");

        nuevaEdad=edadPaciente(nuevaEdad);

        nodoBuscar->persona.edad=nuevaEdad;


         printf("Datos modificados con exito en el arbol.\n");

return arbol;

}
nodoArbol* buscarDniMenor(nodoArbol* arbol)
{
    while (arbol->izq != NULL) {
        arbol = arbol->izq;
    }
    return arbol;
}
nodoArbol* eliminarNodo(nodoArbol* arbol, int dni)
{
    ///ESTA FUNCION LIBERA EL NODO EN EL ARBOL
    if (arbol == NULL) {
        return arbol;
    }


    if (dni < arbol->persona.dni) {
        arbol->izq = eliminarNodo(arbol->izq, dni);
    } else if (dni > arbol->persona.dni) {
        arbol->der = eliminarNodo(arbol->der, dni);
    } else {

        /// nodo sin hijos o 1 solo hijo
        if (arbol->izq == NULL) {
            nodoArbol* temp = arbol->der;
            free(arbol);
            return temp;
        } else if (arbol->der == NULL) {
            nodoArbol* temp = arbol->izq;
            free(arbol);
            return temp;
        }

        ///nodo con dos hijos
        nodoArbol* temp = buscarDniMenor(arbol->der);
        arbol->persona = temp->persona;
        arbol->der = eliminarNodo(arbol->der, temp->persona.dni);
    }

    return arbol;
}
void cargarArbolAArchivo(nodoArbol* arbol, char archivoIngresos[]) {
    FILE* archi = fopen(archivoIngresos, "ab");

    if (archi != NULL) {
        cargarNodosDelArbolRecursivo(arbol, archi);
        fclose(archi);
    } else {
        printf("Error al abrir el archivo %s\n", archivoIngresos);
    }
}

void cargarNodosDelArbolRecursivo(nodoArbol* arbol, FILE* archivo) {
    if (arbol != NULL) {
        fwrite(&(arbol->persona), sizeof(pacientes), 1, archivo);

        cargarNodosDelArbolRecursivo(arbol->izq, archivo);
        cargarNodosDelArbolRecursivo(arbol->der, archivo);
    }
}

