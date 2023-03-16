#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <assert.h> //Funcion para controlar condiciones y si no se cumplen ciertas condiciones, truena el codigo
using namespace std;

int askforvalue(string VarName, int minval = 0); //Voy a usar una funcion con parametro string y se coloca minval=0;
//double**genT(int,int); //Generar tabla de nxk dimensiones
//void printTable(double**,int,int); //Imprimir las tablas con sus dimensiones
void deleteTable(double**, int); //Funcion para eliminar tablas hechas
int RAND(int, int); //Función random
void quicksort(double* , int , int );
int dividir(double* , int , int );
struct Rand2DArray; //Estructura para estrcutura

//------------------------------------------------------------------
struct Rand2DArray { //Declaracion de la estructura con sus tipos de miembros
    double** array;
    double* dim;
    int N;

    Rand2DArray(double** A, double* d, int n) { //Declaracion de una funcion utilizando como parametros a los miembros antes delcarados en la estructura.
        array = A;
        dim = d;
        N = n;
    }
    Rand2DArray(int N, int K) { //Constructor
        array = new double* [N]; //Declaración de puntero vacio a otro puntero.
        dim = new double[N]; //Declaración de un puntero a una lista.
        for (int i = 0; i < N; i++) { //For para generar las tablas
            cout << "Tabla " << i + 1 << ":";
            int r = RAND(10, K);
            dim[i] = r;
            array[i] = new double[r];
            for (int j = 0; j < r; j++) {
                array[i][j] = (rand() % 1001 / 100.0); //Dentro de la tabla K con longitud N, llenarla con valoreas aleatorios de [0,1000]
                cout << array[i][j] << " ";
            }
            cout << endl;
            //REALIZACION DE ORDENAMIENTO E IMPRESION A LA PAR DE QUE VA GENERANDO DICHAS TABLAS CON VALORES ALEATORIOS
            //*************************************REVISAR*****************************
            quicksort(array[i], 0, r - 1); // llamada a la función quicksort para ordenar la tabla i
            cout << "--------------------------\n" << endl;
            cout << "Tabla " << i + 1 << " ordenada:\n";
            for (int j = 0; j < r; j++) {
                cout << array[i][j] << " "; // Imprimir tabla ordenada
            }
            cout << endl;    
            cout << "--------------------------\n" << endl;
        }
    }
    //    ~Rand2DArray(){ //Destructor
    //        for (int i=0;i<N;i++) delete[] array[i];
    //        delete[] array;
    //
    //    }
};

//---------------------------------------------------------------------
int main() {
    int N = askforvalue("N");
    int K = askforvalue("K", 10);
    int seed = (int)clock();
    srand(seed);
    Rand2DArray array(N, K);
    //printTable(array.array,N,K);
    deleteTable(array.array, N);

    return 0;
}
//---------------------------------------------------------------------

int askforvalue(string VarName, int minval) { //Función entera en donde pide la variable para regresar la variable entera.
    int var = 0;
    do {
        cout << "Ingresa " << VarName << ":";
        cin >> var;
    } while (var < minval);
    return var;
}

//-----------------------------------------------------------------------
//double** genT(int N, int K){
//    double** Array= new double*[N]; //Declaración de puntero vacio a otro puntero.
//    for(int i=0;i<N;i++){ //For para generar las tablas
//        int r=RAND(10,K);
//        Array[i]=new double[r];
//        for (int j=0;j<r;j++)
//            Array[i][j]=(rand()%1001/100.0); //Dentro de la tabla K con longitud N, llenarla con valoreas aleatorios de [0,1000]
//    }
//    return Array;
//}
//------------------------------------------------------------------------
void printTable(double** array, int N, int K) {

    for (int i = 0; i < N; i++) {
        cout << "Table " << i + 1 << " : ";
        for (int j = 0; j < K; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
//----------------------------------------------------------------------
int RAND(int min, int max) {
    assert(min <= max);
    return min + rand() % (max - min + 1);
}

//-------------------------------------------------------------------
void deleteTable(double** array, int N) {
    for (int i = 0; i < N; i++) delete[] array[i];
    delete[] array;

}

//-------------------------------------------------------------------
void quicksort(double* T, int minimo, int maximo)
{
    if (minimo < maximo)
    {
        int piv = dividir(T, minimo, maximo);
        quicksort(T, minimo, piv - 1);
        quicksort(T, piv + 1, maximo);
    }
}

//-------------------------------------------------------------------
int dividir(double* T, int minimo, int maximo)
{
    double pivote = T[maximo];
    int i = minimo - 1;

    for (int j = minimo; j <= maximo - 1; j++)
    {
        if (T[j] > pivote)
        {
            i++;
            double auxiliar = T[i];
            T[i] = T[j];
            T[j] = auxiliar;
        }
    }
    double auxiliar = T[i + 1];
    T[i + 1] = T[maximo];
    T[maximo] = auxiliar;

    return (i + 1);
}
