/*********************************************************************************
 * Programación 1. Práctica 6
 * Autores: Diego Marco Beisty 755232
 * Ultima revisión: 14 de diciembre de 2018
 * Resumen: Fichero de interfaz «bizi-estacion.h» de un módulo para trabajar con
 *          registros que representan estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#ifndef BIZI_ESTACION_H_INCLUDED
#define BIZI_ESTACION_H_INCLUDED

#include <istream>
using namespace std;

const int NUM_ESTACIONES = 130;
const int MAX_NOMBRE = 300;
const int MAX_LINEA = 1000;
const char DELIMITADOR = ';';
const int ID_MINIMO = 1;
const int ID_MAXIMO = 130;

struct Estacion {
   int id_estacion;
   char nombre[MAX_NOMBRE];
   int num_usos;
};



/* Pre:  El flujo «origen» está asociado con un fichero de texto con el formato de estaciones
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera , 
 *       <<estaciones>> es un array de registros de tipo <<Estaciones>> que representan
 *      las estaciones de bizi zaragoza
 *Post: Ha guardado en <<estaciones>> las caracteristicas de 
 *      las estaciones leidas del flujo <<origen>>
 */
void leer(istream& origen, Estacion estaciones[]);

/*
 * Pre:  La cadena de caracteres «rutaFicheroEstaciones» contiene la ruta de
 *       acceso y nombre de un fichero de estaciones Bizi que sigue la sintaxis
 *       establecida en el enunciado y que contiene información de
 *       «NUM_ESTACIONES» estaciones. El vector «estaciones» tiene
 *       «NUM_ESTACIONES» componentes.
 * Post: Si no ha habido problemas de lectura del fichero «rutaFicheroEstaciones»,
 *       la función ha devuelto «true» y se han leído los datos de las estaciones
 *       Bizi contenidos en el fichero
 *       indicado por «rutaFicheroEstaciones» y se han almacenado en el vector
 *       «estaciones» de forma tal que en cada componente «i» se almacena el
 *       identificador y el nombre de la estación de identificador «i» + 1 (es
 *       decir, en estaciones[0] se encuentra almacenada la información de la
 *       estación con identificador 1, en estaciones[1] se encuentra almacenada la
 *       estación con identificador 2 y así sucesivamente). La información sobre
 *       el número de usos de cada estación es 0 en todas ellas.
 *       Si no se ha podido leer el fichero «rutaFicheroEstaciones», se ha
 *       limitado a devolver «false».
 */
bool leerEstaciones(const char rutaFicheroEstaciones[], Estacion estaciones[]);


/*
 * Pre:  La cadena de caracteres «rutaFichero» representa la ruta de acceso y el
 *       nombre de un fichero de texto con el formato de usos del sistema Bizi
 *       establecido en el enunciado. El vector «estaciones» tiene
 *       «NUM_ESTACIONES» componentes donde se ha almacenado información sobre
 *       estaciones Bizi de forma tal que en cada componente «i» se almacena la
 *       información de la estación de identificador «i» + 1 (es decir, en
 *       estaciones[0] se encuentra almacenada la información de la estación con
 *       identificador 1, en estaciones[1] se encuentra almacenada la estación con
 *       identificador 2 y así sucesivamente). La información sobre
 *       el número de usos de cada estación es 0 en todas ellas.
 * Post: Si no ha habido problemas de lectura del fichero «rutaFichero», la
 *       función ha devuelto «true» y ha actualizado el número de usos de cada
 *       estación del vector «estaciones» de acuerdo con el contenido del fichero
 *       «rutaFichero», contabilizando como un uso tanto la retirada como la
 *       devolución de bicicletas. En caso contrario, se ha limitado a devolver
 *       «false».
 */
bool contarUsosEstaciones(const char rutaFichero[], Estacion estaciones[]);

/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de usos
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera.
 * Post: Ha intentado leer la línea mencionada en la precondición y, si no se han
 *       terminado los datos del fichero en dicho intento, ha actualizado el campo num_usos
 *       de un registro del array <<estaciones>>
 */
void leerUso(istream& f, Estacion estaciones[]);

/*
 * Pre:  La cadena de caracteres «rutaFichero» representa la ruta de acceso y el
 *       nombre de un fichero de texto con el formato de usos del sistema Bizi
 *       establecido en el enunciado. El vector «estaciones» tiene
 *       «NUM_ESTACIONES» componentes donde se ha almacenado información sobre
 *       estaciones Bizi de forma tal que en cada componente «i» se almacena la
 *       información de la estación de identificador «i» + 1 (es decir, en
 *       estaciones[0] se encuentra almacenada la información de la estación con
 *       identificador 1, en estaciones[1] se encuentra almacenada la estación con
 *       identificador 2 y así sucesivamente). La información sobre
 *       el número de usos de cada estación es 0 en todas ellas.
 * Post: Si no ha habido problemas de lectura del fichero «rutaFichero», la
 *       función ha devuelto «true» y ha actualizado el número de usos de cada
 *       estación del vector «estaciones» de acuerdo con el contenido del fichero
 *       «rutaFichero», contabilizando como un uso tanto la retirada como la
 *       devolución de bicicletas. En caso contrario, se ha limitado a devolver
 *       «false».
 */
bool contarUsosEstaciones(const char rutaFichero[], Estacion estaciones[]);

/*Pre:
 *Post: Devuelve <<true>> si numero de usos de <<uno>> es menor que el numero de usos de <<otro>>
 */
bool esMenor (Estacion uno, Estacion otro);

/*
 * Pre:  El vector «estaciones» tiene «NUM_ESTACIONES» componentes.
 * Post: El contenido del vector «estaciones» es una permutación del contenido
 *       inicial del mismo que está ahora ordenado de mayor a menor número de usos
 *       de las estaciones.
 */
void ordenarPorUso(Estacion estaciones[]);


/*
 * Pre:  ---
 * Post: Si la función ha podido crear un fichero de texto cuyo nombre es el
 *       contenido de la cadena de caracteres «nombreFichero», la función ha
 *       devuelto «true» y  ha escrito en el fichero creado la
 *       siguiente información sobre cada estación almacenada en el vector
 *       «estaciones»: puesto, número de usos, identificador de la estación y
 *       nombre, con un formato similar al siguiente:
 *
 *           Puesto    Usos  Id Nombre
 *           ------ ------- --- ---------------------------------------
 *                1   47064  16 Plaza España
 *                2   42306  67 Avda. G. Gómez de Avellaneda - C/ Clara Campoamor
 *                3   40251  47 Plaza San Francisco - Universidad
 *           ...
 */
bool escribirInforme(const char nombreFichero[], const Estacion estaciones[]);

/*
 * Pre:  ---
 * Post: Si la función ha podido crear un fichero de texto cuyo nombre es el
 *       contenido de la cadena de caracteres «nombreFichero», la función ha
 *       devuelto «true» y  ha escrito en la pantalla las primeras 8 lineas almacenads en el vector
 *       «estaciones»: puesto, número de usos, identificador de la estación y
 *       nombre, con un formato similar al siguiente:
 *
 *           Puesto    Usos  Id Nombre
 *           ------ ------- --- ---------------------------------------
 *                1   47064  16 Plaza España
 *                2   42306  67 Avda. G. Gómez de Avellaneda - C/ Clara Campoamor
 *                3   40251  47 Plaza San Francisco - Universidad
 *           ...
 */
void escribirInformePantalla(const Estacion estaciones[]);

#endif // BIZI_ESTACION_H_INCLUDED