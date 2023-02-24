//
//  main.cpp
//  Activity9
//
//  Created by Itzel Robles on 20/02/23.
// Determinar si N es numero entero o no.

#include <iostream>
using namespace std;

int main() {
    int N;
    bool primo=true;
    cout<<"Ingrese un número: ";
    cin>>N;
    if (N<=1){
        primo=false;
    }else{
        for (int i=2; i<=(N/2); i++){
            if(N % i ==0){
                primo=false;
                break;
            }
        }
    }
    if(primo){
        cout<<"El numero es primo "<<endl;
        
    }else{
        cout<<"el numero NO es primo "<<endl;
    }
    
    return 0;
}
