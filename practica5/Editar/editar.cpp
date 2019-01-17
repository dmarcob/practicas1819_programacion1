#include <fstream>
#include <iostream>
#include "../../Biblioteca/nombres.h"
#include "../../Biblioteca/nombres.cpp"
using namespace std;

/*Pre: <<origen>> y <<destino>>, son dos cadenas de caracteres que indican el nombre de los ficheros desde donde
 *     se quiere leer y escribir
 *Post: En el fichero <<destino>> se han escrito todos los nombres leidos de <<origen>> en la forma (mayuscula){minuscula}[coma]
 */
void abrir ( char origen[],  char destino[]) {
    rutaCompleta ( origen, destino); //FUNCION DE BIBLIOTECA nombres
    ifstream orig (origen);
    if (orig.is_open()) {
        //caso en que he conseguido establecer el flujo de entrada
        ofstream dest (destino);
        if (dest.is_open()) {
            //caso en que he conseguido establecer el flujo de salida
            editar (orig, dest); //FUNCION DE BIBLIOTECA nombres
            dest.close();
        }
        else {
            cerr << "No se ha podido abrir el fichero " << destino << endl; 
        }
        orig.close();
    }
    else {
        cerr << "No se ha podido abrir el fichero " << origen << endl;
    }
}

int main () {           
    char origen [MAX];
    char destino[MAX];
    cout <<"Fichero de nombres propios (en la carpeta de datos): ";
    cin >> origen;
    cout << endl << "Fichero a crear (en la carpeta de datos): ";
    cin >>destino;
    abrir(origen,destino);

}