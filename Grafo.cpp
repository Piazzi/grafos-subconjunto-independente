#include "Grafo.h"
#include "stdio.h"

using namespace std;

Grafo::Grafo(int representacao, int qntVertices)
{
    qntVertices = qntVertices;
    representacao = representacao;
    if(representacao == 1)
    {
        int matriz[qntVertices][qntVertices];
        for(int i = 0; i< qntVertices; i++)
        {
            for(int j = 0; j<qntVertices; j++)
            {
                matriz[i][j] = 0;
            }
        }
    }
}

Grafo::~Grafo()
{

}

int Grafo::getGrau()
{
    return grau;
}

void Grafo::setGrau(int val)
{
    grau = val;
}

int Grafo::getOrdem()
{
    return ordem;
}

void Grafo::setOrdem(int val)
{
    ordem = val;
}

bool Grafo::getNoPonderado()
{
    return noPonderado;
}

void Grafo::setNoPonderado(bool val)
{
    noPonderado = val;
}

void Grafo::printMatrizAdjacente()
{
    /*
    for(int i = 0; i< qntVertices; i++)
    {
        if(i == 0)
        {
            cout << "\t";
            for(int j = 0; j < qntVertices; j++)
                cout << j << "\t";
            cout << endl;
        }

        for(int j = 0; j < qntVertices; j++)
        {
            if(j == 0)
                cout << i << "\t";
            cout << matriz[i][j] + "\t";
        }
        cout << endl;
    }
    */
}

