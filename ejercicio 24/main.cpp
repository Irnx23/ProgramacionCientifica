#include "CTable.hpp"

int main(int argc, const char* argv[]) {
	cout << "------EJERCICIO 24------" << endl;
	//crear tabla de tamano 10
	CSortedTable T(10);
		cout << "---TABLA INICIAL---" << endl;
	
	T.print();

	//EJERCICIO 24
	//SORT DE MANERA DECRECIENTE
	cout << "1. Agregamos el valor 150 a la tabla y ordenamos---" << endl;
	T.insert(150);
	T.Sort();
	T.print();
	cout << "2. Eliminamos el primer elemento de la tabla ---" << endl;
	T.erase();
	T.print();
	cout << "--------------" << endl;

	return 0;
}

