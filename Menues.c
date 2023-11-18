#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipados.h"


///funciones:
void menuADMIN()
{
    int opcion=1000;
    do{

        printf("Bienvenido/a USUARIO ADMIN\n");
        printf("1-Registrar paciente\n2-Registrar orden\n3-Ver resultados\n4-Buscar pacientes\n5-Cargar resultados LAB\n6-Buscar Pacientes\n7-Eliminar Cuentas\n8-Ver historial Pacientes\n0-Salir");

        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
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
    }while(opcion!=0);
}

void menuAdministrativo()
{
    int opcion=1000;
    do{

        printf("¡Bienvenido al MENU Administrativo!\n");
        printf("1-Registrar Pacientes\n2-Registrar Orden\n3-Ver Resultados\n-4-Buscar Paciente\n0-Salir\n");

        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                ///aca seria el registro o crear cuenta, ya tenemos esa funcion, solo falta conectar todo.
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                ///aca tenemos que solicitar el ingreso, de eso me voy a encargar en otra librería
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
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

void menuLaboratorio()
{
    int opcion;
    do{
        printf("  Menu Laboratorio\n");
        printf("1-Cargar Resultados\n2-Buscar pacientes\n3-\n0-Salir\n");

        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
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

