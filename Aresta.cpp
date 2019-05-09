#include "No.h"
#include "Aresta.h"

Aresta::Aresta(No *cabeca , No* cauda , int pesoAresta)
{
    this.cabeca = cabeca;
    this.cauda = cauda;
    this.pesoAresta = pesoAresta;
}
Aresta::Aresta(No *cabeca , No* cauda)
{
    this.cabeca = cabeca;
    this.cauda = cauda;
}
Aresta::Aresta(){
}
Aresta::~Aresta()
{

}

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
/*
void Aresta::setPeso(int val){
    peso = val;
}

int Aresta::getPeso(){
    return peso;
}*/
