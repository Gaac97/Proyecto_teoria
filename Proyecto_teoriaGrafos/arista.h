#ifndef ARISTA_H
#define ARISTA_H
#include "circulo.h"

class arista
{
    public:
        arista(int p,circulo * d);
        int peso;
        arista * next;
        circulo * destino;

        virtual ~arista();

    protected:

    private:
};

#endif // ARISTA_H
