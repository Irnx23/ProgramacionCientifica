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
#include <ctime>

using namespace std;
//int num_nodes;
//----------------------------ALGORITMO DE KOSARAJU----------------------------------------
// "&Vct" es una referencia que apunta a un objeto para evitar copias inecesesarias
// en dfs1 se ingresa un vector de vectores de tipo entero, un vector booleano, un stack y un nodo inicial


void dfs1(vector<vector<int>>& Vct, vector<bool>& visitado, stack<int>& stck, int nodo) {
    visitado[nodo] = true; //Dentro del vector booleano 'visitado' Marca el primer nodo como visitado
    cout<<"Nodo visitado: "<<nodo<<" ";
//    if(Vct[nodo].size()==0){
//        cout<<"No hay conexiones, se regresa al nodo anterior a la conexion: ";
//    }
    for(int i=0; i<Vct[nodo].size(); i++) { //Recorre el tamaño del vector de vectores adj
        int vecino = Vct[nodo][i]; //Declara un entero y toma el valor de i en el vector de vectores
        cout <<" -> "<<vecino<<" ";
        if(!visitado[vecino]){
            cout<<endl;// Verifica que el nodo adyacente al nodo inicial no ha sido visitado
            dfs1(Vct, visitado, stck, vecino); //Función recursiva
        }else{cout<<"√, ";}
    }
    stck.push(nodo); //Apila el nodo a el stack st
}

void dfs2(vector<vector<int>>& Vct, vector<bool>& visitado, vector<int>& vect, int nodo){
    visitado[nodo] = true;
    cout<<"Nodo visitado: "<<nodo;
    vect.push_back(nodo); //
    for(int i=0; i<Vct[nodo].size(); i++) {
        int vecino = Vct[nodo][i];
        cout <<" <- "<<vecino<<" ";
        if(!visitado[vecino]){
            cout<<endl;
            dfs2(Vct, visitado, vect, vecino);
        }else{cout<<"√, ";}
    }
}
//---------------------------------------------------------------------------------------
vector<vector<int>> kosaraju(vector<vector<int>>& Vct) {
    double n = Vct.size();
    vector<bool> visited(n, false);
    stack<int> stk;

// Primera fase: hacer un dfs desde cada nodo y agregarlo a una pila
    cout<<"Haciendo DFS "<<endl;
    for(int i=0; i<n; i++) {
        if(!visited[i]){
            dfs1(Vct, visited, stk, i);
            cout<<endl;
        }
    }
    cout<<endl;

// Segunda fase: invertir el grafo
    vector<vector<int>> inv_Vct(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<Vct[i].size(); j++) {
            inv_Vct[Vct[i][j]].push_back(i);
        }
    }

// Tercera fase: hacer un dfs desde la pila y encontrar componentes fuertemente conectadas
    vector<vector<int>> scc;
    cout<<"Haciendo DFS a las conexiones invertidas"<<endl;
    fill(visited.begin(), visited.end(), false); //llena una vector desde el begin hasta el end de "false"
    while(!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if(!visited[node]) {
            vector<int> stk_inv;
            dfs2(inv_Vct, visited, stk_inv, node);
            cout<<endl;
            scc.push_back(stk_inv);
        }
    }

    return scc;
}



//--------------------------------------------------------------------------------------------
void LecturaComponentes(vector<vector<int>>&a){
    for(int i=0; i<a.size(); i++) {
        cout << "Componente " << i << ": ";
        for(int j=0; j<a[i].size(); j++){
            cout << a[i][j] << "  ";
        }
        cout<<endl;
    }
}

//--------------------------------------------------------------------------------------------

void LecturaComponentesNodos(vector<vector<int>>&a){
    for(int i=0; i<a.size(); i++) {
        cout << "Nodo " << i << ": ";
        for(int j=0; j<a[i].size(); j++){
            cout << " -> "<< a[i][j];
        }
        cout<<endl;
    }
}

//--------------------------------------------------------------------------------------------
vector<vector<int>> conexiones(int a,vector<vector<int>>& b,vector<vector<int>>&c,double prob){ //void
    cout<<"Haciendo conexiones aleatoriamente"<<endl;
    //prob=prob*2;
    for(int i=0;i<b[a].size();i++){
        if (i != a) {
            double r = rand()/((double)RAND_MAX);  // Generar un número aleatorio entre 0 y 1
            //cout<<"R= "<<r<<" "<<"Prob: "<<prob<<endl;
            if (r <= prob) {
                c[a].push_back(i);
                c[i].push_back(a);//Vector de conexiones
                cout<<a<<" -> "<<i<<" y "<<i<<" -> "<<a;
                cout<<endl;
            }
            
        }
        
    }
    //LecturaComponentesNodos(c);
    //vector<vector<int>>vector_fuerte2 = kosaraju(c);
    //LecturaComponentes(vector_fuerte2);
    return c;
}
//----------------------------------------------------------------------------------------------
vector<vector<int>> RevisionAdj( vector<vector<int>>&adj_,vector<vector<int>>&adj,double prob){
        int max=0;
        int j=-1;
        for (int i=0;i < adj_.size(); i++) {
            double x=adj_[i].size();
            if(x>max){
                max=x;
                j=i;
            }
        }
        if (j != -1){
            cout <<"Nodo con menor conexiones "<<j<<endl;
            cout<<"Sus conexiones son: ";
            for(int k=0;k<adj[j].size();k++){
                cout<<adj[j][k]<<" ";
            }
            cout<<endl;
        }
        prob=prob*2;
    
    for(int i=0;i<adj_[j].size();i++){
        if (i != j) {
            bool encontrado = false;
            for(int k=0; k<adj[j].size(); k++){
                if(adj[j][k] == i){
                    encontrado = true;
                    break;
                       }
                   }
            
            if(!encontrado){
                double r = rand()/((double)RAND_MAX);  // Generar un número aleatorio entre 0 y 1
                //cout<<"R= "<<r<<" "<<"Prob: "<<prob<<endl;
                if (r <= prob) {
                    adj[j].push_back(i);
                    adj[i].push_back(j);//Vector de conexiones
                    cout<<j<<" -> "<<i<<" y "<<i<<" -> "<<j;
                    cout<<endl;
                }
            }
            
        }
        
    }
   // LecturaComponentesNodos(adj);
    return adj;
}

//----------------------------------------------------------------------------------------------

vector<vector<int>>Revision_adj_(vector<vector<int>>&adj_,vector<vector<int>>&adj){
    for (int i = 0; i <adj.size(); i++) {
        for (int j = 0; j <adj.size(); j++) {
            if(adj_[i][j]!= adj[i][j]){
                if(adj_[i].size()<=j){
                    adj_[i].resize(j+1);
                }
                adj_[i].push_back(j);
               // adj_[i][j]=adj[i][j];
            }
        }
    }
            
    return adj_;
    }


//----------------------------------------------------------------------------------------------
int main() {
    int n = 0; // Número de nodos
    unsigned int seed=123;
    srand(seed);
    srand(time(nullptr));
    cout<<"Ingresa el números de nodos: ";
    cin>>n;
    double prob=1;
    do{
        cout<<"Ingresa la probabilidad de conectividad: ";
        cin>>prob;}while (0<prob<1);
    //-------------------------- Genera las conexiones en los nodos -------------------------
    
    vector<vector<int>>adj(n);
    vector<vector<int>>adj_(n);
   // cout<<"CONEXIONES: "<<endl;
    for (int i = 0; i < n; i++) {
        //cout<<"Nodo: "<<i;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double r = rand()/((double)RAND_MAX); // Generar un número aleatorio entre 0 y 1
                if (r <= prob) {
                    adj[i].push_back(j); //Vector de conexiones
                    //cout<<" -> "<<j<<" ";
                }else{adj_[i].push_back(j); //Vector de NO conexiones
                    // cout<<" / " <<j<<" ";
                }
                
            }
        }
       // cout<<endl;
    }
    
    //-----------------------------------------------------------------------------------------------
    cout<<"-------------------------------------"<<endl;
    vector<vector<int>> vector_fuerte = kosaraju(adj);
    cout<<endl;
    double b=vector_fuerte.size();
    //bool estado=false;
    LecturaComponentes(vector_fuerte);
    cout<<"-------------------------------------"<<endl;
    int iteraciones=0;
    if(b>1){
        while (b != 1){
            cout<<"Hay "<<b<<" componentes" <<endl;
            vector<vector<int>>resultado_adj=RevisionAdj(adj_, adj, prob);
            LecturaComponentesNodos(resultado_adj);
            //vector<vector<int>>resultado_adj_=Revision_adj_(adj_,adj) ;
            vector<vector<int>>prueba=kosaraju(resultado_adj);
            cout<<endl;
            LecturaComponentes(prueba);
            adj=resultado_adj;
            //adj_=resultado_adj_;
            b=prueba.size();
            cout<<b<<endl;
            cout<<"-------------------------------------"<<endl;
            iteraciones++;
        }
    }else{
        cout<<"Solo hay una componente."<<endl;
    }
    cout<<"Hubieron "<<iteraciones<<" iteraciones";
        cout<<endl;
    return 0;
}

