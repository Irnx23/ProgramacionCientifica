//
//  Solucionador.cpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 06/06/23.
//

#include "Solucionador.hpp"

//---------------------------------------------------------------
Solucion::Solucion(Instance *I){

    try {
        _model=IloModel(env);
        _cplex=IloCplex(_model);
        _obj = IloAdd(_model, IloMinimize(env, 0) );
        _Constraints=IloRangeArray(env);

        _x=IloArray<IloNumVarArray>(env,I->size());
        for(int i=0;i<I->size();i++){
            _x[i]=IloNumVarArray(env);
        }
        for (int i = 0; i <I->size(); ++i) {
            _x[i] = IloNumVarArray(env);
            for (int j = 0; j <I->size(); ++j) {
            std::string label = "x_" + std::to_string(i) + "_" + std::to_string(j);
                _x[i].add(IloNumVar(env,0,1,ILOINT,label.c_str()));
            }
        }
        
     //Restricciones
    for (int i = 0; i <I->size(); ++i) {
        IloExpr rowSum(env);
        for (int j = 0; j < I->size(); ++j) {
            rowSum +=_x[i][j];
        }
        _Constraints.add(rowSum == 1);
    }
    for (int j = 0; j <I->size(); ++j) {
        IloExpr colSum(env);
        for (int i = 0; i <I->size(); ++i) {
            colSum += _x[i][j];
        }
        _Constraints.add(colSum == 1);
    }
        
    //Objetivo
    IloExpr obj(env);
    for (int i = 0; i <I->size(); ++i) {
        for (int j = 0; j <I->size(); ++j) {
            int dij=I->getCosto(i, j);
            obj += dij * _x[i][j];
        }
    }
    _obj.setExpr(obj);
    _model.add(_Constraints);
    _cplex.exportModel("Model.lp");
//-----------------------------------------------------------
    // Solución

    _cplex=IloCplex(_model);
    auto start_time=chrono::high_resolution_clock::now();
    _cplex.solve();
    auto end_time= chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end_time-start_time);
        
      duration=(duration/10000);
        
        
    char _filename;
    _filename=I->size();
        int w=5;
    if (_cplex.getStatus() == IloAlgorithm::Optimal) {
        ofstream output("Output/"+to_string(_filename)+".txt");
       // std::cout << "La solución optima fue encontrada, con un costo total de: " << _cplex.getObjValue() << std::endl;
        output<<"La solución optima fue encontrada, con un costo total de: "<< _cplex.getObjValue() << endl;
        output<<"Con un tiempo aproximado de: "<<duration.count()<<"ms"<<endl;
        output<<"Con la siguiente asignacion:"<<endl;
        output<<"Trabajador -> Trabajo = Costo"<<endl;
        for (int i = 0; i <I->size(); ++i) {
            for (int j = 0; j < I->size(); ++j) {
                if (_cplex.getValue(_x[i][j]) > 0.5) {
                    int dij=I->getCosto(i,j);
                    output<<setw(w)<<"["<<i<<"]"<<setw(7)<<" -> "<<setw(3)<<"["<<j<<"]"<<setw(w)<<" = "<<dij<<endl;
                  //  std::cout << "Trabajador " << i << " Trabajo asignado " << j <<", Con valor de:" <<dij<< std::endl;
                }
            }
        }
        
    } else {
        std::cout << "No feasible solution found." << std::endl;
    }
} catch (IloException& e) {
    std::cout << "Error: " << e << std::endl;
} catch (...) {
    std::cout << "Unknown exception occurred." << std::endl;
}
env.end();

}

//---------------------------------------------------------------

void Solucion::saveresults(Instance* I,string OutputFile){
   int size=I->size();
    if(OutputFile==""){
        OutputFile="Output/"+to_string(size)+"_prueba.txt";
    }
    ifstream input(OutputFile);
    ofstream output(OutputFile,ios::app);
    int w=10;
    
    if(!input.is_open() ){
        output=ofstream(OutputFile);
        assert(output.is_open());
        output<<setw(2*w)<<"#nodes"<<setw(2*w)<<"Solver"<<setw(w)<<"TimLim"<<setw(w)<<"Fitness"<<setw(w)<<"cpuTime"<<setw(w)<<"Gap"<<setw(w)<<"Feas"<<endl;
        output<<setw(2*w)<<I->size()<<setw(2*w)<<endl;

    }
    else input.close();
    
    }

