#include <iostream>
#include <cstring>

#include "../../biblioteca/naturales-grandes.h" //Esta biblioteca no esta implementada con arrays para soportar numeros grandes

/*Dise ̃nar  un  programa  interactivo  que,  al  ser  ejecutado,  itera  el  siguiente  di ́alogo  con  el
 *operador hasta que  ́este responde con un negativo. En cada iteraci ́on el programa pide al
 *operador que determine el valor de un n ́umero natural y le informa del valor del factorial de
 *dicho natural. El programa ha de ser capaz de calcular factoriales con hasta 1000 d ́ıgitos.
 */

using namespace std;
const int MAX_DIGITOS = 1000;

int primerTermino(const int n, int& potencia){
    char array [MAX_DIGITOS];
    int numero = 2;
    potencia = 1;
    int resultado;
    if (n == 1) {
        numero = 1;
    }
    else {convertir(numero,array);
        while (strlen(array) != n) {
            numero *= 2;
            convertir(numero,array);
            potencia +=1; 
        } 
        
    }
    return numero;
}


int main(){ //SE CUELGA CON NUMEROS GRANDES (EJ:21)
    int termino;
    int potencia = 1;
    cout<<"Numero de digitos ( 0 o negativo para acabar):"<<flush;
    int digitos;
    cin>>digitos;
   while(digitos>0){
            termino = primerTermino(digitos,potencia);
            cout << termino <<"es 2 elevado a la " << potencia << "potencia" << endl;
            cout <<"Numero de digitos ( 0 o negativo para acabar):"<<flush;
            cin>>digitos;
   }
    return 0;
}