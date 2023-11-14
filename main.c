#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"


int main()
{
    cargaPaciente("miarchivo2.bin");
    nodoArbol*arbol = inicArbol();
    arbol=pasarArchiToArbol(arbol, "miarchivo2.bin");
    mostrarArbol(arbol);


    return 0;
}
