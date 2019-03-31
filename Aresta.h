#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"

class Aresta
{
    public:
        Aresta();
        ~Aresta();
        void setProx(Aresta aresta);
        Aresta getProx();
        void setNoAdj(int val);
        int getNoAdj();

    private:
        Aresta *prox;
        int noAdj;

};

#endif // ARESTA_H_INCLUDED
