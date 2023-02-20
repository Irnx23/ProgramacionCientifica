//
//  main.cpp
//  Activity4
//
//  Created by Itzel Robles on 19/02/23.
//

#include <iostream>
using namespace std;

int main() {
    int A;
    for(int i=8;i<24;i++){
        cout<<"Ingresa el numero "<<i<<endl;
        cin>>A;
        if (A!=i){
            cout<<"error"<<endl;
            //Revisar con sam como le hizo para quedar sobre el mismo numero
        }
    }
    return 0;
}
