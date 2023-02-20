//
//  main.cpp
//  1
//
//  Created by Itzel Robles on 23/12/22.
//
#include<iostream>
int main()
{
    int n1,n2,sum,res,div,mul;
    
    std::cout<<"Ingrese el primer numero: "; //Imprime
    std::cin >>n1; //Recibe
    
    std::cout<<"Ingrese el segundo numero: "; //Imprime
    std::cin >> n2; //Recibe
    
    sum=n1+n2;
    res=n1-n2;
    div=n1/n2;
    mul=n1*n2;
    
    std::cout<<"La respuesta de suma: " <<sum<<std::endl;
    std::cout<<"La respuesta de resta: " <<res<<std::endl;
    std::cout<<"La respuesta de división: " <<div<<std::endl;
    std::cout<<"La respuesta de multiplicación: " <<mul<<std::endl;
    return 0;
}

