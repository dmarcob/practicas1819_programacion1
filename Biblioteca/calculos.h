/* 
 * Fichero calculos.h de interfaz del módulo calculos 
 */

#ifndef CALCULOS_H

#define CALCULOS_H

 


/*
 *  Pre: La sucesión de Fibonacci es una sucesión infinita de números
 *       naturales que comienza con el 0 y el 1 y cuyos restantes términos
 *       son iguales a la suma de los dos que le preceden. Estos son los 
 *       primeros términos de esta sucesión infinita:
 *         0  1  1  2  3  5  8  13  21  34  55  89  144  233  377  ...
 *       y el valor de <n> es mayor que cero
 *  Post: Devuelve el n-ésimo término de la sucesión de Fibonnaci
 */
int fibonacci (int n);

/*
 *  Pre: a != 0 o  b != 0
 *  Post: Devuelve el máximo común divisor de <a> y <b>
 */
int mcd (int a, int b);

/*
 *  Pre: a != 0 o b != 0
 *  Post: Devuelve el mímimo común múltiplo de <a> y <b>
 */
int mcm (int a, int b);

#endif