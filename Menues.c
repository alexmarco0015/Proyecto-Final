#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"


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
                        printf("                    Ha fallado varias veces, volviendo al menu anterior..\n");
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
                printf("\n                    Ha seleccionado salir del Menu..\n                    volviendo al Menu principal\n");
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
        printf("                    5-Eliminar o dar de alta un empleado\n");
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

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("                    Mostrando Pacientes:\n");

              //  recorrerYmostrarEstructuraCompuestaInOrder(arbol);

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                //cargaPaciente(archivoPacientes);

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
    int contador=0;
    int ingresito;
    ingresos persona;
    do{
        printf("                    Menu Laboratorio\n");
        printf("                    1-Cargar Resultados\n");
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
                    flag=buscaPaciente(archivoPaciente, dni);
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
                    persona=crearIngresos(persona, archivoIngresos, dni);

                    //cargaIngreso(archivoIngresos, archivoPaciente, persona);

                    //cargaPractica(archivoPractXingresos, persona.nroIngreso);
                }

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Escriba a continuacion el ingreso que usted desee modificar..\n");
                scanf("%d", &ingresito);
                modificarIngresoMenu(ingresito, archivoIngresos, arbol);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Escriba a continuacion el ingreso que usted desee modificar..\n");
                scanf("%d", &ingresito);
                menuModPracticasxIngreso(archivoPractXingresos, ingresito);
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

