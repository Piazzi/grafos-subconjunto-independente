#ifndef PRIM_H_INCLUDED
#define PRIM_H_INCLUDED

#include "Grafo.h"

using namespace std;

class Prim()
{
public:

    void arvoreGeradoraMinima();
    void imprimeSolucao();
    Aresta * getArestaMenorPeso(Grafo *grafo, Grafo *arvoreGeradoraMinima);


};


#endif // PRIM_H_INCLUDED
