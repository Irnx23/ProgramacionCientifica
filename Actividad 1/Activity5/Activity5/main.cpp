//
//  main.cpp
//  Activity5
//
//  Created by Itzel Robles on 19/02/23.
// Revisado by Samantha Lopez
//
//Write  a  program  that  asks  the  user  to  type  all  the  integersbetween 8 and 23 (both included) using a while.

#include <iostream>
using namespace std;

int main() {
    int A=0,i=8;
    while(i<24){
        cout<<"Ingresa el numero "<<i<<endl;
        cin>>A;
        if (A!=i){
            cout<<"error"<<endl;
            i--;
            //Revisar: es necesario colocar break
        }
        i++;
    }
    
            
    return 0;
}

