// Clase_20_04.cpp: define el punto de entrada de la aplicación de consola.
//


#include <iostream>
#include <vector>

using namespace std;
class Lista
{
	int size;
	int capacity;
	int *buffer;
public:
	Lista(int size) :size(size), capacity(size)
	{
		buffer = new int[size];
	}
	~Lista() { delete buffer; }
	int& operator [] (int pos) { return buffer[pos]; }//a lo bruto, se suele hacer una función add que controla las condiciones para añadir cosas
	const int& operator [] (int pos) const { return buffer[pos]; }//tienen que estar ambos para que pueda usar con y sin const
};

int main()
{
	Lista l(10);
	l[0] = 8;
	std::vector<int> n;
	n.push_back(10);
	cout << l[10];
    return 0;
}

