//-----------------------------------------------------------------------
// File:    prueba1.cc
// Author:  Profesores de Programación 2
// Date:    12/01/2017, reviewed: Profesores de Programación 2
// Coms:    Programa para realizar pruebas básicas del comportamiento de
//          los tipos Persona, Nif y Fecha
//-------------------------------------------------------------------------

#include <iostream>
#include <iomanip>

// Ofrece el tipo Persona junto con una colección de funciones
// para realizar operaciones básicas con personas: definir un
// dato de tipo Persona y consultar algunos datos personales de
// una persona (nombre, fecha de nacimiento y NIF)

#include "fecha.h"
#include "nif.h"
#include "persona.h"

using namespace std;

/*
 * Pre: --
 * Post: Devuelve un dato correspondiente a una persona cuyos datos
 *       personales (nombre y apellido, fecha de nacimiento y NIF)
 *       son facilitados interactivamente por el operador tras un
 *       diálogo análogo al siguiente:
 *
 *       Nombre y apellido: Elena Salvador
 *       Fecha de nacimiento (aaaammdd): 19980803
 *       Numero de NIF: 76876504
 */
Persona nuevaPersona () {
    char nombre[64];
    int nacimiento;
    int dni;
    // Pregunta y lee el nombre y apellido de la persona
    cout << "Nombre y apellido: " << flush;
    cin.getline(nombre, 64);
    // Pregunta y lee su fecha de nacimiento
    cout << "Fecha de nacimiento (aaaammdd): " << flush;
    cin >> nacimiento;
    // Pregunta y lee su número de NIF
    cout << "Numero de NIF: " << flush;
    cin >> dni;
    Nif suNif = crearNif(dni);
    Fecha suNacimiento = definirFecha(nacimiento);
    // Devuelve una persona cuyos datos personales corresponden
    // con los definidos previamente por el operador
    return definirPersona(nombre, suNif, suNacimiento);
}

/*
 * Pre: ---
 * Post: Presenta por el dispositivo estándar de salida una linea con
 *       los datos personales de p con el siguiente formato:
 *
 *       Elena Salvador, con NIF 76876504-Q, nacio el 03/08/1998
 */
 void mostrar (const Persona p) {
    char suNombre[64];
    nombre(p, suNombre);
    Nif suNif = nif(p);
    Fecha f = nacimiento(p);
    cout << endl << suNombre
         << ", con NIF " << numero(suNif) << '-' << letra (suNif)
         << ", nacio el " << setfill('0') << setw(2) << dia(f) << '/'
         << setw(2) << mes(f) << '/' << setw(4) << anyo(f)<< endl;
 }

/*
 * Programa elemental de prueba del funcionamiento de los módulos
 * de biblioteca persona, nif y fecha. Se limita a crear un dato
 * de tipo Persona a partir de la información suministrada interactivamente
 * por el operador y muestra a continuación por pantalla los datos
 * personales de dicha persona con el siguente formato:
 *
 *    Nombre y apellido: Elena Salvador
 *    Fecha de nacimiento (aaaammdd): 19980803
 *    Numero de NIF: 76876504
 *
 *    Elena Salvador, con NIF 76876504-Q, nacio el 03/08/1998
 */
int main() {
    Persona p = nuevaPersona();
    mostrar(p);
    return 0;
}