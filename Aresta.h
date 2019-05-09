#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"

class Aresta
{
    public:
        Aresta(No *cabeca , No *cauda , int pesoAresta);
        Aresta(No *cabeca, No *cauda);
        Aresta();
        ~Aresta();
        void setProx(Aresta aresta);
        Aresta getProx();
        void setNoAdj(int val);
        int getNoAdj();
        //int getPeso();
        //void setPeso(int val);

    private:
        Aresta *prox;
        int noAdj;
        int peso;
        No* cabeca;
        No* cauda;
        int pesoAresta;
};

#endif // ARESTA_H_INCLUDED
