//
//  main.cpp
//  Activity5
//
//  Created by Itzel Robles on 19/02/23.
//
//Write  a  program  that  asks  the  user  to  type  all  the  integersbetween 8 and 23 (both included) using a while.

#include <iostream>
using namespace std;

int main() {
    int A,i=8;
    while(i<24){
        cout<<"Ingresa el numero "<<i<<endl;
        cin>>A;
        if (A!=i){
            cout<<"error"<<endl;
            break;
        }
        i++;
    }
    
            
    return 0;
}

