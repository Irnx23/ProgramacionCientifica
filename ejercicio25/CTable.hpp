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
#include<chrono>

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
public:
	//funciones
	CSortedTable(int m) :CTable(m) { Sort(); };
	CSortedTable() :CTable() { Sort(); };
	void insert(double val);
	void erase();
};

//------------------------------------------------------------------------------------


class SortedList {
protected:
	int valores;
	list <double> List;
public:
	SortedList(int L);
	SortedList();
	SortedList(string txt, string folder);
	~SortedList();

	void printList();
	void saveList(string txt, string floder);
	void InsertList(double val);
	void EraseList();

};


#endif /*CTable_hpp*/