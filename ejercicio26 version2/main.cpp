#include "Contenair.hpp"

int main(int argc, const char* argv[]) {
	//EJERCICIO 26
	//contenedor---------------------------------------------------------------------------------------------------
	cout << "------EJERCICIO 26------" << endl;
	SortedContainer C1(10);
	cout << "---contenedor---" << endl;
	std::chrono::steady_clock::time_point _startCon(std::chrono::steady_clock::now());
	C1.insert(234);
	C1.print();
	C1.erase();
	C1.print();
	
	//-----------------------------------------
	bool proofCONT = C1.check(C1);
	cout << "--------------------------------------" << endl;
	if (proofCONT) {
		cout << "Verificacion SORT EXITOSA" << endl;
	}
	else
	{
		cout << "No cumple con el sort de manera descendente" << endl;
	}
	cout << "--------------------------------------" << endl;
	std::chrono::steady_clock::time_point _endCon(std::chrono::steady_clock::now());
	double timeCon = std::chrono::duration_cast<std::chrono::duration<double>>(_endCon - _startCon).count();
	cout << "CPU Time Contenedor (insert/erase/check/print): " << timeCon << " seconds" << endl;
	cout << "--------------------------------------" << endl;
	
	//-----------------------------------------------------------------------------------------------------------------------------------
	
	cout << "---tabla---" << endl;
	SortedContainer* T1 = new SortedTable(20);
	//SortedTable T1(15);
	//T1->print();
	std::chrono::steady_clock::time_point _startTab(std::chrono::steady_clock::now());
	T1->insert(870);
	T1->print();
	T1->erase();
	T1->print();
	std::chrono::steady_clock::time_point _endTab(std::chrono::steady_clock::now());
	double timeTab = std::chrono::duration_cast<std::chrono::duration<double>>(_endTab - _startTab).count();
	cout << "--------------------------------------" << endl;
	cout << "CPU Time Contenedor (insert/erase/print): " << timeTab << " seconds" << endl;
	cout << "--------------------------------------" << endl;

	//-----------------------------------------------------------------------------------------------------------------------------------

	SortedContainer* L1 = new SortedList(20);
	std::chrono::steady_clock::time_point _startList(std::chrono::steady_clock::now());
	cout << "---lista---" << endl;
	L1->insert(23);
	L1->print();
	L1->erase();
	L1->print();
	std::chrono::steady_clock::time_point _endList(std::chrono::steady_clock::now());
	double timeList = std::chrono::duration_cast<std::chrono::duration<double>>(_endList - _startList).count();
	cout << "--------------------------------------" << endl;
	cout << "CPU Time Contenedor (insert/erase/print): " << timeList << " seconds" << endl;
	cout << "--------------------------------------" << endl;

	//COMPARACION TIEMPO DE EJECUCION-----------------------------------------------------------------------------
	cout << "--------Comparacion CPU TIME-------- " << endl;
	cout << "El CPU TIME (print/insert/erase) TABLA vs LISTA" << endl;
	if (timeTab < timeList) {
		cout << "Tabla MENOR Lista " << endl;
		cout << "CPU TIME Tabla: " << timeTab << " < " << timeList << endl;
	}
	else {
		if (timeTab == timeList) {
			cout << "Tabla IGUAL Lista " << endl;
			cout << "CPU TIME Tabla: " << timeTab << " = " << timeList << endl;
		}
		else
		{
			cout << "Tabla MAYOR Lista " << endl;
			cout << "CPU TIME Tabla: " << timeTab << " > " << timeList << endl;
		}

	}
	cout << "--------------------------------------" << endl;


	return 0;
}
