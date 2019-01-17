#include <fstream>
#include <iostream>
#include "../../Biblioteca/nombres.h"
using namespace std;

/*Pre: <<origen>> es la ruta completa del fichero a leer, <<nombre>> es el nombre que hay que localizar en el archivo <<origen>>
 *Post: Ha devuelto la posicion del nombre en el archivo o un -1 si ese nombre no se encuentra en el archivo
 */
int abrir ( char origen[],  char nombre[]) {
    int posicion = 0;
    ifstream orig (origen);
    if (orig.is_open()) {
        //caso en que ha conseguido establecer un flujo de entrada
        localizar (orig, nombre, posicion); //FUNCION DE BIBLIOTECA nombres
        orig.close();
    }
    else {
        cerr << "No se ha podido abrir el fichero " << origen << endl;
    }
    return posicion;
}

int main () {  
    char origen[MAX] ="../../../Datos/Nombres/nombres-propios.txt";
    char nombre [MAX];
    cout <<"Escriba un nombre (pulse la tecla de RETORNO para acabar): ";
    cin >> nombre;
    int posicion = abrir(origen,nombre);
    if (posicion != -1) {
        //caso en que la llamada abrir() ha encontrado el nombre y devuelve la posicion de este
        cout << "El nombre " << nombre << " esta situado en la posicion " << posicion << " del fichero" << endl;
    }
    else {
        //caso en que la llamada abrir() no ha encontrado el nombre y devuelve -1
        cout << "El nombre " << nombre << " no se encuentra en el fichero" << endl;
    }
}