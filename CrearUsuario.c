#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define digitosDNI 999
#include "prototipados.h"
#include "pacientes.h"

///sacamos el nombre de usuario como puntero a través de un arreglo de tipo string para luego usarlo en el crear usuario
void nombreUsuario(char usuario[], int tamanio)
{
    char seguro;
    do{
            printf("Inserte nombre usuario:\n");
            fflush(stdin);
            gets(usuario);
            printf("\nSeguro que desea ese nombre de usuario? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(usuario)>tamanio && strlen(usuario)<4){
                system("cls");
                printf("se ha excedido en la cantidad de caracteres que puede ocupar, por favor, ingrese menos de 20 y mas de 4..\n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');

}

///hacemos lo mismo que hicimos en el anterior pero con la tontraseña:
void contraseniaUsuario(char contrasenia[], int tamanio)
{
    char contra[20];
    do{
            printf("Ahora ingrese su contrasenia:\n");
            fflush(stdin);
            gets(contrasenia);
            system("cls");
            printf("Ingrese de nuevo su contrasenia para continuar..\n");
            fflush(stdin);
            gets(contra);
            system("cls");
            if(strcmp(contra, contrasenia)!=0){
                system("cls");
                printf("La contrasenia que usted ha ingresado no es la misma...\n");
                system("pause");
                system("cls");
            }
            if(strlen(contra)>tamanio && strlen(contrasenia)>tamanio){
                system("cls");
                printf("La contrasenia ha excedido la cantidad de caracteres..\n");
                system("pause");
                system("cls");
            }

        }while(strcmp(contra, contrasenia)!=0 || strlen(contra)>tamanio);

}

///recopilamos el nombre y apellido como puntero a traves de la funcion
void nombreYapellidoUsuario(char nombre[], int tamanio)
{
    char seguro;
    do{
            printf("Inserte nombre y apellido:\n");
            fflush(stdin);
            gets(nombre);
            printf("\nSeguro que desea ese nombre y apellido? 's' para si y 'n' para no\n");
            fflush(stdin);
            scanf("%c", &seguro);
            system("cls");
            if(strlen(nombre)>tamanio && strlen(nombre)<7){//verificamos que no se exceda de la cantidad de caracteres
                system("cls");
                printf("se ha excedido en la cantidad de caracteres que puede ocupar o no ha puesto su nombre completo, por favor, ingrese menos de 40..\n");
                seguro='n';
                system("pause");
                system("cls");
            }
        }while(seguro!='s' && seguro!='S');
}
///que elija entre las 2 posibles opciones, no puede elegir otra que no sea esas 2
int crearPerfil(int perfil)
{
    do{
            printf("                    Es de tipo 1:ADMINISTRATIVO, 2:LABORATORIO\n");
            fflush(stdin);
            scanf("%d", &perfil);
            if(perfil!=1 && perfil!=2){
                system("cls");
                printf("Ha ingresado un dato incorrecto, intentelo nuevamente.\n");
                system("pause");
                system("cls");
            }
        }while(perfil!=1 && perfil!=2);

    return perfil;
}
///modularizando todo anteriormente, plasmamos todo en esta función, luego retornando el "usuario completamente registrado"
empleados_laboratorio crearCuenta(empleados_laboratorio usuario)
{
    int tamanio=sizeof(char)*20;
    int tamanioNombre=sizeof(char)*40;
    char contrasenia[20];
    char nickName[20];
    char nombre[40];

    nombreUsuario(nickName, tamanio);
    strcpy(usuario.usuario, nickName);
    system("cls");
    contraseniaUsuario(contrasenia, tamanio);
    strcpy(usuario.contrasenia, contrasenia);
    system("cls");
    nombreYapellidoUsuario(nombre, tamanioNombre);
    strcpy(usuario.apeYnombre, nombre);
    system("cls");
    usuario.perfil=crearPerfil(usuario.perfil);
    usuario.eliminado=0;
    return usuario;
}
///funcion que crea el usuario y si no existía antes de crear el perfil. Si existe no permite crearte un perfil, si no, lo crea e inserta en el archivo
void crearusuario(const char archivo[], empleados_laboratorio arreglo[], int validos)
{
    FILE *buffer=fopen(archivo, "ab");
    empleados_laboratorio usuario;
    int verificacion;


    if(buffer){
        usuario.dni=dniPaciente(usuario.dni);
        verificacion=verificarEmpleado(usuario.dni, arreglo, validos);
        if(verificacion==0){
            usuario=crearCuenta(usuario);
            fwrite(&usuario, sizeof(empleados_laboratorio), 1, buffer);
            printf("\nCuenta creada con EXITO!!\n");
            system("pause");
            system("cls");
        }
        else{
            system("cls");
            printf("\nLa cuenta ya esta registrada en el programa..\n");
            system("pause");
            system("cls");
        }

        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
}
///ahora a verificar si existe el empleado ya en el sitema.

int plasmarEnArreglo(const char archivo[], empleados_laboratorio arreglo[], int validos)
{
    int i=validos;
    FILE *buffer=fopen(archivo, "rb");
    empleados_laboratorio usuario;

    if(buffer){
        while(fread(&usuario, sizeof(empleados_laboratorio), 1, buffer)>0){
            arreglo[i]=usuario;
            i++;
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo...\n");
        system("pause");
        system("cls");
    }


   return i;
}

void mostrarArregloEmpleados(empleados_laboratorio arreglo[], int validos)
{
    int i=0;

    while(i<validos){
        printf("                    -----------------------------------\n");
        printf("                    nombre de usuario: %s\n", arreglo[i].usuario);
        printf("                    contrasenia: %s\n", arreglo[i].contrasenia);
        if(arreglo[i].perfil==1){
            printf("                    perfil: administrativo\n");
        }
        if(arreglo[i].perfil==2)
        {
            printf("                    perfil: laboratorio\n");
        }
        printf("                    nombre y apellido: %s\n", arreglo[i].apeYnombre);
        printf("                    dni: %d\n", arreglo[i].dni);
        i++;
    }



}
///funcion que devuelve 0 si no existe el empleado en el sistema, 1 si existe. La verificacion se hace a traves del documento, puede modificarse luego
int verificarEmpleado(int dniEmpleado, empleados_laboratorio arreglo[], int validos)
{
   int flag=0, i=0;

    while(flag!=1 && i<validos){
        if(dniEmpleado==arreglo[i].dni){
            flag=1;
            break;
        }
        i++;
    }

    return flag;
}

///FUNCIONES DE MODIFICACION:

void modDni(const char archivo[], int dni, int dniNuevo)
{
    FILE *buffer=fopen(archivo, "r+b");
    empleados_laboratorio persona;
    int pos;

    if (buffer){

        while(fread(&persona, sizeof(empleados_laboratorio), 1, buffer)>0){

            if(dni==persona.dni){
                printf("Pasando a ingresar un dni nuevo: \n");
                system("pause");
                system("cls");
                persona.dni=dniNuevo;
                pos=ftell(buffer)-sizeof(empleados_laboratorio);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&persona, sizeof(empleados_laboratorio), 1, buffer);
                break;
            }
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("\nError al ingresar al archivo...\n");
        system("pause");
        system("cls");
    }
}

void modApeYnombre(const char archivo[], int dni)
{
    FILE * buffer=fopen(archivo, "r+b");
    empleados_laboratorio persona;
    int pos;
    int tamanio=sizeof(char)*40;

    if(buffer){

        while(fread(&persona, sizeof(empleados_laboratorio), 1, buffer)>0){
            if(persona.dni==dni){
                printf("                    Este es el nombre y apellido actual: %s\n", persona.apeYnombre);
                printf("                    Pasamos a modificar su nombre...\n\n");
                system("pause");
                system("cls");
                nombreYapellidoUsuario(persona.apeYnombre, tamanio);
                pos=ftell(buffer)-sizeof(empleados_laboratorio);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&persona, sizeof(empleados_laboratorio), 1, buffer);
                break;
            }
        }

        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
}

void modUsername(const char archivo[], int dni)
{
    FILE * buffer=fopen(archivo, "r+b");
    empleados_laboratorio persona;
    int pos;
    int tamanio=sizeof(char)*20;

    if(buffer){

        while(fread(&persona, sizeof(empleados_laboratorio), 1, buffer)>0){
            if(persona.dni==dni){
                printf("                    Este es el nombre de usuario actual: %s\n", persona.usuario);
                printf("                    Pasamos a modificar su nombre de usuario..\n\n");
                system("pause");
                system("cls");
                nombreUsuario(persona.usuario, tamanio);
                pos=ftell(buffer)-sizeof(empleados_laboratorio);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&persona, sizeof(empleados_laboratorio), 1, buffer);
                break;
            }
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
}

void modContrasenia(const char archivo[], int dni)
{
    FILE * buffer=fopen(archivo, "r+b");
    empleados_laboratorio persona;
    int pos;
    int tamanio=sizeof(char)*20;

    if(buffer){

        while(fread(&persona, sizeof(empleados_laboratorio), 1, buffer)>0){
            if(persona.dni==dni){
                printf("                    Este es la contrasenia actual: %s\n", persona.contrasenia);
                printf("                    Pasamos a modificar su contrasenia..\n\n");
                system("pause");
                system("cls");
                contraseniaUsuario(persona.contrasenia, tamanio);
                pos=ftell(buffer)-sizeof(empleados_laboratorio);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&persona, sizeof(empleados_laboratorio), 1, buffer);
                break;
            }
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
}

void modTipoPerfil(const char archivo[], int dni)
{
    FILE * buffer=fopen(archivo, "r+b");
    empleados_laboratorio persona;
    int pos;

    if(buffer){

        while(fread(&persona, sizeof(empleados_laboratorio), 1, buffer)>0){
            if(persona.dni==dni){
                printf("Este es el perfil actual: %d  (1:ADMIN 2:Laboratorio 3:Administrativo\n)\n", persona.perfil);
                printf("Pasamos a modificar su perfil..\n\n");
                system("pause");
                system("cls");
                persona.perfil=crearPerfil(persona.perfil);
                pos=ftell(buffer)-sizeof(empleados_laboratorio);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&persona, sizeof(empleados_laboratorio), 1, buffer);
                break;
            }
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo..\n");
        system("pause");
        system("cls");
    }
}

void darDeBajaEmpleado(const char archivoEmpleados[], int dni)
{
    FILE*buffer=fopen(archivoEmpleados, "r+b");

    empleados_laboratorio persona;
    int pos;

    if(buffer)
    {
        while(fread(&persona, sizeof(empleados_laboratorio), 1, buffer)>0){
            if(persona.dni==dni){
                printf("Este es el estado actual %d  (1:Eliminado 0:No eliminado\n)", persona.eliminado);
                printf("Pasamos a cambiar su estado \n");

                do{
                    printf("Desea que sea eliminado? 1=eliminado | 0=No eliminado\n");
                    fflush(stdin);
                    scanf("%d", &persona.eliminado);

                    if(persona.eliminado!=1 && persona.eliminado!=0)
                    {
                        printf("Ha ingresado un dato incorrecto, es 1 o 0, vuelva a ingresar..\n");
                    }
                }while(persona.eliminado!=1 && persona.eliminado!=0);
                pos=ftell(buffer)-sizeof(empleados_laboratorio);
                fseek(buffer, pos, SEEK_SET);
                fwrite(&persona, sizeof(empleados_laboratorio), 1, buffer);
                break;
            }
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("                    Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }
}

void chequearEmpleadoAdmin(empleados_laboratorio arregloEmpleados[], int validosEmpleados, int dni)
{
    int i=0;
    while(i<validosEmpleados)
    {
        if(arregloEmpleados[i].dni==dni)
        {
            printf("       ---------------------------------------\n");
            printf("       nombre de usuario: %s\n", arregloEmpleados[i].usuario);
            printf("       contrasenia: %s\n", arregloEmpleados[i].contrasenia);
            if(arregloEmpleados[i].perfil==1){
            printf("                    perfil: administrativo\n");
            }
            if(arregloEmpleados[i].perfil==2)
            {
                printf("                    perfil: laboratorio\n");
            }
            printf("       nombre y apellido: %s\n", arregloEmpleados[i].apeYnombre);
            printf("       dni: %d\n", arregloEmpleados[i].dni);
            if(arregloEmpleados[i].eliminado==0)
            {
                printf("       Estado de servicio:  EN SERVICIO\n");
            }
            else{
                printf("       Estado de servicio: FUERA DE SERVICIO\n");
            }
            printf("       ------------------------------------------\n");
            break;
        }
        i++;
    }
    if(i>validosEmpleados)
    {
        printf("El dni que usted ingresó no se encuentra en el sistema..\n");
    }
}

void chequearEmpleadoAdministrativo(empleados_laboratorio arregloEmpleados[], int validosEmpleados, int dni)
{
    int i=0;
    while(i<validosEmpleados)
    {
        if(arregloEmpleados[i].dni==dni)
        {
            printf("       ---------------------------------------\n");
            printf("       nombre de usuario: %s\n", arregloEmpleados[i].usuario);
            printf("       contrasenia: %s\n", arregloEmpleados[i].contrasenia);
            if(arregloEmpleados[i].perfil==1){
            printf("                    perfil: administrativo\n");
            }
            if(arregloEmpleados[i].perfil==2)
            {
                printf("                    perfil: laboratorio\n");
            }
            printf("       contrasenia: ");
            for (int j = 0; j < sizeof(arregloEmpleados[i].contrasenia) - 1 && arregloEmpleados[i].contrasenia[j] != '\0'; j++) {
            printf("*");
            }
            printf("\ndni: %d\n", arregloEmpleados[i].dni);
            if(arregloEmpleados[i].eliminado==0)
            {
                printf("       Estado de servicio:  EN SERVICIO\n");
            }
            else{
                printf("       Estado de servicio: FUERA DE SERVICIO\n");
            }
            printf("       ------------------------------------------\n");
            break;
        }
        i++;
    }
    if(i>validosEmpleados)
    {
        printf("       El dni que usted ingresó no se encuentra en el sistema..\n");
    }
}

void ordenarEmpleadosPorName(empleados_laboratorio arreglo[], int tamano) {
    int i, j;
    empleados_laboratorio temp;

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
