

#include "fecha.h"
/*
 * Pre: d >= 1 y d <= 31, m >= 1 y m <= 12, a > 0
 * Post: Devuelve la fecha definida por d/m/a
 */
Fecha definirFecha (int d, int m, int a){
	Fecha f;
	f.dia=d;
	f.mes=m;
	f.anyo=a;
	return f;
}
 
/*
 * Pre: El valor de fecha tiene ocho cifras cuando se escribe en 
 *      base 10: aaaammdd, donde aaaa define el año, mm el número
 *      del mes y dd el día del mes
 * Post: Devuelve la fecha definida por dia/mes/año
 */
Fecha definirFecha (int fecha){
	Fecha f;
	f.dia=fecha%100;
    f.mes=(fecha/100)%100;
    f.anyo=fecha%10000;
    return f;                                                                                                                              
}

/*
 * Pre: f es una fecha válida del calendario
 * Post: devuelve el número correspondiente al día de la fecha [f]
 */
int dia (Fecha f){
	return f.dia;
}

/*
 * Pre: f es una fecha válida del calendario
 * Post: devuelve el número correspondiente al mes de la fecha [f]
 */
int mes (Fecha f){
	return f.mes;
}

/*
 * Pre: f es una fecha válida del calendario
 * Post: devuelve el número correspondiente al año de la fecha [f]
 */
int anyo (Fecha f){
	f.anyo;
}

