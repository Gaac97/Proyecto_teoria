#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "circulo.h"
#include "arista.h"
#include "Cset.h"
#include "Conjunto.h"
using namespace std;

struct etiqueta{
    int destin;
    int distancia;
    int origen;

};

struct dijikstra{
    int distancia;
    vector<int>ruta;
};
class grafo
{
    public:
    Cset stv,ste;
        grafo();
        etiqueta e;
        dijikstra d;
        int verificar(etiqueta arr[],int n);
        void dijkstra(int actual,int des);
        void auxiliar(int c,etiqueta arreglo[],int no,int ant,int peso,int actual,int dest);
        int dibujar();
        grafo(Cset vr, Cset er);

        int mayor();

        vector<arista *>vertices;
        virtual ~grafo();



    protected:

    private:
        void graf();
};

#endif // GRAFO_H
