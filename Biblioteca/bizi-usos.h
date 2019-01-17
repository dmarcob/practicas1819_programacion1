/*********************************************************************************
 * Programación 1. Práctica 6
 * Autor: Diego Marco Beisty, 755232
 * Fichero: bizi-usos.h
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de interfaz «bizi-usos.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#ifndef BIZI_USOS_H_INCLUDED
#define BIZI_USOS_H_INCLUDED

#include <istream>
#include "bizi-estacion.h"
#include "bizi-usuario.h"
using namespace std;
const int NUM_ESTACIONES2 = 130;
const int MAX_NOMBRE2 = 300;
const int MAX_LINEA2 = 1000;
const char DELIMITADOR2 = ';';
const int ID_MINIMO2 = 1;
const int ID_MAXIMO2 = 130;
struct UsoBizi {
    int id_usuario; //Número de identificacion del usuario de la biciclera
    int estacion_retirada; //Número de identificación de la estación de la que se ha retirado la bicicleta
    int estacion_devolucion;//Número de identificación de la estación en la que se ha devuelto la bicicleta
};



//---------------------------FUNCIONES AUXILIARES-----------------------------------------------------------------------
/*Pre: <<uso>> representa un uso de una bicicleta cuyo formato está especificado en el 
 *      enunciado de la práctica. <<cumple>> es <<true>> si el uso es circular o traslado (puede ser que el uso no cumpla
 *      las especificaciones, entonces seria <<false>>)
 *Post: Ha devuelto true si la estacion origen y destino son la misma estacion, devuelve <<false>>, si la estacion origen y destino
 *      no son la misma estacion, o el uso no cumple las especificaciones
 */
bool circular(UsoBizi uso, bool& cumple);

/*Pre:   <<uso>> representa un registro de un uso de una bicicleta
 *Post: «traslados» es el número de usos entre estaciones distintas del sistema 
 *       Bizi Zaragoza y «usosCirculares» es el número de
 *       usos contenidos en dicho fichero que tienen como origen y destino la
 *       misma estación.
 */
void contador (UsoBizi uso,int& traslados, int& usosCirculares);

/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de usos
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera.
 * Post: Ha intentado leer la línea mencionada en la precondición y, si no se han
 *       terminado los datos del fichero en dicho intento, ha actualizado el campo num_usos
 *       de un registro del array <<estaciones>>
 */
void leerUso(istream& f, Estacion estaciones[]);

/*Pre:   <<uso>> es un registro que representa un uso de una bicicleta.
 *       <<idUsuario>> es el identificador de un usuario del sistema bizi.
 *Post: <<viaje>> representa el numero de viajes que ha realizado el usuario <<idUsuario>>.
 */
void contador2 (UsoBizi uso,int idUsuario,int& viajes);

/*Pre:  <<idUsuario>>, es el identificador de un usuario del sistema bizi especificado en el 
 *      enunciado. <<ficheroUsos>> es la ruta y nombre de un fichero de texto de usos del sistema
 *      bizi.
 *Post: Si ha podido abrir el fichero <<ficheroUsos>>, ha devuelto <<true>>, y ha almacenado en <<viajes>
 *      el numero de viajes que ha realizado el usuario <<idUsuario>>. En cso contrario ha devuelto <<false>>
 */
bool viajesUsuario(int idUsuario,const char ficheroUsos[], int& viajes);

/*Pre: <<ficheroUsos> representa los usos del sistema Bizi, <<vector>> almacena todos los usuarios del sistema Bizi.
 *      <<totalUsuarios>> representa el numero total de usuarios del sistema Bizi. 
 *Post: Lee los usos de <<ficheroUsos>> y por cada uso, busca en <<vector>> el género del usuario que ha hecho ese
 *      uso.<<hombres>> y <<mujeres>> reprentan el numero total de usos por mujeres y por hombres.
 *      el numero de 
 *      Devuelve true si ha podido abrir el fichero <<ficheroUsos>>, devuelve false en caso contrario.
 */

bool contarEstadisticas(const char ficheroUsos[], Usuario vector[],int totalUsuarios, int& hombres, int& mujeres);
//--------------------------FUNCIONES OBLIGATORIAS---------------------------------------------------------------------
/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de usos
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera.
 * Post: Ha intentado leer la línea mencionada en la precondición y, si no se han
 *       terminado los datos del fichero en dicho intento, ha almacenado en los
 *       campos del parámetro «uso» el identificador del usuario al que
 *       corresponde la utilización de la línea leída y los códigos de las
 *       estaciones de retira y devolución de la bicicleta.
 */
void leerUso(istream& f, UsoBizi& uso);


/*
 * Pre:  La cadena de caracteres «rutaFichero» respresenta la ruta de acceso y el
 *       nombre de un fichero de texto con el formato de usos del sistema Bizi
 *       establecido en el enunciado.
 * Post: Si el fichero de nombre «rutaFichero» se ha podido abrir y leer
 *       correctamente, la función ha devuelto «true», «traslados» es el número de
 *       usos entre estaciones distintas del sistema Bizi Zaragoza contenidos en
 *       el fichero de nombre «rutaFichero» y «usosCirculares» es el número de
 *       usos contenidos en dicho fichero que tienen como origen y destino la
 *       misma estación. En caso contrario, la función ha devuelto «false».
 */
bool contarUsos(const char rutaFichero[], int& traslados, int& usosCirculares);




#endif // BIZI_USOS_H_INCLUDED