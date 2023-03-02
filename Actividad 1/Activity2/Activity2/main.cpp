//
//  main.cpp
//  Activity2
//
//  Created by Itzel Robles on 16/02/23.
//
//programa para obtener el promedio de 5 numeros enteros que se ingresen
#include <iostream>
using namespace std;

int main() {
    int N=0,S=0;
    
    for (int i=0;i<5;i++){
        cout<<"Ingresa un numero entero "<<i+1<<endl;
        cin>>N;
        S+=N;
    }
    
    //calcular promedio de los numeros
    float promedio=(float)S/5;
   
    cout<<"El promedio es: "<<promedio<<endl;
    
    return 0;
}
