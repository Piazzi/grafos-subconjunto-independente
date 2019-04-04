#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"

class Grafo
{
    public:
        Grafo(int representacao, int qntVertices);
        ~Grafo();
        int getOrdem();
        void setOrdem(int val);
        int getGrau();
        void setGrau(int val);
        bool getNoPonderado();
        void setNoPonderado(bool val);
        void printMatrizAdjacente();

    private:
       int ordem;
       int grau;
       bool noPonderado;
       int qntVertices;
       int representacao;
       int *matriz;
       No *listaNos;

};


#endif // GRAFO_H_INCLUDED
