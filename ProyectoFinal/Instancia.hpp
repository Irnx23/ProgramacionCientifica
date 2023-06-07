//
//  Instancia.hpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//
#pragma once
#include "Header.hpp"

using namespace std;
class Instance;
class AsignacionCostos{
    int numTrabajadores, numTrabajo,costo;
public:
    friend class Instance;
    AsignacionCostos(int a,int b,int c){
        numTrabajadores=a;
        numTrabajo=b;
        costo=c;
    }
    int getNumTrabajadores() const {
        return numTrabajadores;
    }
    
    int getNumTrabajo() const {
        return numTrabajo;
    }
    
    int getCosto() const{
        return costo;
    }
};

class Instance{
    int _n;
    string _filename;
    vector<AsignacionCostos*>_AC;
    //AsignacionCostos**_asignacioncostos;
    vector<vector<AsignacionCostos>> _asignacioncostos;
public:
    int getCosto(int i, int j) const; //-------
    int getNumTrabajadores(int i) const;
    int getNumTrabajo(int i) const;
    Instance(int n,string filename);
    Instance(string filename);
    void print();
    void save();
    int size(){return _n;}
    //const vector<vector<AsignacionCostos>>& getAsignacionCostos() const {
       // return _asignacioncostos;}
    ~Instance();
};
