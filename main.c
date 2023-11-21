#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"


int main()
{
    cargaPaciente("miarchivo.bin");
    nodoArbol*arbol = inicArbol();
    arbol=pasarArchiToArbol(arbol, "miarchivo.bin");


    return 0;
}
