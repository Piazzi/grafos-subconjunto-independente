#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"
#include "Aresta.cpp"
#include <vector>

using namespace std;

class No
{
    public:
        No(int id);
        ~No();

        vector<No *> nosAdjacentes;

        int id;
        int getPeso();
        void setPeso(int val);
        int getGrau();
        void setGrau(int val);
        int getVisitado();
        void setVisitado(bool val);
        No* getProx();
        void setProx(No* val);
        vector<No *> getAdjacentes();
        void adicionaNoAdjacente(No *no);


    private:
        int peso;
        int grau;
        vector<Aresta *> arestas;
        bool visitado;

};

#endif // NO_H_INCLUDED
