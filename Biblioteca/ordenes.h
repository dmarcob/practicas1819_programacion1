/*********************************************************************************
 * Programación 1. 
 * Autor: Diego Marco Beisty, 755232
 * Fichero: ordenes.h
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de implementacion «ordenes.cpp» de un módulo para implementar los comandos
 *          usados en Trabajo.cpp
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#ifndef ORDENES_H_INCLUDED
#define ORDENES_H_INCLUDED
const int ORDER = 100; //Máximo numero de caracteres de una orden
const int MAX_RUTA = 100; //Máximo número de caracteres de la ruta de un fichero

/*Pre:  <<fichero>> almacena caracteres que pueden estar en mayúscula o minúscula
 *Post: <<fichero>> almacena caracteres que están en mayúscula
 */
void mayusculas(char fichero[]);

/*Pre: <<orden>> es una orden ingresada por el usuario. <<informe>> corresponde a la orden "INFORME".
 *     <<usuario>> corresponde a la orden "USUARIO".
 *Post: Ha devuelto <<true>> si <<orden>> es igual a <<informe>> o <<usuario>>.
 */
bool tieneArgumento (const char orden[],const char informe[],const char usuario[]);

/*Pre:  <<orden>> es una orden ingresada por el usuario.<<informe>> corresponde a la orden "INFORME".
 *      <<usuario>> corresponde a la orden "USUARIO".
 *Post: Ha leido texto de la entrada estándar hasta encontrar un " " o "\n", y lo ha guardado en <<orden>>.
 *      Si <<orden>> es igual a <<informe>> o <<usuario>>, ha leido texto de la entrada estandar y lo 
 *      ha guardado en <<argumento>>.
 */
void ingresarOrden(char orden[],char argumento[],const char informe[],const char usuario[]);



//--------------------------ÓRDENES------------------------------------------------------------------------
/*Pre:
 *Post: Saca por la salida estándar las órdenes disponibles para ingresar en el programa.
 */
void ordenAyuda();

/*Pre: <<ficheroUsos>> y <<ficheroUsuarios>> son dos ficheros pertenecientes al sistema Bizi.
 *Post: Modifica la selección de ficheros <<ficheroUsos>> y <<ficheroUsuarios>>.
 *      La función no finaliza hasta que el usuario seleccione una opción disponible.
 */
void ordenFichero(char ficheroUsos[], char ficheroUsuarios[]);

/*Pre: <<argumento>> y <<nombreFicheroUsos>> son el nombre de dos ficheros de texto
 *Post: <<argumento>> es el nombre del fichero en el que se va a escribir información acerca de las 
 *      estaciones Bizi más usadas de acuerdo con el fichero <<nombreFicheroUsos>>.
 *      Adicionalmente se mostrarán por pantalla las primeras diez lineas del fichero correspondiente 
 *      al informe, de forma que muestre las ocho estaciones más utilizadas
 */
void ordenInforme(char argumento[], char nombreFicheroUsos[]);

/*Pre: <<argumento>> es el identificador de usuario del sistema Bizi 
 *Post: Muestra por pantalla el número de utilizaciones que el usuario <<argumento>>
 *      ha realizado, de acuerdo con los ficheros seleccionados actualmente.
 */
void ordenUsuario(char argumento[], const char ficheroUsos[]);

/*Pre: <<ficheroUsos>> y <<ficheroUsuarios>> son los ficheros del sistema Bizi seleccionados
 *      actualemente.
 *Post: Muestra el número de utilizaciones del sistema que han realizado hombres y mujeres, de 
 *      acuerdo con los ficheros seleccionados actualmente.
 */
void ordenEstadisticas(const char ficheroUsos[],const char ficheroUsuarios[]);


#endif // ORDENES_H_INCLUDED


