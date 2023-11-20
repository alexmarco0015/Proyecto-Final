#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

const char archivoEmpleados[]="empleados.bin";
int main()
{
    empleados_laboratorio arregloEmpleados[100];
    int validosEmpleados=0;
    int opcion=1000;
//    cargaPaciente("miarchivo2.bin");
//    nodoArbol*arbol = inicArbol();
//    arbol=pasarArchiToArbol(arbol, "miarchivo2.bin");
//    mostrarArbol(arbol);
//
//    int opcion=1000;


   do{
        printf("           Laboratorio Central - Hospital de ninios\n");
        printf("1-Registrarse\n2-Ingresar\n0-Salir del Programa\n");
        printf("Ingrese la opcion a elegir.. ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
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
                        menuAdministrativo();
                        system("cls");
                        break;
                    case 2://perfil de uso prof laboratorio
                        system("cls");
                        menuLaboratorio();
                        system("cls");
                        break;
                    case 3://administrativo
                        system("cls");
                        menuADMIN(arregloEmpleados, validosEmpleados, archivoEmpleados);
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
            case 4:
                mostrarArregloEmpleados(arregloEmpleados, validosEmpleados);
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
