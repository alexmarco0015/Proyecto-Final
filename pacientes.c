#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

///PROTOTIPADOS
int validarDni(char archivo[], int dniBuscado){
    int flag=0;
    if(dniBuscado>10000000 && dniBuscado<99999999){

        flag=1;
    }
    return flag;
}
int buscaPaciente(char archivo[], int dniBuscado){

    FILE*archi=fopen(archivo, "rb");

    pacientes persona;

    int flag=0;

        if(archi){
            while(fread(&persona, sizeof(pacientes), 1, archi)&& flag!=1){

                if(persona.dni==dniBuscado){

                    flag=1;
                }
            }
        }else{
            printf("ERROR AL ABRIR EL ARCHIVO...");
        }
        return flag;
}

void cargaPaciente(char archivo[]){
        FILE *archi=fopen(archivo, "ab");

        pacientes persona;

        char cont='s';

        if(archi){
                while(cont=='s'){

            printf("ingrese el dni: \n");
            scanf("%i", &persona.dni);

            if(validarDni(archivo, persona.dni)==1){

                printf("EL DNI INGRESADO ES ERRONEO, INTENTE NUEVAMENTE...\n");

                  printf("ingrese el dni: \n");
                  scanf("%i", &persona.dni);
            }
            if(buscaPaciente(archivo, persona.dni)==1){

                printf("El paciente ya existe en el sistema...\n");
                break;
            }
            printf("ingrese nombre del paciente:\n");
            fflush(stdin);
            gets(persona.apeYnombre);
            printf("ingrese edad: \n");
            scanf("%i", &persona.edad);
            printf("ingrese direccion del domicilio: \n");
            fflush(stdin);
            gets(persona.direccion);
            printf("ingrese numero de telefono/celular: \n");
            fflush(stdin);
            gets(persona.telefono);

            fwrite(&persona, sizeof(pacientes), 1, archi);


            printf("¿Desea ingresar otro paciente? (s/n): ");
            fflush(stdin);
            scanf(" %c", &cont);

                }

        }
        else{
            printf("ERROR AL ABRIR EL ARCHIVO...");
        }
        fclose(archi);
}

