#include "arista.h"
#include "circulo.h"

arista::arista(int p,circulo * d)
{
    next=0;
    destino=d;
    peso=p;
}

arista::~arista()
{
    //dtor
}
