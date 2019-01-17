/*********************************************************************************
 * Programación 1. 
 * Autor: Diego Marco Beisty, 755232
 * Fichero: ordenes.cpp
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de implementacion «ordenes.cpp» de un módulo para implementar los comandos
 *          usados en Trabajo.cpp
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "ordenes.h"
#include "bizi-usos.h"
#include "bizi-usuario.h"
#include "bizi-estacion.h"


/*Pre:  <<fichero>> almacena caracteres que pueden estar en mayúscula o minúscula
 *Post: <<fichero>> almacena caracteres que están en mayúscula
 */
void mayusculas(char fichero[]) {
    int i = 0;
    while (fichero[i] != '\0') {
         fichero[i] = toupper(fichero[i]);
         i++;
     }
}

/*Pre: <<orden>> es una orden ingresada por el usuario. <<informe>> corresponde a la orden "INFORME".
 *     <<usuario>> corresponde a la orden "USUARIO".
 *Post: Ha devuelto <<true>> si <<orden>> es igual a <<informe>> o <<usuario>>.
 */
bool tieneArgumento (const char orden[],const char informe[],const char usuario[]) {
    bool argumento = false; //<<false>> indica que a la orden <<orden>> no le sigue un argumento
    if (strcmp(orden,informe) == 0) {argumento = true;}
    else if (strcmp(orden,usuario) == 0) {argumento = true;}
    return argumento;
}


/*Pre:  <<orden>> es una orden ingresada por el usuario.<<informe>> corresponde a la orden "INFORME".
 *      <<usuario>> corresponde a la orden "USUARIO".
 *Post: Ha leido texto de la entrada estándar hasta encontrar un " " o "\n", y lo ha guardado en <<orden>>.
 *      Si <<orden>> es igual a <<informe>> o <<usuario>>, ha seguido leyendo de la entrada estandar y lo 
 *      ha guardado en <<argumento>>.
 */
void ingresarOrden(char orden[],char argumento[],const char informe[],const char usuario[]) {
    cout << endl;
     cout << "Orden: ";
     cin >> orden;
     //paso <<orden>> a mayusculas
     mayusculas(orden);
     if(tieneArgumento(orden,informe,usuario)) {
         //caso en que <<orden>> es la orden "INFORME" o "USUARIO"   
         cin >> argumento; //Extraigo de la entrada estandar el argumento
     }
}


//-------------------------------ÓRDENES-------------------------------------------------------------------

/*Pre:
 *Post: Saca por la salida estándar las órdenes disponibles para ingresar en el programa.
 */
void ordenAyuda() {
    cout << endl;
    cout << "ORDENES DISPONIBLES" << endl;
    cout << "====================" << endl;
    cout << "AYUDA:   muestra esta pantalla de ayuda." <<endl;
    cout << "FICHERO: permite elegir los ficheros de usos y usuarios" << endl;
    cout << "INFORME: <nombre-fichero>: escribe en el fichero especificando un informe con el numero" << endl;
    cout << "de usos de las estaciones segun los ficheros seleccionados actualmente" << endl;
    cout << "USUARIO: <id-usuarios>: informa acerca del numero de usos realizados por el usuario" << endl;
    cout << "especificado" << endl;
    cout << "ESTADISTICAS: informa sobre el numero de usos de hombres y mujeres segun el contenido" << endl;
    cout << "de los fichero seleccionados actualmente." << endl;
    cout << "FIN:     termina la ejecucion de este programa" <<endl;
}


/*Pre: <<ficheroUsos>> y <<ficheroUsuarios>> son dos ficheros pertenecientes al sistema Bizi.
 *Post: Modifica la selección de ficheros <<ficheroUsos>> y <<ficheroUsuarios>>.
 *      La función no finaliza hasta que el usuario seleccione una opción disponible.
 */
void ordenFichero(char ficheroUsos[], char ficheroUsuarios[]) {
    char rutaUsos[MAX_RUTA] = "../../Datos/Bizi/usos-"; //ruta común a cualquier fichero de usos
    char rutaUsuarios[MAX_RUTA] = "../../Datos/Bizi/usuarios-"; //ruta común a cualquier fichero de usuarios
    char anho[ORDER]; //año del fichero
    char extension[MAX_RUTA] = ".csv";
    int param1; //Lo uso como parametro para contarUsos()
    int param2; //Lo uso como parametro para contarUsos()
    bool correcto = false; //<<false>> indica que los ficheros introducidos no son correctos
    while (!correcto) {
        //caso en que no ha conseguido abrir el fichero ingresado
        cout << "Eleccion de ficheros de usos y usuarios. Opciones disponibles:" << endl;
        cout << "16: octubre 2016 a marzo 2017" <<endl;
        cout << "17: marzo 2017 a agosto 2017" <<endl;
        cout << "Introduzca una opcion: ";
        cin >>anho;
        strcpy(ficheroUsos,rutaUsos); //ficheroUsos = "../..Datos/Bizi/usos-"
        strcat(ficheroUsos,anho);     //ficheroUsos = "../..Datos/Bizi/usos-nn"
        strcat(ficheroUsos,extension);//ficheroUsos = "../..Datos/Bizi/usos-nn.csv"
        
        strcpy(ficheroUsuarios,rutaUsuarios); //ficheroUsuarios = "../..Datos/Bizi/usuarios-"
        strcat(ficheroUsuarios,anho); //ficheroUsuarios = "../..Datos/Bizi/usuarios-nn"
        strcat(ficheroUsuarios,extension); //ficheroUsuarios = "../..Datos/Bizi/usuarios-nn.csv"
        
        if (contarUsos(ficheroUsos,param1,param2)) {
            //caso que que el fichero de usos existe
            correcto = true;
            cout << "El fichero " << "\"" << ficheroUsos << "\"" << " existe y contiene " << param1 + param2 << " utilizaciones." << endl;
            //por lo tanto el fichero de usuarios tambien existirá
            Usuario vector[MAX_USUARIOS];
            if ((param1 = leerUsuarios(ficheroUsuarios,vector)) != -1) {
                //caso en que ha leido correctamente del fichero de usuarios
                cout << "El fichero " << "\"" << ficheroUsuarios << "\"" << " existe y contiene " << param1 << " usuarios." << endl;
            }
        }
        else { cerr << "No se ha podido abrir el fichero " << "\"" << ficheroUsos <<"\"." << endl << endl;}
    }
}


/*Pre: <<argumento>> y <<nombreFicheroUsos>> son el nombre de dos ficheros de texto
 *Post: <<argumento>> es el nombre del fichero en el que se va a escribir información acerca de las 
 *      estaciones Bizi más usadas de acuerdo con el fichero <<nombreFicheroUsos>>.
 *      Adicionalmente se mostrarán por pantalla las primeras diez lineas del fichero correspondiente 
 *      al informe, de forma que muestre las ocho estaciones más utilizadas
 */
void ordenInforme(char argumento[], char nombreFicheroUsos[]) {
    char nombreFicheroEstaciones[MAX_NOMBRE] = "../../Datos/Bizi/estaciones.csv"; //Ruta con el fichero estaciones
    char nombreFicheroInforme[MAX_NOMBRE] = "../../Datos/Bizi/";
    Estacion estaciones [NUM_ESTACIONES];
    //-----------------------------------------------------------------
    strcat(nombreFicheroInforme, argumento); //Ruta con el fichero de informe
    //
    if (leerEstaciones(nombreFicheroEstaciones,estaciones)) {
        //Ha conseguido leer el fichero estaciones y guardar la informacion en un array de tipo Estacion
        if (contarUsosEstaciones(nombreFicheroUsos,estaciones)) {
            //Actualiza los usos de cada estacion leyendo del fichero de usos
            ordenarPorUso(estaciones);
            //Oirdena las estaciones de mayor a menor segun el numero de usos
           if(!escribirInforme(nombreFicheroInforme,estaciones)) { //escribe en el fichero informe  la info almacenada en el array de tipo Estacion
               cerr << "No se ha podido abrir o escribir  el fichero " << nombreFicheroInforme<< endl;
           }
           else{ escribirInformePantalla(estaciones);} //Escribe por pantalla las primeras 8 estaciones almacenadas en el array de tipo Estacion
        }
        else{cerr << "No se ha podido abrir o leer el fichero " << nombreFicheroUsos << endl;}
    }
    else {cerr << "No se ha podido abrir o leer el fichero " << nombreFicheroEstaciones << endl;}
}


/*Pre: <<argumento>> es el identificador de usuario del sistema Bizi 
 *Post: Muestra por pantalla el número de utilizaciones que el usuario <<argumento>>
 *      ha realizado, de acuerdo con los ficheros seleccionados actualmente.
 */
void ordenUsuario(char argumento[],const char ficheroUsos[]) {
    int viajes = 0;
    //Cuento el numero de viajes que ha realizado
    if (!viajesUsuario(atoi(argumento), ficheroUsos, viajes)) {cerr << "No se ha podido abrir el fichero: "<<ficheroUsos<<endl;} 
    else {cout <<"El/la usuario/a " << argumento << " a realizado " << viajes << " viajes." << endl;}
}

                        
/*Pre: <<ficheroUsos>> y <<ficheroUsuarios>> son los ficheros del sistema Bizi seleccionados
 *      actualemente.
 *Post: Muestra el número de utilizaciones del sistema que han realizado hombres y mujeres, de 
 *      acuerdo con los ficheros seleccionados actualmente.
 */
void ordenEstadisticas (const char ficheroUsuarios[],const char ficheroUsos[]) {
    Usuario vector[MAX_USUARIOS];
    int numUsuarios; //numero total de usuarios del sistema bizi
    if((numUsuarios = leerUsuarios(ficheroUsuarios,vector)) != -1) {
        //caso en que ha conseguido leer del fichero de usuarios
        int hombres = 0;
        int mujeres = 0;
        contarEstadisticas(ficheroUsos,vector,numUsuarios,hombres,mujeres);
        cout << "Usos de Bizi por hombres: " << hombres << endl;
        cout << "Usos de Bizi por mujeres: " << mujeres << endl;
        //ME QUEDO AQUI, SEGUIR ARREGLANDO LAS FUNCIONES MAS PROFUNDAS
        
    }
}