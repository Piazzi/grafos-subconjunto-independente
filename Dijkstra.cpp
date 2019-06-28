#include "Dijkstra.h"
#include "Grafo.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

/**
 * Calcula o custo de um caminho minimo entre dois nos
 *
*/
void Dijkstra::custoCaminhoMinimo(Grafo *grafo, int id1, int id2)
{
    No *NoInicial = grafo->getNo(id1);
    NoInicial->distancia = 0;

    /// o restante dos nos ja estao definidos com a distancia = infinito atraves do construtor da classe No

    vector<No *> Nos(grafo->listaNo);
   // while (!Nos.empty())
    //{
        No *No = getNoDistanciaMinima(Nos);

        for (auto NoAdjacente : No->nosAdjacentes)
        {
            cout<<No->nosAdjacentes[0]<<endl;
            Aresta *aresta = grafo->getAresta(id1, id2);
            /// relaxamento da aresta
            if (NoAdjacente->distancia > No->distancia + aresta->peso)
            {
                NoAdjacente->distancia = No->distancia + aresta->peso;
                grafo->getNo(NoAdjacente->id)->distancia = NoAdjacente->distancia;
            }
        }
        Nos.push_back(No);
   // }
cout<<"1"<<endl;
    int custo = grafo->getNo(id2)->distancia;

    /// numeric_limits representa o infinito
    if (custo < numeric_limits<int>::max())
    {
        cout << "O custo do caminho m�nimo �: " << grafo->getNo(id2)->distancia << endl;
    }
    else
    {
        cout << "Nao existe caminho entre os dois vertices." << endl;
    }
}

/**
 *
 *
*/
No *Dijkstra::getNoDistanciaMinima(vector<No *> Nos)
{
    No *NoDistanciaMinima = Nos.front();

    for (auto i = Nos.begin(); i != Nos.end(); i++)
    {
        No *No = *i;
        if (No->distancia < NoDistanciaMinima->distancia)
        {
            NoDistanciaMinima = No;
        }
    }

    return NoDistanciaMinima;
}
