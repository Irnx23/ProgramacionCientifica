//
//  main.cpp
//  Activity6
//
//  Created by Itzel Robles on 20/02/23.
//Write  a  program  that  asks  the  user  to  type  10  integers  and writes the smallest value.

#include <iostream>
using namespace std;
int main() {
    int N[10],m;
    cout<<"Ingresa 10 valores enteros"<<endl;
    for (int i=0;i<10;i++){
        cin>>N[i];
    }
    
    m=N[0]; //m toma el valor 0 en N
    for (int i=0;i<10;i++){ 
        if(N[i]<m){
            m=N[i];
        }
    }
        cout<<"El valor más pequeño es: "<<m<<endl;
        
    return 0;
}
