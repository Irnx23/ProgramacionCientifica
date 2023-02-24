//
//  main.cpp
//  Activity10
//
//  Created by Itzel Robles on 22/02/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int A=0;
    int C=0;
    char B;
    srand(time(NULL));
    int random=rand()%100+1;
    
    cout<<"Adivina el número entre 1 y 100 ";
    while (A!=random){
        cin>>A;
        C++;
        if (A<random){
            cout<<"Número abajo, intentalo de nuevo ";
        }else if (A>random){
            cout<<"número arriba, intentalo de nuevo ";
        }else{
            cout<<"Felicidades encontraste el número :), con "<<C<<" intentos";
            cout<<"Quieres volver a jugar? (y/n) ";
            cin>>B;
            if (B=='y'){
                random=rand()%100+1;
                A=0;C=0;
                cout<<"Adivina el número entre 1 y 100 ";
            }
        }
    }
        
        return 0;
    
}
