#include <iostream>
#include <list>
#ifndef CONJUNTO_H
#define CONJUNTO_H
using namespace std;

class Conjunto
{
    public:
        //Propiedades
        list<int> datos;
        string tipoC="";
        //Funciones
        virtual void insertarElemento(int n){datos.push_back(n);}
        virtual void imprimir(){cout<<"vacio"<<endl;}
};

#endif // CONJUNTO_H
