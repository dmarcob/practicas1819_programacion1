#include "nombres.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

void rutaCompleta(char origen[], char destino[]) {
    char rutaUno[MAX] ="../../../Datos/Nombres/";
    char rutaDos[MAX] ="../../../Datos/Nombres/";
    //modifico origen[] := (rutaUno) (origen)
    strcat(rutaUno,origen);
    strcpy(origen,rutaUno);
    //modifico destino[] := (rutaDos) (destino)
    strcat(rutaDos,destino);
    strcpy(destino,rutaDos);
}

void editNombre(char recibido[]) {
    int i = 0;
    //Modifico primer caracter a Mayuscula, en el caso de que sea minuscula
    recibido[i] = toupper(recibido[i]);
    i++;
     while (recibido[i] != '\0') {
         //Modifico los siguientes caracteres a minuscula en el caso de que sean mayusculas
        recibido[i] = tolower(recibido[i]);
        i++;
    }
}
void editar(istream& orig, ostream& dest){
    char recibido[MAX];
    char comillas = orig.get(); //intento leer las " del principio del nombre
    char coma;
    if (!orig.eof()) {
        //Si ha conseguido leerlas, leo el nombre hasta las siguientes comillas, que descarto
        orig.getline (recibido,MAX,'"');
        //TRANSFORMAR EL NOMBRE
        editNombre(recibido);
        dest << comillas << recibido << comillas;
        //Intento leer la siguiente coma
        coma = orig.get();
    }
    while(!orig.eof()) {
        //He podido leer la coma
        comillas = orig.get();
         orig.getline (recibido,MAX,'"');
         //TRANSFORMAR EL NOMBRE
         editNombre(recibido);
         dest << coma << comillas << recibido << comillas;
         //Intento leer la siguiente coma
         coma = orig.get();
    }
}


bool localizarNombre (char recibido[], char nombre[]) {
    return strcmp(recibido,nombre) == 0;
}


void localizar(istream& orig, char nombre[],int& posicion){
    posicion = 0;
    char recibido[MAX];
    bool encontrado = false;
    char comillas = orig.get(); //intento leer las " del principio del nombre
    char coma;
    //--------------------------------------------------------------------------------------
    //paso el nombre al formato del fichero de lectura que son todo mayusculas
    int i = 0;
    while (nombre[i] != '\0') {
    //el nombre insertado por el usuario lo pasamos a mayusculas para comparar en el fichero
    nombre[i] = toupper(nombre[i]);
    i++;
    }
    //--------------------------------------------------------------------------------------
    if (!orig.eof()) {
        //Si ha conseguido leerlas, leo el nombre hasta las siguientes comillas, que descarto
        orig.getline (recibido,MAX,'"');
        //LOCALIZAR EL NOMBRE
        posicion++;
       if( localizarNombre(recibido,nombre)) { encontrado = true;}
        //Intento leer la siguiente coma
        coma = orig.get();
    }
    while(!orig.eof() && !encontrado) {
        //He podido leer la coma
        comillas = orig.get();
         orig.getline (recibido,MAX,'"');
         //TRANSFORMAR EL NOMBRE
        posicion++;
        if( localizarNombre(recibido, nombre)) { encontrado = true;}
         //Intento leer la siguiente coma
         coma = orig.get();
   }
    if (!encontrado) { posicion = -1;}
}

int factorA(char nombre []) {
    int i = 0;
    int valoracion = 0;
    while (nombre[i] != '\0') {
        valoracion += (nombre[i] - 'A') + 1;
        i++;
    }
    return valoracion;
}

void entablar ( istream& orig, char array[][MAXE],int& contador) {
    char recibido[MAX];
    char comillas = orig.get(); //intento leer las " del principio del nombre
    char coma;
    contador = 0;
    if (!orig.eof()) {
        //Si ha conseguido leerlas, leo el nombre hasta las siguientes comillas, que descarto
        orig.getline (*(array + contador),MAX,'"'); //guardo en la matriz el nombre leido del fichero
        //GUARDAMOS EN ARRAY DE PUNTEROS A CADENA DE CARACTERES
        contador++;
        //Intento leer la siguiente coma
        coma = orig.get();
    }
    while(!orig.eof()) {
        //He podido leer la coma
        comillas = orig.get();
        orig.getline (*(array + contador),MAX,'"');
        contador++;
         //Intento leer la siguiente coma
         coma = orig.get();
  }
}

bool esMayor (char* menor, char* otro) {
    int i = 0;
    bool mayor = false;
    int uno = menor [i] - 'A';
    int dos = otro[i] - 'A';
    while (menor[i] != '\0' && uno == dos ) {
        i++;
        uno = menor [i] - 'A';
        dos = otro[i] - 'A';
    }
    if (uno != dos) { return  uno > dos;}
    return mayor;
}

void ordenar (char array[][MAXE],int contador) {
    //aplico algoritmo de ordenacion para los nombres del fichero que he guardado en una matriz
     char menor[MAXE];
     char aux[MAXE];
    for (int i = 0; i < contador - 1; i++) {
        strcpy(menor,*(array + i));
        for (int j = i+1; j < contador; j++) {
            if (esMayor(menor,*(array + j))){
                strcpy(aux,menor);
                strcpy(menor, *(array + j));
                strcpy(*(array + j), aux);
                strcpy(*(array + i), menor);
            }
        }
    }
    
}

int factorB(istream& orig, char nombre[]) { //ME QUEDO AQUI
    bool encontrado = false;
    int i = 0;
    int contador = 0;
    char array [MAX][MAXE]; //puntero a array de punteros
    //guardo en un vector de punteros todos los nombres leidos del fichero
    entablar (orig, array, contador);
    //ordeno los nombres del array de punteros por orden alfabetico
    ordenar (array, contador);
    while( i <= MAX && !encontrado) { //miro la posicion <<i>> de nombre respecto a una lista de todos los nombres ordenados alfabeticamente
        if (strcmp(*(array + i),nombre) == 0) {
            encontrado = true;
        }
        i++;
    }
    if (!encontrado) { i = 0;} //encaso de que no se encuentre, su valoracion es de cero
    return i;
}


