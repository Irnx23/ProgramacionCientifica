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
    float x1,x2,y1,y2, dist;
    cout<<"Ingrese coordenada x del punto A"<<endl;
    cin>>x1;
    cout<<"Ingrese coordenada y del punto A"<<endl;
    cin>>y1;
    cout<<"Ingrese coordenada x del punto B"<<endl;
    cin>>x2;
    cout<<"Ingrese coordenada y del punto B"<<endl;
    cin>>y2;
    
    dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    cout<<"Distancia entre A y B es: "<<dist<<endl;
    
    
    return 0;
}
