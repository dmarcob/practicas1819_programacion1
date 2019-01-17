

#include <iostream>
#include "testCalculadora.h"

using namespace std;

/*
 * Pre:  ---
 * Post: Ha realizado pruebas unitarias de las funciones del módulo de
 *       biblioteca «calculos». En cada prueba, ha indicado los parámetros
 *       utilizados y si el resultado ha sido correcto o no. Además, en
 *       los casos negativos, ha indicado las salidas producidas por la
 *       función y las que debería haber producido.
 */
int main() {
    probarFibonacci(1, 0);
    probarFibonacci(2, 1);
    probarFibonacci(3, 1);
    probarFibonacci(4, 2);
    probarFibonacci(5, 3);
    probarFibonacci(6, 5);
    probarFibonacci(7, 8);
    probarFibonacci(8, 13);
    probarFibonacci(9, 21);
    probarFibonacci(10, 34);
    probarFibonacci(11, 55);
    probarFibonacci(12, 89);
    probarFibonacci(13, 144);
    probarFibonacci(14, 233);
    probarFibonacci(15, 377);
    probarFibonacci(16, 610);
    probarFibonacci(47, 1836311903);

    probarMcm(0, 1, 0);
    probarMcm(1, 0, 0);
    probarMcm(1, 1, 1);
    probarMcm(2, 2, 2);
    probarMcm(6, 6, 6);
    probarMcm(2, 3, 6);
    probarMcm(3, 2, 6);
    probarMcm(3, 12, 12);
    probarMcm(12, 3, 12);
    probarMcm(10, 15, 30);
    probarMcm(15, 10, 30);
    probarMcm(-10, 15, 30);
    probarMcm(10, -15, 30);
    probarMcm(-10, -15, 30);
    probarMcm(41273, 80758, 22369966);

    return 0;
}