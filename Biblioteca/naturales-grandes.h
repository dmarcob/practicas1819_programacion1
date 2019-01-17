/*********************************************************************************
 * Programación 1. Práctica 4
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Ultima revisión: 10 de noviembre de 2018
 * Resumen: Fichero de interfaz «naturales-grandes.h» de un módulo denominado
 *          «naturales-grandes» para trabajar con números naturales de gran
 *          magnitud el la 4.ª práctica.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#ifndef NATURALES_GRANDES_H_INCLUDED
#define NATURALES_GRANDES_H_INCLUDED

/*
 * Pre:  n >= 0
 * Post: «secuencia» almacena una cadena de caracteres, la secuencia
 *       de dígitos de «n». Sea «nD» el número de dígitos de «n».
 *       El carácter secuencia[«nD»-1] representa las unidades de «n»,
 *       el carácter secuencia[«nD»-2] las decenas de «n» y así, sucesivamente, el
 *       carácter secuencia[0] representa el dígito más significativo. El carácter
 *       secuencia[«nD»] es igual al carácter '\0' (cuyo código ASCII es 0).
 */
void convertir(const int n, char secuencia[]);

/*
 * Pre:  «secuencia» almacena una secuencia de caracteres que corresponden a los
 *       dígitos de un número natural comprendido en el intervalo de
 *       valores representables por el tipo «int», seguida por el carácter '\0'
 *       (cuyo código ASCII es 0).
 * Post: Ha devuelto el valor numérico del natural almacenado en «secuencia».
 */
int valor(const char secuencia[]);

/*
 * Pre:  «a» y «b» almacenan sendas cadenas de caracteres con la secuencias
 *       de dígitos de dos números naturales. Sea «nA» el número de dígitos de «a»
 *       y «nB» el número de dígitos de «b». Los caracteres a[«nA»-1] y b[«nB»-1]
 *       representan las unidades, los caracteres a[«nA»-2] y b[«nB»-2] las
 *       decenas y así sucesivamente.
 * Post: «suma» almacena la secuencia de dígitos de la suma de los naturales
 *       representados por «a» y «b». Sea «nS» el número de dígitos de suma.
 *       El carácter suma[«nS»-1] representa las unidades de la suma, el carácter
 *       suma[«nS»-2] representa las decenas y así sucesivamente.
 */
void sumar(const char a[], const char b[], char suma[]);

/*
 * Pre:  «numero» almacena una cadena de caracteres con la secuencia de dígitos de
 *       un número natural. Sea «nD» el número de dígitos de «numero».
 *       El carácter numero[«nD»-1] representa las unidades de «numero»,
 *       el carácter numero[«nD»-2] las decenas de «numero» y así,
 *       sucesivamente, el carácter numero[0] representa el dígito más
 *       significativo. El carácter numero[«nD»] es igual al carácter '\0' (cuyo
 *       código ASCII es 0).
 * Post: «imagen» almacena una cadena de caracteres con la secuencia de dígitos
 *       correspondiente a la imagen especular de «numero».
 */
void calcularImagen(const char numero[], char imagen[]);

/*
 * Pre:  «numero» almacena una cadena de caracteres con la secuencia de dígitos de
 *       un número natural. Sea «nD» el número de dígitos de «numero».
 *       El carácter numero[«nD»-1] representa las unidades de «numero»,
 *       el carácter numero[«nD»-2] las decenas de «numero» y así,
 *       sucesivamente, el carácter numero[0] representa el dígito más
 *       significativo. El carácter numero[«nD»] es igual al carácter '\0' (cuyo
 *       código ASCII es 0).
 * Post: Ha devuelto «true» si y solo si la secuencia de dígitos «numero» se
 *       corresponde con la de un número capicúa.
 */
bool esCapicua(const char numero[]);

#endif // NATURALES_GRANDES_H_INCLUDED