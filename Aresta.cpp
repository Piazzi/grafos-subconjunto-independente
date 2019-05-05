#include "No.h"
#include "Aresta.h"
#include <iostream>

Aresta::Aresta()
{
    peso = 0 ;
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
