//
//  Solucionador.hpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 06/06/23.
//



#include <stdio.h>
#include"Header.hpp"
#include "Instancia.hpp"
typedef int param_t;

class Solucion{
    IloEnv env; //ambiente, solo inicializarlo
    IloCplex _cplex; //Solver (El decide como se resuelve, si tiene variables enteras se hace por programacion lineal, si tiene una variable diferente, el decide como resolverlo)
    IloModel _model; //Constructor
    IloObjective _obj; // An instance is an objetive in a model.
    IloRangeArray _Constraints; //Condiciones
    IloArray< IloNumVarArray >  _x; //"_x" arreglo bidimensional, "IloArray" implementacion de un arreglo dinamico, "IloNumVarArray" arreglo de variables de desición.
    
protected:
    Instance* _I;
    string _name;
    chrono::time_point<chrono::system_clock> _start;
    chrono::time_point<chrono::system_clock> _end;

    void startTimer() { _start = chrono::system_clock::now(); }
    void stopTimer() { _end = chrono::system_clock::now(); }
public:
    string name() { return _name; } //Funcion para poder leer el nombre de la instancia.
    Solucion(Instance* I);

    void saveAsignacion(Instance *I,string OutputFile="");
    void saveDatos(Instance *I,string outputFile="");
    double cpuTime() { return chrono::duration_cast<std::chrono::seconds>(_end - _start).count(); }
    bool isFeasible(Instance*I);
};

