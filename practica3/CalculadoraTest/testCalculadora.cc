

#include <iostream>
#include "../../Biblioteca/calculos.h"
#include "testCalculadora.h"
using namespace std;


/*
 * Pre:  «valorEsperado» es el «n»-ésimo término de la sucesión de Fibonnaci.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «fibonacci», invocada con el argumento «n», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarFibonacci(const int n, const int valorEsperado) {
	cout << "Prueba fibonacci(" << n << ") ";
	int valorDevuelto = fibonacci(n);
	if (valorDevuelto == valorEsperado) {
		cout << "correcta" << endl;
	} else {
		cout << "incorrecta:" << endl;
		cout << "   debería haber devuelto " << valorEsperado
		     << " pero ha devuelto " << valorDevuelto << endl;
	}
}

/*
 * Pre:  «valorEsperado» es el mínimo común múltimo de «n» y «m».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «mcm», invocada con los argumentos «n» y «m», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarMcm(const int n, const int m, const int valorEsperado) {
		cout << "Prueba mcm(" << n << ", " << m << ") ";
	int valorDevuelto = mcm(n, m);
	if (valorDevuelto == valorEsperado) {
		cout << "correcta" << endl;
	} else {
		cout << "incorrecta:" << endl;
		cout << "   debería haber devuelto " << valorEsperado
		     << " pero ha devuelto " << valorDevuelto << endl;
	}
}