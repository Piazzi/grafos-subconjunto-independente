#include "Prim.h"
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Recebe um grafo e gera uma �rvore geradora m�nima para ele
 * @param Grafo
 * @return void
*/
void Prim::arvoreGeradoraMinima(Grafo *grafo) {

    /// precisa verificar se o grafo � conexo.
    if (true) {
        auto *arvoreGeradoraMinima = new Grafo();

        int tam = grafo->listaNo.size();

        /// pega um v�rtice aleat�rio e o insere na AGM.
        auto *noInicial = new No(grafo->listaNo.at(rand() % tam-1)->id);
        arvoreGeradoraMinima->listaNo.push_back(noInicial);

        /// adiciona n�s e arestas de menor peso enquanto a AGM n�o possuir todos os v�rtices.
        while (arvoreGeradoraMinima->listaNo.size() < tam) {
            Aresta *aresta = getArestaMenorPeso(grafo, arvoreGeradoraMinima);

            auto *No1 = new No(aresta->No1->id);
            auto *No2 = new No(aresta->No2->id);

            if (!arvoreGeradoraMinima->verificaId(No1->id)) {
                arvoreGeradoraMinima->listaNo.push_back(No1);
            }

            if (!arvoreGeradoraMinima->verificaId(No2->id)) {
                arvoreGeradoraMinima->listaNo.push_back(No2);
            }

            arvoreGeradoraMinima->arestas.push_back(aresta);
        }

        imprimirSolucao(arvoreGeradoraMinima);
    } else {
        cout << "O grafo eh desconexo." << endl;
    }
}

/**
 * Retorna a aresta de menor peso de um grafo
 * @param Grafo
 * @param Grafo
 * @return Aresta
*/
Aresta *Prim::getArestaMenorPeso(Grafo *grafo, Grafo *arvoreGeradoraMinima) {
    auto *arestaMenorPeso = new Aresta();
    int pesoMinimo = numeric_limits<int>::max();

    for (auto aresta : grafo->arestas) {
        if (!(arvoreGeradoraMinima->verificaId(aresta->No1->id) && arvoreGeradoraMinima->verificaId(aresta->No2->id))) {
            if (arvoreGeradoraMinima->verificaId(aresta->No1->id)|| arvoreGeradoraMinima->verificaId(aresta->No2->id)) {
                if (aresta->peso < pesoMinimo) {
                    arestaMenorPeso = aresta;
                    pesoMinimo = aresta->peso;
                }
            }
        }
    }

    return arestaMenorPeso;
}

/**
 * Imprime uma �rvore geradora m�nima de um grafo
 * @param Grafo
 * @return void
*/
void Prim::imprimeSolucao(Grafo *grafo) {
    cout << "Arvore Geradora Minima - Prim:" << endl;
    for (auto aresta : grafo->arestas) {
        cout << "(" << aresta->No1->id << "," << aresta->No2->id << ") ";
    }
    cout << endl;
}
