//  main.cpp
//  Proyecto
//
//  Created by Itzel Robles on 15/03/23.
//
#include <iostream>
#include <vector>
#include <cstdlib> // Para la función rand()
#include <queue>
#include <stack>
using namespace std;
//---------------------------------------------------------------------------------------------
struct Nodo {
    int id;
    bool visitado;
    vector<int>vecinos;
};
//----------------------------------------------------------------------------------------------

struct DirectedEdge {
    int from;
    int to;
    // Otros atributos del arco dirigido
};
//----------------------------------------------------------------------------------------------
int num_nodos;
vector<Nodo> nodos; // Vector nodes de tipo 'Node' (es la estructura Node)
vector<DirectedEdge> edges; //Vector edges de tipo 'DirectEdge'
//---------------------------------------------------------------------------------------------
void printNodos() {
    cout << "Nodos del grafo:" << endl;
    for (int i = 0; i < num_nodos; i++) {
        cout << nodos[i].id << " ";
    }
    cout << endl;
}
//----------------------------------------------------------------------------------------------
void printEdges() {
    cout << "Arcos dirigidos del grafo:" << endl;
    //cout << edges[i].from;
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].from << "->" << edges[i].to<<endl;
        //cout << "->" << edges[i].to;//edges[i].from << "->" << edges[i].to;
    }
}
//----------------------------------------------------------------------------------------------
void DFS(int s){
    vector<bool> visitado(num_nodos,false);
    stack<int>cola;
    int a=0;
    
    visitado[s]=true;
    cola.push(s);
    while (!cola.empty()) {
            int nodo = cola.top();
            //if(s!=nodo){
            cout << nodo << " -> ";
            cola.pop();
     
            for (DirectedEdge edge : edges) {
                if (edge.from == nodo && !visitado[edge.to]) {
                    visitado[edge.to] = true;
                    cola.push(edge.to);
                    //cout<<edge.to<<endl;
                }
            }
        a=a+1;
            //}
        }
    cout<<endl;
   // cout<< "Numero de nodos: "<<a<<endl;
    int b=num_nodos;
    if (a == b) {
        cout<<"El nodo esta fuertemente conexo con todos los demás nodos."<<endl;
    }else{
        cout<<"El nodo no esta fuertemente conexo"<<endl;
    }
    }
//----------------------ALGORITMO PARA FUERTEMENTE CONEXO --------------------------------
void dfs1(int n, stack<int>&pila){
    nodos[n].visitado=true;
    for( int vecino:nodos[n].vecinos){
        if(!nodos[vecino].visitado){
            dfs1(vecino,pila);
        }
    }
    pila.push(n);
}

vector<Nodo>transpuestos(num_nodos);
vector<DirectedEdge> edges_transpuestos;

for(const DirectedEdge &arco:edges){
    int nodo_origen=arco.to;
    int nodo_destino=arco.from;
    transpuestos[nodo_origen].vecinos.push_back(nodo_destino);
    edges_transpuestos.push_back({nodo_origen,nodo_destino});
}


void dfs2(int n, vector<int> &comp_actual){
    transpuestos[n].visitado=true;
    comp_actual.push_back(n);
    for(int vecino: transpuestos[n].vecinos){
        if(!transpuestos[vecino].visitado){
            dfs2(vecino,comp_actual);
        }
    }
}

vector<vector<int>> comp_fuerte_conex;
while(!pila.empty()){
    int nodo=pila.top();
    pila.pop();
    if(!transpuestos[nodo].visitado){
        
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

    num_nodos = n;
    nodos.resize(n);
    
    for (int i = 0; i < n; i++) {
        nodos[i].id = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double r = ((double) rand() / RAND_MAX); // Generar un número aleatorio entre 0 y 1
                if (r <= prob) {
                    DirectedEdge edge; //Vector Direc Edg.. con nombre edge
                    edge.from = i;
                    edge.to = j;
                    edges.push_back(edge); // Añadir el arco dirigido al vector de arcos
                    nodos[i].vecinos.push_back(j);
                }
                
            }
        }
    }
    
    //printNodos();
    //printEdges();
    int a=0;
    cout<<"Ingresa el nodo a explorar: ";
    cin >>a;
    
    DFS(a);
    stak<int> stk;
    
    DirectedEdge edge;
    edge.from=a;
    cout<<"A: "<<a<<endl;
    
    for(int j=0;j<=edges.size();j++){
        if(a==edges[j].from){
            cout<<"Nodo adyacente: "<<edges[j].to<<endl;
        }else{ cout<<" ";}
    }
    
    
    return 0;
}
//----------------------------------------------------------------------------------------------

