//
//  main.cpp
//  Activity8
//
//  Created by Itzel Robles on 20/02/23.
//

#include <iostream>
using namespace std;

int main() {
    unsigned long N,F=1;
    cout<<"Ingrese un valor entero ";
    cin>>N;
    for (int i=1;i<=N;i++){
        F*=i;
    }
    cout<<"El factorial de: "<<N<<" es: "<<F<<endl;
    return 0;
}
