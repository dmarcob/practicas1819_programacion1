#include <fstream>
#include "cola.h"
using namespace std;

 /*
  * Capacidad máxima de almacenamiento de datos en las colas que
  * puedan definirse a partir del tipo genérico Cola
  */


/*
 * Predeclaración del tipo Cola
 */
template <typename T>
struct Cola;

/*
 * Pre: ---
 * Post:  C = []
 */
template <typename T>
void vaciar (Cola <T>& C) {
   C.tabla[0]='\n';
}

/*
 * Pre: C = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
 * Post: C = [d_1, d_2, ..., d_K, nuevo]
 */
template <typename T>
void insertar (Cola<T>& C, const T nuevo) {
    C.tabla[ultimoDato+1]=nuevo;
}

/*
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
 * Post: C = [d_2, ..., d_(K-1), d_K]
 */
template <typename T>
void retirar (Cola<T>& C) {
    . . .  // Escribir aquí el código de la función
}

/*
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
 * Post: primero(C) = d_1
 */
template <typename T>
T primero (const Cola<T>& C) {
    . . .  // Escribir aquí el código de la función
}

/*
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K >= 0
 * Post: numElementos(C) = K
 */
template <typename T>
int numElementos (const Cola<T>& C) {
    . . .  // Escribir aquí el código de la función
}

/*
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K >= 0
 * Post: estaLlena(C) = (K == DIM)
 */
template <typename T>
bool estaLlena (const Cola<T>& C) {
    . . .  // Escribir aquí el código de la función
}
