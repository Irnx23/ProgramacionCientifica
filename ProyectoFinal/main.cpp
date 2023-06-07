#include "Header.hpp"
#include "Instancia.hpp"
#include "Solucionador.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc>2);
    string mode=argv[1];
    if(mode=="-g"){
        int n=atoi(argv[2]);
        int seed= (int)clock();
        string instname="Asig_"+to_string(n)+"_"+to_string(seed)+".txt";
        if(argc>=4) seed=atoi(argv[3]);
        if(argc==5) instname=argv[4];
        cout<<"Hagamos una instancia de "<<n<<" clientes, semilla = "<<seed<<endl;
        cout<<"Archivo de salida: "<<instname<<endl;
        srand(seed);
        Instance * I = new Instance(n,instname);
        I->print();
        I->save();
        
    }else if(mode=="-s"){
        string instname=argv[2];
        Instance *I=new Instance(instname); //Lee la instancia de .txt
        Solucion *A=new Solucion(I); //Resuelve el problema y guarda el modelo en un archivo.
        A->saveresults(I,""); //Guarda el resultado del problema en un archivo de texto llamado 'Prueba.txt'
        
    }
}
