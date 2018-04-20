// Ejerc_propuesto_sobrecarga.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include "Punto.h"

using namespace std;

ostream & operator<<(ostream & os, const Punto& obj)
{
	// TODO: insertar una instrucción return aquí
	os << "El punto tiene como coordenadas:\nX=[" << obj.get_x() << "], Y=[" << obj.get_y() << "]" << endl;
	return os;
}
istream& operator>> (istream& is, Punto& obj)//se entiende que dentro del flujo vendrán las coordenadas del punto, primero la x y luego la y
{
	is >> obj.x >> obj.y;
	return is;
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
	system("PAUSE");
    return 0;
}

