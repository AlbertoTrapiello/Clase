// Ejerc_propuesto_sobrecarga.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include "Punto.h"
#include <fstream>
using namespace std;

ostream & operator<<(ostream & os, const Punto& obj)//sobra el friend, para necesitar friend no se usaría el get_x
{
	// TODO: insertar una instrucción return aquí
	os << "El punto tiene como coordenadas:\nX=[" << obj.get_x() << "], Y=[" << obj.get_y() << "]" << endl;
	return os;
}
/*istream& operator>> (istream& is, Punto& obj)//se entiende que dentro del flujo vendrán las coordenadas del punto, primero la x y luego la y
{
	is >> obj.x >> obj.y;
	return is;
}*/
istream& operator>> (istream& is, Punto& obj)//se entiende que dentro del flujo vendrán las coordenadas del punto, primero la x y luego la y
{
	char token;

	//lee punto, se podría poner en una línea 
	is >> token;
	is >> obj.x;
	is >> token;
	is >> obj.y;
	is >> token;//para mantener el protocolo

	/*if (!obj.is_valid)
	{
		//tratamiento error
		is.setstate(ios::failbit);// pone a estado de fallo el flujo
	}*/
	return is;
}

bool operator ==(const Punto& rhs, const Punto& lhs)
{
	return(lhs.x == rhs.x&&lhs.y == rhs.y);
}
bool operator !=(const Punto& rhs, const Punto& lhs)
{
	return ! operator==(lhs,rhs);
}

bool operator <(const Punto& rhs, const Punto& lhs)
{
	return(lhs.modulo()<rhs.modulo() );
}

bool operator >(const Punto& rhs, const Punto& lhs)
{
	return(rhs.modulo()<lhs.modulo());
}

Punto operator +(Punto lhs, const Punto& rhs)
{
	lhs += rhs;
	return lhs;
}

int main()
{
	Punto p;
	p.set_x(5);
	p.set_y(6);
	p.get_x();
	cout << p << endl;
	cout << "Introduzca valores: " << endl;
	cin >> p;
	cout << p << endl;
	//cout << p.to_string;

	system("PAUSE");
    return 0;
}

