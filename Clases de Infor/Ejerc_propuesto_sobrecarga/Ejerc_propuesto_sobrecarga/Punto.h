#pragma once
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

class Punto
{
	double x, y;
public:
	
	Punto(): x(0.0), y(0.0) {}
	Punto operator + (Punto);
	ostream & print( ostream& =cout) const;
	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	double get_x(void) const { return x; }
	double get_y(void) const { return y; }
	bool operator ! ();
	//friend Punto operator + (const Punto p1, const Punto & p2);
	//friend Punto operator + (double k, Punto p);
	Punto operator + (double k); //puede estar ya que el primer elemento es un punto; además hace que haya conmutabilidad
	Punto& operator = (const Punto& p)//NO RECOMENDABLE AQUÍ LA COPIA SUPERFICIAL VALE
	{
		if (this != &p)
		{
			this->x = p.x;
			this->y = p.y;
		}
		return *this;
	}

	friend ostream& operator<< (ostream& os, const Punto& obj);
	friend istream& operator>> (istream& os, Punto& obj);
	//string to_string();//aplanador por excelencia en C++
	//validador
	bool is_valid(); //definir cuando la lectura del punto sea lectura válida

	friend bool operator ==(const Punto& rhs, const Punto& lhs);
	friend bool operator !=(const Punto& rhs, const Punto& lhs);
	friend bool operator <(const Punto& rhs, const Punto& lhs);
	friend bool operator >(const Punto& rhs, const Punto& lhs);
	Punto& operator += (const Punto &rhs);
	friend Punto operator +(Punto lhs, const Punto& rhs);
	Punto& operator ++();
	Punto operator ++(int);


	//modulo
	double modulo()const;

};

