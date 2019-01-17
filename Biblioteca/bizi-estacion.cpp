
/*********************************************************************************
 * Programación 1. Práctica 6
 * Autores: Diego Marco Beisty 755232
 * Ultima revisión: 14 de diciembre de 2018
 * Resumen: Fichero de implementación «bizi-estacion.cpp» de un módulo para trabajar con
 *          registros que representan estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "bizi-estacion.h"
#include "bizi-usos.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;



/* Pre:  El flujo «origen» está asociado con un fichero de texto con el formato de estaciones
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera , 
 *       <<estaciones>> es un array de registros de tipo <<Estaciones>> que representan
 *      las estaciones de bizi zaragoza
 *Post: Ha guardado en <<estaciones>> las caracteristicas de 
 *      las estaciones leidas del flujo <<origen>>
 */
void leer(istream& origen, Estacion estaciones[]) {
   // char url[MAX_LINEA]; //Guardare todo el link <url-id>
    int idN; //Guardare el id de la estacion convertido del array <<id>>
    char name[MAX_LINEA]; //Guardare el nombre de la estacion
    int usos = 0;//numero de usos de cada estacion inicializado a 0
  //  origen.getline(url,MAX_LINEA,';'); //Intento extraer <url-id>
    origen.ignore(MAX_LINEA,'/'); //Intento ignorar el primer fragmento de la URL
    while (!origen.eof()) {
        //He ignorar el primer fragmento de la URL
        //enteroId(url,idN);
        for (int i = 0; i < 6; i++){
            origen.ignore(MAX_LINEA,'/'); //ignoro trozos del URL
        }
        origen >> idN;
        origen.ignore(MAX_LINEA,DELIMITADOR); //ignoro lo que queda de URL    ";
        origen.ignore(MAX_LINEA,DELIMITADOR); //lgnoro <url-acerca-de>
        origen.ignore(MAX_LINEA,'"'); //Ignoro comillas iniciales del nombre
        origen.getline(name,MAX_LINEA,'"'); //Leo el nombre de la estacion
        origen.ignore(MAX_LINEA,DELIMITADOR);//Ignoro delimitador despues del nombre
        origen.ignore(MAX_LINEA,'\n'); //Ignoro todo hasta encontrar un salto de linea '\n'
        //Actualizo el registo estaciones [idN-1]
        estaciones[idN-1].id_estacion = idN;
        strcpy(estaciones[idN-1].nombre,name);
        estaciones[idN-1].num_usos = usos;
        //Intento leer una nueva linea
        origen.ignore(MAX_LINEA,'/'); //Intento ignorar el primer fragmento de la URL siguiente
    }
    
}


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
bool leerEstaciones(const char rutaFicheroEstaciones[], Estacion estaciones[]) {
     bool correcto = false; //<<false no se ha podido abrir o leer, <<true>> se ha podido abrir y leer
     ifstream origen(rutaFicheroEstaciones);
     if(origen.is_open()) {
         correcto = true; //se ha podido abrir
         //ignoro la primera linea de cabecera
         origen. ignore(MAX_LINEA,'\n');
         //leo del flujo origen el resto de lineas y actualizo estaciones[]
         leer (origen, estaciones);
         //cierro el flujo origen
         origen.close();
     }
     return correcto;
}


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
bool contarUsosEstaciones(const char rutaFichero[], Estacion estaciones[]) {
    bool correcto = false; //Indica si se ha podido abrir y leer correctamente el fichero <<true>>, en caso contrario <<false>>
    ifstream f(rutaFichero); //Declaro un flujo de entrada y lo asocio con la ruta <<rutaFichero>>
    if (f.is_open()) {
        correcto = true; //se ha podido abrir el fichero
        f.ignore(MAX_LINEA,'\n'); //Intento ignorar la linea de cabecera
        if (!f.eof()) {
            
            //caso en que he podido ignorar la primera linea (no ha encontrado el caracter fin de fichero)
             //Intento leer una nueva linea, en caso afirmativo actualizo el campo num_usos del registro <<estaciones[i]>>
            leerUso(f,estaciones);
            while (!f.eof()) { 
                //caso en el que la llamada leerUso(f,estaciones), ha conseguido leer la siguiente linea
                leerUso(f,estaciones); //Intento leer una nueva linea
            }
            
        }
        else {cerr << "Error en la cabecera del fichero" << rutaFichero << endl;}
        f.close();
    }
    return correcto;
}
/*Pre:
 *Post: Devuelve <<true>> si numero de usos de <<uno>> es menor que el numero de usos de <<otro>>
 */
bool esMenor (Estacion uno, Estacion otro) {
    return uno.num_usos < otro.num_usos;
} 

/*
 * Pre:  El vector «estaciones» tiene «NUM_ESTACIONES» componentes.
 * Post: El contenido del vector «estaciones» es una permutación del contenido
 *       inicial del mismo que está ahora ordenado de mayor a menor número de usos
 *       de las estaciones.
 */
void ordenarPorUso(Estacion estaciones[]) {
    for (int i = 0; i < NUM_ESTACIONES - 1; i++) {
        int mayor = i;
        for (int j = i+1; j < NUM_ESTACIONES; j++) {
            if (esMenor(estaciones[mayor],estaciones[j])) {
                //caso en que estaciones[mayor].num_usos es menor a estaciones[j].num_usos
                mayor = j; 
            }
        }
        if (mayor != i) {
            //permuto si el elemento con el mayor numero de usos es distinto a <<i>>
            Estacion aux = estaciones[i];
            estaciones[i] = estaciones[mayor];
            estaciones[mayor] = aux;
        }
    }
}



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
bool escribirInforme(const char nombreFichero[], const Estacion estaciones[]) {
    bool correcto = false;
    ofstream destino(nombreFichero);
    if(destino.is_open()) {
        correcto = true;
        destino << "Puesto    Usos  Id Nombre" << endl;
        destino << "------ ------- --- ---------------------------------------" << endl;
        for (int i = 0; i < NUM_ESTACIONES; i++) {
            destino << setw(6) << i+1 << setw(8) << estaciones[i].num_usos << setw(4) << estaciones[i].id_estacion << " " << estaciones[i].nombre << endl;
        }
        destino.close();
    }
    return correcto;
}

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
void escribirInformePantalla(const Estacion estaciones[]) {
        const int MAX = 8;
        cout << "Puesto    Usos  Id Nombre" << endl;
        cout << "------ ------- --- ---------------------------------------" << endl;
        for (int i = 0; i < MAX; i++) {
            cout << setw(6) << i+1 << setw(8) << estaciones[i].num_usos << setw(4) << estaciones[i].id_estacion << " " << estaciones[i].nombre << endl;
        }
}