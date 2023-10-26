#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

///PROTOTIPADOS
int validarEdad(int edad)
{
    int flag=0;
    if(edad<1 || edad>20)
    {
        flag=1;
    }
    return flag;
}
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
int buscaPaciente(char archivo[], int dniBuscado)
{

    FILE*archi=fopen(archivo, "rb");

    pacientes persona;

    int flag=0;

    if(archi)
    {
        while(fread(&persona, sizeof(pacientes), 1, archi)&& flag!=1)
        {

            if(persona.dni==dniBuscado)
            {

                flag=1;
            }
        }
    }
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO...");
    }
    return flag;
}

void cargaPaciente(char archivo[])
{
    FILE *archi=fopen(archivo, "ab");

    pacientes persona;

    char cont='s';

    if(archi)
    {
        while(cont=='s')
        {
            int flag=0;
            while(!flag)
            {

                printf("ingrese el dni: sin puntos ni espacios...\n");
                scanf("%i", &persona.dni);

                flag=validarDni(persona.dni);

                if(flag==1)
                {

                    printf("EL DNI INGRESADO ES ERRONEO, INTENTE NUEVAMENTE...\n");

                    flag=0;


                }
                else
                {
                    flag=1;
                }
            }


            if(buscaPaciente(archivo, persona.dni)==1)
            {

                printf("El paciente ya existe en el sistema...\n");
                break;
            }
            printf("ingrese nombre del paciente:\n");
            fflush(stdin);
            gets(persona.apeYnombre);

            printf("ingrese edad: \n");
            scanf("%i", &persona.edad);

            if(validarEdad(persona.edad)==1)
            {

                printf("ERROR AL INGRESAR EDAD, INTENTE NUEVAMENTE...\n");

                printf("ingrese edad: \n");
                scanf("%i", &persona.edad);
            }

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
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO...");
    }
    fclose(archi);
}

