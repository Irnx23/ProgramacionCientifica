//
//  MIPSolver.cpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//

#include "MIPSolver.hpp"
#include "Instancia.hpp"
MILPSolver::MILPSolver(Instance*I):Solver(I,"MILPSolver"){
    const vector<vector<AsignacionCostos>>&asignacioncostos=I->getAsignacionCostos();
    try{
           _model=IloModel(env);
           _cplex=IloCplex(_model);
        _x=IloArray<IloNumVarArray>(env,I->size());
        for(int i=0;i<I->size();i++){
            _x[i]=IloNumVarArray(env);
        }
        
        //Modelo
        IloModel model(env);
        for (int i = 0; i <I->size(); ++i) {
            _x[i]=IloNumVarArray(env);
                for (int j = 0; j < I->size(); ++j) {
                    std::string label = "x_" + std::to_string(i) + "_" + std::to_string(j);
                    _x[i].add(IloNumVar(env,0,1,ILOINT,label.c_str()));
                           }
                       }
        
        
//        for(int i=0;i<I->size();i++){
//            for(int j=0;j<I->size();j++){
//                _x[i][j]=asignacioncostos[i][j];
//            }
//        }
        
        }
    
    
 //   _model=IloModel(env);
  //  _cplex=IloCplex(_model);
//    vector<vector<AsignacionCostos>>_asignacioncostos;
//    int filas=_asignacioncostos.size();
//    int cols =_asignacioncostos[0].size();
//    vector<vector<AsignacionCostos>>abc(filas,vector<AsignacionCostos>(cols));
//    try{
//        for(int i=0;i<I->size();i++){
//            for(int j=0;j<I->size();j++){
//                abc[i][j]=_asignacioncostos[i][j];
//            }
//        }
//        //MODELO
//        IloModel model(env);
//        BoolVarMatrix asignnacion(env,I->size());
//        for (int i = 0; i <I->size(); ++i) {
//                   asignnacion[i] = IloBoolVarArray(env, I->size());
//                   for (int j = 0; j < I->size(); ++j) {
//                       std::string label = "x_" + std::to_string(i) + "_" + std::to_string(j);
//                       asignnacion[i][j] = IloBoolVar(env, label.c_str());
//                   }
//               }
//
//                for (int i = 0; i < I->size(); ++i) {
//                    IloExpr rowSum(env);
//                    for (int j = 0; j < I->size(); ++j) {
//                        rowSum += asignnacion[i][j];
//                    }
//                    model.add(rowSum == 1);
//                }
//                for (int j = 0; j < I->size(); ++j) {
//                    IloExpr colSum(env);
//                    for (int i = 0; i < I->size(); ++i) {
//                        colSum += asignnacion[i][j];
//                    }
//                    model.add(colSum == 1);
//                }
//
//                IloExpr obj(env);
//                for (int i = 0; i < I->size(); ++i) {
//                    for (int j = 0; j <I->size(); ++j) {
//                        obj += abc[i][j].getCosto() * asignnacion[i][j];
//                    }
//                }
////                model.add(IloMinimize(env, obj));
//  }
        catch (IloException& e) {
//            std::cout << "Error: " << e << std::endl;
        } catch (...) {
//            std::cout << "Unknown exception occurred." << std::endl;
        }
 //      env.end();
  }
