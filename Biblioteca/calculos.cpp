/* 
 * Fichero calculos.cc de implementación del módulo calculos 
 */
 


 #include "../../biblioteca/calculos.h"
 using namespace std;
 


/*
 *  Pre: La sucesión de Fibonacci es una sucesión infinita de números
 *       naturales que comienza con el 0 y el 1 y cuyos restantes términos
 *       son iguales a la suma de los dos que le preceden. Estos son los 
 *       primeros términos de esta sucesión infinita:
 *         0  1  1  2  3  5  8  13  21  34  55  89  144  233  377  ...
 *       y el valor de <n> es mayor que cero
 *  Post: Devuelve el n-ésimo término de la sucesión de Fibonnaci
 */


int fibonacci(int n){
    const int MAX=1000;
    int tabla[MAX];
    tabla[1]=0;
    tabla[2]=1;
    for(int i=3;i<=n;i++){
        tabla[i]=tabla[i-1]+tabla[i-2];
    }
    return tabla[n];
}



/*
 *  Pre: a != 0 ó b != 0
 *  Post: Devuelve el máximo común divisor de <a> y <b>
 */
int mcd (int a, int b) {
    if (a < 0) { a = -a; }
    if (b < 0) { b = -b; }
    while (b != 0) {
        int resto = a % b;
        a = b;  b = resto;
    }
    return a;
}


 /*
 *  Pre: a != 0 ó b != 0
 *  Post: Devuelve el mayor de a y b
 */
 int max(int a,int b){
     if(a>b){
         return a;
     }
     return b;
 }
 
 
 /*
 *  Pre: a != 0 ó b != 0
 *  Post: Devuelve el menor de a y b
 */
 int min(int a,int b){
      if(a<b){
         return a;
     }
     return b;
 }
     
 
 /*
 *  Pre: a != 0 ó b != 0
 *  Post: Devuelve el mímimo común múltiplo de <a> y <b>
 */
int mcm (int a, int b) {
     if (a < 0) { a = -a; }
     if (b < 0) { b = -b; }
   int c;
   c=max(a,b);
   int d;
   d=min(a,b);
  int mcm=(c/mcd(a,b))*d;
  return mcm;
}
