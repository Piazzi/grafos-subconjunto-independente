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
        //int getPeso();
        //void setPeso(int val);

    private:
        Aresta *prox;
        int noAdj;
        int peso;

};

#endif // ARESTA_H_INCLUDED
