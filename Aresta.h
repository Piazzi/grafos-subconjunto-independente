#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include "No.h"

class Aresta
{
    public:


        // Implementa��o antiga
        /*
        void setProx(Aresta aresta);
        Aresta getProx();
        void setNoAdj(int val);
        int getNoAdj();
        //int getPeso();
        //void setPeso(int val);
        Aresta *prox;
        int noAdj;
        */

        // Nova implementa��o

         Aresta();
        ~Aresta();

        explicit Aresta(No *cauda, No *cabeca);
        Aresta(No *cauda, No* cabeca, peso);

        No *cauda;
        No *cabeca;
        int peso;


};

#endif // ARESTA_H_INCLUDED
