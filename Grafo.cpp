#include "Grafo.h"
#include "stdio.h"
#include <vector>

using namespace std;

Grafo::Grafo()
{

}

Grafo::~Grafo()
{

}

int Grafo::getGrau()
{
    return grau;
}

void Grafo::setGrau(int val)
{
    grau = val;
}

int Grafo::getOrdem()
{
    return ordem;
}

void Grafo::setOrdem(int val)
{
    ordem = val;
}

bool Grafo::getNoPonderado()
{
    return noPonderado;
}

void Grafo::setNoPonderado(bool val)
{
    noPonderado = val;
}

void Grafo::printMatrizAdjacencia()
{
    int tam = listaNo.size();
    int matriz[tam][tam];
    for(int i = 0; i < tam;i++)
        for(int j = 0; j < tam; j++)
            matriz[i][j] = 0;

    for(int i = 0; i< tam; i++)
    {
        if(i == 0)
        {
            cout << "   ";
            for(int i = 0; i < tam; i++)
            cout << "[" << listaNo[i]->id << "]";
            cout << endl;
        }

        for(int j = 0; j < tam; j++)
        {
            if(j == 0)
                cout << "[" << listaNo[i]->id << "] ";
            matriz[i][j] = 0;
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }

}

/*
void Grafo::printListaAdjacencia()
{
    int tam = listaNo.size();
    for(int i = 0; i < tam; i++)
    {
        No elemento = listaNo[i];
        vector<No *> adjacentes = elemento.getAdjacentes()
        cout << elemento->id
        for(int j = 0; j < tam; j++)
        {
            if(find(adjacentes.begin(), adjacentes.end(), listaNo[j])){
                cout << " -> " << listaNo[j]->id;
            }
        }
    }
}
*/

void Grafo::adicionaVertice(No *no)
{
    if(verificaId(no->id))
    {
        cout << "Esse id ja esta sendo utilizado, digite um id valido" << endl;
    }
    else
    {
        listaNo.push_back(no);
        cout << "No adicionado com sucesso" << endl;
    }
}

bool Grafo::verificaId(int id)
{
    for(int i = 0; i < listaNo.size(); i++)
    {
        if(listaNo[i]->id == id)
        {
            return true;
        }
    }
    return false;
}

No * Grafo::getNo(int id)
{
    if(verificaId(id))
    {
        for(int i = 0; i < listaNo.size(); i++)
        {
            if(listaNo[i]->id == id)
                return listaNo[i];
        }
    }
}

