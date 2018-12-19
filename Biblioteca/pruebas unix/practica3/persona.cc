/*
 * Programador:
 * Fecha de la última revisión:
 */

/*
 * Fichero de interfaz persona.h del módulo persona
 */
 

#include "persona.h"
#include "fecha.h"
#include "nif.h"
#include <cstring>
// Máxima longitud del nombre de una persona




/*
 * Pre: ---
 * Post: Devuelve una persona cuyo nombre es [nombre], su NIF es [nif] y
 *       ha nacido en la fecha [nacimiento]
 */
Persona definirPersona (const char nombre[], const Nif nif, const Fecha nacimiento){

	Persona p;
	strcpy(p.nombre,nombre);
	p.nif=nif;
	p.nacimiento=nacimiento;
	return p;

	}

/*
 * Pre: ---
 * Post: La cadena de caracteres [suNombre] es el nombre 
 *       de la persona [p]
 */
void nombre (Persona p, char suNombre[]){
	strcpy(p.nombre,suNombre);
	
	
}

/*
 * Pre: ---
 * Post: Devuelve el NIF de la persona [p]
 */
Nif nif (Persona p){
	return p.nif;
}

/*
 * Pre: ---
 * Post: Devuelve la fecha de nacimiento de la persona [p]
 */
Fecha nacimiento (Persona p){
	return p.nacimiento;
}

