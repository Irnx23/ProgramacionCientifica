#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

//FUNCIONES
int solicitud(string VarName);
double** genTable(int, int); //GENERACION DE LA TABLA
void printTable(double**, int, int);
void printquick(double**, int, int);
void quicksort(double*, int, int);
int dividir(double*, int, int);
void deleteTable(double**, int);

int main()
{
    int N = solicitud("N");
    int K = solicitud("K");

    int seed = (int)clock();
    //cout << "Seed used: " << seed << endl;
    srand(seed);

    double** Table = genTable(N, K);

    //Imprimir tabla sin ordenar
    cout << "Tablas generadas: " << endl;
    printTable(Table, N, K);
    cout << endl;

    cout << "Tabla a ordenar: " << endl;
    printTable(Table, 1, K);


    //---------------REVISAR---------------------------------------------------------------------------
    //medicion de tiempo de ejecucion en la fila 0
    auto inicio = chrono::system_clock::now(); // Iniciar el tiempo
    quicksort(Table[0], 0, K - 1);
    auto final = chrono::system_clock::now(); /// Detener el tiempo
    //-------------------------------------------------------------------------------------------------


    //Imprimir tabla ya ordenada
    cout << "Tabla ordenada de manera decreciente: " << endl;
    printquick(Table, N, K);

    // Calcular y mostrar el tiempo de ejecución
    auto duracion = duration_cast<microseconds>(final - inicio);
    cout << endl << "Tiempo de ejecucion: " << duracion.count() << " microsegundos." << endl;

    deleteTable(Table, N);

    return 0;
}


//FUNCION SOLICITUD DATOS
int solicitud(string VarName)
{
    int Var = 0;
    //ingresar dentro de un do while para validacion de los datos que se estan ingresando
    do
    {
        cout << "Ingresar el valor de " << VarName << " : ";
        cin >> Var;
    } while (Var <= 0);
    return Var;
}

//FUNCION PARA GENERAR TABLA
double** genTable(int N, int K)
{
    double** Array = new double* [N];
    for (int i = 0; i < N; i++)
    {
        Array[i] = new double[K];
        for (int j = 0; j < K; j++)
            // Array[i][j] = ((rand() % 10001) / 100.0);   DA SOLO VALORES DEL 0 AL 100
            Array[i][j] = ((rand() % 10001) / 10.0);   // VALORES DEL 0 AL 1000
    }
    return Array;
}



void printTable(double** T, int N, int K)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Fila " << i << ": ";
        for (int j = 0; j < K; j++)
            cout << setw(8) << T[i][j] << " ";
        cout << endl;
    }
}


//immprima solo la fila a trabajar 
void printquick(double** T, int N, int K)
{
    for (int i = 0; i < 1; i++)
    {
        cout << "Fila " << i << ": ";
        for (int j = 0; j < K; j++)
            cout << setw(8) << T[i][j] << " ";
        cout << endl;
    }
}

//metodo de ordenamiento 
void quicksort(double* T, int minimo, int maximo)
{

    if (minimo < maximo)
    {
        int piv = dividir(T, minimo, maximo);
        quicksort(T, minimo, piv - 1);
        quicksort(T, piv + 1, maximo);
    }
}

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

void deleteTable(double** Array, int N)
{
    //IMPORTANCIA DEL ORDEN EN QUE SE VACIAN LOS DATOS
    for (int i = 0; i < N; i++)
        delete[] Array[i];   //ELIMINA PRIMERO LA INFORMACION DE CADA FILA
    delete[] Array;   // ELIMINA COLUMNA, PARA PODER DESOCUPAR LA MEMORIA 
}
