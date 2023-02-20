//
//  main.cpp
//  E1
//
//  Created by Itzel Robles on 03/02/23.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

float** generate_tables(int N, int K){
    float** tables = new float*[K];
    for (int i=0; i<K; i++){
        tables[i]=new float[N];
    }
    srand(time(nullptr));
    for (int i=0;i<K;i++){
        for (int j=0;j<N;j++){
            tables[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/1000.0f);
        }
    }
    return tables;
}


int main() {
    int N,K;
//Imprime para que se ingrese el largo de la lista
    cout<<"Ingrese un numero para el largo de una lista"<<endl;
//Captura lo solicitado
    cin>>N;
//Imprime para que se ingrese cuantas listas se debe de generar
    cout<<"Ingrese cuantas listas "<<endl;
//Captura lo solicitado
    cin>>K;
    
    float** tables=generate_tables(N, K);
    
    for (int i=0;i<K;i++){
            cout<<"Tabla "<< i+1<< ":" <<endl;
        for (int j=0;j<N;j++){
            cout<<tables[i][j]<< " ";
        }
        cout<<endl;
        
    }
    for (int a=0;a<K;a++){
        delete[] tables[a];
    }
    delete[]tables;
    return 0;
}
