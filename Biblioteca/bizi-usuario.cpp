/*********************************************************************************
 * Programación 1. 
 * Autor: Diego Marco Beisty, 755232
 * Fichero: bizi-usuario.cpp
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de implementación «bizi-usuario.cpp» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/
#include "bizi-usuario.h"
#include <fstream>
#include <iostream>
using namespace std;
/*Pre:   La cadena de caracteres «rutaFichero» representa la ruta de acceso y el
 *       nombre de un fichero de texto con el formato de usos del sistema Bizi
 *       establecido en el enunciado. El array de usuarios <<usuarios>> representa
 *       los usuarios leidos del fichero de texto de ruta y nombre <<rutaFichero>>.
 *Post:  Si no ha habido problemas de lectura del fichero «rutaFichero», la
 *       función ha devuelto el numero de datos de tipo Usuario leidos
 *       y ha actualizado el número de Usuarios de cada
 *       del vector «usuarios» de acuerdo con el contenido del fichero
 *       «rutaFichero». En caso contrario, ha devuelto -1.
 */
int leerUsuarios( const char rutaFichero[], Usuario usuarios[]) {
    int numUsuarios = 0; //numero de usuarios leidos de fichero
    ifstream f(rutaFichero); //Declaro un stream de entrada e intento abrir el fichero <<rutaFichero>>
    if (f.is_open()) {
        //caso en que el fichero esta abierto
        f.ignore(MAX_LINEA3,'\n'); //Intento ignorar la linea de cabecera
        if (!f.eof()) {
            //caso en que he podido ignorar la linea de cabecera
            int i = 0;
            f >> usuarios[i].id_usuario; //Intento leer el id de usuario
            while (!f.eof()) {
                //He conseguido leer el id de usuario
                f.ignore(); //ignoro el ';'
                usuarios[i].sexo = f.get();
                f.ignore(MAX_LINEA3,'\n'); //Ignoro el resto de linea
                i++;
                f >> usuarios[i].id_usuario; //Intento leer el siguiente id de usuario
                
            }
            numUsuarios = i;
        }
    }
    else{ cerr << "No se ha podido abrir el fichero " << rutaFichero << endl; 
          numUsuarios = -1;
          }
    return numUsuarios;
}

/*Pre: <<identificador>> representa le numero de identificacion de un usuario del sistema
 *      bizi especificado en el enunciado. el array de usuarios << usuarios>> representa los 
 *      usuarios pertenecientes a este sistema. <<totalUsuarios>> representa el numero total 
 *      de usuarios que pertenecen al sistema <<bizi>>.
 *Post: Ha devuelto el índice del usuario cuyo identificador es <<identificador>> y que se encuentra
 *      indexado en el array <<usuarios>>. En caso de no encontrarlo, devuelve -1
 */
int buscarUsuario (int identificador,Usuario usuarios[],int totalUsuarios) {
    int inferior = 0; //Declaro extremo inferior del array
    int superior = totalUsuarios -1; //declaro extremo superior del array
    int medio; //elemento medio entre extremo inferior y superior
    while (inferior < superior) {
         medio = (inferior + superior) / 2; 
        if (usuarios[medio].id_usuario < identificador ) {
            //el identificador buscado es mayor que el identificador usuarios[medio].id_usuario
            inferior = medio + 1; 
        }
        else  {
            //El identificador buscado es menor o igual que el identificador usuarios[medio].id_usuario
            superior = medio;
        }
        
    }
    // inferior == superior
    if (usuarios[superior].id_usuario != identificador) {
        cerr << "Identificador de usuario " << identificador << " incorrecto." << endl; 
        superior = -1;
    }
    return superior; //Devuelve el indice del usuario buscado o -1 en caso de no existir  
}