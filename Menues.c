#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"
#include "pracXingresos.h"
#include "Menues.h"
#include "ingresos.h"
#include "pacientes.h"

///funciones:
void menuADMIN(empleados_laboratorio arregloEmpleados[], int validosEmpleados, const char archivoEmpleados[], char archivoPacientes[], char archivoPractXingresos[], char archivoIngresos[], nodoArbol * arbol, pacientes arregloPacientes[], int validosPacientes)
{
    int opcion=1000;
   // int personas=0;
    do{

        printf("                    Bienvenido/a MENU ADMIN\n");
        printf("                    1-Entrar a Menu Administrativo\n");
        printf("                    2-Entrar a Menu de Laboratorio\n");
        printf("                    3-Menu control Empleados\n");
        printf("                    0-Salir del Menu\n");
        printf("\nIngrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                menuAdministrativo(archivoPacientes, arregloEmpleados, validosEmpleados, arbol, arregloPacientes, validosPacientes, archivoIngresos);
                system("cls");
                break;
            case 2:
                system("cls");
                menuLaboratorio(archivoPacientes, archivoPractXingresos, archivoIngresos, arbol);

                system("cls");
                break;
            case 3:
                system("cls");
                menuAdminEmpleados(arregloEmpleados, validosEmpleados, archivoEmpleados);

                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del Menu actual..\n volviendo al menu anterior!!\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=0);
}
void menuAdminEmpleados(empleados_laboratorio arreglo[], int validosEmpleados, const char archivoEmpleados[])
{
    int opcion=1000;
    int dni=0;
    int verificado;
    int contador=0;

    do{

        printf("                    Bienvenido al MENU de control de empleados\n");
        printf("                    1-Ver empleados\n");
        printf("                    2-Registrar un empleado\n");
        printf("                    3-Modificar un empleado\n");
        printf("                    4-Buscar un empleado en particular\n");
        printf("                    0-Salir\n");
        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                validosEmpleados=cargarArregloUsuarios(archivoEmpleados, arreglo);
                mostrarArregloEmpleados(arreglo, validosEmpleados);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                crearusuario(archivoEmpleados, arreglo, validosEmpleados);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                do{
                    if(contador>4){
                        printf("Ha fallado varias veces, volviendo al menu anterior..\n");
                        break;
                    }

                    printf("                    Empleados del laboratorio:\n");
                    mostrarArregloEmpleados(arreglo, validosEmpleados);
                    printf("\nDe todos los empleados, seleccione el dni del empleado a modificar..\n");
                    fflush(stdin);
                    scanf("%d", &dni);
                    verificado=verificarEmpleado(dni, arreglo, validosEmpleados);
                    if(verificado==0){
                        system("cls");
                        printf("El dni del usuario que usted busca no se encuentra en el sistema, por favor, seleccione correctamente...\n");
                        system("pause");
                        system("cls");
                        contador++;
                    }
                }while(verificado==0);
                system("cls");
                if(contador<4){
                    modificarEmpleadoMenu(dni, arreglo, validosEmpleados, archivoEmpleados);
                }
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Ingrese el dni del empleado a buscar..\n");
                fflush(stdin);
                scanf("%d", &dni);
                chequearEmpleadoAdmin(arreglo, validosEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del Menu..\nvolviendo al Menu principal\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=0);
}

void modificarEmpleadoMenu(int dni, empleados_laboratorio arreglo[], int validosEmpleados, const char archivoEmpleados[])
{
    int opcion=1000;
    int verificado;
    char seguro='n';
    int dniNuevo;

    do{
        printf("                    Menu de modificaciones del empleado\n");
        printf("                    1-Modificar dni\n");
        printf("                    2-Modificar nombre y apellido\n");
        printf("                    3-Modoficar nombre de usuario\n");
        printf("                    4-Modificar contrasenia\n");
        printf("                    5-Modificar el perfil del usuario\n");
        printf("                    6-Eliminar o dar de alta un empleado\n");
        printf("                    0-salir del menu\n");
        printf("Elija una opcion.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';
        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Seguro que desea cambiar el dni? UNA VEZ ESCOJA SI NO HAY VUELTA ATRAS.. (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro=='s'){
                    do{
                        printf("Ingrese el dniNuevo:\n");
                        dniNuevo=dniPaciente(dniNuevo);
                        verificado=verificarEmpleado(dniNuevo, arreglo, validosEmpleados);
                        if(verificado!=0){
                            printf("Ha ingresado un dni que ya existe en el sistema, NO SE PUEDEN REPETIR DNI.\n");
                        }
                    }while(verificado!=0);
                    modDni(archivoEmpleados, dni, dniNuevo);
                }
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 2:
                system("cls");
                modApeYnombre(archivoEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                modUsername(archivoEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                modContrasenia(archivoEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                modTipoPerfil(archivoEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                darDeBajaEmpleado(archivoEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("Volviendo al menu anterior...\n");
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

void menuAdministrativo(char archivoPacientes[], empleados_laboratorio arregloEmpleados[], int validosEmpleados, nodoArbol * arbol, pacientes arregloPacientes[], int validosPacientes,char archivoIngresos[])
{
    int dni=0;
    int opcion=1000;
    int verificacion=-1;
    int contador=0;
    do{
        contador=0;
        printf("                    Bienvenido al MENU Administrativo\n");
        printf("                    1-Lista de Pacientes\n");
        printf("                    2-Registrar Pacientes\n");
        printf("                    3-Buscar Paciente y modificar\n");
        printf("                    4-Chequear Un Empleado\n");
        printf("                    5-Ver lista de ingresos general\n");
        printf("                    0-Salir del Menu\n");
        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        validosPacientes=0;
        recorrer_arbol_y_almacenar(arbol, arregloPacientes, &validosPacientes);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("                    Mostrando Pacientes:\n");
                ordenarPacientesPorName(arregloPacientes, validosPacientes);
                mostrarArreglo(arregloPacientes, validosPacientes);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                pacientes persona=cargaPaciente(arbol);
                if(persona.dni!=-1)
                {
                    arbol=insertarNodoPaciente(arbol, persona);
                    printf("            \n\nPaciente agregado con exito!!\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                do{
                    contador++;
                    if(contador>3)
                    {
                        printf("Ha ingresado mal el dni 3 veces seguidas, volviendo..\n");
                        break;
                    }
                    printf("Ingrese el dni del paciente a buscar..\n");
                    fflush(stdin);
                    scanf("%d", &dni);
                    verificacion=existeEnElArbol(arbol, dni);
                    if(verificacion!=1)
                    {
                        system("cls");
                        printf("Ha seleccionado un dni que no se encuentra.. vuelva a ingresar\n\n");
                        system("pause");
                    }
                }while(verificacion!=1);

                if(contador<4){
                    system("cls");
                    menuPaciente(archivoPacientes, dni, arbol);
                }
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Ingrese el dni del empleado a buscar..\n");
                fflush(stdin);
                scanf("%d", &dni);
                chequearEmpleadoAdministrativo(arregloEmpleados, validosEmpleados, dni);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                inOrderSinPracticas(arbol);
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del Menu..\n volviendo al Menu principal\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion!=0);
}

void menuLaboratorio(char archivoPaciente[], char archivoPractXingresos[], char archivoIngresos[], nodoArbol * arbol)
{
    int opcion=-1;
    int dni=-1;
    int flag=-1;
    int contador2=0;
    int contador=0;
    char seguro='n';
    int ingresito=0;
    int numeroIngreso=0;
    int practiquita=0;
    do{
        printf("                    Menu Laboratorio\n");
        printf("                    1-Cargar Practicas\n");
        printf("                    2-Modificar un ingreso\n");
        printf("                    3-Modificar una PracticaxIngreso\n");
        printf("                    4-Eliminar un ingreso\n");
        printf("                    0-Salir\n");
        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                do{
                    if(contador==3)
                    {
                        printf("Ha ingresado incorrectamente el dni 3 veces, volviendo al menu..\n");
                        break;
                    }
                    printf("Ingrese el dni del paciente:\n");
                    fflush(stdin);
                    scanf("%d", &dni);
                    flag=existeEnElArbol(arbol, dni);
                    if(flag==0){
                        system("cls");
                        printf("Ingreso un dni incorrecto, vuelva a ingresar..\n\n");
                        system("pause");
                        system("cls");
                        contador++;
                    }
                }while(flag!=1);

                if(contador!=3)
                {
                    printf("El ingreso que busca, existe?\n");
                    fflush(stdin);
                    scanf("%c", &seguro);
                    if(seguro=='s')
                    {
                        do{
                            if(contador2==3)
                            {
                                printf("Demasiados errores al buscar ingreso..\n");
                                break;
                            }
                            printf("Ingrese el ingreso que usted está buscando..\n");
                            fflush(stdin);
                            scanf("%d", &ingresito);
                            nodoArbol*auxarbol=buscarPorDNI(arbol, dni);
                            nodoListaIngresos*aux=buscarIngreso(auxarbol->lista, ingresito);
                            contador2++;
                            if(aux==NULL)
                            {
                                flag=0;
                                printf("Ingreso un ingreso que no existe..\n");
                            }
                            else{
                                flag=1;
                            }
                        }while(contador2!=3 && flag==0);
                        if(contador2!=3)
                        {
                            arbol=agregarPracticaAlArbol(arbol, ingresito);
                        }
                    }
                    else{
                        arbol=cargarIngresoenArbol(arbol, dni);
                        ultIngreso(arbol, &numeroIngreso);
                        arbol=agregarPracticaAlArbol(arbol, numeroIngreso);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Escriba a continuacion el ingreso que usted desee modificar..\n");
                ingresito=0;
                scanf("%d", &ingresito);
                modificarIngresoMenu(ingresito, archivoIngresos, arbol);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                do{
                    printf("Escriba a continuacion la ingreso de la practica que usted desee modificar..\n");
                    scanf("%d", &ingresito);
                    flag=existeIngresoArbol(arbol, ingresito);
                    if(flag==1)
                    {
                        nodoListaIngresos* aux=buscarIngresoArbol(arbol, ingresito);
                        printf("Ahora ingrese la practica\n");
                        fflush(stdin);
                        scanf("%d", &practiquita);
                        flag=estaLaPract(practiquita, aux->lista);
                        if(flag==1)
                        {
                            menuModPracticasxIngreso(archivoPractXingresos, practiquita, arbol, ingresito);
                        }
                        else{
                            printf("No existe esa practica..\n");
                            seguro='s';
                        }
                    }
                    else{
                        printf("No existe ese ingreso, desea probar otra vez?\n");
                        fflush(stdin);
                        scanf("%c", &seguro);
                    }
                }while(seguro!='n');
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Inserte el ingreso a ser eliminado..\n");
                fflush(stdin);
                scanf("%d", &ingresito);
                eliminarIngreso(ingresito, archivoIngresos);
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nHa seleccionado salir del Menu actual..\n volviendo al menu anterior!!\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                printf("Ha seleccionado un caracter o un numero incorrecto, por favor, vuelva a elegir correctamente..\n");
                system("pause");
                system("cls");
                break;
        }
    }while (opcion!=0);
}

///menú para modificaciones del archivo de pracXingresos.
void menuModPracticasxIngreso(char archivo[],int numeroPrac, nodoArbol * arbol, int nroIngreso)
{
    int opcion=1000;
    char seguro='n';
    nodoListaIngresos*aux;
    do{
        printf("Menu de modificaciones de una practica\n");
        printf("1-Modificar resultado\n2-Modificar numero de ingreso\n0-salir del menu\n");
        printf("Elija una opcion.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';
        switch(opcion)
        {
            case 1:
                system("cls");
                aux=buscarIngresoArbol(arbol, nroIngreso);
                modificarResultadoPractica(nroIngreso, aux->lista);
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 2:
                system("cls");
                aux=buscarIngresoArbol(arbol, nroIngreso);
                modificarNrodePracticaxIngreso(numeroPrac, aux->lista);
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 0:
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
///menu de modificaciones de ingresos..
void modificarIngresoMenu(int ingreso,char archivo[], nodoArbol*arbol)
{
    int opcion=1000;
    char seguro='n';
    nodoListaIngresos *aux;
    do{
        printf("Menu de modificaciones del ingreso\n");
        printf("1-Modificar matricula\n2-Modificar fecha ingreso\n3-Modificar Fecha Retiro\n0-salir del menu\n");
        printf("Elija una opcion.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';
        switch(opcion)
        {
            case 1:
                system("cls");
                    aux=buscarIngresoArbol(arbol, ingreso);
                    modificarMatricula(ingreso, aux);
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 2:
                system("cls");
                aux=buscarIngresoArbol(arbol, ingreso);
                modificarFechaIngreso(ingreso, aux);
                system("pause");
                system("cls");
                opcion=0;
                break;
            case 3:
                system("cls");
                aux=buscarIngresoArbol(arbol, ingreso);
                modificarFechaRetiro(ingreso, aux);
                system("pause");
                system("cls");
                break;
            case 0:
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
///menu de modificaciones pacientes..
void menuPaciente(char archivo[], int dni, nodoArbol*arbol){
    ///PEDIR DNI CUANDO SE LLAME A ESTE MENU
    int opcion=1000;
    int verificado;
    char seguro='n';
    char nuevoName[40];
    char nuevoTelefono[40];
    char nuevaDireccion[40];
    int dniNuevo=0;
    int edadNuevo=0;
    do{
        printf("                    Menu de modificaciones del paciente\n");
        printf("                    1-Modificar dni\n");
        printf("                    2-Modificar nombre y apellido\n");
        printf("                    3-Modoficar edad\n");
        printf("                    4-Modificar direccion\n");
        printf("                    5-Telefono\n");
        printf("                    0-salir del menu\n");

        printf("datos del paciente: \n");
        nodoArbol * aux=buscarPorDNI(arbol, dni);
        mostrarNodo(aux->persona);
        printf("Elija una opcion.. \n");
        fflush(stdin);
        scanf("%d", &opcion);
        seguro='n';

        switch(opcion){
            case 1:
                system("cls");
                   arbol=modificarDniArbol(dniNuevo,dni,arbol);
                    printf("Volviendo al menu...");
                system("pause");
                system("cls");
            break;
            case 2:
                system("cls");
                arbol=modificarNombreYApellidoArbol(arbol,dni,nuevoName);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                arbol=modificarEdadArbol(arbol,dni,edadNuevo);
                system("pause");
                system("cls");
            break;
            case 4:
                system("cls");
                arbol=modificarDireccionArbol(arbol,dni,nuevaDireccion);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                arbol=modificarTelefonoArbol(arbol,dni,nuevoTelefono);
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                printf("Volviendo al menu anterior...\n");
                system("pause");
                system("cls");
                break;
            default :
                system("cls");
                printf("HA INGRESADO UNA OPCION INCORRECTA...\n");
                system("pause");
                system("cls");
                break;
            }
    }while(seguro!='n');
}
