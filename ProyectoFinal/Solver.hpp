//
//  Solver.hpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
#pragma once
#include "Solution.hpp"
typedef int param_t;
class Solver{

protected:
    Instance* _I;
    string _name;
    double _timlim;
    double _mingap;
    chrono::time_point<chrono::system_clock> _start;
    chrono::time_point<chrono::system_clock> _end;

    void startTimer() { _start = chrono::system_clock::now(); }

    void stopTimer() { _end = chrono::system_clock::now(); }
    
    bool hasTimeLeft(){
        stopTimer();
        double timespent=cpuTime();
        return (timespent<=_timlim);
    }


    virtual void solvemethod(Solution* S) = 0;


public:
    //parameters
    
    static const param_t TimLim = 0;
    static const param_t Gap = 1;

    Solver(Instance* I, string name);
    virtual ~Solver() {};

    void setparam(param_t PARAM, double value);

    string name() { return _name; }

    double cpuTime() { return chrono::duration_cast<std::chrono::seconds>(_end - _start).count(); }

    void solve(Solution* S=NULL); //C.solver

    virtual double gap(){
        return 1;
    };

    virtual Solution* getsolution()=0;
    void saveresults(string OutputFile="");

};



