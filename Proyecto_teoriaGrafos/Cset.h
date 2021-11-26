#include <iostream>
#include <list>
#include "Conjunto.h"
#include "Csecuencia.h"
#ifndef CSET_H
#define CSET_H
using namespace std;

//lsec guardara los pares ordenados que unen los vertices.
//cada sec es un par ordenado, el tipoSet puede ser "primitivo" o "secuencia"

class Cset: public Conjunto{
    public:
        //--- PROPIEDADES ---
        list<Csecuencia> lsec;
        string tipoSet="";
        Cset(string tipoSe);
        //--- FUNCIONES ---
        void insertarElemento(int n);
        void insertarElemento(Csecuencia n);
        void imprimir();
        Cset();

};

#endif // CSET_H
