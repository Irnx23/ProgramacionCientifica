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
        startTimer(); //Comienza a contar el cronometro
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
    _cplex.solve();
        
    if (_cplex.getStatus() == IloAlgorithm::Optimal) {
        cout<<"Solucion optima encontrada."<<endl;
    } else {
        std::cout << "No feasible solution found." << std::endl;
    }
} catch (IloException& e) {
    std::cout << "Error: " << e << std::endl;
} catch (...) {
    std::cout << "Unknown exception occurred." << std::endl;
}
//env.end();
    stopTimer(); //Para el cronometro
    
}

//---------------------------------------------------------------

void Solucion::saveAsignacion(Instance* I,string OutputFile){
    int w=10;
    int size=I->size();
    if(OutputFile==""){
        OutputFile="Output/"+to_string(size)+"_Asignacion.txt";
        }
    ofstream output(OutputFile, ios::app);
    cout<<OutputFile<<endl;
    assert(output.is_open());
    output<<"La solución optima fue encontrada, con un costo total de: "<< _cplex.getObjValue() << endl;
        output<<"Con la siguiente asignacion:"<<endl;
        output<<"Trabajador -> Trabajo = Costo"<<endl;
        for (int i = 0; i <I->size(); ++i) {
            for (int j = 0; j < I->size(); ++j) {
                if (_cplex.getValue(_x[i][j]) > 0.5) {
                    int dij=I->getCosto(i,j);
                    output<<setw(w)<<"["<<i<<"]"<<setw(7)<<" -> "<<setw(3)<<"["<<j<<"]"<<setw(w)<<" = "<<dij<<endl;
                }
            }
        }
    output<<endl;
    output.close();
}

    
void Solucion::saveDatos(Instance *I,string outputfile){
    bool a= isFeasible(I);
        int w=5;
        if (outputfile==""){
            outputfile="Output/"+to_string(I->size())+"_Datos.txt";
        }
        ofstream output(outputfile,ios::app);
        output<<"Nombre"<<setw(3*w)<<"#nodes"<<setw(3*w)<<"CpuTime"<<setw(2*w)<<"Fitness"<<endl;
        ofstream Output(outputfile,ios::app);
                assert(Output.is_open());
                Output<<I->getFilename()<<setw(2*w)<<I->size()<<setw(2*w)<<cpuTime()<<setw(2*w)<<a<<setw(2*w)<<endl;
                
        Output.close();
    }
//--------------------------------------------------------
bool Solucion::isFeasible(Instance *I)
{
    vector<string> ErrorMessage;

    int* count = new int[I->size()];
    for (int i = 0; i < I->size(); i++) {
        count[i] = 0;
    }

    for (int i = 0; i < I->size(); i++) {
        for (int j = 0; j < I->size(); j++) {
            if (_cplex.getValue(_x[i][j]) > 0.5) {
                count[i]++;
            }
        }
    }

    for (int i = 0; i < I->size(); i++) {
        if (count[i] == 0) {
            ErrorMessage.push_back("Error: Trabajador " + to_string(i) + " no ha sido asignado");
        }
        else if (count[i] > 1) {
            ErrorMessage.push_back("Error: Trabajador " + to_string(i) + " ha sido asignado " + to_string(count[i]) + " veces");
        }
    }

    delete[] count;
    return ErrorMessage.empty();
}

    
