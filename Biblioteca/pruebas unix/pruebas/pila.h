/*
 * Programador:
 * Fecha de la última revisión:
 */
 
/*
 * Este fichero contiene la definición del tipo genérico Pila, que representa
 * una pila de datos genéricos, y un conjunto de funciones básicas para trabajar 
 * con pilas genéricas
 */
 
#ifndef PILA_GENERICA_H

#define PILA_GENERICA_H

/*
 * Capacidad máxima de almacenamiento de datos en las pilas que 
 * puedan definirse a partir del tipo genérico Pila
 */
const int DIM = 120;            // Redefinir su valor en caso necesario

/*
 * Predeclaración del tipo Pila
 */
template<typename T> 
struct Pila;

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
void vaciar (Pila <T>& P);

/* 
 * Pre: P = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
 * Post: P = [d_1, d_2, ..., d_K, nuevo] 
 */
template <typename T>
void apilar (Pila <T>& P, const T nuevo);

/* 
 * Pre: P = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
 * Post: P = [d_1, d_2, ..., d_(K-1)] 
 */
template <typename T>
void desapilar (Pila<T>& P);

/* 
 * Pre: P = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
 * Post: cima(P) = d_K
 */
template <typename T>
T cima (const Pila<T>& P);

/* 
 * Pre: ---
 * Post: estaVacia(P) = (P = [])
 */
template <typename T>
bool estaVacia (const Pila<T>& P);
/* 
 * Pre: P = [d_1, d_2, ..., d_K]
 * Post: estaLlena(P) = (K = DIM])
 */
template <typename T>
bool estaLlena (const Pila<T>& P);

/*
 * Un dato definido a partir del tipo genérico Pila representa una pila
 * de datos de tipo T. Los datos son gestionados según una política FIFO,
 * es decir, el último en entrar (en ser apilado) será el primero en salir
 * (en ser desapilado).
 */
template <typename T> 
struct Pila {
private:
	T pila [DIM];
	int ultimoDato;
    public:
	 // Estas son las únicas funciones que van a tener visibilidad sobre 
	 // los datos ocultos definidos como 'private' de cualquier registro
	 // de tipo Pila
	 friend void vaciar<T> (Pila<T>& P);
	 friend void apilar<T> (Pila<T>& P, const T nuevo);
	 friend void desapilar<T> (Pila<T>& P);
	 friend T cima<T>  (const Pila<T>& P);
	 friend bool estaVacia<T> (const Pila<T>& P);
	 friend bool estaLlena<T> (const Pila<T>& P);
};

#endif