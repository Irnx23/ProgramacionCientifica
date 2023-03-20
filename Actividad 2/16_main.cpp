//
//  main.cpp
//  E3
//
//  Created by Itzel Robles on 08/03/23.
//Write  a  function  that  is  taking  a  pointer  to  a  table  as  aparameter and print its stored value on the screen.  Add this function to theprevious program to print the generated tables.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int askforvalue(string VarName,int minval=0); //Voy a usar una funcion con parametro string
int RAND(int,int);
//void printTable(double**,int,int); //Imprimir las tablas con sus dimensiones
void deleteTable(double**,int);
double*extraerFirstValue(double**);
//----------------------------------------------------------------------------
struct Rand2DArray{ //Declaracion de la estructura con sus tipos de miembros
    double**array;
    double* dim;
    int N;
    
    Rand2DArray(double** A, double* d, int n){ //Declaracion de una funcion utilizando como parametros a los miembros antes delcarados en la estructura.
        array=A;
        dim=d;
        N=n;
    }
    Rand2DArray(int N,int K){ //Constructor
        array= new double*[N]; //Declaración de puntero vacio a otro puntero.
        dim=new double[N]; //Declaración de un puntero a una lista.
        for(int i=0;i<N;i++){ //For para generar las tablas
            //cout<<"Tabla "<<i+1<<":";
            int r=RAND(10,K);
            dim[i]=r;
            array[i]=new double[r];
            for (int j=0;j<r;j++){
                array[i][j]=(rand()%1001/100.0); //Dentro de la tabla K con longitud N, llenarla con valoreas aleatorios de [0,1000]
              //  cout<<array[i][j]<<" ";
            }
           // cout<<endl;
        }
    }
};




//---------------------------------------------------------------------
//********************************************************************
int main(){
    int N=askforvalue("K");
    int K=askforvalue("N");
    int seed=(int)clock();
    srand(seed);
    Rand2DArray array(N,K);
    extraerFirstValue(array.array);
    //cout<<"direccion: "<<*d<<endl;
    deleteTable(array.array,N);
    return 0;
}
    //*********************************************************************
    
    //---------------------------------------------------------------------
    
int askforvalue(string VarName,int minval){ //Función entera en donde pide la variable para regresar la variable entera.
        int var=0;
        do{
            cout<<"Ingresa " <<VarName<<":";
            cin>>var;
        }while(var<minval);
        return var;
    }
    //----------------------------------------------------------------------
    double* extraerFirstValue(double**Array){
        double*PrimerArray=&Array[0][0];
        cout<<"Dirección del puntero a tabla: "<<PrimerArray<<endl;
        
        return PrimerArray;
    }
    
    //--------------------------------------------------------------------------
    void deleteTable(double**array, int N){
        for (int i=0;i<N;i++) delete [] array[i];
        delete[] array;
        
    }
    
    //----------------------------------------------------------------------
    int RAND(int min, int max){
        assert(min<=max);
        return min+rand()%(max-min+1);
    }
    

