/*************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 22 de octubre de 2018
 * Resumen: Fichero de implementación de un módulo auxiliar «pruebas»
 *          que hace pruebas unitarias de las funciones del módulo
 *          «fechas».
 *          Para escribir estas funciones, solo se han utilizado
 *          conceptos de C++ que se han visto en la asignatura (es por
 *          ello que hay mucho código repetido, ya que las estructuras
 *          de las funciones se repiten).
 ************************************************************************/

#include <iostream>
#include "../../Biblioteca/fechas.h"
#include "fechas-test.h"
using namespace std;


/*
 * Pre:  «valorEsperado» es el entero que, al ser escrito en base 10, tiene
 *       la forma aaaammdd que representa la fecha «dia»/«mes»/«agno» donde los
 *       dígitos  aaaa representan el año, los dígitos mm el mes y los
 *       digitos dd el día de la fecha dia/mes/anyo.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «componer», invocada con los argumentos de entrada «dia», «mes» y
 *       «agno», ha calculado el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto que calculó
 *       la función.
 */
void probarComponer(const int dia, const int mes, const int agno,
                    const int valorEsperado) {
    cout << "Prueba componer(" << dia << ", " << mes << ", " << agno
         << ", int&) ";
    int valorCalculado;
    componer(dia, mes, agno, valorCalculado);
    if (valorCalculado == valorEsperado) {
        cout << "correcta" << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber obtenido " << valorEsperado
             << " pero ha calculado " << valorCalculado << endl;
    }
}

/*
 * Pre:  «diaEsperado», «mesEsperado» y «agnoEsperado» son el día, mes y año
 *       representados por el entero «fecha» que, al ser escrito en base 10,
 *       tiene la forma aaaammdd donde los dígitos aaaa representan el año, los
 *       dígitos mm el mes y los  digitos dd el día.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «descomponer», invocada con el argumento de entrada «fecha», ha
 *       calculado los valores correctos de día, mes y año. En caso negativo, ha
 *       informado también acerca de los valores incorrectos que calculó la
 *       función.
 */
void probarDescomponer(const int fecha,
    const int diaEsperado, const int mesEsperado, const int agnoEsperado) {
    cout << "Prueba descomponer(" << fecha << ", int&, int&, int&) ";
    int diaCalculado, mesCalculado, agnoCalculado;
    descomponer(fecha, diaCalculado, mesCalculado, agnoCalculado);
    if (diaCalculado == diaEsperado && mesCalculado == mesEsperado &&
        agnoCalculado == agnoEsperado) {
        cout << "correcta" << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber calculado "
             << "dia=" << diaEsperado << ", mes=" << mesEsperado << " y anyo="
             << agnoEsperado << endl
             << "   pero ha calculado "
             << "dia=" << diaCalculado << ", mes=" << mesCalculado << " y anyo="
             << agnoCalculado << endl;
    }
}

/*
 * Pre:  1 ≤ mes ≤ 12, agno > 1582 y «valorEsperado» es el número de días
 *       del mes correspondiente al parámetro «mes» del año
 *       correspondiente al parámetro «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diasDelMes», invocada con los argumentos «mes» y «agno»,
 *       ha devuelto el valor correcto «valorEsperado». En caso negativo,
 *       ha informado también acerca del valor incorrecto devuelto por
 *       la función.
 */
void probarDiasDelMes(const int mes, const int agno,
                      const int valorEsperado) {
    cout << "Prueba diasDelMes(" << mes << ", " << agno << ") ";
    int valorDevuelto = diasDelMes(mes, agno);
    if (valorDevuelto == valorEsperado) {
        cout << "correcta" << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber devuelto " << valorEsperado
             << " pero ha devuelto " << valorDevuelto << endl;
    }
}

/*
 * Pre:  agno > 1582 y «valorEsperado» es el número de días que tiene el
 *       año «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diasDelAgno», invocada con el argumento
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiasDelAgno(const int agno, const int valorEsperado) {
    cout << "Prueba diasDelAgno(" << agno << ") ";
    int valorDevuelto = diasDelAgno(agno);
    if (valorDevuelto == valorEsperado) {
        cout << "correcta" << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber devuelto " << valorEsperado
             << " pero ha devuelto " << valorDevuelto << endl;
    }
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno > 1582, la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano y
 *       «valorEsperado» es el número de día del año de esa fecha.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diaEnElAgno», invocada con los argumentos «dia», «mes» y
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiaEnElAgno(const int dia, const int mes, const int agno,
                       const int valorEsperado) {
    cout << "Prueba diaEnElAgno(" << dia << ", " << mes << ", " << agno
         << ") ";
    int valorDevuelto = diaEnElAgno(dia, mes, agno);
    if (valorDevuelto == valorEsperado) {
        cout << "correcta" << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber devuelto " << valorEsperado
             << " pero ha devuelto " << valorDevuelto << endl;
    }
}

/*
 * Pre:  «valorEsperado» es true si y solo si «fecha1» es anterior
 *       cronológicamente a «fecha2».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esAnterior», invocada con los argumentos «fecha1» y «fecha2», ha
 *       devuelto el valor correcto «valorEsperado». En caso negativo, ha
 *       informado también acerca del valor incorrecto que devolvió la función.
 */
void probarEsAnterior(const int fecha1, const int fecha2,
                      const bool valorEsperado) {
    cout << "Prueba esAnterior(" << fecha1 << ", " << fecha2 << ") ";
    bool valorDevuelto = esAnterior(fecha1, fecha2);
    if (valorDevuelto == valorEsperado) {
        cout << "correcta" << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber devuelto " << boolalpha << valorEsperado
             << " pero ha devuelto " << valorDevuelto << endl;
    }
}

/*
 * Pre:  «valorEsperado» representa el día siguiente a «fecha».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «diaSiguiente», invocada con los argumentos «fecha», ha
 *       devuelto el valor correcto «valorEsperado». En caso negativo, ha
 *       informado también acerca del valor incorrecto que devolvió la función.
 */
void probarDiaSiguiente(const int fecha, const int valorEsperado) {
    cout << "Prueba diaSiguiente(" << fecha << ") ";
    int valorDevuelto = diaSiguiente(fecha);
    if (valorDevuelto == valorEsperado) {
        cout << "correcta" << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber devuelto " << valorEsperado
             << " pero ha devuelto " << valorDevuelto << endl;
    }
}