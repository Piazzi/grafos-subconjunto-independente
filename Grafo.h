#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
#include <vector>
#include <iostream>

using namespace std;

class Grafo
{
    public:
        Grafo();
        ~Grafo();

        vector<No*> listaNo;
        vector<Aresta *> arestas;

        int getOrdem();
        void setOrdem(int val);
        int getGrau();
        void setGrau(int val);
        bool getNoPonderado();
        void setNoPonderado(bool val);
        void printMatrizAdjacencia();
        void printListaAdjacencia();
        void adicionaVertice(No *no);
        No *getVertice(int id);
        bool possuiAresta(int id1, int id2);
        Aresta *getAresta(int id1, int id2);
        bool verificaId(int id);

    private:
       int ordem;
       int grau;
       bool noPonderado;

};


#endif // GRAFO_H_INCLUDED
