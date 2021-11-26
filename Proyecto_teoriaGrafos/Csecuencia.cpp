#include "Csecuencia.h"


void Csecuencia::imprimir(){
    list<int> ::iterator pos;
    list<int> ::iterator fin;
    pos = datos.begin();
    fin = datos.end();
    fin--;
    cout<<" ( ";
    while(pos != datos.end()){
        cout<<*pos;
        if(pos != fin){
            cout<<" , ";
        }
        pos++;
    }
    cout<<" )";
}


void Csecuencia::insertarElemento(int n){
    list<int> ::iterator pos;
    pos = datos.begin();
    bool seInserto = false;
    while(pos != datos.end()){
        if((!seInserto)&&(*pos >= n)){
            datos.insert(pos, n);
            seInserto = true;
            break;
        }
        pos++;
    }
    if(!seInserto){
        datos.push_back(n);
    }
}

