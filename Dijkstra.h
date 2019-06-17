#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include "Grafo.h"
#include "No.h"

using namespace std;

class Dijkstra()
{
    static void custoCaminhoMinimo(Grafo *grafo, int idNo1, int idNo2);
    static No *getNoDistanciaMinima(list<No *> Nos);
};

#endif // DIJKSTRA_H_INCLUDED
