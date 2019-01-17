#ifndef NOMBRES_H
#define NOMBRES_H

#include <fstream>
#include <iostream>
using namespace std;
const int MAX = 9000;
const int MAXE = 30;
/*Pre: <<origen> y <<destino>> son dos cadenas de caracteres que indican el nombre de dos ficheros de texto
 *Post: <<origen>> y <<destino>> son dos cadenas de caracteres que indican la direccion relativa de los ficheros de texto
 */
void rutaCompleta(char origen[], char destino[]);
 
/*Pre:<<recibido>> es una cadena de caracteres que representan las letras mayusculas y minusculas en cualquier ordenacion
 *Post:<<recibido>> es una cadena de caracteres cuyo primer carácter está en mayúscula y los siguientes enminúscula
 */
void editNombre(char recibido[]);

/*Pre: <<orig>> es un flujo de entrada de un fichero de texto, <<dest>> es un flujo de salida a un fichero de texto
 *Post:Se ha modificado el fichero de texto apuntado por el flujo de salida siguiendo las especificaciones de la practica 5
 */
void editar(istream& orig, ostream& dest);

/*Pre: <<orig>> es un flujo de entrada a un fichero de texto, <<nombre>> es un nombre a localizar en el fichero apuntado por <<orig>>
 *     <<posicion>> es un entero de valor nulo
 * Post: devuelve en <<posicion>> la posicion del <<nombre>> en el fichero apuntado por el flujo <<orig>>, o en caso de no existir, 
 *       devuelve en <<posicion>> el valor -1
 */ 
void localizar(istream& orig, char nombre[],int& posicion);

/*Pre: <<recibido>> y <<nombre>> son cadenas de caracteres que representan nombres
 *post: Ha devuelto true si <<recibido>> perteneciente a un fichero de texto, corresponde con <<nombre>>, insertado por usuario
 */
bool localizarNombre (char recibido[], char nombre[]);

/*Pre: <<nombre>> es una cadena de caracteres ingresada por el usuario
 *Post: ha devuelto un entero correspondiente a la suma de la posicion que tienen todos sus caracteres en el alfabeto
 */
int factorA(char nombre []);

/*Pre:
 *Post: ha devuelto la valoracion que tiene el nombre
 */
int factorB(istream& orig, char nombre[]);

/*Pre:
 *Post: Ha almacenado en <<array>> punteros a cadenas de caracteres leidos del fichero de texto
 */
void entablar ( istream& orig, char array[][MAXE], int& contador);

/*Pre:
 *Post: Ha ordenado alfabeticamente las cadenas de caracteres apuntadas en el array de punteros <<array>>
 */
void ordenar (char array[][MAXE],int contador);

bool esMayor (char* menor, char* otro);
#endif