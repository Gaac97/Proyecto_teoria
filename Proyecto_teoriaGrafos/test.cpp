#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "grafo.h"
#include "Cset.h"
#include "Conjunto.h"
using namespace std;

int main()
{
    Cset vr, er;
    grafo * g= new grafo(vr, er);
    return  g->dibujar();
}

