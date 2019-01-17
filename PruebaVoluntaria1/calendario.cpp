/*************************************************************************
 * Fichero: calendario.cpp
 * Autor: Diego Marco, 755232
 * Fecha: 7 de noviembre, 2018
 * Resumen: Prueba1
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include "../../Biblioteca/fechas.h"

using namespace std;


/*
 * Pre:  ---
 * Post: Ha solicitado reiteradamente al usuario un mes de un año igual o
 *       posterior a 1900, leyéndolos en los parámetros «mes» y «agno», hasta que
 *       1 ≤ mes ≤ 12 y hasta que agno ≥ 1900.
 */
void pedirDatos(int& mes, int& agno) {
     cout << "Introduzca el mes [1-12]: " << flush;
     cin >> mes;
     while (mes > 12 || mes < 1) {
         cout << "El mes debe estar comprendido entre 1 y 12: " << flush;
         cin >> mes;
        
     }
     cout << "Introduzca un agno igual o posterior a 1900: " << flush;
     cin >> agno;
     while (agno < 1900) {
         cout << "El agno debe ser igual o posterior a 1900: " <<flush;
         cin >>agno;
     }
}


/*
 * Pre:  Los valores de los parámetros «dia», «mes» y «agno» representan
 *       conjuntamente una fecha válida del calendario gregoriano igual o
 *       posterior al 1 de enero de 1900.
 * Post: Ha devuelto un entero que codifica el día de la semana de la fecha
 *       representada por los valores de los parámetros «dia», «mes» y «agno», de
 *       acuerdo con la siguiente codificación: el 0 codifica el lunes, el 1
 *       codifica martes y así sucesivamente hasta el 6, que codifica el domingo.
 */
int diaDeLaSemana(const int dia, const int mes, const int agno) {
    //Inicializacion de variables
    int agnoBase = 1990;
    int diasTot = 0;
    while (agnoBase < agno) {
         // cuento el numero de dias desde el 01/01/1900 hasta 01/01/agno
         diasTot += diasDelAgno(agno);
         agnoBase++;
    }
    //Cuento el numero de dias desde el 01/01/agno hasta dia/mes/agno
    diasTot += diaEnElAgno(dia,mes,agno);
    //aplico modulo 7 para obtener de 0 a 6 el dia de la semana que es
    diasTot = diasTot % 7;
    //Como la codificacion difiere de 6 unidades respecto la codificacion especificada, aplico este cambio
    diasTot = (diasTot + 6) % 7;
    return diasTot;
}

/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla el nombre (en mayúsculas) del mes
 *       correspondiente al valor del parámetro «mes».
 * Nota: Este código se explicará adecuadamente en el tema 10 (cadenas de
 *       caracteres).
 */
void escribirNombreMes(const int mes) {
    const int NUM_MESES = 12;
    const int MAX_LONG_NOMBRE_MES = 10;
    const char NOMBRES_MES[NUM_MESES][MAX_LONG_NOMBRE_MES + 1] = { "ENERO",
            "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
            "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };
    cout << NOMBRES_MES[mes - 1];
}

/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla la cabecera del calendario del mes «mes» del
 *       año «agno» con un el formato del siguiente ejemplo:
 *
 *                     NOVIEMBRE 2018
 *          L   M   X   J   V   S   D
 *       ----------------------------
 */
void escribirCabecera(const int mes, const int agno) {
    cout << setw(32);
    escribirNombreMes (mes);
    cout <<  setw(5) << agno << endl;
    cout << setw(37) << "L   M   X   J   V   S   D" <<endl;
    cout << setw(37) << "-----------------------------" << endl;
   
}

/*Pre: 1<=mes<=12 y agno>1900
 *Post: Escribe en pantalla el primer dia <<dia>> del mes <<mes>> del año <<agno>> en el calendario
 *      segun la reperesentacion en la postcondicion de la funcion escribirCalendario(int mes, int agno)
 */
void primerDia (int mes, int agno) {
    //Declaro variables
    const int MAX = 7;
    //margen hasta dia <<dia>> cuando es lunes
    int margen = 13;
    //valor numerico del primer dia <<dia>> del mes
    int primerElem = 1;
    //codificacion del primer dia <<dia>> del mes
    int codificacion = diaDeLaSemana(primerElem,mes,agno);
    int array[MAX];
    //inicializo el vector de enteros con los posibles valores del margen del primer elemento del calendario
    //segun el dia de la semana en el que comience.
    for (int i = 0; i < MAX; i++) {
        array[i]= margen;
        margen += 4;
    }
    //Escribo en pantalla el primer dia del mes con su margen segun el dia de la semana
    if (codificacion == 6) {
       //caso en que el primer dia de la semana es domingo
       cout << setw( array[codificacion] ) << primerElem << endl;
    }
    else {
        //caso en que el primer dia de la semana NO es domingo
        cout << setw( array[codificacion] ) << primerElem; 
    }
}


/*
 * Pre:  1 ≤ mes ≤ 12 y agno ≥ 1900
 * Post: Ha escrito en la pantalla el calendario del mes «mes» del año «agno» con
 *       el formato del siguiente ejemplo:
 *
 *                     NOVIEMBRE 2018
 *          L   M   X   J   V   S   D
 *       ----------------------------
 *                      1   2   3   4
 *          5   6   7   8   9  10  11
 *         12  13  14  15  16  17  18
 *         19  20  21  22  23  24  25
 *         26  27  28  29  30
 */
void escribirCalendario(const int mes, const int agno) {
    //margen entre dias
    int margen = 4;
    //primer margen en cada fila
    int margenXL = 13;
    escribirCabecera(mes, agno);
    //Saco por pantalla el primer dia del mes
    primerDia(mes, agno);
    //escribo por pantalla los dias del mes empezando por el segundo dia
    for (int i = 2; i <= diasDelMes(mes, agno); i++) {
        if (diaDeLaSemana(i, mes, agno) == 6) {
            //caso en que es domingo
            cout << setw(margen) << i <<endl;
        }
        else if (diaDeLaSemana(i,mes,agno) == 0) {
            //caso en que es lunes
            cout << setw (margenXL) << i;
        }
        else {
            //caso en que es martes, miercoles, jueves, viernes o sabado
            cout << setw(margen) << i;
        }
        
    }
}

/*
 * Pre:  ---
 * Post: Ha solicitado al usuario un mes de un año igual o posterior a 1900, se
 *       ha asegurado de que el mes introducido está comprendido entre 1 y 12 y
 *       de que el año es igual o posterior a 1900 y ha terminado escribiendo el
 *       calendario del mes solicitado en la pantalla.
 */
int main() {
    int mes, agno;
    pedirDatos(mes, agno);
    escribirCalendario(mes, agno);
    return 0;
}