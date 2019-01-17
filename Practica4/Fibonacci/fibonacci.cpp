#include <iostream>
#include <cstring>

#include "../../Biblioteca/naturales-grandes.h"
//#include "../../Biblioteca/naturales-grandes.cpp"
using namespace std;
const int MAX_DIGITOS = 300;
//const int MAX_DIGITOS = 1000;
/*
 *   Disenar un programa interactivo que, al ser ejecutado, itera el siguiente tipo de di ́alogo
 *con el operador hasta que  ́Este responde con un 0 o un negativo. En cada iteraci ́on, pide al
 *operador que determine un n ́umero de d ́ıgitos y, si es positivo, el programa le informa del
 *valor y posici ́on del primer t ́ermino de la sucesi ́on de Fibonacci con ese n ́umero de d ́ıgitos.
 *El programa ha de ser capaz de ser capaz de calcular t ́erminos de la sucesi ́on de Fibonacci
 *de hasta 1000 d ́ıgitos.
 */

long fibo(int n){ //CON NUMEROS MUY GRANDES PETA
    int resultado = 0;
    int anterior = 1; //posicion 2 de la sucesion
    int preanterior = 0; //posicion 1 de la sucesion
    if (n==1) {
        resultado = 0;
    }
    if (n == 2) {
        resultado = 1;
    }
    else { //caso en que n >= 3
        int i = 3;
        while (i <= n) {
            resultado = anterior + preanterior;
            preanterior = anterior;
            anterior = resultado;
            i++;
        }
    }
    return resultado;
}

void presentarTabla (int desde, int hasta){
    for(int i=desde; i<=hasta ; i++){
        cout << i << ". "  <<  fibo(i) << endl;
    }
}
int main(){
    cout<<"Terminos desde y hasta (0 o negativo para acabar) :" <<flush;
    bool acabar = false;
    int desde,hasta;
    cin>>desde;
    if (desde == 0) {acabar =true;}
    else {cin >> hasta;}
    while(!acabar){
            presentarTabla(desde,hasta);
            cout<<"Terminos desde y hasta (0 o negativo para acabar) :" <<flush;
            cin>>desde;
              if (desde == 0) {acabar =true;}
              else {cin >> hasta;}
    }
    cout <<"terminao"<<endl;
    return 0;
}
