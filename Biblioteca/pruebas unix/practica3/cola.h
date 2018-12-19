/*
 * Programador:Diego Marco Beisty
 * Fecha de la última revisión:
 */

/*
 * Fichero cola.h que contiene la definición del tipo genérico Cola, que
 * representa una cola de datos genéricos, y un conjunto de funciones básicas 
 * para trabajar con colas definidas a partir del tipo genérico Cola
 */
 
#ifndef COLA_H
#define COLA_H

#include <fstream>

using namespace std;

 /*
  * Capacidad máxima de almacenamiento de datos en las colas que 
  * puedan definirse a partir del tipo genérico Cola
  */
const int DIM = 250;       // Redefinir su valor en caso necesario

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
   C.n=0;
}
/* 
 * Pre: C = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
 * Post: C = [d_1, d_2, ..., d_K, nuevo]
 */
template <typename T>
void insertar (Cola<T>& C, const T nuevo) {
    if(C.n<DIM){
		C.tabla[n]=nuevo;
		C.n++;
	}
}
/* 
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
 * Post: C = [d_2, ..., d_(K-1), d_K]
 */
template <typename T>
void retirar (Cola<T>& C) {
	if(C.n>0){
		C.n--;
		}
}
/* 
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
 * Post: primero(C) = d_1
 */
template <typename T>
T primero (const Cola<T>& C) {
   return C.tipoCola[0];
}
/* 
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K >= 0
 * Post: numElementos(C) = K
 */
template <typename T>
int numElementos (const Cola<T>& C) {
    return C.n;
}
/* 
 * Pre: C = [d_1, d_2, ...,d_(K-1), d_K] AND K >= 0
 * Post: estaLlena(C) = (K == DIM)
 */
template <typename T>
bool estaLlena (const Cola<T>& C) {
  return(C.n==DIM);
}
/*
 * Un dato definido a partir del tipo genérico Cola representa una cola de datos 
 * de tipo T, donde T es un tipo genérico. Los datos de la cola son gestionados 
 * según una política FIFO, es decir, el primero en entrar (en ser incorporado 
 * a la cola) será el primero en salir (en abandonar la cola).
 */
template <typename T> 
struct Cola {
    private:
      T tabla[];
	  int n;
    public:
        // Funciones con acceso a la estructura interna anterior
        friend void vaciar<T> (Cola <T>& C);
        friend void insertar<T> (Cola<T>& C, const T nuevo);
        friend void retirar<T> (Cola<T>& C);
        friend T primero<T> (const Cola<T>& C);
        friend int numElementos<T> (const Cola<T>& C);
        friend bool estaLlena<T> (const Cola<T>& C);
};

#endif