/*
 * Programador:
 * Fecha de la última revisión:
 */

/*
 * Fichero de interfaz persona.h del módulo persona
 */
 
#ifndef PERSONA_H
#define PERSONA_H

#include "nif.h"  
#include "fecha.h"  

// Máxima longitud del nombre de una persona
const int MAX_LONG = 32;

/* 
 * Un dato de tipo Persona representa algunas informaciones relevante de
 * una persona: su nombre, su número de identificación fiscal y su fecha
 * de nacimiento
 */
struct Persona {
    private:
        char nombre[MAX_LONG];
		Nif nif;
		Fecha nacimiento;
    public:
        // Funciones con acceso a la estructura interna anterior
        friend Persona definirPersona (const char nombre[], const Nif nif, 
                                       const Fecha nacimiento);
        friend void nombre (Persona p, char suNombre[]);
        friend Nif nif (Persona p);
        friend Fecha nacimiento (Persona p);
};

/*
 * Pre: ---
 * Post: Devuelve una persona cuyo nombre es [nombre], su NIF es [nif] y
 *       ha nacido en la fecha [nacimiento]
 */
Persona definirPersona (const char nombre[], const Nif nif, 
			const Fecha nacimiento);

/*
 * Pre: ---
 * Post: La cadena de caracteres [suNombre] es el nombre 
 *       de la persona [p]
 */
void nombre (Persona p, char suNombre[]);

/*
 * Pre: ---
 * Post: Devuelve el NIF de la persona [p]
 */
Nif nif (Persona p);

/*
 * Pre: ---
 * Post: Devuelve la fecha de nacimiento de la persona [p]
 */
Fecha nacimiento (Persona p);

#endif