//
//  main.cpp
//  Activity2
//
//  Created by Itzel Robles on 16/02/23.
//

#include <iostream>
using namespace std;

int main() {
    int N,S=0;
    
    for (int i=0;i<5;i++){
        cout<<"Ingresa un numero entero "<<i+1<<endl;
        cin>>N;
        S+=N;
        
    }
    float promedio=(float)S/5;
    cout<<"El proemedio es: "<<promedio<<endl;
    
    return 0;
}
