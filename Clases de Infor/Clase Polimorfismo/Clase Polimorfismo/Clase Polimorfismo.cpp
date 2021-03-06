// Clase Polimorfismo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Personaje
{
	int altura;
public:
	Personaje(int altura = 10) : altura(altura) {};
	virtual int atacar() {
		cout << "ATACAR COMO PERSONAJE" << endl;
		return 9;
	}
	virtual ostream& print(ostream& o = cout) const { o << "PERSONAJE SOY YO" << endl; return o; }//siempre print es útil
	//friend ostream& operator<<(ostream &o, const Personaje&);//por si es  privado
};

class Guerrero :public Personaje
{
public:
	int atacar()//para ver que busca la primera que encuentre hacia arriba
	{
		cout << "ATACAR COMO GUERRERO" << endl;
		return 4;
	}
	ostream& print(ostream& o = cout) const { o << "GUERRERO SOY YO" << endl; return o; }//siempre print es útil

};

class Mago:public Guerrero
{
public:
	int atacar()
	{
		cout << "ATACAR COMO MAGO" << endl;
		return 9;
	}
	ostream& print(ostream& o = cout) const { o << "MAGO SOY YO" << endl; return o; }//siempre print es útil

};

//FUCION INDEPENDIENTE QUE PERMITE ATACAR A ACUALQUIER TIPO DE LA JERARQUÍA
void atacar(Personaje & p)
{
	p.atacar();
}

void imprimir(Personaje & p)
{
	p.print(cout);
}

//operador texto
ostream& operator << (ostream & o, const Personaje& p)
{
	p.print(o);
	return o;
}


int main()
{
	Personaje p;
	Guerrero g;
	Mago m;
	atacar(m);


	cout << m << p << g << endl;
	system("PAUSE");
    return 0;
}

