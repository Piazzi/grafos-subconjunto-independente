#include "No.h"
#include "Aresta.h"
#include <vector>

using namespace std;


Aresta::Aresta(No *cauda, No *cabeca)
{
    cauda->arestas.push_back(this);
    cabeca->arestas.push_back(this);

    cauda->nosAdjacentes.push_back(cabeca);
    cabeca->nosAdjacentes.push_back(cauda);

    cauda->grau++;
    cabeca->grau++;

    this->cabeca = cabeca;
    this->cauda = cauda;

}


/*
int Aresta::getNoAdj()
{
    return noAdj;
}

void Aresta::setNoAdj(int val)
{
    noAdj = val;
}

Aresta Aresta::getProx()
{
    return *prox;
}

void Aresta::setProx(Aresta aresta)
{
    *prox = aresta;
}

void Aresta::setPeso(int val){
    peso = val;
}

int Aresta::getPeso(){
    return peso;
}*/
