#ifndef LISTAARISTA_H
#define LISTAARISTA_H
#include "arista.h"

class listaArista
{
    public:
        listaArista();
        arista * head;
        arista * fin;
        int cant;
        void add(arista * a);
        virtual ~listaArista();

    protected:

    private:
};

#endif // LISTAARISTA_H
