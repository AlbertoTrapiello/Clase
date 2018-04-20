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

Punto operator + (const Punto a, const Punto & b)
{
	Punto res(a);
	res.x += b.x;
	res.y += b.y;
	return res;
}



