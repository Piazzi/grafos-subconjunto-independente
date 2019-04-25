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
        void matrizAdjacencia(bool val);
        void printListaAdjacencia();
        void printNos();
        void adicionaVertice(No *no);
        void removeVertice();
        void auxRemoveVertice(No* noASerRemovido);
        void removeTodasAdjacenciasDeUmNo(No* noASerRemovido);
        void removeAresta();
        void buscaProfundidade(int idInicial);
        No *getVertice(int id);
        bool possuiAresta(int id1, int id2);
        Aresta *getAresta(int id1, int id2);
        bool verificaId(int id);
        No * getNo(int id);
        void printAdjacentesAoNo();

    private:
       int ordem;
       bool noPonderado;
       int grau;
       void buscaProfundidade_recursiva(int ini, int *visitado, int cont);

};


#endif // GRAFO_H_INCLUDED
