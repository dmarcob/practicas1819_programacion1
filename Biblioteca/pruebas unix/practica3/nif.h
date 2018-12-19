/*
 * Programador:
 * Fecha de la última revisión:
 */

/*
 * Fichero de interfaz nif.h del módulo nif
 */
 
#ifndef NIF_H
#define NIF_H

/*
 * Un dato de tipo Nif que representa la información del NIF
 * (Número de Identificación Fiscal) de un ciudadano
 */
struct Nif {
    private:
        int numero;
		char letra;
    public:
        // Funciones con acceso a la estructura interna anterior
	friend Nif crearNif (const int numero);
	friend int numero (const Nif unNif);
	friend char letra (const Nif unNif);
};

/*
 * Pre: numero > 0 
 * Post: Devuelve un dato que representa un NIF con número igual a [numero] 
 */
Nif crearNif (const int numero);

/*
 * Pre: ---
 * Post: Devuelve el número del NIF unNif
 */
int numero (const Nif unNif);

/*
 * Pre: ---
 * Post: Devuelve la letra del NIF unNif
 */
char letra (const Nif unNif);

#endif