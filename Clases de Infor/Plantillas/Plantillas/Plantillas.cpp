// Plantillas.cpp: define el punto de entrada de la aplicación de consola.
//
#include  <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include "mi_template.h"


using namespace std;

template <typename T>

class Punto
{
	T x, y;
public:
	Punto(T x=0.0, T y=0.0):x(x),y(y){}
	double mod () const
	{
		return sqrt(x*x + y * y);
	}

	string to_string()
	{
		string res;
		stringstream sstr;

		sstr << "[" << x << "]" << "[" << y << "]" << endl;
		sstr >> res;

		return res;
	}

	template <class U>
	string to_string()
	{
		string res;
		stringstream sstr;

		sstr << "[" << static_cast<U> (x) << "]" << "[" << static_cast<U> (y) << "]" << endl;
		sstr >> res;

		return res;
	}
};

template <typename T>

bool operator < (const Punto<T>& lhs, const Punto<T>& rhs)
{
	return lhs.mod() < rhs.mod();
}

template <typename T>
class Less
{
public:
	//functor
	bool operator()(T &a, T &b) const ;//nace para servir, al mandale los dato spasa por aquí y realiza lo que estña dentro
};


template <typename T>
class Swap
{
public:
	void operator()(T& a, T& b);
};

//fucnion global par acalcular si un número es menor que otro
template <typename T>
bool less(T a, T b)
{
	return a < b;
}


int main()
{
	/*
	if (::less(3, 5))
		cout << "ES MENOR" << endl;

	Less<int> l;
	if(l(3,4))
		cout << "ES MENOR" << endl;
	system("PAUSE");

	if(Less<int>()(3,4))
		cout << "ES MENOR" << endl;
	*/
	/*
	Punto p1(1, 1);
	Punto p2(5, 7);
	
	if(Less<Punto>()(p1,p2))
		cout << "ES MENOR" << endl;
	if (::less(p1, p2))//con las funciones puedes obviar el <Punto> ya lo sane el 
		cout << "ES MENOR" << endl;
	Swap<Punto>()(p1, p2);
	cout << p1.to_string() << endl;
	*/
	
	Punto<double> p1(1, 1.5);
	Punto<double> p2(5.3, 7.6);

	if (Less<Punto<double>>()(p1, p2))
		cout << "ES MENOR" << endl;
	if (::less(p1, p2))//con las funciones puedes obviar el <Punto> ya lo sane el 
		cout << "ES MENOR" << endl;
	Swap<Punto<double>>()(p1, p2);
	cout << p1.to_string<int>() << endl;
	


	isEqual(3, 5);

	system("PAUSE");
    return 0;
}

template<typename T>
bool Less<T>::operator()(T& a, T& b) const
{
	return a<b;
}

template<typename T>
void Swap<T>::operator()(T & a, T & b)
{
	T aux = a;//requiere de contruct copia bien hecho y el de asignación
	a = b;
	b = aux;
}
