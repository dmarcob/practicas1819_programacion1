/*********************************************************************************
 * Programación 1. Práctica 6
 * Autor: Diego Marco Beisty, 755232
 * Fichero: bizi-usos.cpp
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de implementacion «bizi-usos.cpp» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/
#include "bizi-usos.h"
#include "bizi-estacion.h"
#include "bizi-usuario.h"
#include <fstream>
#include <iostream>
using namespace std;
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
void leerUso(istream& f, UsoBizi& uso) {
    f >> uso.id_usuario; //Leo el id de usuario
    f.ignore(); //ignoro el ';' despues del id de usuario
    f.ignore(MAX_LINEA2,DELIMITADOR2); //ignoro la fecha de retirada
    f >> uso.estacion_retirada;
    f.ignore(); //ignoro el ';' tras el identificador de estacion
    f.ignore(MAX_LINEA2,DELIMITADOR2); //ignoro la fecha de devolución
    f >> uso.estacion_devolucion;
    f.ignore(MAX_LINEA2,'\n'); //ignoro lo que pueda quedar de linea
}

/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de usos
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera.
 * Post: Ha intentado leer la línea mencionada en la precondición y, si no se han
 *       terminado los datos del fichero en dicho intento, ha actualizado el campo num_usos
 *       de un registro del array <<estaciones>>
 */
void leerUso(istream& f, Estacion estaciones[]) {
    int retirada; //id estacion retirda
    int devolucion; //id estacion devolucion
    //leo de flujo f
    f.ignore(MAX_LINEA,DELIMITADOR); //Ignoro el id de usuario
    f.ignore(MAX_LINEA,DELIMITADOR); //ignoro la fecha de retirada
    f >> retirada; 
    f.ignore(); //ignoro el ';' tras el identificador de estacion
    f.ignore(MAX_LINEA,DELIMITADOR); //ignoro la fecha de devolución
    f >> devolucion; 
    f.ignore(MAX_LINEA,'\n'); //ignoro lo que pueda quedar de linea
    //actualizo registros del array <<estaciones>>
    if ( (retirada <= 130 && retirada > 0) && (devolucion <= 130 && devolucion > 0)) {
    estaciones[retirada-1].num_usos++; //incremento el numero de usos de la estaicon donde se retira la bici
    estaciones[devolucion-1].num_usos++; //incremento el numero de usos de la estacion donde se devuelve la bici
    }
}

/*Pre: <<uso>> representa un uso de una bicicleta cuyo formato está especificado en el 
 *      enunciado de la práctica. <<cumple>> es <<true>> si el uso es circular o traslado (puede ser que el uso no cumpla
 *      las especificaciones, entonces seria <<false>>)
 *Post: Ha devuelto <<true>> si la estacion origen y destino son la misma estacion, devuelve <<false>>, si la estacion origen y destino
 *      no son la misma estacion, o el uso no cumple las especificaciones
 */
bool circular(UsoBizi uso, bool& cumple) {
    bool circular = false; //<<true>> es circular, <<false>> no es circular o no cumple especificaciones
   cumple = false; //<<true>> es circular o traslado, <<false>> el uso no cumple las especificaciones
    int ret = uso.estacion_retirada;
    int dev = uso.estacion_devolucion;
    if(ret >= ID_MINIMO2 && dev >= ID_MINIMO2) {
        //solo tengo en cuenta las estaciones cuyo identificador es mayor al ID_MINIMO
        circular = uso.estacion_retirada == uso.estacion_devolucion;
        cumple = true; //el uso cumple las especificaciones
    }
    return circular;
}

/*Pre:   uso en un registro que representa un uso de una bicicleta.
 *Post: «traslados» es el número de usos entre estaciones distintas del sistema 
 *       Bizi Zaragoza y «usosCirculares» es el número de
 *       usos contenidos en dicho fichero que tienen como origen y destino la
 *       misma estación.
 */
void contador (UsoBizi uso,int& traslados, int& usosCirculares) {
    
    bool cumple = false; //<<false>> indica que el uso no es ni circular ni traslado
        if (circular(uso, cumple)) {
            //caso en que el uso tiene como origen y destino la misma estacion y el uso cumple con las especificaciones
            usosCirculares++;
        }
        else if (cumple) {
            //caso en que el uso tiene como origen y destino estaciones distintas y el uso cumple con las especificaciones
            traslados++;
        }
        else { 
            cerr <<" El uso no cumple con las especificaciones (id estacion incorrecta,..) o el fichero esta vacio" << endl;} 
}
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
bool contarUsos(const char rutaFichero[], int& traslados, int& usosCirculares) {
    bool correcto = false; //Indica si se ha podido abrir y leer correctamente el fichero <<true>>, en caso contrario <<false>>
    ifstream f(rutaFichero); //Declaro un flujo de entrada y lo asocio con la ruta <<rutaFichero>>
    if (f.is_open()) {
        UsoBizi uso;
        correcto = true; //se ha podido abrir el fichero
        f.ignore(MAX_LINEA2,'\n'); //Intento ignorar la linea de cabecera
        if (!f.eof()) {
            //caso en que he podido ignorar la primera linea (no ha encontrado el caracter fin de fichero)
            leerUso(f,uso); //Intento leer una nueva linea, en caso afirmativo relleno el registro UsoBizi
            while (!f.eof()) { 
                contador (uso,traslados,usosCirculares);
                //caso en el que la llamada leerUso(f,array[i]), ha conseguido leer la siguiente linea
                leerUso(f,uso); //Intento leer una nueva linea, en caso afirmativo relleno el registro UsoBizi
            }
            
        }
        else {cerr << "Error en la cabecera del fichero" << endl;}
        f.close();
    }
    return correcto;
}


/*Pre:   <<uso>> es un registro que representa un uso de una bicicleta.
 *       <<idUsuario>> es el identificador de un usuario del sistema bizi.
 *Post: <<viaje>> representa el numero de viajes que ha realizado el usuario <<idUsuario>>.
 */
void contador2 (UsoBizi uso,int idUsuario,int& viajes) {
   
    if (uso.id_usuario == idUsuario) {
        //caso en que el usuario <<idUsuario>> usa el sistema bizi
        viajes++;
    }
}

/*Pre:  <<idUsuario>>, es el identificador de un usuario del sistema bizi especificado en el 
 *      enunciado. <<ficheroUsos>> es la ruta y nombre de un fichero de texto de usos del sistema
 *      bizi.
 *Post: Si ha podido abrir el fichero <<ficheroUsos>>, ha devuelto <<true>>, y ha almacenado en <<viajes>
 *      el numero de viajes que ha realizado el usuario <<idUsuario>>. En cso contrario ha devuelto <<false>>
 */
bool viajesUsuario(int idUsuario,const char ficheroUsos[], int& viajes) {
    viajes = 0; //Inicializo los viajes realizados a 0
     bool correcto = false; //Indica si se ha podido abrir y leer correctamente el fichero <<true>>, en caso contrario <<false>>
    ifstream f(ficheroUsos); //Declaro un flujo de entrada y lo asocio con la ruta <<ficheroUsos>>
    if (f.is_open()) {
        UsoBizi uso;
        correcto = true; //se ha podido abrir el fichero
        f.ignore(MAX_LINEA2,'\n'); //Intento ignorar la linea de cabecera
        if (!f.eof()) {
            //caso en que he podido ignorar la primera linea (no ha encontrado el caracter fin de fichero)
            leerUso(f,uso); //Intento leer una nueva linea, en caso afirmativo relleno el registro UsoBizi
            while (!f.eof()) { 
                contador2 (uso,idUsuario,viajes);
                //caso en el que la llamada leerUso(f,array[i]), ha conseguido leer la siguiente linea
                leerUso(f,uso); //Intento leer una nueva linea, en caso afirmativo relleno el registro UsoBizi
            }
            
        }
        else {cerr << "Error en la cabecera del fichero" << endl;}
        f.close();
    }
    return correcto;
}


/*Pre: <<ficheroUsos> representa los usos del sistema Bizi, <<vector>> almacena todos los usuarios del sistema Bizi.
 *      <<totalUsuarios>> representa el numero total de usuarios del sistema Bizi. 
 *Post: Lee los usos de <<ficheroUsos>> y por cada uso, busca en <<vector>> el género del usuario que ha hecho ese
 *      uso.<<hombres>> y <<mujeres>> reprentan el numero total de usos por mujeres y por hombres.
 *      el numero de 
 *      Devuelve true si ha podido abrir el fichero <<ficheroUsos>>, devuelve false en caso contrario.
 */

bool contarEstadisticas(const char ficheroUsos[], Usuario vector[],int totalUsuarios,int& hombres, int& mujeres ) {
     hombres = 0; //valor inicial de hombres que usan Bizi a 0
     mujeres = 0; //valor inicial de mujeres que usan Bizi a 0
     bool correcto = false; //Indica si se ha podido abrir y leer correctamente el fichero <<true>>, en caso contrario <<false>>
     int id;
     ifstream f(ficheroUsos); //Declaro un flujo de entrada y lo asocio con la ruta <<ficheroUsos>>
     if (f.is_open()) {
        UsoBizi uso;
        correcto = true; //se ha podido abrir el fichero
        f.ignore(MAX_LINEA2,'\n'); //Intento ignorar la linea de cabecera
        if (!f.eof()) {
            //caso en que he podido ignorar la primera linea (no ha encontrado el caracter fin de fichero)
            leerUso(f,uso); //Intento leer una nueva linea, en caso afirmativo relleno el registro UsoBizi
            while (!f.eof()) { 
                //caso en el que la llamada leerUso(f,array[i]), ha conseguido leer la siguiente linea
                if( (id = buscarUsuario (uso.id_usuario,vector,totalUsuarios)) == -1) {cerr << "usuario " << uso.id_usuario << "no existe" << endl;}
                if (vector[id].sexo == 'M') {
                    hombres++;
                }
                else {mujeres++;}
                leerUso(f,uso); //Intento leer una nueva linea, en caso afirmativo relleno el registro UsoBizi
            }
            
        }
        else {cerr << "Error en la cabecera del fichero" << endl;}
        f.close();
    }
    return correcto;
}