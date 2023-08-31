//
//  main.cpp
//  E19
//
//  Created by Itzel Robles on 16/03/23.
//Write a program that can receive throughargv[] parametersand excecutes the following actions according to the number of parameters:

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <sstream>
using namespace std;

int askforvalue(string VarName,int minval=0); //Voy a usar una funcion con parametro string
void deleteTable(double**,int);
double*extraerFirstValue(double**);
void escribirArchivo(double**,int,int,string);
void SaveTables(string);
void swap(double**,int,int);
int partition(double**,int,int);
void quickSort(double**,int,int);
void printArray(double**,int,int);
void sortTables(double**,int,int);
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
            array[i]=new double[K];
            for (int j=0;j<K;j++){
                array[i][j]=(rand()%1001/100.0); //Dentro de la tabla K con longitud N, llenarla con valoreas aleatorios de [0,1000]
              //  cout<<array[i][j]<<" ";
            }
           // cout<<endl;
        }
    }
};
//---------------------------------------------------------------------
//********************************************************************

int main(int argc, const char * argv[]) {
    if (argc==4){
        string Filename=argv[1];
        int N=atoi(argv[2]);
        int K=atoi(argv[3]);
        Rand2DArray prueba(N,K);
        escribirArchivo(prueba.array,N,K,"Prueba.txt");
        cout<<"Se generó el archivo con 3 valores"<<endl;
        deleteTable(prueba.array, N);
        
    }else if(argc==2){
        cout<<"Solo se ingresó un valor, se debe de leer un txt"<<endl;
        SaveTables("Prueba.txt");
        
        }else
        cout<<"error"<<endl;
        return 0;
    }

//---------------------------------------------------------------------
//********************************************************************

void deleteTable(double**array, int N){
    for (int i=0;i<N;i++) delete [] array[i];
    delete[] array;
}

//----------------------------------------------------------------------
void escribirArchivo(double**array, int N,int K, string nombreArchivo){
    ofstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo :( ";
        return;
    }
    archivo<<N<<" ";
    archivo<<K<<endl;
    archivo<<endl;
    for (int i=0; i<N;i++){
        for(int j=0; j<K;j++){
            if (array[i][j]>0.001){
                archivo<<array[i][j]<<" ";
            }
            else {};
        }
        archivo <<endl;
    }
    archivo.close();
}

//------------------------------------------------------------------
void SaveTables(string filename){
    //string filename=("Prueba.txt");
    int N,K;
    ifstream file(filename);
    file >>N>>K;
    cout<<"Numero de filas: "<<N<<" Numero maximo de datos: "<<K<<endl;;
    string line;
    getline(file, line);
    double** matriz=new double*[N];
    for (int i=0;i<N;i++){
        matriz[i]=new double[K];
                            }
    for (int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            file>>matriz[i][j];
        }
    }
    
    file.close();
    
     printArray(matriz,N,K);
    sortTables(matriz, N, K);

    cout << "Arreglo ordenado en orden descendente:" << endl;
    printArray(matriz, N, K);
    deleteTable(matriz, N);
    
}


// -----------------  ALGORITMO SORT  ------------------------------

void swap(double** arr, int table, int a, int b) {
    double temp = arr[table][a];
    arr[table][a] = arr[table][b];
    arr[table][b] = temp;
}

// Función para seleccionar el pivote
int partition(double** arr, int table, int low, int high) {
    double pivot = arr[table][high]; // seleccionamos el último elemento como pivote
    int i = low - 1; // índice del elemento más grande

    for (int j = low; j < high; j++) {
        // Si el elemento actual es más grande que el pivote
        if (arr[table][j] >= pivot) {
            i++; // incrementamos el índice del elemento más grande
            swap(arr, table, i, j); // intercambiamos los elementos
        }
    }
    swap(arr, table, i + 1, high); // ponemos el pivote en su posición correcta
    return (i + 1); // devolvemos el índice del pivote
}

// Función recursiva para aplicar el algoritmo QuickSort
void quickSort(double** arr, int table, int low, int high) {
    if (low < high) {
        // encontramos el índice del pivote
        int pi = partition(arr, table, low, high);

        // ordenamos los subarreglos antes y después del pivote
        quickSort(arr, table, low, pi - 1);
        quickSort(arr, table, pi + 1, high);
    }
}
// Función para imprimir el arreglo
void printArray(double** matriz, int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


// Función para ordenar cada tabla del arreglo bidimensional
void sortTables(double** arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        quickSort(arr, i, 0, k - 1);
    }
}



