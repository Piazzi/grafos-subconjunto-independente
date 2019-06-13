#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"
#include <vector>
#include <iostream>

class Aresta
{
    public:
        Aresta(int id);
        ~Aresta();
        void setProx(Aresta aresta);
        Aresta getProx();
        void setNoAdj(int val);
        int getNoAdj();
        int getPeso();
        void setPeso(int val);
        void setAresta(int val , int val2);

    private:
        Aresta *prox;
        int noAdj;
        int peso;
        int id;

};

#endif // ARESTA_H_INCLUDED
