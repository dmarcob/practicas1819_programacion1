/*************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 22 de octubre de 2018
 * Resumen: Módulo principal de un programa que hace pruebas unitarias de
 *          las funciones del módulo «fechas».
 ************************************************************************/

 #include <iostream>
 #include "../../Biblioteca/fechas.h"
 #include "fechas-test.h"
 using namespace std;


/*
 * Pre:  ---
 * Post: Ha realizado pruebas unitarias de las funciones del módulo de
 *       biblioteca «fechas». En cada prueba, ha indicado los parámetros
 *       utilizados y si el resultado ha sido correcto o no. Además, en
 *       los casos negativos, ha indicado las salidas producidas por la
 *       función y las que debería haber producido.
 */
int main() {
    probarComponer(31, 10, 2016, 20161031);
    probarComponer(1, 11, 2016, 20161101);
    probarComponer(19, 9, 2016, 20160919);
    probarComponer(1, 2, 2017, 20170201);

    probarDescomponer(20161031, 31, 10, 2016);
    probarDescomponer(20161101, 1, 11, 2016);
    probarDescomponer(20160919, 19, 9, 2016);
    probarDescomponer(20170201, 1, 2, 2017);

    probarEsAnterior(20161031, 20161031, false);
    probarEsAnterior(20161030, 20161031, true);
    probarEsAnterior(20161031, 20161030, false);
    probarEsAnterior(20161130, 20161031, false);
    probarEsAnterior(20161031, 20161130, true);
    probarEsAnterior(20161130, 20171031, true);
    probarEsAnterior(20171031, 20161130, false);

    probarDiasDelMes( 1, 2018, 31);
    probarDiasDelMes( 2, 2018, 28);
    probarDiasDelMes( 2, 2020, 29);
    probarDiasDelMes( 2, 2100, 28);
    probarDiasDelMes( 2, 2400, 29);
    probarDiasDelMes( 3, 2018, 31);
    probarDiasDelMes( 4, 2018, 30);
    probarDiasDelMes( 5, 2018, 31);
    probarDiasDelMes( 6, 2018, 30);
    probarDiasDelMes( 7, 2018, 31);
    probarDiasDelMes( 8, 2018, 31);
    probarDiasDelMes( 9, 2018, 30);
    probarDiasDelMes(10, 2018, 31);
    probarDiasDelMes(11, 2018, 30);
    probarDiasDelMes(12, 2018, 31);

    probarDiasDelAgno(2019, 365);
    probarDiasDelAgno(2024, 366);
    probarDiasDelAgno(1900, 365);
    probarDiasDelAgno(2000, 366);

    probarDiaEnElAgno( 1,  1, 2019,  1);
    probarDiaEnElAgno( 2,  1, 2019,  2);
    probarDiaEnElAgno(31,  1, 2019, 31);
    probarDiaEnElAgno( 1,  2, 2019, 32);
    probarDiaEnElAgno(28,  2, 2019, 59);
    probarDiaEnElAgno( 1,  3, 2019, 60);
    probarDiaEnElAgno(31, 12, 2019, 365);
    probarDiaEnElAgno(31, 12, 2020, 366);

    probarDiaSiguiente(20161030, 20161031);
    probarDiaSiguiente(20161031, 20161101);
    probarDiaSiguiente(20161130, 20161201);
    probarDiaSiguiente(20161231, 20170101);
    probarDiaSiguiente(20170228, 20170301);
    probarDiaSiguiente(20160228, 20160229);
    probarDiaSiguiente(21000228, 21000301);
    probarDiaSiguiente(20000228, 20000229);
    return 0;
}