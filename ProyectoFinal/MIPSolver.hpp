//
//  MIPSolver.hpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//

#pragma once
#include"Solver.hpp"

class MILPSolver:public Solver{
    IloEnv env;
    IloCplex _cplex;
    IloModel _model;
    IloObjective _obj;
    IloArray<IloNumVarArray>_x;
    
    
public:
    MILPSolver(Instance*I);
    ~MILPSolver();

};

