/*********************************************************************************
 * Programación 1. Práctica 4
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Ultima revisión: 20 de noviembre de 2018
 * Resumen: Programa de pruebas del módulo «naturales-grandes» de la 4.ª práctica.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <cstdlib>
#include "naturales-grandes-test.h"
using namespace std;


/* Pre:  ---
 * Post: Ha probado las funciones de la biblioteca «natGrandes»
 */
int main() {
    probarConvertir(0, "0");
    probarConvertir(1, "1");
    probarConvertir(902, "902");
    probarConvertir(10015, "10015");
    probarConvertir(27043573, "27043573");
    probarConvertir(2147483647, "2147483647");

    // Elemento neutro
    probarSumar("0", "0", "0");
    probarSumar("00", "000", "0");
    probarSumar("132", "0", "132");
    probarSumar("0", "335", "335");
    // Sumas sin llevar
    probarSumar("802", "100", "902");
    probarSumar("802", "10", "812");
    // Ceros a la izquierda en las entradas
    probarSumar("00802", "100", "902");
    probarSumar("802", "0010", "812");
    // Con accarreo
    probarSumar("189", "21", "210");
    probarSumar("9999", "1", "10000");
    // Con accarreo y ceros a la izquierda en las entradas
    probarSumar("0189", "21", "210");
    probarSumar("09999", "1", "10000");
    probarSumar("189", "021", "210");
    probarSumar("9999", "01", "10000");
    // De más de 20 dígitos (no representables como int ni como long long)
    probarSumar("12345678901234567890", "10", "12345678901234567900");
    probarSumar("99999999999999999999", "1", "100000000000000000000");

    probarValor("0", 0);
    probarValor("7", 7);
    probarValor("18", 18);
    probarValor("903", 903);
    probarValor("100670", 100670);
    probarValor("123456789", 123456789);

    probarCalcularImagen("0", "0");
    probarCalcularImagen("000", "0");
    probarCalcularImagen("1", "1");
    probarCalcularImagen("18", "81");
    probarCalcularImagen("903", "309");
    probarCalcularImagen("0903", "309");
    probarCalcularImagen("123456789", "987654321");
    probarCalcularImagen("1030507090", "907050301");
    probarCalcularImagen("12345678901234567890", "09876543210987654321");

    probarEsCapicua("0", true);
    probarEsCapicua("000", true);
    probarEsCapicua("1", true);
    probarEsCapicua("10", false);
    probarEsCapicua("11", true);
    probarEsCapicua("100", false);
    probarEsCapicua("101", true);
    probarEsCapicua("91718", false);
    probarEsCapicua("91719", true);
    probarEsCapicua("091718", false);
    probarEsCapicua("091719", true);
    probarEsCapicua("1234567890123456789", false);
    probarEsCapicua("1234567890987654321", true);

    return 0;
}