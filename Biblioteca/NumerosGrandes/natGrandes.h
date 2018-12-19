/* 
 * Fichero natGrandes.h de interfaz del módulo natGrandes 
 */
 
#ifndef NATURALES_GRANDES_H

#define NATURALES_GRANDES_H

/*
 * Pre: n >= 0
 * Post: sec almacena una cadena de caracteres, la secuencia de dígitos de <n> 
 *       seguida por el carácter NUL, cuyo código ASCII es el '\0'. 
 *       Sea nDIG el número de dígitos de <n>. El carácter sec[nDIG-1] representa 
 *       las unidades de <n>, el carácter sec[nDIG-2] las decenas de <n> y así 
 *       sucesivamente, y finalmente, el carácter sec[0] representa el dígito
 *       mas significativo de <n>.
 */
void convertir (const int n, char sec[]);

/*
 * Pre: <sec> almacena una secuencia de caracteres que corresponden a los dígitos
 *      de un número natural comprendido en el intervalo de valores representables
 *      por el tipo <int>, seguida por el carácter NUL, cuyo código ASCII es el '\0'.
 * Post: Devuelve el valor numérico del natural almacenado en <sec>
 */
int valor (const char sec[]);

/*
 * Pre: <a> y <b> almacenan sendas cadenas de caracteres con la secuencia 
 *      de dígitos de dos números naturales seguidos por el carácter NUL,  
 *      cuyo código ASCII es el '\0'. Sea nA el número de dígitos de <a>
 *      y nB el número de dígitos de <b>. Los caracteres a[nA-1] y b[nB-1]
 *      representan las unidades, los caracteres a[nA-2] y b[nB-2] las decenas y  
 *      así sucesivamente y, finalmente, los caracteres a[0] y b[0] representan 
 *      los dígitos mas significativos de <a> y <b>, respectivamente.
 * Post: <suma> almacena la secuencia de dígitos de la suma de los naturales 
 *       representados por <a> y <b>. Sea nS el número de dígitos de suma.
 *       El carácter suma[nS-1] representa las unidades de la suma, el carácter 
 *       suma[nS-2] representa las decenas y así sucesivamente y, finalmente,
 *       el carácter suma[0] representa el dígito más significativo de la suma.
 */
void sumar (const char a[], const char b[], char suma[]);

#endif