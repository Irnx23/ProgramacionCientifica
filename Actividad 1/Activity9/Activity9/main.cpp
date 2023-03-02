//
//  main.cpp
//  Activity9
//
//  Created by Itzel Robles on 20/02/23.
// Determinar si N es numero entero o no.

#include <iostream>
using namespace std;

int main() {
    bool primo=true;
    cout<<"Ingrese un número: ";
    int N=0;
    cin>>N;
    if (N<=1){
        primo=false;
    }else{
        for (int i=2; i<=(N/2); i++){
            //realizando operacion de manera directa en el if 
            if(N % i ==0){
               //no es primo -- cambia valor a 0
                primo=false;
                break;
            }
        }
    }
    //Revisar -- no es necesario especificar comparacion en el if
    //if (primo == true)
    if(primo){
        cout<<"El numero " << N << " es primo" <<endl;
        
    }else{
        cout<<"El numero " << N << " NO es primo"<<endl;
    }
    
    return 0;
}
