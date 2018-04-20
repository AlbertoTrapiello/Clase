#include "Punto.h"

Punto Punto::operator+(Punto b)
{
	Punto res(*this);//puede copiarse a sí mismo
	res.x += b.x;
	res.y += b.y;

	return res;
}

ostream & Punto::print( ostream & o) const //marshalling??? conversión o aplanamiento de un obj a ascii
{
	// TODO: insertar una instrucción return aquí
	o << "X " << this->x << " Y " << this->y << endl ;
	return o;
}
bool Punto::operator!()
{
	return (this->x == 0.0 && this->y == 0.0);
}

Punto Punto::operator+(double k)
{
	Punto res(*this);
	res.x += k;
	res.y += k;
	return res;
}

/*string Punto::to_string()
{
	stringstream sstr;//saben convetir todo a flujo 
	sstr << "[" << this->x << "] [" << this->y << "]" << endl;
	string res(sstr.str);//constructor copia 

	return string();
}*/

bool Punto::is_valid()
{
	//código de validación del protocolo...
	return false;
}

Punto & Punto::operator+=(const Punto & rhs)
{
	// TODO: insertar una instrucción return aquí
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

double Punto::modulo() const
{

	return sqrt(this->x*this->x+this->y*this->y);
}

/*Punto operator + (const Punto a, const Punto & b)
{
	Punto res(a);
	res.x += b.x;
	res.y += b.y;
	return res;
}
*/


bool is_valid()
{
	return 1;
}
Punto& Punto::operator ++()
{
	this->x++;
	this->y++;
	return *this;
}

Punto Punto::operator ++(int)
{
	Punto tmp(*this);
	operator++();
	return tmp;
}