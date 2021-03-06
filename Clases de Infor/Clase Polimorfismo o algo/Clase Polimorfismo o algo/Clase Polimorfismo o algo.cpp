// Clase Polimorfismo o algo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
//CLASE INTERFAZ sólo declara las funciones, hace un contrato para el resto de cosas que cuelguen de ella 

class IObjeto//tiene un método virtual puro => es abstracta, no se pueden crear IObjetos
{
	//por diseño no hay nombre porque quizás no todos tienen nombre
public:
	virtual string get_name() = 0;//no se tiene que definir y no se podrá utilizar para un IObjeto
	virtual int get_grosor() = 0;
};


class Arma :public IObjeto//vuelve a ser otra clase abstracta ya que le falta get_name SI NO TIENE TODOS LOS VIRTUAL ES TAMBIÉN ABSTRACTA
{
	int grosor;
public:
	virtual int get_grosor() { return grosor; }

};

class Espada:public Arma//hereda el get_grosor por lo que no es Abstracta
{
	string name;
public:
	Espada(string str="TIZONA"): name(str) {}
	string get_name() { return name; }//al cliente le da igual si está dentro o fuera que si por puntero accede a una Espada donde u Obj va ser público
};

//ejemplo de uso de la jerarquía 
string foo(IObjeto* o)
{
	return (o->get_name());
}
*/


class IFibo
{
public: 
	virtual int fibo(int n) = 0;
};

class FiboA : public IFibo
{
	int fibo(int n) { cout << "SOY FIBO_A" << endl; return 10; }//hacemos un mock function porque la algoritmia ya se meten los curritos = programadores
};


class FiboB : public IFibo
{
	int fibo(int n) { cout << "SOY FIBO_B" << endl; return 10; }
};


class FiboEngine //encapsulador (wrapper) de la función
{
	IFibo *pf;
public:
	FiboEngine(IFibo* p) :pf(p) {}
	int fibo(int n);
};


int FiboEngine::fibo(int n)
{
	return pf->fibo(n);
}


int main()
{
	/*
	Espada e;
	IObjeto* po = new Espada("EXCALIBUR");//se puede crear puntero a Obj
	cout << foo(&e) << endl;
	cout << po->get_name() << endl;
	*/
	FiboEngine f = new FiboA;
	f.fibo(10);

	FiboEngine f1 = new FiboB;
	f1.fibo(10);

	system("PAUSE");
    return 0;
}

