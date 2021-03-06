// Clase Herencias.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <string>

using namespace std;

class PuntoBase
{
public:
	enum tipo_t {CRUZ=0, ESTRELLA, CIRCULO };//ES PUBLCO PERO PREVIO PASO POR PUNTOBASE
	enum col_t {AZUL=0, ROJO, NEGRO};//si se llama en otro sitio necesita de PuntoBase::
	static string to_string_col(col_t);//funciones que no dependan del estado de la clase se puede poner como static
	static string to_string_type(tipo_t);
	int get_id()const { return id; }
	void set_id(int id) { this->id = id; }
	PuntoBase(int i) { id = i; }

protected:
	int id;
	ostream & print(ostream & = cout);
	//PuntoBase(int i) { id = i; }
};

class Punto: public PuntoBase //id es también de Punto, aunque no pueda acceder  ello, las clases de 
{
	double x, y;
public:
	Punto(int id= 0.0, double x = 0.0, double y = 0.0);//cuenta como constr copia sin argm
	ostream & print (ostream & = cout);//a ser distintos tipos te deja aunque heredes print, no debería colisionar
	Punto& operator =(const Punto &);
};


class PuntoGordo :public Punto
{
	tipo_t forma;//datos
	col_t color;
public:
	PuntoGordo(const Punto&, tipo_t t, col_t c);
	ostream & print(ostream & = cout);
	PuntoGordo& operator =(const PuntoGordo &);
	PuntoGordo(const PuntoGordo &);

};


//funcion gobal que gestiona puntos

void foo(Punto& p)//se tragaría los tipos de abajo "UPCAST" es que se convierte todos los tipos de abajo al de arriba, 
{
	p.print();
}

int main()
{
//	PuntoBase pb(1); una vez puesto el constructor protected
	Punto p(8, 1.0, 3.0);
	p.print();
	//PuntoBase pb(7);
	//pb.print();
	//p.PuntoBase::print(); si hay que imprimir solo desde el PuntoBase

	PuntoGordo pg(p, PuntoGordo::ESTRELLA, PuntoGordo::AZUL);//ESTRELLA está dentro de PuntoBase por lo que desde fuera  no pueder acceder a ella sin scope
	//funcionaría el PuntoBase:: pero el cliente no tiene por qué conocer el PuntoBase 
	pg.print();
	foo(p);
	//UPCAST
	foo(pg);//ya se verá lo que hace, pero te deja
	PuntoGordo* pPG=&pg;
	pPG->print();
	Punto* pP = pPG;//es feo pero funciona, seguramente pase sin querer. Pierdes la parte de su naturaleza que pertenece a PuntoGordo
	pP->print();

	//asignar puntos
	PuntoGordo pg1(pg);//como no hay constr copia va copiando por niveles de arriba a abajo
	pg1.print();
	pg.set_id(100);
	pg1 = pg;//funcionan ambos, si no hace falta no lo toques
	pg1.print();



	system("PAUSE");
    return 0;
}

string PuntoBase::to_string_col(col_t c)
{
	string res;
	switch (c)
	{
	case AZUL:
	{
		res = "AZUL";
		break;
	}
	case ROJO:
	{
		res = "ROJO";
		break;
	}case NEGRO:
	{
		res = "NEGRO";
		break;
	}
	
	}
	return res;
}

string PuntoBase::to_string_type(tipo_t t)
{
	string res;

	switch (t)
	{
	case CRUZ:
	{
		res = "CRUZ";
		break;
	}
	case ESTRELLA:
	{
		res = "ESTRELLA";
		break;
	}case CIRCULO:
	{
		res = "CIRCULO";
		break;
	}

	}

	return res;
}

ostream & PuntoBase::print(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	o << "ID: " << id << endl;//no puedes ver los enum porque son como typedef, no tienen nada, sólo tienes el ID
	return o;
}

Punto::Punto(int id, double x, double y)
	:	PuntoBase(id),	x(x),  y(y)	//al igual que cuando tienes otra clase dentro de tu clase, hay que construirlo antes
{
	//...
}

ostream & Punto::print(ostream & o)
{
	PuntoBase::print(o) << "X: " << x << " Y: " << y << endl;//llamas a la otra función aquí 
	// TODO: insertar una instrucción return aquí
	return o;
}

Punto& Punto::operator=(const Punto& p)//cuando igual empezará por PuntoBase y usará el predet, cuando llegue a lo de Punto usará el definido
{
	cout << "LLAMANDO AL OPERADOR ASIGNACIÓN DEL PUNTO" << endl;
	if (this != &p)
	{
		this->x = p.x;
		this->y = p.y;
		this->id=p.id;//te haces responsable de copiar bien, de modo que si lo haces sin esto no copiará el id
	}
	return *this;
}

PuntoGordo& PuntoGordo::operator=(const PuntoGordo& pg)//cuando igual empezará por PuntoBase y usará el predet, cuando llegue a lo de Punto usará el definido
{
	cout << "LLAMANDO AL OPERADOR ASIGNACIÓN DEL PUNTOGORDO" << endl;
	if (this != &pg)
	{
		Punto::operator=(pg);
		this->forma = pg.forma;
		this->color = pg.color;
	}
	return *this;
}

PuntoGordo::PuntoGordo(const PuntoGordo &pg): Punto(pg)//si hubiera constrc de Punto sin argumentos, llamaría al de arriba para construir antes de entrar el Punto, no necesitarías la lista de inicialización
{
	//construir lo mío, lo otro ya se hará 
}

PuntoGordo::PuntoGordo(const Punto & p, tipo_t t, col_t c): Punto(p)
{
	this->forma = t;
	this->color = c;
}

ostream & PuntoGordo::print(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	Punto::print();
	o << to_string_type(this->forma) << " ";//Estamos dentro de PuntoGord que contiene lo de PuntoBase
	o << to_string_col(this->color) << endl;
	return o;
}
