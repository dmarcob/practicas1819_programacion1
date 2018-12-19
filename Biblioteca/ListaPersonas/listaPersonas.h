/*
 *  Fichero de interfaz listaPersonas.h del módulo listaPersonas
 */

#include "../TipoPersona/persona.h"

#ifndef LISTA_PERSONAS_H

#define LISTA_PERSONAS_H

// Capacidad máxima de las listas de personas a definir
const int DIM = 200;   

/*
 * Representa una lista de datos de tipo Persona con capacidad
 * máxima de almacenamiento igual a DIM
 */
struct ListaPersonas {
    private:
        Persona personas[DIM];
        int numPersonas;
    public:
        // lista de funciones con acceso permitido a la representación
        // interna de los datos de tipo ListaPersonas
        friend ListaPersonas nuevaLista ();
        friend int numPersonas (const ListaPersonas L);
        friend Persona consultar (const ListaPersonas L, const int i);
        friend void anyadir (ListaPersonas& L, const Persona p);
        friend Persona retirar (ListaPersonas& L);
        friend void insertar (ListaPersonas& L, const Persona p, const int i);
        friend void eliminar (ListaPersonas& L, const int i);
};

/*
 * Pre: ---
 * Post: Devuelve una lista que no almacena ninguna persona, es decir,
 *       devuelve la lista <>
 */
ListaPersonas nuevaLista ();

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 * Post: Devuelve el número K de personas almacenadas en la lista L
 */
int numPersonas (const ListaPersonas L);

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 *      y i >= 1 y i <= K
 * Post: Devuelve p_i, es decir, la persona ubicada en la posición i
 *       de la lista L
 */
Persona consultar (const ListaPersonas L, const int i);

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 *      y K < DIM
 * Post: La lista L almacena K+1 personas ya que a las K personas que
 *       almacenaba inicialmente se ha incorporado p como último elemento
 *       de la lista, es decir, ahora L = < p_1, p_2, ..., p_K, p >
 */
void anyadir (ListaPersonas& L, const Persona p);

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 *      y K > 0
 * Post: Devuelve la persona que ocupaba el primer lugar de la lista L, es
 *       decir, p_1, y modifica la lista L eliminando de ella la persona p_1,
 *       es decir, ahora L = < p_2, ..., p_K >
 */
Persona retirar (ListaPersonas& L);

/*
 * Pre: La lista L, siendo L = < p_1, p2, ..., p_i-1, p_i,..., p_K >, almacena K
 *      personas, K < DIM, i >= 1 e i <= K
 * Post: La lista L almacena K+1 personas ya que a las K personas que almacenaba
 *       inicialmente se ha incorporado [p] como i-ésimo elemento de la lista, es decir,
 *       ahora L = < p_1, p2, ..., p_i-1, p, p_i, ..., p_K >
 */
void insertar (ListaPersonas& L, const Persona p, const int i);

/*
 * Pre: La lista L, siendo,  L = < p_1, p2, ..., p_i-1, p_i, p_i+1, ..., p_K >,
 *      almacena K personas, K > 0, i >= 1 e i < = K
 * Post: Modifica la lista L eliminando de ella la persona p_i, es decir ahora solo
 *       almacena K-1 personas, siendo L = < p_1, p2, ..., p_i-1, p_i+1, ..., p_K >
 */
void eliminar (ListaPersonas& L, const int i);

#endif