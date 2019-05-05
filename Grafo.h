#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
#include <vector>
#include <stack>
#include <iostream>
#include <list>
#define NIL-1

using namespace std;

class Grafo
{
    public:
        Grafo();
        ~Grafo();
        vector<No*> listaNo;
        list<int> *adj;
        vector<Aresta *> arestas;
        void adicionaVerticePonderado(No *no, int peso);
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
        No *getVertice(int id);
        bool possuiAresta(int id1, int id2);
        Aresta *getAresta(int id1, int id2);
        bool verificaId(int id);
        No * getNo(int id);
        void printAdjacentesAoNo();
        void caminhamentoEmProfundidade(int id);
        void aprofunda(No* no);
        void caminhamentoEmLargura(int id);
        void setVisitadoEmTodosNos(bool visitado);
        void caminhaEmLargura(vector<No*> fila);
        void componentesConexas();
        void componenteFortementeConexas();
        void imprimePesoVertice();
        void imprimePesoAresta();
        void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]);
        void SCC();


    private:
       int ordem;
       int grau;
       bool noPonderado;

};


#endif // GRAFO_H_INCLUDED
