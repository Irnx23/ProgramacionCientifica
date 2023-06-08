#include "Contenair.hpp"

int main(int argc, const char* argv[]) {
	//EJERCICIO 26
	//contenedor---------------------------------------------------------------------------------------------------
	cout << "------EJERCICIO 26------" << endl;
	SortedContainer C1(10);
	cout << "---contenedor---" << endl;
	C1.print();
	C1.insert(234);
	C1.print();
	
	//-----------------------------------------
	bool proofCONT = C1.check(C1);

	if (proofCONT) {
		cout << "Verificacion EXITOSA" << endl;
	}
	else
	{
		cout << "No cumple con el sort de manera descendente" << endl;
	}
	//------------------------------------------
	
	cout << "---tabla---" << endl;
	SortedContainer* T1 = new SortedTable(15);
	//SortedTable T1(15);
	//T1->print();
	T1->insert(870);
	T1->print();
	T1->erase();
	T1->print();

	SortedContainer* L1 = new SortedList(8);
	cout << "---lista---" << endl;
	L1->insert(23);
	L1->print();
	L1->erase();
	L1->print();

	return 0;
}
