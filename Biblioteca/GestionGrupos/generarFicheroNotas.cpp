/* 
 * Fichero <generarFicheroNotas.cc> que define un programa que permite generar un fichero
 * binario de calificaciones a partir de un fichero textual de calificaciones.
 * 
 * Ejemplo de fichero textual de calificaciones:
 *        51730586 AP 64
 *        51809151 NP SU 32
 *        51868593 SU 33 NP
 *        51878868 AP 65
 *        71920840 SU 30 NO 71
 *             .  .  .
 *        51943339 NP AP 51
 *        51971113 NO 71
 *
 * El fichero binario de calificaciones generado al ejecutar el programa será el siguiente
 * (los datos entre <ángulos> son datos binarios de tipo int):
 *        <51730586> <AP> <64> <51809151> <NP> <SU> <32> <51868593> <SU> <33> <NP>
 *        <51878868> <AP> <65> <71920840> <SU> <30> <NO> <71> ... <51943339> <NP> 
 *        <AP> <51> <51971113> <NO> <71>
 */
 
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Posibles calificaciones cualitativas de una asignatura en una convocatoria
const int MH = 4;      // matricula de honor

const int SB = 3;      // sobresaliente
const int NO = 2;      // notable
const int AP = 1;      // aprobado
const int SU = 0;      // suspenso
const int NP = -1;     // no presentado

/*
 * Pre: El flujo <f> está asociado a un fichero de texto que almacena la información de 
 *      las calificaciones de un grupo de alumnos de forma textual. El siguiente dato a 
 *      leer de él correponde a una calificación cualitativa.
 *      El flujo <g> está asociado a un fichero binario que almacena las calificaciones
 *      leídas hasta el momento del fichero asociado a <f>
 * Post: Ha leído una calificación del fichero asociado a <f>, la calificación cualitativa
 *       y, salvo que ésta sea NP, la calificación cuantitativa, ha almacenado en el 
 *       fichero asociado a <g> la calificación cualitativa leida y, en su caso, la 
 *       cuantitativa y ha asignado a <notaCual> el valor de la calificación cuantitativa
 */
void copiarNota (ifstream& f, ofstream& g, int& notaCual) {
    char nota[4];
    f >> nota;
    if (strcmp(nota, "NP") == 0) {
        notaCual = NP;
    }
    else if (strcmp(nota, "SU") == 0) {
        notaCual = SU;
    }
    else if (strcmp(nota, "MH") == 0) {
        notaCual = MH;
    }
    else if (strcmp(nota, "SB") == 0) {
        notaCual = SB;
    }
    else if (strcmp(nota, "NO") == 0) {
        notaCual = NO;
    }
    else {
        notaCual = AP;
    }
    g.write(reinterpret_cast<char *>(&notaCual), sizeof(int));
    if (notaCual != NP) {
        int notaCuan;
        f >> notaCuan;
        g.write(reinterpret_cast<char *>(&notaCuan), sizeof(int));
    }
}

/*
 * Pre: <notasTextuales> es un fichero de texto que almacena la información de las
 *      calificaciones de un grupo de alumnos de forma textual. Ejemplo:
 *         51730586 AP 64
 *         51809151 NP SU 32
 *         51868593 SU 33 NP
 *         51878868 AP 65
 *         71920840 SU 30 NO 71
 *              .  .  .
 *         51943339 NP AP 51
 *         51971113 NO 71
 * Post: Ha creado el fichero <notasBinarias> que almacena una información similar
 *       a la de <notasTextuales> con la diferencia de que todos los datos están 
 *       codificados en binario como datos de tipo <int>. Ejemplo:
 *         <51730586> <AP> <64> <51809151> <NP> <SU> <32> <51868593> <SU> <33> <NP>
 *         <51878868> <AP> <65> <71920840> <SU> <30> <NO> <71> ... <51943339> <NP> 
 *         <AP> <51> <51971113> <NO> <71>
 */
bool generarNotas (const char notasTextuales[], const char notasBinarias[]) {
    ifstream f(notasTextuales);
    if (f.is_open()) {
        ofstream g(notasBinarias, ios::binary);
        // Intenta leer el código numérico del primer alumno
        int codigo;
        f >> codigo;
        while (!f.eof()) {
            // Almacena en el fichero asociado a <g> el código numérico del alumno
            g.write(reinterpret_cast<char *>(&codigo), sizeof(int));
            // Lee del fichero asociado a <f> la calificación del alumno en la
            // primera convocatoria y la almacena en el fichero asociado a <g>
            int notaCual;
            copiarNota(f, g, notaCual);
            if ((notaCual == NP) || (notaCual == SU)) {
                // Lee del fichero asociado a <f> la calificación del alumno en la
                // primera convocatoria y la almacena en el fichero asociado a <g>
                copiarNota(f, g, notaCual);
            }
            // Intenta leer el código numérico de un nuevo alumno
            f >> codigo; 
        }
        // Libera los ficheros a sociados a los flujos <f> y <g>
        f.close();  g.close();
        // Se han almacenado exitosamente las califiones en el fichero binario que ha
        // estado asociado a flujo <g>
        return true;
    }
    else {
        // No se ha podido acceder al fichero <notasTextuales>
        return false;
    }
}

/*
 * Pre: <FICHERO_TEXTUAL_NOTAS> es un fichero de texto que almacena la información de las
 *      calificaciones de un grupo de alumnos de forma textual.
 * Post: Si se ha accedido al fichero <FICHERO_TEXTUAL_NOTAS> sin problemas, entonces 
 *       ha creado el fichero <notasBinarias> que almacena una información similar
 *       a la de <FICHERO_BINARIO_NOTAS> con la diferencia de que todos los datos están 
 *       codificados en binario como datos de tipo <int> y ha informado de la creación
 *       del fichero mediante un mensaje por pantalla.
 *       Si se ha podido acceder al fichero <FICHERO_TEXTUAL_NOTAS> entonces se ha 
 *       limitado a informar de ello mediante un mensaje por pantalla.
 */
int main() {
    // Nombre de un fichero de texto que almacena las calificaciones de los alumnos
    // de ese mismo grupo (modificar el nombre si el nombre del fichero es distinto)
    const char FICHERO_TEXTUAL_NOTAS[64] = "../../datos/notas2Grupo.txt";
    // Nombre de un fichero binario que almacena las calificaciones de los alumnos
    // de ese mismo grupo (modificar el nombre si interesa que el nombre del fichero 
    // binario a crear sea diferente
    const char FICHERO_BINARIO_NOTAS[64] = "../../datos/notas2Grupo.bin"; 
    // Intenta generar el fichero binario de calificaciones <FICHERO_BINARIO_NOTAS> a
    // partir de los datos del fichero textual de calificaciones <FICHERO_TEXTUAL_NOTAS>
    if (generarNotas(FICHERO_TEXTUAL_NOTAS, FICHERO_BINARIO_NOTAS)) {
        // El fichero binario de calificaciones ha sido creado
        cout << "Creado el fichero binario de notas " << FICHERO_BINARIO_NOTAS << endl;
    }
    else {
        // El fichero binario de calificaciones no ha podido ser creado al no haberse
        // podido acceder al fichero textual de calificaciones <FICHERO_TEXTUAL_NOTAS>
        cout << "El fichero " << FICHERO_TEXTUAL_NOTAS << " no es accesible" << endl;
    }
    return 0;
}