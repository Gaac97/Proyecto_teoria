#include <iostream>
#include <list>
#include "Conjunto.h"
#ifndef CSECUENCIA_H
#define CSECUENCIA_H
using namespace std;

class Csecuencia: public Conjunto
{
    public:
        Csecuencia(){tipoC="sec";}
        void insertarElemento(int n);
        void limpiezaDatos();
        void imprimir();
};

#endif // CSECUENCIA_H
