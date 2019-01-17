#include <iostream>
#include "../../Biblioteca/bizi-estaciones.h"
#include <cstring>
int main () {                                 //NUMERO DE USOS NO COINCIDEN POR POCO
    char usos[MAX_NOMBRE];
    char informe[MAX_NOMBRE];
    char nombreFicheroEstaciones[MAX_NOMBRE] = "../../../Datos/Bizi/estaciones.csv"; //Ruta con el fichero estaciones
    char nombreFicheroUsos[MAX_NOMBRE] = "../../../Datos/Bizi/";
    char nombreFicheroInforme[MAX_NOMBRE] = "../../../Datos/Bizi/";
    Estacion estaciones [NUM_ESTACIONES];
    //-----------INTERACCION CON USUARIO-------------------------------
    cout << "Escriba el nombre de un fichero de usos del sistema Bizi: ";
    cin >> usos;
    cout << endl << "Escriba el nombre del fichero de informe: ";
    cin >>informe;
    
    //-----------------------------------------------------------------
    strcat(nombreFicheroUsos,usos); //Ruta con el fichero de usos
    strcat(nombreFicheroInforme, informe); //Ruta con el fichero de informe
    //
    if (leerEstaciones(nombreFicheroEstaciones,estaciones)) {
        //
        if (contarUsosEstaciones(nombreFicheroUsos,estaciones)) {
            //
            ordenarPorUso(estaciones);
            //
           if(!escribirInforme(nombreFicheroInforme,estaciones)) {
               cerr << "No se ha podido abrir o escribir  el fichero " << nombreFicheroInforme<< endl;
           }
        }
        else{cerr << "No se ha podido abrir o leer el fichero " << nombreFicheroUsos << endl;}
    }
    else {cerr << "No se ha podido abrir o leer el fichero " << nombreFicheroEstaciones << endl;}
    return 0;
    
}
