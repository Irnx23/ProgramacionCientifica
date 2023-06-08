#include "CTable.hpp"

int main(int argc, const char* argv[]) {
	//EJERCICIO 24
	//TABLA---------------------------------------------------------------------------------------------------
	cout << "------EJERCICIO 24------" << endl;
	//crear tabla de tamano 10
	CSortedTable T(10);
	cout << "---TABLA INICIAL---" << endl;

	T.print();

	cout << "1. Agregamos el valor 150 a la tabla y ordenamos---" << endl;
	std::chrono::steady_clock::time_point _starttable(std::chrono::steady_clock::now());
	T.insert(150);
	T.Sort();
	T.print();
	cout << "2. Eliminamos el primer elemento de la tabla ---" << endl;
	T.erase();
	std::chrono::steady_clock::time_point _endtable(std::chrono::steady_clock::now());
	T.print();
	cout << "--------------" << endl;
	double timeTable = std::chrono::duration_cast<std::chrono::duration<double>>(_endtable - _starttable).count();
	cout << "CPU Time: " << timeTable <<" seconds"<<endl;
	cout << "--------------" << endl;
	
	//EJERCICIO 25
	//LISTA----------------------------------------------------------------------------------------------------
	cout << "------EJERCICIO 25------" << endl;
	SortedList L(15);
	cout << "---LISTA INICIAL---" << endl;
	L.printList();
	cout << "1. Agregamos el valor 32 a la lista y ordenamos---" << endl;
	std::chrono::steady_clock::time_point _startlist(std::chrono::steady_clock::now());
	L.InsertList(32);
	L.printList();
	cout << "2. Eliminamos el primer elemento de la lista ---" << endl;
	L.EraseList();
	std::chrono::steady_clock::time_point _endlist(std::chrono::steady_clock::now());
	L.printList();
	cout << "--------------" << endl;
	double timeList = std::chrono::duration_cast<std::chrono::duration<double>>(_endlist - _startlist).count();
	cout << "CPU Time: " << timeList << " seconds" << endl;
	cout << "--------------" << endl;

	//COMPARACION TIEMPO DE EJECUCION-----------------------------------------------------------------------------
	cout << "Comparacion CPU TIME " << endl;
	if (timeTable < timeList) {
		cout << "El CPU TIME que requiere insertar y eliminar una TABLA es MENOR a realizar con una LISTA" << endl;
		cout << "CPU TIME Tabla" << timeTable << " < "<< timeList<<endl;
	}
	else {
		if (timeTable == timeList) {
			cout << "El CPU TIME que requiere insertar y eliminar una TABLA es IGUAL que para realizarlo con una lista" << endl;
			cout << "CPU TIME Tabla" << timeTable << " = " << timeList << endl;
		}
		else
		{
			cout << "El CPU TIME que requiere insertar y eliminar una TABLA es MAYOR a realizar con una LISTA" << endl;
			cout << "CPU TIME Tabla" << timeTable << " > " << timeList << endl;
		}

	}


	return 0;
}

