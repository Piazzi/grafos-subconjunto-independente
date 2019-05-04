#include "No.h"
#include "Aresta.h"

Aresta::Aresta()
{

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

