//revisar configuracion
#include "CTable.hpp"

//-----------------------------------------------------------------------------------------------
CTable::CTable(int n) {
	_n = n;
	_array = new double[_n];

	for (int i = 0; i < _n; ++i) _array[i] = 100.0 * (double)(rand() % 10001 / 1000.0);
}

//inicializar tabla vacia - tamano 0
CTable::CTable() {
	CTable(0);
}

CTable::CTable(string txt, string folder) {
	ifstream archivo(folder + txt);
	archivo >> _n;
	
	_array= new double[_n];
	for (int i = 0; i < _n; i++) archivo >> _array[i];
}


CTable::~CTable() {
	delete[]_array;
}

void CTable::print() {
	int w = 10;
	for (int i = 0; i < _n; i++) {
		cout << setw(w) << _array[i] << " ";
	}
	cout << endl;
}

void CTable::save(string txt, string folder) {
	ofstream archivo(folder + txt);
	archivo << _n << endl;
	for (int i = 0; i < _n; i++)
		archivo << _array[i] << " ";
}

void CTable::Sort() {
	//ESPECIFICA INICIO, FIN 
	//QUEREMOS EL ORDEN SEA MAYOR A MENOR
	//AGREGAMOS UN 3er parametro
	sort(_array, _array + _n,greater<int>());
}

//-----------------------------------------------------------------------------------------------
void CSortedTable::insert(double val) {
	double* oldarray = _array;
	_n++; 
	_array = new double[_n + 1];
	_array[0] = val;
	for (int i = 1; i < _n; i++) _array[i] = oldarray[i - 1];
	delete[] oldarray;
}

void CSortedTable::erase() {
	//si hay un arreglo de tamano 1 , no lo leo, solo lo omites
	if (_n == 1) {
		_n--;  //eliminamos, no se puede mostrar valores
	}
	else {
		_n--;
		double* oldarray = _array;
		//_n--;
		_array = new double[_n];
		//_array[0] = val;
		for (int i = 0; i < _n; i++) _array[i] = oldarray[i + 1];
		delete[] oldarray;
	}
}

//-----------------------------------------------------------------------------------------------
