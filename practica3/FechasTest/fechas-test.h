/*************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 22 de octubre de 2018
 * Resumen: Fichero de interfaz de un módulo auxiliar «pruebas»
 *          que hace pruebas unitarias de las funciones del módulo
 *          «fechas».
 ************************************************************************/

#ifndef FECHAS_TEST_H_INCLUDED
#define FECHAS_TEST_H_INCLUDED

/*
 * Pre:  «valorEsperado» es el entero que, al ser escrito en base 10,
 *       tiene la forma «aaaammdd» que representa la fecha
 *       «dia»/«mes»/«agno», formada por los valores de los parámetros
 *       «dia», «mes» y «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «componer», invocada con los argumentos de entrada «dia»,
 *       «mes» y «agno», ha calculado el valor correcto «valorEsperado».
 *       En caso negativo, ha informado también acerca del valor
 *       incorrecto que calculó la función.
 */
void probarComponer(const int dia, const int mes, const int agno,
                    const int valorEsperado);


/*
 * Pre:  «diaEsperado», «mesEsperado» y «agnoEsperado» son el día, mes y
 *       año representados por el entero «fecha» que, al ser escrito en
 *       base 10, tiene la forma «aaaammdd» donde los dígitos «aaaa»
 *       representan el año, los, dígitos «mm» el mes y los dígitos «dd»,
 *       el día.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «descomponer», invocada con el argumento de entrada
 *       «fecha», ha calculado los valores correctos de día, mes y año.
 *       En caso negativo, ha  informado también acerca de los valores
 *       incorrectos que calculó la función.
 */
void probarDescomponer(const int fecha,
    const int diaEsperado, const int mesEsperado, const int agnoEsperado);


/*
 * Pre:  «valorEsperado» es true si y solo si «fecha1» es anterior
 *       cronológicamente a «fecha2».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esAnterior», invocada con los argumentos «fecha1» y «fecha2», ha
 *       devuelto el valor correcto «valorEsperado». En caso negativo, ha
 *       informado también acerca del valor incorrecto que devolvió la función.
 */
void probarEsAnterior(const int fecha1, const int fecha2,
                      const bool valorEsperado);


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
                      const int valorEsperado);

/*
 * Pre:  agno > 1582 y «valorEsperado» es el número de días que tiene el
 *       año «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diasDelAgno», invocada con el argumento
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiasDelAgno(const int agno, const int valorEsperado);

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
                       const int valorEsperado);

/*
 * Pre:  «valorEsperado» representa el día siguiente a «fecha».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «diaSiguiente», invocada con los argumentos «fecha», ha
 *       devuelto el valor correcto «valorEsperado». En caso negativo, ha
 *       informado también acerca del valor incorrecto que devolvió la función.
 */
void probarDiaSiguiente(const int fecha, const int valorEsperado);

#endif // FECHAS_TEST_H_INCLUDED
