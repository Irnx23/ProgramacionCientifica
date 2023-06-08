#ifndef CTable_hpp
#define CTable_hpp

//LIBRERIAS----------------------------------------------------------------------
#include<bits/stdc++.h>

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<utility>
#include<assert.h>
#include<fstream>
#include<math.h>

using namespace std;

//-------------------------------------------------------------------------------
class CTable {
protected:
	int _n;
	double* _array;

public:
	CTable(int n);
	CTable(string txt, string folder);
	//toma un objeto tipo tabla y lo va a copiar
	CTable();

	~CTable();
	//funciones------------
	void print();
	void save(string txt, string floder);
	void Sort();
};

//------------------------------------------------------------------------------------
class CSortedTable :public CTable {
	//al hacer el public haces copy and paste de lo de antes
public:
	//funciones
	CSortedTable(int m) :CTable(m) { Sort(); };
	CSortedTable() :CTable() { Sort(); };
	void insert(double val);
	void erase();
};

//------------------------------------------------------------------------------------

/*
class List;

class List {
protected:
	int valores;
	double* lista;

public:
	void InsertList();

	void EraseList();

};

*/


#endif /*CTable_hpp*/