#include <fstream>
#include <iostream>
#include <cctype>
#include "../../Biblioteca/nombres.h"
using namespace std;

/*Pre: <<origen>> es la ruta completa del fichero a leer, <<nombre>> es el nombre que hay que localizar en el archivo <<origen>>
 *Post: Ha devuelto la posicion del nombre en el archivo o un -1 si ese nombre no se encuentra en el archivo
 */
int abrir ( char origen[],  char nombre[]) {
    int valoracion = -1;
    ifstream orig (origen);
    if (orig.is_open()) {
        //caso en que ha conseguido establecer un flujo de entrada
        //-------------------------------------------------------------------------------------------
        int i = 0;
        while (nombre[i] != '\0') { //pasamos <<nombre>> a mayusculas
            nombre[i] = toupper(nombre[i]);
            i++;
        }
        //---------------------------------------------------------------------------------------------
        valoracion = factorA(nombre) * factorB(orig, nombre); //FUNCION DE BIBLIOTECA nombres
        orig.close();
    }
    else {
        cerr << "No se ha podido abrir el fichero " << origen << endl;
    }
    return valoracion;
}

int main () {  
    char origen[MAX] ="../../../Datos/Nombres/nombres-propios.txt";
    char nombre [MAX];
    cout <<"Escriba un nombre (pulse la tecla de RETORNO para acabar): ";
    cin >> nombre;
    int valoracion = abrir(origen,nombre);
    cout << "La valoracion de " << nombre << " es de " << valoracion << endl;
    
}