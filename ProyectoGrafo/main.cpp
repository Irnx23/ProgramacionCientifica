//
//  main.cpp
//  Proyecto
//
//  Created by Itzel Robles on 15/03/23.
//
#include <iostream>
#include <vector>
#include <cstdlib> // Para la función rand()
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;
//int num_nodes;
//----------------------------ALGORITMO DE KOSARAJU----------------------------------------
// "&Vct" es una referencia que apunta a un objeto para evitar copias inecesesarias
// en dfs1 se ingresa un vector de vectores de tipo entero, un vector booleano, un stack y un nodo inicial


void dfs1(vector<vector<int>>& Vct, vector<bool>& visitado, stack<int>& stck, int nodo) {
    visitado[nodo] = true; //Dentro del vector booleano 'visitado' Marca el primer nodo como visitado
    //cout<<"Nodo visitado: "<<nodo<<endl;
    for(int i=0; i<Vct[nodo].size(); i++) { //Recorre el tamaño del vector de vectores adj
        int vecino = Vct[nodo][i]; //Declara un entero y toma el valor de i en el vector de vectores
       // cout <<"Nodo vecino: "<<vecino<<endl;
        if(!visitado[vecino]) // Verifica que el nodo adyacente al nodo inicial no ha sido visitado
            dfs1(Vct, visitado, stck, vecino); //Función recursiva
    }
    stck.push(nodo); //Apila el nodo a el stack st
}

void dfs2(vector<vector<int>>& Vct, vector<bool>& visitado, vector<int>& vect, int nodo) {
    visitado[nodo] = true;
    vect.push_back(nodo); //
    for(int i=0; i<Vct[nodo].size(); i++) {
        int vecino = Vct[nodo][i];
        if(!visitado[vecino])
            dfs2(Vct, visitado, vect, vecino);
    }
}
//---------------------------------------------------------------------------------------
vector<vector<int>> kosaraju(vector<vector<int>>& Vct) {
    double n = Vct.size();
    vector<bool> visited(n, false);
    stack<int> stk;

// Primera fase: hacer un dfs desde cada nodo y agregarlo a una pila
    for(int i=0; i<n; i++) {
        if(!visited[i])
            dfs1(Vct, visited, stk, i);
    }

// Segunda fase: invertir el grafo
    vector<vector<int>> inv_Vct(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<Vct[i].size(); j++) {
            inv_Vct[Vct[i][j]].push_back(i);
        }
    }

// Tercera fase: hacer un dfs desde la pila y encontrar componentes fuertemente conectadas
    vector<vector<int>> scc;
    fill(visited.begin(), visited.end(), false); //llena una vector desde el begin hasta el end de "false"
    while(!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if(!visited[node]) {
            vector<int> stk_inv;
            dfs2(inv_Vct, visited, stk_inv, node);
            scc.push_back(stk_inv);
        }
    }

    return scc;
}



//--------------------------------------------------------------------------------------------
void conexiones(vector<vector<int>>& a){
    double b=a.size();
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            if(i != j){
                
            }
        }
        
    }
}


//----------------------------------------------------------------------------------------------
int main() {
    int n = 0; // Número de nodos
    cout<<"Ingresa el números de nodos: ";
    cin>>n;
    double prob=1;
    do{
        cout<<"Ingresa la probabilidad de conectividad: ";
        cin>>prob;}while (0<prob<1);
    //-------------------------- Genera las conexiones en los nodos -------------------------
    
    vector<vector<int>>adj(n); // HAY QUE UTILIZAR ESTE VECTOR PARA HACER LAS CONEXIONES FALTANTES
    vector<vector<int>> adj_(n);
    for (int i = 0; i < n; i++) {
        cout<<"Nodo: "<<i;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double r = ((double) rand() / RAND_MAX); // Generar un número aleatorio entre 0 y 1
                if (r <= prob) {
                    adj[i].push_back(j); //Vector de conexiones
                     cout<<" -> "<<j;
                }else{adj_[i].push_back(j); //Vector de NO conexiones
                    // cout<<" / " <<j<<" ";
                }
                
            }
        }
        cout<<endl;
    }
    
    //-----------------------------------------------------------------------------------------------
    cout<<"-------------------------------------"<<endl;
    vector<vector<int>> vector_fuerte = kosaraju(adj);
    double b=vector_fuerte.size();
    for(int i=0; i<vector_fuerte.size(); i++) {
        cout << "Componente " << i+1 << ": ";
        for(int j=0; j<vector_fuerte[i].size(); j++){
            cout << vector_fuerte[i][j] << "  ";
        }
        cout<<endl;
    }
    
    cout<<"-------------------------------------"<<endl;
    bool estado=false;
    
    if (b>1){
        cout<<"Hay "<<b<<" componentes" <<endl;
        estado=true;
        
    }else{
        cout<<"Solo hay una componente"<<endl;
    }

        int max=0;
        int j=-1;
        for (int i=0;i < adj_.size(); i++) { // "adj_" tiene como size el numero de nodos ingresados
            double x=adj_[i].size();
            //cout<<"El nodo: "<<i<<" tiene: "<<x<<" ";
            if(x>max){
                max=x;
                j=i;
            }
        }
        if (j != -1){
            cout <<"Nodo con menor conexiones "<<j<<endl;
            double m=adj[j].size();
            cout<<"Largo de: "<<m<<endl;
            cout<<"Sus conexiones son: ";
            for(int k=0;k<adj[j].size();k++){
                cout<<adj[j][k]<<" ";
            }
            cout<<endl;
        }
    
    do{
        
    }while(estado=true);

    return 0;
}

