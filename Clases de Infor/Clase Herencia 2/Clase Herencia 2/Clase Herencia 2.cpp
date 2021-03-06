// Clase Herencia 2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/*class guerrero
{

};

class mago :private guerrero
{

};

void foo(guerrero g)
{
	cout << "Soy un guerrero" << endl;
}
*/

class Objeto
{
	int pos;
public:
	Objeto(int pos):	pos(pos)	{}
};
class Espada : public Objeto
{
	bool filo;
public:
	Espada(int pos, bool filo): Objeto(pos), filo(filo) {}
	Espada () : filo(1000), Objeto(0){}
	ostream& print(ostream & o) { cout << "SOY UNA ESPADA" << endl; }
};

class Personaje
{
	int fuerza;
protected:
	Personaje(int fuerza = 100) : fuerza(fuerza) {}
};


class Mago: private Espada, public Personaje
{
	int sombrero;
public:
	Mago(int s): sombrero(s), Espada(){}

};


class Conjurador : public Mago
{
	int conjuro;
public:
	Conjurador(int sombrero, int conj) : Mago(sombrero), conjuro(conj) {}
	
};
//función independiente
void foo(Objeto &o)
{
	cout << "Soy un objeto" << endl;
}

int main()
{
	/*
	mago merlin;
	foo(merlin);//no puede usar a mago porque es private
	*/
	Conjurador c(10, 20);
	Espada e(30, 100);

/*
	foo(c);//se traga el conjurador si Mago tiene herencia pública
*/
	//c.print(cout);//conjurador no sabe nada de espada

	system("PAUSE");
    return 0;
}

