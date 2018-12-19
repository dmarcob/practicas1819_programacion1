#include <iostream>
#include <cstring>
#include <cmath>
#include "../../biblioteca/NumerosGrandes/natGrandes.h"
using namespace std;
/*
 * Pre: n >= 0
 * Post: sec almacena una cadena de caracteres, la secuencia de dígitos de <n> 
 *       seguida por el carácter NUL, cuyo código ASCII es el '\0'. 
 *       Sea nDIG el número de dígitos de <n>. El carácter sec[nDIG-1] representa 
 *       las unidades de <n>, el carácter sec[nDIG-2] las decenas de <n> y así 
 *       sucesivamente, y finalmente, el carácter sec[0] representa el dígito
 *       mas significativo de <n>.
 */
void convertir (const int n, char sec[]) {
    int m = n;
    int lon_n = 0;
    while (m > 0) {
        lon_n++;
        m = m/10;
    }
    m = n;
    for (int i = lon_n-1; i>=0; i--) {
        int ult_cif = m%10;
        sec[i] = ult_cif + '0';
        m = m/10;
    }
    sec[lon_n] = '\0';
}

/*
 * Pre: <sec> almacena una secuencia de caracteres que corresponden a los dígitos
 *      de un número natural comprendido en el intervalo de valores representables
 *      por el tipo <int>, seguida por el carácter NUL, cuyo código ASCII es el '\0'.
 * Post: Devuelve el valor numérico del natural almacenado en <sec>
 */
int valor (const char sec[]) {
    int n = 0;
    int lon_s = strlen(sec);
    for(int i = lon_s-1; i>=0; i--) {
        n += int(sec[i] - '0') * pow(10,lon_s-1-i);
    }
    return n;
}

/* Pre: <ori> almacena una secuencia de caracteres que corresponden a los dígitos
 *      de un número natural, seguida por el carácter NUL, cuyo código ASCII es el '\0'.
 *      <fin> contiene espacio suficiente para almacenar <ori> menos los ceros a la izquierda
 * Post: ha cambiado sec eliminando los dígitos "0" a la izquierda (excepto si el valor es 0).
 */
void corregir (char sec[]) {
    int n_ceros = 0;
    int lon_sec = strlen(sec);
    while (sec[n_ceros] == '0' && n_ceros < lon_sec-1) {
        n_ceros++;
    }
    int i = 0;
    while (sec[i+n_ceros] != '\0') {
        sec[i] = sec[i+n_ceros];
        i++;
    }
    sec[lon_sec-n_ceros] = '\0';
}

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
void sumar (const char a[], const char b[], char suma[]) {
    int ult_a = strlen(a)-1; // El índice de la última cifra de <a>
    int ult_b = strlen(b)-1; // El índice de la última de <b>
    int ult_suma;               //   "   "    "     "     de <suma> (el más largo entre <a> y <b>, + 1)
    if (ult_a >= ult_b) {
        ult_suma = ult_a+1;
    }
    else {
        ult_suma = ult_b+1;
    }
    int llev = 0; // Llevada (la primera es 0...)
    for (int i=0; i<=ult_suma; i++) {
        int cifra = llev; // Lo primero, le sumamos a la cifra la llevada
        if (ult_a >= i) { // Si <a> "no se ha acabado", sumamos a <cifra> la cifra correspondiente de <a>
            cifra += int(a[ult_a-i] - '0');    // valor(a[ult_a-i]);
        }
        if (ult_b >= i) { // Ídem con <b>
            cifra += int(b[ult_b-i] - '0');    // valor(b[ult_b-i]); 
        }
        llev = 0;        // La llevada se hace 0
        if (cifra > 9) { // Si <cifra> es mayor que 9, tenemos llevada y reducimos <cifra> con el módulo 10.
            llev = 1;
            cifra = cifra % 10;
        }
        suma[ult_suma-i] = cifra + '0';
    }
    suma[ult_suma+1] = '\0';
    corregir(suma);
}

