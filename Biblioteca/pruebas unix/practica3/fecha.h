/*
 * Programador:
 * Fecha de la última revisión:
 */

/*
 *  Fichero de interfaz fecha.h del módulo fecha
 */

#ifndef FECHA_H
#define FECHA_H

/*
 * Un dato de tipo Fecha permite representar cualquier fecha
 * del calendario
 */
struct Fecha {
    private:
        int dia;
		int mes;
		int anyo;
    public:
        // Funciones con acceso a la estructura interna anterior
	friend Fecha definirFecha (int d, int m, int a);
	friend Fecha definirFecha (int fecha);
	friend int dia (Fecha f);
	friend int mes (Fecha f);
	friend int anyo (Fecha f);
};

/*
 * Pre: d >= 1 y d <= 31, m >= 1 y m <= 12, a > 0
 * Post: Devuelve la fecha definida por d/m/a
 */
Fecha definirFecha (int d, int m, int a);

/*
 * Pre: El valor de fecha tiene ocho cifras cuando se escribe en 
 *      base 10: aaaammdd, donde aaaa define el año, mm el número
 *      del mes y dd el día del mes
 * Post: Devuelve la fecha definida por dia/mes/año
 */
Fecha definirFecha (int fecha);

/*
 * Pre: f es una fecha válida del calendario
 * Post: devuelve el número correspondiente al día de la fecha [f]
 */
int dia (Fecha f);

/*
 * Pre: f es una fecha válida del calendario
 * Post: devuelve el número correspondiente al mes de la fecha [f]
 */
int mes (Fecha f);

/*
 * Pre: f es una fecha válida del calendario
 * Post: devuelve el número correspondiente al año de la fecha [f]
 */
int anyo (Fecha f) ;

#endif

