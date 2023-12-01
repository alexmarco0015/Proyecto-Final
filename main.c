#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

const char archivoEmpleados[]="empleados.bin";



int main()
{
    char archivoPractXingresos[]="PracXingresos.bin";
    char archivoPacientes[]="pacientes.bin";
    char archivoIngresos[]="ingresos.bin";
    empleados_laboratorio arregloEmpleados[100];
    int validosEmpleados=0, validosPacientes=0;
    int opcion=-1;
    nodoArbol * arbol=inicArbol();
    pacientes arregloPacientes[100];

   do{
        printf("           Laboratorio Central - Hospital de ninios\n");
        printf("1-Registrarse\n2-Ingresar\n0-Salir del Programa\n");
        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);
        arbol=pasarArchiToArbol(arbol, archivoPacientes);

        switch(opcion)
        {
            case 1:
                system("cls");
                validosEmpleados=plasmarEnArreglo(archivoEmpleados, arregloEmpleados, validosEmpleados);
                crearusuario(archivoEmpleados, arregloEmpleados, validosEmpleados);
                system("cls");
                break;
            case 2:
                system("cls");
                int perfil=ingresoPerfil(arregloEmpleados, validosEmpleados, archivoEmpleados);

                switch(perfil)
                {
                    case 1://perfil de uso administrativo
                        system("cls");
                        validosEmpleados=plasmarEnArreglo(archivoEmpleados, arregloEmpleados, validosEmpleados);
                        menuAdministrativo(archivoPacientes, arregloEmpleados, validosEmpleados, arbol, arregloPacientes, validosPacientes,archivoIngresos);
                        system("cls");
                        break;
                    case 2://perfil de uso prof laboratorio
                        system("cls");
                        menuLaboratorio(archivoPacientes, archivoPractXingresos, archivoIngresos, arbol);
                        system("cls");
                        break;
                    case 3://admin
                        system("cls");
                        validosEmpleados=plasmarEnArreglo(archivoEmpleados, arregloEmpleados, validosEmpleados);
                        menuADMIN(arregloEmpleados, validosEmpleados, archivoEmpleados, archivoPacientes, archivoPractXingresos, archivoIngresos, arbol, arregloPacientes, validosPacientes);
                        system("cls");
                        break;
                    case -1:
                        system("cls");
                        break;
                }
                system("cls");
                break;
            case 0:
                system("cls");
                printf("Ha seleccionado salir del programa..\n NOS VEMOS!!\n");
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
    } while(opcion!=0);

    return 0;
}
