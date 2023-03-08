//
//  main.cpp
//  E2
//
//  Created by Itzel Robles on 06/03/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int askforvalueN(string VarName); //Voy a usar una funcion con parametro string
int askforvalueK(string Varname);
double**genT(int,int); //Generar tabla de nxk dimensiones
void printTable(double**,int,int); //Imprimir las tablas con sus dimensiones
void deleteTable(double**,int);

//---------------------------------------------------------------------
int main(){
    int N=askforvalueK("K");
    int K=askforvalueN("N");
    int seed=(int)clock();
    srand(seed);
    double**Table=genT(N,K);
    printTable(Table, N, K);
    //cout<<Table;
    deleteTable(Table,N);
    return 0;
}

//---------------------------------------------------------------------

int askforvalueN(string VarName){ //Función entera en donde pide la variable para regresar la variable entera.
    int var=0;
    do{
        cout<<"Ingresa " <<VarName<<":";
        cin>>var;
    }while(var<=10);
    return var;
}

//----------------------------------------------------------------------
int askforvalueK(string VarName){ //Función entera en donde pide la variable para regresar la variable entera.
    int var=0;
    do{
        cout<<"Ingresa " <<VarName<<":";
        cin>>var;
    }while(var<=0);
    return var;
}

//-----------------------------------------------------------------------
double** genT(int N, int K){
    double** Array= new double*[K]; //Declaración de puntero vacio a otro puntero.
    for(int i=0;i<K;i++){ //For para generar las tablas
        N=rand()%(N-(10+1))+10; //Sobre escribir N para que aleatoriamente tome valor entre [10,N] y genere la tabla K de cierta longitud
        Array[i]=new double[N];
        
        for (int j=0;j<N;j++)
            Array[i][j]=(rand()%1001/100.0); //Dentro de la tabla K con longitud N, llenarla con valoreas aleatorios de [0,1000]
    }
    return Array;
}
//------------------------------------------------------------------------
void printTable(double** T,int N,int K){
    
    for(int i=0;i<N;i++){
        cout<<"Table "<<i+1<<" : ";
        for(int j=0;j<K;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}
void deleteTable(double**array, int N){
    for (int i=0;i<N;i++) delete [] array[i];
    delete[] array;
    
}
