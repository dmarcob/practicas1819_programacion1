

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
Nif crearNif (const int numero){
	Nif n;
	n.numero=numero;
	const int MAXIMO=23;	
	char tabla[MAXIMO]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
	int resto=numero%23;
	n.letra=tabla[resto];
	return n;
}

/*
 * Pre: ---
 * Post: Devuelve el número del NIF unNif
 */
int numero (const Nif unNif){
	return unNif.numero;
}

/*
 * Pre: ---
 * Post: Devuelve la letra del NIF unNif
 */
char letra (const Nif unNif){
	return unNif.letra;
}

