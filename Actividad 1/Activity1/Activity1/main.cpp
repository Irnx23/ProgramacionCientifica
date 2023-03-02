//
//  main.cpp
//  Activity1
//
//  Created by Itzel Robles on 16/02/23.
//  Revision by Samantha Lopez

#include <iostream>
using namespace std;

int main() {
    cout<<"Altura"<<endl;
    //iniciar variables con valor
    int A=0;
    cin>>A;
    cout<<"Base"<<endl;
    int B=0;
    cin>>B;
    
    //calculamos perimetro
    int C=0;
    C=(2*A+2*B);
    cout<<"El perimetro del rectangulo: "<< C <<endl;
    
    //calculamos area
    int Area=0;
    Area = A*B;
    cout<<"El area del rectangulo: "<< Area <<endl;
    
    return 0;
}
