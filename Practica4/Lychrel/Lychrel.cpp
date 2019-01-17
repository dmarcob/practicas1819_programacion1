#include <iostream>
#include <cstring>

#include "../../Biblioteca/naturales-grandes.h"
using namespace std;

/*Pre:---
 *Post:---
 */
void Lychrel (int numero) {
    //inicializo variables
    const int MAX = 1000;
    char suma[MAX];
    char array[MAX];
    char imagen[MAX];
    int contador = 0;
    int cifras = 0;
    bool capicua = false;
    cout << "Iteracion " << contador << ": " << numero << endl;
    convertir (numero,array);
    if(esCapicua(array)) {capicua = true;}
    //bucle que itera hasta que encuentre un numero que sea capicua o llegue a las 1000 cifras
    while (!capicua && cifras <= MAX ) {
        contador++;
        cifras = strlen(array);
        calcularImagen(array,imagen);
        sumar(array,imagen,suma);
        cout << "Iteracion " << contador << ": " << array <<" + "<< imagen << " = " << suma << endl;
        if(esCapicua(suma)) {capicua = true;}
        else {
            //caso en que no es capicua, se prepara para la siguiente iteracion
            strcpy (array, suma);
        }
    }
}


int main(){ //SE CUELGA CON NUMEROS GRANDES (modificar libreria)
    cout<<"Escriba un numero natural: "<<flush;
    int numero;
    cin>>numero;
    Lychrel (numero);
   }