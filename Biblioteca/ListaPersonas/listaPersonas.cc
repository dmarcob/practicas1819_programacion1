#include <iostream>
#include "../Enteros/fechas.h"
#include "../TipoPersona/persona.h"
#include "listaPersonas.h"

using namespace std;

/*
 * Pre: ---
 * Post: Devuelve una lista que no almacena ninguna persona, es decir,
 *       devuelve la lista <>
 */
ListaPersonas nuevaLista (){
        ListaPersonas L;
        L.numPersonas = 0;
        return L;
}

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 * Post: Devuelve el número K de personas almacenadas en la lista L
 */
int numPersonas (const ListaPersonas L){
        return L.numPersonas;
}

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 *      y i >= 1 y i <= K
 * Post: Devuelve p_i, es decir, la persona ubicada en la posición i
 *       de la lista L
 */
Persona consultar (const ListaPersonas L, const int i){
        return L.personas[i-1];
}

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 *      y K < DIM
 * Post: La lista L almacena K+1 personas ya que a las K personas que
 *       almacenaba inicialmente se ha incorporado p como último elemento
 *       de la lista, es decir, ahora L = < p_1, p_2, ..., p_K, p >
 */
void anyadir (ListaPersonas& L, const Persona p){
        L.personas[numPersonas(L)] = p;
        L.numPersonas++;
}

/*
 * Pre: La lista L almacena K personas, es decir, L = < p_1, p_2, ..., p_K >
 *      y K > 0
 * Post: Devuelve la persona que ocupaba el primer lugar de la lista L, es
 *       decir, p_1, y modifica la lista L eliminando de ella la persona p_1,
 *       es decir, ahora L = < p_2, ..., p_K >
 */
Persona retirar (ListaPersonas& L){
        Persona resultado = L.personas[0];
        int n=numPersonas(L);
        for(int i=1; i<n; i++){
                L.personas[i-1] = L.personas[i];
        }
        L.numPersonas--;
        return resultado;
}

/*
 * Pre: La lista L, siendo L = < p_1, p2, ..., p_i-1, p_i,..., p_K >, almacena K
 *      personas, K < DIM, i >= 1 e i <= K
 * Post: La lista L almacena K+1 personas ya que a las K personas que almacenaba
 *       inicialmente se ha incorporado [p] como i-ésimo elemento de la lista, es decir,
 *       ahora L = < p_1, p2, ..., p_i-1, p, p_i, ..., p_K >
 */
void insertar (ListaPersonas& L, const Persona p, const int i){
        for(int j = numPersonas(L); j>i; j--){
                L.personas[j] = L.personas[j-1];
        }
        L.personas[i-1] = p;
        L.numPersonas++;
}

/*
 * Pre: La lista L, siendo,  L = < p_1, p2, ..., p_i-1, p_i, p_i+1, ..., p_K >,
 *      almacena K personas, K > 0, i >= 1 e i < = K
 * Post: Modifica la lista L eliminando de ella la persona p_i, es decir ahora solo
 *       almacena K-1 personas, siendo L = < p_1, p2, ..., p_i-1, p_i+1, ..., p_K >
 */
void eliminar (ListaPersonas& L, const int i){
        int n=numPersonas(L);
        for(int j=i;j<n;j++){
                L.personas[j-1]=L.personas[j];
        }
        L.numPersonas--;
}