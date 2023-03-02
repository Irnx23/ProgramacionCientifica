//
//  main.cpp
//  Activity3
//
//  Created by Itzel Robles on 16/02/23.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout<<"Ingrese coordenada x del punto A"<<endl;
    double x1=0;
    cin>>x1;
    cout<<"Ingrese coordenada y del punto A"<<endl;
    double y1=0;
    cin>>y1;
    cout<<"Ingrese coordenada x del punto B"<<endl;
    double x2=0;
    cin>>x2;
    cout<<"Ingrese coordenada y del punto B"<<endl;
    double y2=0;
    cin>>y2;
    
    //operaciones a realizar
    double dist=0;
    dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    cout<<"Distancia entre A y B es: "<<dist<<endl;
    
    
    return 0;
}
