//
//  Solution.hpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//
#pragma once
#include "Instancia.hpp"
class Solution : public vector<int>{
    Instance* _I;

public:
    Solution(Instance* I);
    ~Solution();

    bool isFeasible();
    
    void print();
    
    double fitness();
};
