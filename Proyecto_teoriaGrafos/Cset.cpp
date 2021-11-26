#include "Cset.h"

Cset::Cset(string tipoSe){
    tipoSet = tipoSe;
    tipoC="set";
}

Cset::Cset(){
    
}

void Cset::imprimir(){
    if(tipoSet == "entero"){
        list<int> ::iterator pos;
        list<int> ::iterator fin;
        pos = datos.begin();
        fin = datos.end();
        fin--;
        cout<<" { ";
        while(pos != datos.end()){
            cout<<*pos;
            if(pos != fin){
                cout<<" , ";
            }
            pos++;
        }
        cout<<" }";
    }else{
        list<Csecuencia> ::iterator pos;
        list<Csecuencia> ::iterator fin;
        pos = lsec.begin();
        fin = lsec.end();
        fin--;
        cout<<" { ";
        while(pos != lsec.end()){
            Csecuencia c = *pos;
            c.imprimir();
            if(pos != fin){
                cout<<" , ";
            }
            pos++;
        }
        cout<<" }";
    }

}

void Cset::insertarElemento(int n){
    bool hayRepetidos = false;
    list<int> ::iterator pos;
    pos = datos.begin();
    while(pos != datos.end()){
        if(*pos == n){
            hayRepetidos = true;
            break;
        }
        pos++;
    }
    if(!hayRepetidos){
        datos.push_back(n);
    }else{
        cout<<"El valor ya existe en el SET."<<endl;
    }
}

void Cset::insertarElemento(Csecuencia n){
    bool hayRepetidos = false;
    list<int> Ln = n.datos;
    list<Csecuencia> ::iterator pos;
    pos = lsec.begin();
    while(pos != lsec.end()){
        list<int> L2;
        Csecuencia cs = *pos;
        L2 = cs.datos;
        if(L2 == Ln){
            hayRepetidos = true;
            break;
        }
        pos++;
    }
    if(!hayRepetidos){
        lsec.push_back(n);
    }else{
        cout<<"El valor ya existe en el SET."<<endl;
    }
}
