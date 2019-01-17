/*********************************************************************************
 * Programación 1.
 * Autor: Diego Marco Beisty, 755232
 * Fichero: bizi-usario.h
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de interfaz «bizi-usuario.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

/*********************************************************************************
 * Programación 1. 
 * Autor: Diego Marco Beisty, 755232
 * Fichero: bizi-usuario.h
 * Fecha: 24 Diciembre, 2018
 * Resumen: Fichero de interfaz «bizi-usuario.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#ifndef BIZI_USUARIO_H 
#define BIZI_USUARIO_H 

const char DELIMITADOR3 = ',';
const int MAX_LINEA3 = 1000;
const int MAX_USUARIOS = 30000;
struct Usuario {
  int id_usuario; //identificador de usuario 
  char sexo;      //'M' indica hombre, 'F' indica mujer
};

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
int leerUsuarios( const char rutaFichero[], Usuario usuarios[]);

/*Pre: <<identificador>> representa le numero de identificacion de un usuario del sistema
 *      bizi especificado en el enunciado. el array de usuarios << usuarios>> representa los 
 *      usuarios pertenecientes a este sistema. <<totalUsuarios>> representa el numero total 
 *      de usuarios que pertenecen al sistema <<bizi>>.
 *Post: Ha devuelto el índice del usuario cuyo identificador es <<identificador>> y que se encuentra
 *      indexado en el array <<usuarios>>.
 */
int buscarUsuario (int identificador,Usuario usuarios[],int totalUsuarios);
#endif