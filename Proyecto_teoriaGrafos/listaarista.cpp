#include "listaarista.h"

listaArista::listaArista()
{
    cant=0;
    head=0;
    fin=0;
}

listaArista::~listaArista()
{
    //dtor
}

void listaArista::add(arista * a)
{
    if(head==0)
        head=a;
    else
        fin->next=a;
    fin=a;
}

