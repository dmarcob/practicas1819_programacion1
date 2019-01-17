/*********************************************************************************
 * Programación 1. 
 * Autor: Diego Marco Beisty, 755232
 * Fichero: Trabajo.cpp
 * Fecha: 31 Diciembre, 2018
 * Resumen: Modulo principal del trabajo obligatorio de programacion 1 2018-19
\********************************************************************************/

#include "../../Biblioteca/ordenes.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


/*Pre:
 *Post:Intérprete de órdenes que reiteradamente solicita una orden al usuario y la ejecuta, hasta que el usuario
 *     de por concluida la ejecución del programa. Cuando el pograma comienza su ejecución, solicita al usuario
 *     el conjunto de datos con el que va a trabajar inicialmente. El programa ofrecerá las opciones disponibles 
 *     actualmente y solicitará una. A continuación el programa informará de cuales son las órdenes que acepta.
 *     Después el programa solicitará interactivamente una de las órdenes disponibles.
 *     La orden FICHERO permite modificar la selección de ficheros actual.
 *     La orden INFORME muestra las estaciones mas usadas de acuerdo con el fichero de usos actualmente seleccionado.
 *     La orden USUARIO muestra el  numero de viajes realizados por un usuario de acuerdo con los ficheros seleccionados.
 *     La orden ESTADISTICAS informa del número de utilizaciones que han realizado hombres y mujeres, del sistema Bizi.
 *     La orden FIN hace que finalice el programa.
 */
int main () {
    //Condición de iteración bucle while
    bool finalizar = false;
    //-----------DATOS ÓRDENES DE USUARIO-----------------------------------------------------------
    char orden[ORDER];       //aqui guardaré la orden ingresada por el usuario
    char argumento[ORDER];   //aqui guardaré el argumento ingresado por el usuario 
    char ayuda[ORDER] = "AYUDA";
    char fichero[ORDER] = "FICHERO";
    char informe[ORDER] = "INFORME";
    char usuario[ORDER] = "USUARIO";
    char estadisticas[ORDER] = "ESTADISTICAS";
    char fin[ORDER] = "FIN";
    //----------DATOS FICHEROS DE TEXTO------------------------------------------------------------
    char ficheroUsos[ORDER]; //Ruta completa del fichero de usos seleccionado por el usuario
    char ficheroUsuarios[ORDER]; //Ruta completa del fichero de usuarios seleccionado por el usuario
    //----------COMPORTAMIENTO PROGRAMA--------------------------------------------------------
    ordenFichero(ficheroUsos,ficheroUsuarios);  //Actualizar fichero de usos y usuarios
    ordenAyuda();  //mostrar comandos disponibles
    while (!finalizar) {
        //caso en que usuario no ha insertado la orden <<fin>>
        ingresarOrden(orden,argumento,informe,usuario); //recibo orden de la entrada estándar
        if (strcmp(orden, ayuda) == 0) {
            //caso en que  orden = "AYUDA"
            ordenAyuda();
        }
        else if (strcmp(orden,fichero) == 0) {
            //caso en que orden = "FICHERO"
            ordenFichero(ficheroUsos, ficheroUsuarios);
        }
        else if (strcmp(orden,informe) == 0) {
            //caso en que orden = "INFORME"
            ordenInforme(argumento,ficheroUsos);
        }
        else if ( strcmp(orden, usuario) == 0){
            //caso en que orden = "USUARIO"
            ordenUsuario(argumento,ficheroUsos);
        }
        else if (strcmp(orden,estadisticas) == 0) {
            //caso en que orden = "ESTADISTICAS"
            ordenEstadisticas(ficheroUsuarios, ficheroUsos);
        }
        else if (strcmp(orden,fin) == 0) {
            //caso en que orden = "FIN"
            finalizar = true; 
        }
        else {
            //caso en que la orden es incorrecta
            cout << "Orden " << "\"" << orden << "\"" << " desconocida" << endl <<endl;
        }
   }
   //Se ha ingresado la orden <<FIN>>, programa acaba.
    return 0;
}