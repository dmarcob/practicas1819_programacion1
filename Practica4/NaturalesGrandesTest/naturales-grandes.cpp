/*********************************************************************************
 * Programación 1. Práctica 4
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Ultima revisión: 20 de noviembre de 2018
 * Resumen: Fichero de implementación «naturales-grandes.cpp» de un módulo
 *          denominado «naturales-grandes» para trabajar con números naturales de
 *          gran magnitud el la 4.ª práctica.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "../../Biblioteca/naturales-grandes.h"
#include <iostream>
using namespace std;
/*
 * Pre:  n >= 0
 * Post: «sec» almacena una cadena de caracteres, la secuencia
 *       de dígitos de «n». Sea nDIG el número de dígitos de «n».
 *       El caracter sec[nDIG-1] representa las unidades de «n»,
 *       el carácter sec[nDIG-2] las decenas de «n» y así sucesivamente
 */
void convertir (const int n, char sec[]) { //PARA NUMEROS MUY GRANDES PETA
     int nDIG = 0;
     int nCopia = n;
     //almaceno en nDIG el numero de digitos de n
     if (n == 0) {
         nDIG = 1;
     }
     while (nCopia != 0) {
         nCopia /= 10;
         nDIG++;
     }
     nCopia = n;
     //relleno el vector segun la especificacion
     for (int i =nDIG-1;i>=0;i--) {
         sec[i] = (nCopia%10) + '0';
         nCopia/= 10;
     }
     //añado el caracter null al final del vector
     sec[nDIG] = '\0';
}


/*
 * Pre:  «sec» almacena una secuencia de caracteres que corresponden a los
 *       dígitos de un número natural comprendido en el intervalo de
 *       valores representables por el tipo <int>, seguida por el carácter
 *       NUL, cuyo código ASCII es el '\0'.
 * Post: Devuelve el valor numérico del natural almacenado en «sec»
 */
int valor(const char sec[]) {
        int i = 1;
        //guardo en natural el primer elemento del vector
        int natural = sec[i-1] - '0';
        while (sec [i] != '\0') {
            natural = (sec[i] -'0') + (natural*10);
            i++;
        }
        return natural;
}


/*
 * Pre:  «a» y «b» almacenan sendas cadenas de caracteres con la secuencias
 *       de dígitos de dos números naturales. Sea nA el número de dígitos de «a»
 *       y nB el número de dígitos de «b». Los caracteres a[nA-1] y b[nB-1]
 *       representan las unidades, los caracteres a[nA-2] y b[nB-2] las decenas
 *       y así sucesivamente.
 * Post: «suma» almacena la secuencia de dígitos de la suma de los naturales
 *       representados por «a» y «b». Sea nS el número de dígitos de suma.
 *       El caracter suma[nS-1] representa las unidades de la suma, el caracter
 *       suma[nS-2] representa las decenas y así sucesivamente.
 */
void sumar (const char a[], const char b[], char suma[]) {
    //<<uno>> y <<dos>> almacenan el valor natural del las cadenas <<a>> y <<b>>.
    int uno = valor(a);
    int dos = valor(b);
    int resultado = uno + dos;
    //Convierto a cadena de caracteres el valor numerico de <<resultado>>
    convertir(resultado, suma);
}


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
void calcularImagen(const char numero[], char imagen[]) {
    int num = valor (numero);
    bool negativo = num < 0;
    if (negativo) { 
        num = -num;
    }
    int resultado = num % 10;
    num /= 10;
    while (num != 0) {
        resultado = (resultado*10) + (num%10);
        num /= 10;
    }
    convertir (resultado,imagen);
}


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
bool esCapicua(const char numero[]) { //CON NUMEROS MUY GRANDES PETA
    const int MAX = 100;
    char imagen[MAX];
    //calculo la imagen de la cadena de caracteres;
    calcularImagen (numero, imagen);
    //calculo su valor numerico
    int num = valor(numero);
    int imag = valor(imagen); 
    //si es capicua cumple que el mismo menos su imagen es igual a cero
    return num - imag == 0;
}