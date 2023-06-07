//
//  Solver.cpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//

#include "Solver.hpp"
Solver::Solver(Instance* I, string name)
{
    _I = I;
    _name = name;
    _start=_end= chrono::system_clock::now();
    _timlim = 60;
    _mingap = 0.01;
}
//---------------------------------------------------------------------------
void Solver::setparam(param_t PARAM, double value)
{
    if (PARAM == TimLim) _timlim = value;
    else if (PARAM == Gap) _mingap = value;
}
//---------------------------------------------------------------------------
void Solver::solve(Solution* S) //C.solution
{
    startTimer();
    solvemethod(S); //C.Greedy
    stopTimer();
}
//---------------------------------------------------------------------------
void Solver::saveresults(string OutputFile){
    
    if(OutputFile==""){
        OutputFile="Output/"+name()+"_"+to_string((int)_timlim)+".txt";
    }
    
    ifstream input(OutputFile);
    ofstream output(OutputFile,ios::app);
    
    int w=10;
    
    if(!input.is_open() ){
        output=ofstream(OutputFile);
        //assert(output.is_open());
        output<<setw(2*w)<<"InstName"<<setw(w)<<"#nodes"<<setw(2*w)<<"Solver"<<setw(w)<<"TimLim"<<setw(w)<<"Fitness"<<setw(w)<<"cpuTime"<<setw(w)<<"Gap"<<setw(w)<<"Feas"<<endl;
    }
    else input.close();

    
    Solution* S=getsolution(); //h.solver
  
    string Feas="n/a";
    string Fitness="n/a";
    if(S!=NULL){
        Fitness=to_string((int)S->fitness());
        if(S->isFeasible()) Feas="True";
        else Feas="False";
    }
    
    double g=ceil(gap()*100)/100.0;
    output<<setw(w)<<Fitness<<setw(w)<<cpuTime()<<setw(w)<<g<<setw(w)<<Feas<<endl;

}
