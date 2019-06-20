#include "Dijkstra.h"
#include "Grafo.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

/**
 * Calcula o custo de um caminho m�nimo entre dois n�s
 *
*/
void Dijkstra::custoCaminhoMinimo(Grafo *grafo, int id1, int id2) {
    No *NoInicial = grafo->getNo(id1);
    NoInicial->distancia = 0;

    vector<No *> Nos(grafo->listaNo);

    while (!Nos.empty()) {
        No *No = getNoDistanciaMinima(Nos);

        for (auto NoAdjacente : No->nosAdjacentes) {
            Aresta *aresta = grafo->getAresta(id1, id2);

            /// relaxamento da aresta
            if (NoAdjacente->distancia > No->distancia + aresta->peso) {
                NoAdjacente->distancia = No->distancia + aresta->peso;
                grafo->getNo(NoAdjacente->id)->distancia = NoAdjacente->distancia;
            }
        }

        Nos.push_back(No);
    }

    int custo = grafo->getNo(id2)->distancia;

    if (custo < numeric_limits<int>::max()) {
        cout << "O custo do caminho m�nimo �: " << grafo->getNo(id2)->distancia << endl;
    } else {
        cout << "N�o existe caminho entre os dois v�rtices." << endl;
    }
}

/**
 *
 *
*/
No *Dijkstra::getNoDistanciaMinima(vector<No *> Nos) {
    No *NoDistanciaMinima = Nos.front();

    for (auto i = Nos.begin(); i != Nos.end(); i++) {
        No *No = *i;
        if (No->distancia < NoDistanciaMinima->distancia) {
            NoDistanciaMinima = No;
        }
    }

    return NoDistanciaMinima;
}
