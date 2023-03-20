//
//  main.cpp
//  E1
//
//  Created by Itzel Robles on 03/02/23.
// Programa que pregunta el tamaño N y numero de listas K para generar, despues llama a una funcion que
// que llena las listas con random con valores no solo enteros de [0,1000].
// Esta funcion the devuelve el puntero de un arreglo de arreglos que contienen las listas.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int askforvalue(string VarName); //Voy a usar una funcion con parametro string
double**genT(int,int); //Generar tabla de nxk dimensiones
void printTable(double**,int,int); //Imprimir las tablas con sus dimensiones
void deleteTable(double**,int);

//---------------------------------------------------------------------
int main(){
    int N=askforvalue("N");
    int K=askforvalue("K");
    int seed=(int)clock();
    srand(seed);
    double**Table=genT(N,K);
    printTable(Table, N, K);
    cout<<"Puntero del puntero de arreglos: "<<Table<<endl; // Direccion de Puntero a puntero
    //cout<<*Table<<endl; // Dirección del puntero al arreglo
    //cout<<**Table<<endl;//Primer valor del arreglo
    
    
    deleteTable(Table,N);
    return 0;
}

//---------------------------------------------------------------------

int askforvalue(string VarName){ //Función entera en donde pide la variable para regresar la variable entera.
    int var=0;
    do{
        cout<<"Ingresa " <<VarName<<":";
        cin>>var;
    }while(var<=0);
    return var;
}
//-----------------------------------------------------------------------
double** genT(int N, int K){
    double** Array= new double*[N]; //Declaración de puntero vacio con otro puntero.
    for(int i=0;i<N;i++){
        Array[i]=new double[K];
        for (int j=0;j<K;j++) Array[i][j]=(rand()%1001)/100.0;
    }
    return Array;
}
//------------------------------------------------------------------------
void printTable(double** T,int N,int K){
    
    for(int i=0;i<N;i++){
        //cout<<"Row "<<i<<" : ";
        for(int j=0;j<K;j++){
          //  cout<<T[i][j]<<" ";
        }
        //cout<<endl;
    }
}
//------------------------------------------------------------------------
void deleteTable(double**array, int N){
    for (int i=0;i<N;i++) delete [] array[i];
    delete[] array;
    
}
