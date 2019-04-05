#include "No.h"
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>

No::No(int i)
{
    id=i;
    grau=0;
    visitado=false;
}

No::~No()
{

}

int No::getGrau()
{
    return grau;
}

void No::setGrau(int val)
{
    grau = val;
}

int No::getPeso()
{
    return peso;
}

void No::setPeso(int val)
{
    peso = val;
}

int No::getVisitado()
{
    return visitado;
}

void No::setVisitado(bool val)
{
    visitado = val;
}

