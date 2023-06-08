#ifndef Contenair_hpp
#define Contenair_hpp


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
class SortedContainer {
protected:
	int _n;
	double* _array;
public:
	//friend bool check(SortedContainer C1, SortedContainer C2);

	SortedContainer(int n);
	SortedContainer();
	SortedContainer(string txt, string folder);
	~SortedContainer();
	
	void save(string txt, string floder);

	//funciones puras
	void insert(double);
	void erase();
	void print();
	bool check(const SortedContainer& other) const;

};
//-------------------------------------------------------------------------------
class SortedTable: public SortedContainer{
public:
	using SortedContainer::SortedContainer;
	//SortedTable(int n);
};

class SortedList : public SortedContainer {
public:
	using SortedContainer::SortedContainer;
	//SortedList(int n);
};




#endif /*Contenair_hpp*/