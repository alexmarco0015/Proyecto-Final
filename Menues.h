#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void menuADMIN(empleados_laboratorio arregloEmpleados[], int validosEmpleados, const char archivoEmpleados[], char archivoPacientes[], char archivoPractXingresos[], char archivoIngresos[], nodoArbol * arbol, pacientes arregloPacientes[], int validosPacientes);
void menuAdminEmpleados(empleados_laboratorio arreglo[], int validosEmpleados, const char archivoEmpleados[]);
void modificarEmpleadoMenu(int dni, empleados_laboratorio arreglo[], int validosEmpleados, const char archivoEmpleados[]);
void menuAdministrativo(char archivoPacientes[], empleados_laboratorio arregloEmpleados[], int validosEmpleados, nodoArbol * arbol, pacientes arregloPacientes[], int validosPacientes,char archivoIngresos[]);
void menuLaboratorio(char archivoPaciente[], char archivoPractXingresos[], char archivoIngresos[], nodoArbol * arbol);
void menuModPracticasxIngreso(char archivo[],int nroIngreso, nodoArbol * arbol);
void modificarIngresoMenu(int ingreso,char archivo[], nodoArbol*arbol);
void menuPaciente(char archivo[], int dni, nodoArbol*arbol);

#endif // MENUES_H_INCLUDED
