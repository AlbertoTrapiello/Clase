// Clase.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <fstream>
#include "Punto.h"
using namespace std;


Punto operator + (double k, Punto p)//para que se haga la suma de k+p, y se aconmutativo con la función miembro
{
	Punto res(p);
	res.x += k;
	res.y += k;
	return res;
}

int main()
{
	
	Punto p2;
	Punto p1;
	p1.set_x(10); p1.set_y(20);
	(p1.operator+(p1)).print();//llamada a la función miembro que tiene qu diferenciarse de la independiente
	(operator+(p2, p1)).print();//llamada a la función independiente definiendo sus parámetros para diferenciarla de la función miembro

	ofstream f("Punto.txt", ios::out);
	if (!f)
	{
		cout << "error al abrir el fichero" << endl;
	}
	(p1.operator+(p2)).print(f);//llamada a la función miembro que tiene qu diferenciarse de la independiente
	(operator+(p2, p1)).print(f); 
	
	int k = 10;

	//test del NOT
	if (!p2)
		p2.print();
	(p1 + k).print();
	(k + p1).print();
	
	//operador asignación predefinido siempre, si requiere coipia profunda crear el operator que copie profundo
	p1 = p2;
	p1.print();
	p2.print();
	system("PAUSE");
    return 0;
}


