#include "Contenair.hpp"

//------------------------------------------------------
SortedContainer::SortedContainer(int n) {
	_n = n;
	_array = new double[_n];

	for (int i = 0; i < _n; ++i) _array[i] = 100.0 * (double)(rand() % 10001 / 1000.0);
	sort(_array, _array + _n, greater<int>());
}

SortedContainer::SortedContainer() {
	SortedContainer(0);
}

SortedContainer::SortedContainer(string txt, string folder) {
	ifstream archivo(folder + txt);
	archivo >> _n;
	_array = new double[_n];
	for (int i = 0; i < _n; i++) archivo >> _array[i];
}

SortedContainer::~SortedContainer() {
	delete[]_array;
}

//------------------------------------------------------
void SortedContainer::save(string txt, string folder) {
	ofstream archivo(folder + txt);
	archivo << _n << endl;
	for (int i = 0; i < _n; i++)
		archivo << _array[i] << " ";
}
//------------------------------------------------------
/*
bool check(SortedContainer& C1, SortedContainer& C2) {
	if (C1._n != C2._n)
		return false;   //si no coincide los tamanos - false

	for (int i = 0; i < C1._n; i++)
		if (C1._array[i] != C2._array[i]) return false;  //si el valor es diferente - false

	return true;
}
*/

bool SortedContainer::check(const SortedContainer& verificacion) const {
	if (_n != verificacion._n)
		return false;   // diferente tamano - false

	for (int i = 0; i < _n; i++) {
		if (_array[i] != verificacion._array[i])
			return false;  // si los valores son diferentes - false
	}

	for (int i = 0; i < _n-1; i++) {
		if (_array[i] <= verificacion._array[i+1])
			return false;  // menor que el siguiente - false
	}

	return true;
}



void SortedContainer::insert(double val) {
	double* oldarray = _array;
	_n++;
	_array = new double[_n + 1];
	_array[0] = val;
	for (int i = 1; i < _n; i++) _array[i] = oldarray[i - 1];
	sort(_array, _array + _n, greater<int>());
	delete[] oldarray;
}

void SortedContainer::erase() {
	if (_n == 1) {
		_n--;  //eliminamos
	}
	else {
		_n--;
		double* oldarray = _array;
		_array = new double[_n];
		for (int i = 0; i < _n; i++) _array[i] = oldarray[i + 1];
		delete[] oldarray;
	}
}

void SortedContainer::print() {
	int w = 10;
	for (int i = 0; i < _n; i++) {
		cout << setw(w) << _array[i] << " ";
	}
	cout << endl;
}
//---------------------------------------------------------------------


