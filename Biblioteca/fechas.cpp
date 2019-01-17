/*************************************************************************
 * Fichero: fechas.cpp
 * Autor: Diego Marco, 755232
 * Fecha: 7 de noviembre, 2018
 * Resumen: Practica 3
 ************************************************************************/

#include <iostream>
#include "../../Biblioteca/fechas.h"
using namespace std;
/* 
 * Fichero fechas.cc de implementación del módulo fechas 
 */
 
/*
 * Pre: El trío de datos (dia,mes,anyo) definen una fecha válida del 
 *      calendario, la fecha dia/mes/anyo
 * Post: El valor de <f> es un entero que, al ser escrito en base 10, tiene 
 *       la forma aaaammdd que representa la fecha dia/mes/anyo donde los 
 *       dígitos  aaaa representan el año, los dígitos mm el mes y los 
 *       digitos dd el día de la fecha dia/mes/anyo
 */
void componer (int dia, int mes, int anyo, int& f) {
    f=anyo*10000+mes*100+dia;
}

/*
 * Pre: El valor de <f> escrito en base 10 tiene la forma aaaammdd donde 
 *      los  dígitos aaaa representan el año, los dígitos mm el mes y 
 *      los digitos dd el día de una fecha
 * Post: Los valores de <dia>, <mes> y <anyo> son iguales al dia al mes y
 *       al año de la fecha <f>
 */
void descomponer (int f, int& dia, int& mes, int& anyo) {
    anyo=f/10000;
    mes=(f/100)%100;
    dia=f%100;
}

/*
 * Pre: Los valores de <f1> y <f2> escritos en base 10 tiene la forma aaaammdd 
 *      donde los dígitos aaaa representan el año, los dígitos mm el mes y 
 *      los digitos dd el día de una fecha del calendario
 * Post: Devuelve true si y solo si la fecha <f1> es anterior a la fecha <f2>
 */
bool esAnterior (int f1, int f2) {
    return (f1<f2);
}

/*pre: Anyo>=0
 *Post: Ha devuelto true si <<anyo>> es bisiesto
 */
 
 bool esBisiesto (int anyo) {
     bool bisiesto = false;
     //Es bisiesto si cumple que es multiplo de cuatro y, no es multiplo de 100 ó es multiplo de 400
     if (anyo % 4 == 0 && (anyo %100 != 0 || anyo % 400 == 0) ){
         bisiesto = true;
     }
     return bisiesto;
}
/*
 * Pre:  1 ≤ mes ≤ 12 y agno > 1582.
 * Post: Ha devuelto el número de días del mes correspondiente al
 *       parámetro «mes» del año correspondiente al parámetro «agno».
 *       Por ejemplo: diasDelMes(10, 2018) devuelve 31,
 *                    diasDelMes(2, 2018) devuelve 28 y
 *                    diasDelMes(2, 2020) devuelve 29.
 */
int diasDelMes (int mes, int anyo) {
    int cantDias = 0;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        cantDias = 31;
    }
    else if (mes == 2 && !esBisiesto(anyo)) {
        cantDias = 28;
    }
    else if (mes == 2 && esBisiesto(anyo)) {
        cantDias = 29;
    }
    else {
        cantDias = 30;
    }
    return cantDias;
}


/*
 * Pre:  agno > 1582.
 * Post: Ha devuelto el número de días que tiene el año «agno».
 *       Por ejemplo: diasDelAgno(2018) devuelve 365 y
 *                    diasDelAgno(2020) devuelve 366.
 */
int diasDelAgno(int agno) {
    int dias;
    if (esBisiesto(agno)) {
        dias = 366;
    }
    else {
        dias = 365;
    }
    return dias;
}



/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno > 1582 y la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano.
 * Post: Ha devuelto el número de día del año de la fecha formada por
 *       «dia/mes/agno».clTabCtrl
 *       Por ejemplo: diaEnElAgno(1, 1, 2019) devuelve 1;
 *                    diaEnElAgno(31, 12, 2018) devuelve 365;
 *                    diaEnElAgno(1, 2, 2019) devuelve 32 y
 *                    diaEnElAgno(31, 12, 2020) devuelve 366.
 */
int diaEnElAgno(int dia, int mes, int agno) {
    int diaTot = dia;
    for (int i = mes-1; i >= 1; i--) {
        diaTot += diasDelMes (i,agno);
    }
    return diaTot;
}



/*
* Pre: El valor de f escrito en base 10 tiene la forma aaaammdd donde los
* dígitos aaaa representan el año, los dígitos mm el mes y los digitos
* dd el dÃ­a de una fecha
* Post: Devuelve la fecha correspondiente al dia siguiente de la fecha f ,
* representada con el mismo formato que la fecha f
*/
int diaSiguiente (int f) {
    int diaSumar = 1;
    int dia = 0, mes = 0, anyo = 0; 
    descomponer (f, dia, mes, anyo);
    int max = diasDelMes (mes, anyo);
    while (dia < max){
        //dia no es el ultimo del mes 
        diaSumar--;
        dia += 1;
        }
    if (diaSumar > 0) {
        //dia es el ultimo del mes
        mes++;
        dia = 1;
        if (mes > 12) {
            //mes es el ultimo del año
            mes = 1;
            anyo++;
        }
    }
    componer(dia,mes,anyo,f);
    return f;
}