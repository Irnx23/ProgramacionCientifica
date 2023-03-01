//EJERCICIO 10
//FUNCION u(N)
#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
    cout << " Ingresa N e imprime u(N) \n";
    cout << "------------------------------------ \n";
    cout << " Ingresa un numero entero para N: ";
    int num = 0;
    cin >> num;
    int actual = 1;
    int anterior = 1;
    int siguiente = 0;
    if (num == 0 || num == 1)
        siguiente = 1;
    else
        for (int i = 2; i <= num; i++)
        {
            //ejemplo
            //u(2) = u(1) + u(0)
            //sabemos que u(1) = 1 y u(0)= 1
            //u(2) = 1 + 1
            siguiente = actual + anterior;
            //recorremos un numero
            anterior = actual;
            //valor actualizado
            actual = siguiente;
        }
    cout << "\n-------------RESULTADOS------------- ";
    cout << "\nu(" << num << ") = " << siguiente;
    cout << "\n------------------------------------ ";
    return 0;
}