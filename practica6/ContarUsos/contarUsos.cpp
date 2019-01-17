/*********************************************************************************
 * Programación 1. Práctica 6
 * Autor: Diego Marco Beisty, 755232
 * Fichero: contarUsos.cpp
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de interfaz «bizi-usos.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "../../Biblioteca/bizi-usos.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
/*Pre:
 *Post:
 */
int main () {
    char nombre[MAX_NOMBRE];
    char ruta [MAX_LINEA] = "../../../Datos/Bizi/";                 
    int traslados = 0;
    int usosCirculares = 0;
    cout << "Escriba el nombre de un fichero de usos del sistema Bizi: ";
    cin >>nombre;
    strcat (ruta,nombre); //concateno el nombre del fichero a su ruta;
    if (contarUsos(ruta,traslados,usosCirculares)){
           //caso en que ha conseguido abrir y leer del fichero
           int totalUsos = traslados + usosCirculares;
           cout <<"Numero de usos como traslado:  " <<setw(8) << traslados << endl;     
           cout <<"Numero de usos circulares:     " <<setw(8) << usosCirculares << endl;
           cout <<"Numero total de usos:          " <<setw(8) << totalUsos <<endl;
    }
    else {cerr <<"No se ha podido abrir o leer el fichero " << nombre << endl;}
    return 0;
}