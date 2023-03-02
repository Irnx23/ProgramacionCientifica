//
//  main.cpp
//  Activity4
//
//  Created by Itzel Robles on 19/02/23.
// Revisado by Samantha Lopez

#include <iostream>
using namespace std;

int main() {
    int A=0;
    for(int i=8;i<24;i++){
        cout<<"Ingresa el numero "<<i<<endl;
        cin>>A;
        if (A!=i){
            cout<<"error"<<endl;
            //se decrementa el valor de i para regresar al valor donde se realizo el error
            i--;
        }
    }
    return 0;
}
