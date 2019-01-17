
/*************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 22 de octubre de 2018
 * Resumen: Fichero de intefaz de un módulo auxiliar «calculos-test» que
 *          hace pruebas unitarias de las funciones del módulo «calculos».
 ************************************************************************/

 /*
 * Pre:  «valorEsperado» es el «n»-ésimo término de la sucesión de Fibonnaci.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «fibonacci», invocada con el argumento «n», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarFibonacci(const int n, const int valorEsperado);

/*
 * Pre:  «valorEsperado» es el mínimo común múltimo de «n» y «m».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «mcm», invocada con los argumentos «n» y «m», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarMcm(const int n, const int m, const int valorEsperado);
