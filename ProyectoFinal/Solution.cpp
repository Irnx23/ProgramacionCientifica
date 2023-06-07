//
//  Solution.cpp
//  PruebaCplexGPT
//
//  Created by Itzel Robles on 05/06/23.
//

#include "Solution.hpp"

Solution::Solution(Instance* I) : vector<int>()
{
    _I = I;
    //TODO
}

Solution::~Solution()
{
    //TODO
}

bool Solution::isFeasible()
{
    vector<string> ErrorMessage;
    
    int* count=new int[_I->size()];
    for(int i=0;i<_I->size();i++) count[i]=0;
    
    for(auto i : *this){
        if(i<0 || i>=_I->size()){
            ErrorMessage.push_back("Error: Node "+to_string(i)+" does not exist");
        }
        else count[i]++;
    }
    
    for(int i=0;i<_I->size();i++){
        if(count[i]==0)
            ErrorMessage.push_back("Error: Node "+to_string(i)+" is not visisted");
        else if (count[i]>1)
            ErrorMessage.push_back("Error: Node "+to_string(i)+" is visited "+to_string(count[i]) +" times");

    }
    
    delete[] count;
    
    return ErrorMessage.empty();
}

void Solution::print(){
    
    cout<<"Fitness: "<<fitness()<<endl;
    
    if(this->empty()) cout<<"Empty Solution"<<endl;
    else{
        int first=this->front();
        cout<<"("+to_string(first)+")";
        
        int prev=first;
        for(auto i : *this) if(i!=first){
            //int d=_I->node(prev)->distanceto(_I->node(i));
            //cout<<"--"+to_string(d)+"->"<<"("+to_string(i)+")";
            prev=i;
        }
        //cout<<"--"+to_string(_I->node(prev)->distanceto(_I->node(first)))+"->"<<"("+to_string(first)+")"<<endl;
    }
    
}

double Solution::fitness(){
    
    if(this->empty()) return 0.0;
    
    double distance=0.0;
    
    int first=this->front();
    
    int prev=first;
    for(auto i : *this) if(i!=first){
       // int d=_I->node(prev)->distanceto(_I->node(i));
        //distance+=d;
        prev=i;
    }
    //distance+=_I->node(prev)->distanceto(_I->node(first));
    
    return distance;
}
