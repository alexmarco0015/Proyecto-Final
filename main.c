#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

const char admin[]="administrador";
const char contraAdmin[]="123456";

int main()
{
    cargaPaciente("miarchivo2.bin");
    nodoArbol*arbol = inicArbol();
    arbol=pasarArchiToArbol(arbol, "miarchivo2.bin");
    mostrarArbol(arbol);

    return 0;
}
