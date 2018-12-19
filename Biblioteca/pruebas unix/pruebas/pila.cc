/*
 * Programador:Diego Marco
 * Fecha de la última revisión:
 */
 
/*
 * Este fichero contiene la definición del tipo genérico Pila, que representa
 * una pila de datos genéricos, y un conjunto de funciones básicas para trabajar 
 * con pilas genéricas
 */
 
#include "pila.h"



#include <iostream>
#include <fstream>
using namespace std;

/*
 * Notación empleada en la especificación de funciones:
 *   P = []  La pila P está vacía, es decir, almacena 0 datos
 *   P = [d_1, d_2, ..., d_K] la pila P almacena K datos. El más antiguo
 *       es el dato d_1, el segundo más antiguo el dato d_2, etc., etc., 
 *       y el más reciente es el dato d_K
 */

/* 
 * Pre: ---
 * Post: P = []
 */
template <typename T>
void vaciar (Pila <T>& P) {
    P.ultimoDato=0;
}

/* 
 * Pre: P = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
 * Post: P = [d_1, d_2, ..., d_K, nuevo] 
 */
template <typename T>
void apilar (Pila <T>& P, const T nuevo) {
P.pila[P.ultimoDato+1]=nuevo;
}

/* 
 * Pre: P = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
 * Post: P = [d_1, d_2, ..., d_(K-1)] 
 */
template <typename T>
void desapilar (Pila<T>& P) {
P.ultimoDato=P.ultimoDato+1;
}

/* 
 * Pre: P = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
 * Post: cima(P) = d_K
 */
template <typename T>
T cima (const Pila<T>& P) {
 return P.pila[P.ultimoDato];
}

/* 
 * Pre: ---
 * Post: estaVacia(P) = (P = [])
 */
template <typename T>
bool estaVacia (const Pila<T>& P) {
	P.ultimoDato==0;
}

/* 
 * Pre: P = [d_1, d_2, ..., d_K]
 * Post: estaLlena(P) = (K = DIM])
 */
template <typename T>
bool estaLlena (const Pila<T>& P) {
   P.ultimoDato==DIM;
}



