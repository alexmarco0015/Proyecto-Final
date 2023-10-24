#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

///PROTOTIPADOS

void cargaPaciente(char archivo[]){
        FILE *archi=fopen(archivo, "ab");

        pacientes persona;


        if(archi){
            printf("ingrese nombre del paciente:\n");
            fflush(stdin);
        }
}

