//
//  main.cpp
//  A 17
//
//  Created by Itzel Robles on 19/03/23.
//Add to the previous program a function that is taking a pointerto a table as a parameter and sorts the values of this table in decreasing order(Method of your choice).  Test it with the K tables generated randomly.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int askforvalue(string VarName,int minval=0); //Voy a usar una funcion con parametro string
int RAND(int,int);
int dividir(double*, int, int);
void deleteTable(double**,int);
double*extraerFirstValue(double**);
void quicksort(double*,int,int);
void imprimir(double*,int);
void imprimir(double**,int,int);
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
   // imprimir(array.array, N, K);
    double *primer_Val=extraerFirstValue(array.array);
    quicksort(primer_Val, 0, K-1);
    cout<<"Tabla 1 ordenada de manera decendente: ";
    imprimir(primer_Val, K);
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
        //cout<<"Dirección del puntero a tabla: ";//PrimerArray<<endl;
        
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
//-------------------------------------------------------------------------
void quicksort(double* T, int minimo, int maximo)
{

    if (minimo < maximo)
    {
        int piv = dividir(T, minimo, maximo);
        quicksort(T, minimo, piv - 1);
        quicksort(T, piv + 1, maximo);
    }
}
//------------------------------------------------------------------------
int dividir(double* T, int minimo, int maximo)
{
    double pivote = T[maximo];
    int i = minimo - 1; //para iniciar en 0

    for (int j = minimo; j <= maximo - 1; j++)
    {
        if (T[j] > pivote)
        {
            i++;
            double auxiliar = T[i];  //guarda el valor en un auxiliar
            T[i] = T[j];    //sustituye el valor de j en i
            T[j] = auxiliar;    //j toma el valor del auxiliar
        }
    }
    double auxiliar = T[i + 1];
    T[i + 1] = T[maximo];
    T[maximo] = auxiliar;

    return (i + 1);
}
//---------------------------------------------------------------
void imprimir(double* array, int K){
        for(int j=0;j<K;j++){
            if (array[j]>0.001){
                cout<<array[j]<<" ";
            }
            else {};
        }
            
        cout<<endl;
    }
//-----------------------------------------------------------------
void imprimir(double** array, int N, int K){
    for(int i=0;i<N;i++){
        cout<<"Tabla: "<<i+1 <<": ";
        for(int j=0;j<K;j++){
            if (array[i][j]>0.001){
                cout<<array[i][j]<<" ";
            }
            else {};
        }
            
        cout<<endl;
    }
}
//-----------------------------------------------------------
