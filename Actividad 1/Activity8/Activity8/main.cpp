//
//  main.cpp
//  Activity8
//
//  Created by Itzel Robles on 20/02/23.
//

#include <iostream>
using namespace std;

int main() {
    cout<<"Ingrese un valor entero ";
    unsigned long N=0;
    cin>>N;
    
    unsigned long F=1;
    for (int i=1;i<=N;i++){
        //F = F*i
        F*=i;
    }
    
    //limite encontrado, solo se puede obtener el factorial del 1 hasta el 33
    cout<<"El factorial de: "<<N<<" es: "<<F<<endl;
    return 0;
}
