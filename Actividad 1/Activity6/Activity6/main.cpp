//
//  main.cpp
//  Activity6
//
//  Created by Itzel Robles on 20/02/23.
// Revisado by Sam Lopez
//Write  a  program  that  asks  the  user  to  type  10  integers  and writes the smallest value.

#include <iostream>
using namespace std;
int main() {
    int N[10],m=0;
    cout<<"Ingresa 10 valores enteros"<<endl;
    for (int i=0;i<10;i++){
        cin>>N[i];
    }
    
    //uso de arreglos para almacenar los 10 numeros ingresados
    m=N[0]; //m toma el valor 0 en N
    for (int i=0;i<10;i++){ 
        if(N[i]<m){
            m=N[i];
        }
    }
        cout<<"El valor más pequeño es: "<<m<<endl;
        
    return 0;
}

// sin uso de arreglo
/*
#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
    cout << "NUMERO MENOR DE 10 INGRESADOS  \n";
    cout << "------------------------------------ \n";
    cout << "1.- Ingrese el numero: ";
    int menor = 0;
    cin >> menor;
    int num = 0;
    for (int i = 1; i <= 9; i++)
    {
        cout << i + 1 << ".- Ingrese el numero: ";
        cin >> num;
        if (menor > num)
        {
            menor = num;
        }
    }
    cout << "------------------------------------ \n";
    cout << "Menor numero de los diez ingresados es: " << menor;
    cout << "\n------------------------------------ ";
    return 0;
}
*/
