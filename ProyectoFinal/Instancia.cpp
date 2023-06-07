//
//  Instancia.cpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//

#include "Instancia.hpp"
#include <vector>
typedef IloArray<IloBoolVarArray> BoolVarMatrix;

Instance::Instance(int n, string filename){
    _n=n;
    _filename=filename;
    _asignacioncostos=vector<vector<AsignacionCostos>>(_n, vector<AsignacionCostos>(_n, AsignacionCostos(0, 0, 0)));

    for (int i = 0; i < _n; ++i) {
        for(int j=0;j<_n;++j){
            int x=rand()%(1000+1);
            _asignacioncostos[i][j] = AsignacionCostos(i, j, x);
        }
    }
}
//---------------------------------------------------------------

void Instance::print(){
    cout << "Instance Name: " << _filename << endl;
       cout << "#nodes: " << _n << endl;
       for (int i = 0; i < _n; i++) {
           for (int j = 0; j < _n; j++) {
               cout << "numTrabajadores: " << _asignacioncostos[i][j].getNumTrabajadores() << ", ";
               cout << "numTrabajo: " << _asignacioncostos[i][j].getNumTrabajo() << ", ";
               cout << "costo: " << _asignacioncostos[i][j].getCosto() << endl;
           }
       }
}
//---------------------------------------------------------------

void Instance::save(){
       ofstream output ("Instancia/"+_filename);
       assert(output.is_open());
        output<<_n<<endl;
        int w=20;
        for(int i=0;i<_n;i++){
            for(int j=0;j<_n;j++){
                output << setw(w) << _asignacioncostos[i][j].getNumTrabajadores() << setw(w) << _asignacioncostos[i][j].getNumTrabajo() << setw(w) << _asignacioncostos[i][j].getCosto() << endl;
                   
            }
        }
        output<<endl;
    
        output.close();
}
//---------------------------------------------------------------
Instance::~Instance()
{}
//---------------------------------------------------------------
int Instance:: getCosto(int i, int j) const{
    int a=_asignacioncostos[i][j].getCosto();
    return a;
}

//---------------------------------------------------------------

Instance::Instance(string filename)
{
    _filename = filename;
    ifstream input("Instancia/" + _filename);
    assert(input.is_open());
    input >> _n;
    cout << _n << endl;
    
    _asignacioncostos=vector<vector<AsignacionCostos>>(_n,vector<AsignacionCostos>(_n, AsignacionCostos(0, 0, 0)));
    
    for(int i=0;i<_n;i++){
        for (int j = 0; j < _n; ++j) {
            int a, b, c;
            input >> a >> b >> c;
            _asignacioncostos[i][j] = AsignacionCostos(a, b, c);
        }
    }
    
    cout << "Leyendo lo almacenado en el vector." << endl;
    
//    for (const auto& fila : _asignacioncostos) {
//        for (const auto& elemento : fila) {
//            std::cout << "Trabajador: " << elemento.numTrabajadores << ", ";
//            std::cout << "Trabajo: " << elemento.numTrabajo << ", ";
//            std::cout << "Costo: " << elemento.costo << std::endl;
//            
//        }
//    }
    
    
}



