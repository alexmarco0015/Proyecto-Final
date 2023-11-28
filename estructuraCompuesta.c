#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"

nodoPractXingreso * leerArchivoPracticas(char archivoPracticas[])
{
    nodoPractXingreso*nuevo=inicListapracXingresos();

    return nuevo;
}

nodoListaIngresos * altaIngresos(nodoListaIngresos*lista, char archivoPracticas[])
{


    return lista;
}



nodoListaIngresos * leerArchivoIngresos(char archivoIngreso[], char archivoPracticas[])
{
    nodoListaIngresos*nuevo=inicListaIngresos();

    return nuevo;
}



nodoArbol * altaPaciente(nodoArbol * arbol, pacientes persona, char archivoIngresos[], char archivoPracticas[])
{
    nodoArbol * aux=buscarPorDNI(arbol, persona.dni);
    nodoListaIngresos * nuevoNodo=inicListaIngresos();

    if(aux==NULL)
    {
        arbol=insertarNodoPaciente(arbol, persona);
        aux=buscarPorDNI(arbol, persona.dni);
    }


    aux->lista=agregarPrincipio(nuevoNodo,aux->lista);

    return arbol;
}

nodoArbol * LeerArchivo(char archivoPacientes[], char archivoIngresos[], char archivoPracticas[])
{
    nodoArbol * nuevo=inicArbol();
    FILE*buffer=fopen(archivoPacientes, "rb");
    pacientes persona;

    if(buffer)
    {
        while(fread(&persona, sizeof(pacientes), 1, buffer)>0)
        {
            nuevo=altaPaciente(nuevo, persona,archivoIngresos, archivoPracticas);
        }
        fclose(buffer);
    }
    else{
        system("cls");
        printf("Error al abrir el archivo..\n\n");
        system("pause");
        system("cls");
    }

}
