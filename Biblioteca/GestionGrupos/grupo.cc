/*
 * Autor del trabajo (escriba su nombre y apellidos): Diego Marco Beisty 
 */

/*
 * Fichero de implementación grupo.cpp del módulo grupo
 */
#include "../../biblioteca/gestionGrupos/grupo.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
/*
 * Post: El alumno que ha devuelto tiene como código numérico <codigo> y su nombre 
 *       y apellidos son los definidos por las cadenas <nombre> y <apellidos>,
 *       respectivamente
 */
 
Alumno definir (const int codigo, const char nombre[], const char apellidos[]){
    Alumno a;
    a.codigoPrivate=codigo;
    strcpy(a.nombrePrivate,nombre);
    strcpy(a.apellidosPrivate,apellidos);
    return a;
     
}
				
/*
 * Post: Devuelve el código numérico del alumno <a>
 */
int codigo (const Alumno a){
    return a.codigoPrivate;
}

/*
 * Post: Ha asignado a <nombre> la cadena de caracteres con el nombre del alumno <a>
 *       y ha asignado a <apellidos> la cadena de caracteres con sus apellidos
 */
void nombreCompleto (const Alumno a, char nombre[], char apellidos[]){
    strcpy(nombre,a.nombrePrivate);
    strcpy(apellidos,a.apellidosPrivate);
}


/*
 * Pre: <nombreFichero> es el nombre del fichero de texto que almacena la información 
 *      de todos los alumnos de un grupo. cada línea del fichero define un alumno del
 *      grupo con el siguiente formato:
 *      555423 MARTIN PEREZ,LUIS CARLOS
 *      82552 LOPEZ DE LA IGLESIA,ANDREA
 *              .   .   .
 * Sintaxis BNF de los datos de este fichero:
 *      <ficheroAlumnos> ::= {  <alumno>  }
 *      <alumno> ::= <codigoNumerico> <blanco> <apellidos> <coma> <nombre> fin_linea
 *      <codigoNumerico> ::= literal_entero
 *      <apellidos> ::= literal_string
 *      <nombre> ::= literal_string
 *      <blanco> ::= " "
 *      <coma>   ::= ","
 * Post: Ha asignado a <g> un dato de tipo Grupo que gestiona la información de todos
 *       los alumnos que constan en el fichero <nombreFichero>
 */
void leerGrupo (const char nombreFichero[],Grupo& g){
    
    
    ifstream archivo;
    archivo.open(nombreFichero,ios::in);
    if(archivo.is_open()){
        
        int codigoNum;
        char nombre[LIMITE_NOMBRE];
        char apellidos[LIMITE_APELLIDOS];
        const char coma=',';
        int i=0;
        archivo>>codigoNum;
        while(!archivo.eof()){
            archivo.getline(apellidos,LIMITE_APELLIDOS,coma);
            archivo.getline(nombre,LIMITE_NOMBRE);
            g.integrantesGrupo[i]=definir(codigoNum,nombre,apellidos);
            i++;
            archivo>>codigoNum;
            
        }
     g.numAlumnos=i;
    
     archivo.close();

    }
     else {
         cout<<endl<<endl;
         cerr<<"No se ha podido acceder al fichero: " <<nombreFichero << endl;
    }
}



/*
 * Post: Devuelve el número de alumnos del grupo <g>
 */
int numAlumnos (const Grupo& g){
    
   return g.numAlumnos;
    
}

/*
 * Pre: i >= 1 y i <= numAlumnos(g)
 * Post: Devuelve el <i>-ésimo alumno del grupo <g>
 */
Alumno alumno (const Grupo& g, const int i){
    return g.integrantesGrupo[i];
    
}





/*
 * Pre: <nombreFichero> es el nombre del fichero binario que almacena las calificaciones
 *      de todos los alumnos en la primera y, en caso de no habe aprobado, en la segunda 
 *      convocatoria con la siguiente sintaxis BNF:
 *          <ficheroNotas> ::= { <notas> }
 *          <notas> ::= <codigoAlumno> <cualitativa> <cuantitativa> 
 *                                     [ <cualitativa> <cuantitativa> ]
 *          <codigoAlumno> ::= <int>
 *          <cualitativa> ::= <int>
 *          <cuantitativa> ::= <int>
 *       Las calificaciones cualitativas pueden tomar únicamente los valores de las 
 *       constantes MH, SB, NO, AP, SU o NP.
 *       Las calificaciones cuantitativas se expresan en décimas de punto, pudiendo estar 
 *       comprendidas entre una calificación mínima de 0 (corresponde a una nota de 0.0) 
 *       y una calificación máxima de 100 (corresponde a una nota de 10.0).
 * Post: En el caso de que no se pueda acceder al fichero <nombreFichero> entonces ha
 *       devuelto <false>; si se puede acceder entonces ha asignado a <numNotas> el número 
 *       de alumnos cuyas calificaciones están almacenadas en el fichero <nombreFichero> 
 *       y ha asignado a lasNotas[0..numAlumnos-1] las calificaciones de dichos alumnos 
 *       y ha devuelto <true>
 */
bool leerNotas (const char nombreFichero[], Notas lasNotas[], int& numAlumnos){
    
    ifstream archivo;
    archivo.open(nombreFichero,ios::binary);
    if(archivo.is_open()){
        int codigoAlumno,cualitativa1,cualitativa2,cuantitativa1,cuantitativa2;
        Notas mochila;
        int i=0;
        archivo.read(reinterpret_cast<char*>(&codigoAlumno),sizeof(int));
        mochila.codigoAlumno = codigoAlumno;
        while(!archivo.eof()){
            archivo.read(reinterpret_cast<char*>(&cualitativa1),sizeof(int));
            mochila.cualitativa1 = cualitativa1;
            if((cualitativa1!=NP)&&(cualitativa1!=SU)){//ha aprobado
                archivo.read(reinterpret_cast<char*>(&cuantitativa1),sizeof(int));
                mochila.cuantitativa1 = cuantitativa1;
                //en este caso cuantitativa2 y cualitativa2 no se utilizan, asi que les paso -99
                mochila.cualitativa2 = -99;
                mochila.cuantitativa2 = -99;
                lasNotas[i]= mochila;
            }
            else if(cualitativa1==SU){ //ha suspendido
                mochila.cualitativa1 = cualitativa1;
                archivo.read(reinterpret_cast<char*>(&cuantitativa1),sizeof(int));
                archivo.read(reinterpret_cast<char*>(&cualitativa2),sizeof(int));
                mochila.cuantitativa1 = cuantitativa1;
                mochila.cualitativa2 = cualitativa2;
                if(cualitativa2!=NP){  //segunda convocatoria se presenta
                  archivo.read(reinterpret_cast<char*>(&cuantitativa2),sizeof(int));
                  mochila.cuantitativa2 = cuantitativa2;
                  lasNotas[i]=mochila;                    
                }
                else{//segunda convocatoria no se presenta
                  //en este caso cuantitativa2 no se utiliza, asi que les paso -99
                  mochila.cuantitativa2=-99;
                  lasNotas[i]=mochila;
                }
            }
            else{//no se ha presentado
                archivo.read(reinterpret_cast<char*>(&cualitativa2),sizeof(int));
                mochila.cualitativa1 = cualitativa1;
                //en este caso cuantitativa1 no se utiliza, asi que les paso -99
                mochila.cuantitativa1 = -99;
                mochila.cualitativa2 = cualitativa2;
                if(cualitativa2!=NP){ //se ha presentado a la segunda convocatoria
                  archivo.read(reinterpret_cast<char*>(&cuantitativa2),sizeof(int));
                  mochila.cuantitativa2 = cuantitativa2;
                  lasNotas[i]=mochila;
                }
                else{ //tampoco se ha presentado ha segunda convocatoria
                  //en este caso cuantitativa2 no se utiliza, asi que les paso -99
                  mochila.cuantitativa2 = -99;
                  lasNotas[i]=mochila;
                }
            }
    
        i++;
        archivo.read(reinterpret_cast<char*>(&codigoAlumno),sizeof(int));
        mochila.codigoAlumno=codigoAlumno;
      }
     numAlumnos=i;
     archivo.close();
     return true;
    
    }
    else{
        cout<<endl<<endl;
        cerr<<"No se ha podido acceder al fichero: "<<nombreFichero;
        return false;
    }
}

/*
 * Post: Devuelve el código numérico del alumno cuyas calificaciones son <n>
 */
int codigoAlumno (const Notas& n){
   return n.codigoAlumno;
}

/*
 * Pre: Las notas <n> presenta calificación en primera convocatoria
 * Post: Ha asignado a <cualitativa> la calificación cualitativa en primera convocatoria
 *       del alumno cuyas calificaciones son <n> y, si la calificación cualitativa no es
 *       la de "no presentado", entonces ha asignado a <cuantitativa> la calificación 
 *       cuantitativa en primera convocatoria
 */
void convocatoria1 (const Notas& n, int& cualitativa, int& cuantitativa){
    cualitativa=n.cualitativa1;
    if(n.cualitativa1!=NP){
        cuantitativa=n.cuantitativa1;
    }
}

/*
 * Pre: Las notas <n> presentan calificaciones en primera convocatoria (suspenso o no
 *      presentado) y en segunda convocatoria
 * Post: Ha asignado a <cualitativa> la calificación cualitativa en segunda convocatoria
 *       del alumno cuyas calificaciones son <n> y, si la calificación cualitativa no es
 *       la de "no presentado", entonces ha asignado a <cuantitativa> la calificación 
 *       cuantitativa en segunda convocatoria
 */
void convocatoria2 (const Notas& n, int& cualitativa, int& cuantitativa){
    cualitativa=n.cualitativa2;
    if(n.cualitativa2!=NP) {
        cuantitativa=n.cuantitativa2;
    }
}

