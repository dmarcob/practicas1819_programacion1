/*************************************************************************
 * Fichero: fechas.h
 * Autor: Diego Marco
 * Fecha: Noviembre 2018
 * Resumen: Practica 3
 ************************************************************************/

#ifndef FECHAS_H

#define FECHAS_H


/*
 * Pre: El trío de datos (dia,mes,anyo) definen una fecha válida del 
 *      calendario, la fecha dia/mes/anyo
 * Post: El valor de <f> es un entero que, al ser escrito en base 10, tiene 
 *       la forma aaaammdd que representa la fecha dia/mes/anyo donde los 
 *       dígitos  aaaa representan el año, los dígitos mm el mes y los 
 *       digitos dd el día de la fecha dia/mes/anyo
 */
void componer (int dia, int mes, int anyo, int& f);

/*
 * Pre: El valor de <f> escrito en base 10 tiene la forma aaaammdd donde 
 *      los  dígitos aaaa representan el año, los dígitos mm el mes y 
 *      los digitos dd el día de una fecha
 * Post: Los valores de <dia>, <mes> y <anyo> son iguales al día, al mes y
 *       al año de la fecha <f>
 */
void descomponer (int f, int& dia, int& mes, int& anyo);

/*
 * Pre: Los valores de <f1> y <f2> escritos en base 10 tiene la forma aaaammdd 
 *      donde los dígitos aaaa representan el año, los dígitos mm el mes y 
 *      los digitos dd el día de una fecha del calendario
 * Post: Devuelve true si y solo si la fecha <f1> es anterior a la fecha <f2>
 */
bool esAnterior (int f1, int f2);
/*pre: Anyo>=0
 *Post: Ha devuelto true si <<anyo>> es bisiesto
 */
 
 bool esBisiesto (int anyo);
/*
 * Pre: El valor de <f> escrito en base 10 tiene la forma aaaammdd donde 
 *      los dígitos aaaa representan el año, los dígitos mm el mes y los 
 *      digitos dd el día de una fecha
 * Post: Devuelve la fecha correspondiente al dia siguiente de la fecha <f>,
 *       representada con el mismo formato que la fecha <f>
 */
 
 
/*
 * Pre:  1 ≤ mes ≤ 12 y agno > 1582.
 * Post: Ha devuelto el número de días del mes correspondiente al
 *       parámetro «mes» del año correspondiente al parámetro «agno».
 *       Por ejemplo: diasDelMes(10, 2018) devuelve 31,
 *                    diasDelMes(2, 2018) devuelve 28 y
 *                    diasDelMes(2, 2020) devuelve 29.
 */
int diasDelMes(int mes, int agno);


/*
 * Pre:  agno > 1582.
 * Post: Ha devuelto el número de días que tiene el año «agno».
 *       Por ejemplo: diasDelAgno(2018) devuelve 365 y
 *                    diasDelAgno(2020) devuelve 366.
 */
int diasDelAgno(int agno);


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno > 1582 y la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano.
 * Post: Ha devuelto el número de día del año de la fecha formada por
 *       «dia/mes/agno».
 *       Por ejemplo: diaEnElAgno(1, 1, 2019) devuelve 1;
 *                    diaEnElAgno(31, 12, 2018) devuelve 365;
 *                    diaEnElAgno(1, 2, 2019) devuelve 32 y
 *                    diaEnElAgno(31, 12, 2020) devuelve 366.
 */
int diaEnElAgno(int dia, int mes, int agno);




/*
 * Pre:  El valor de «fecha» escrito en base 10 tiene la forma «aaaammdd»,
 *       donde los dígitos «aaaa» representan el año, los dígitos «mm», el
 *       mes y los dígitos «dd» el día de una fecha válida del calendario
 *       gregoriano.
 * Post: Ha devuelto la fecha correspondiente al día posterior a la fecha
 *       representada por el valor del parámetro «fecha», representada con
 *       el mismo formato «aaaammdd» que «fecha».
 */
int diaSiguiente (int f);
 
#endif