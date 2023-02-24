//
//  main.cpp
//  Activity7
//
//  Created by Itzel Robles on 20/02/23.
//REVISARRRR************!!!!!!

#include <iostream>
using namespace std;
int main() {
    int u=0,n,a=1,b=1;
    cout<<"Ingresa un entero: ";
    cin>>n;
    if (n==1 || n==0){
        a=1;
    }
        else{
            for(int i=2;i<=n;i++){
                a=a+b;
                b=a;
                a=u;
            }
            cout<<"u= "<<a<<endl;
        }
    
    return 0;
}
