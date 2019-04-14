#include "Grafo.h"
#include "stdio.h"
#include <vector>
#include <algorithm>
#include <stack> //Biblioteca para pilhas

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

/*void Grafo::printMatrizAdjacencia()
{
    int tam = listaNo.size();
    int matriz[tam][tam];
    for(int i = 0; i < tam; i++)
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
            for(int j = 0; j < listaNo[j]->nosAdjacentes.size(); j++)
            {
                if(listaNo[j]->id == listaNo[j]->id)
                    matriz[i][j] == 1;
            }

            cout << matriz[i][j] << "  ";

        }
    }

} */

void Grafo::matrizAdjacencia(bool direcionado)
{
    int tam = listaNo.size();
    int matriz[tam][tam];
    for(int l = 0 ; l < tam ; l++)
        for(int t = 0 ; t < tam ; t++)
            matriz[l][t] = 0;
    for(int i = 0; i < tam; i++)
    {
        No *elementoi = listaNo[i];
        for(int j = 0; j < tam; j++)
        {
            No *elementoj = listaNo[j];
            if(elementoi->verificaAdjacencia(elementoj))
            {
                matriz[i][j]=1;
                if(direcionado == 1)
                {
                    matriz[j][i] = -1;
                }
            }
            else
            {
                if( i > j )
                {
                    if(matriz[j][i] == 0)
                    {
                        matriz[i][j]=0;
                    }
                }
                else
                {
                    matriz[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < tam; i++)
    {
        if(i == 0)
        {
            cout << "    ";
            for(int i = 0; i < tam; i++)
                cout << " [" << listaNo[i]->id << "] ";
            cout << endl;
        }

        for(int j = 0; j < tam; j++)
        {
            if(j == 0)
                cout << "[" << listaNo[i]->id << "] ";
            cout << " [" << matriz[i][j] << "] ";
        }
        cout << endl;
    }
}
void Grafo::printListaAdjacencia()
{
    int tam = listaNo.size();
    int aux = 0 ;
    for(int i = 0; i < tam; i++)
    {
        cout << endl;
        No *elemento = listaNo[i];
        vector<No*> adjacentes = elemento->getAdjacentes();
        cout << elemento->id;
        for(int j = 0; j < tam; j++)
        {
            if(elemento->verificaAdjacencia(listaNo[j]))

            {
                cout << " -> " << listaNo[j]->id;
            }
        }
    }
    cout << endl;
}

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

void Grafo::printNos()
{
    cout << "Lista de vertices do grafo: " << endl;
    for(int i = 0; i < listaNo.size(); i++)
    {
        cout << listaNo[i]->id << " ";
    }
    cout << endl;
}
/*
void Grafo::caminhaProfundidade(int id)
{
    stack<No*> pilha;
    No *no = getNo(id); // nó com o id passado
    vector<No*> visitados[listaNo.size()]; // vetor de nós visitados

    //marcando todos como não visitados
    for(int i = 0; i < listaNo.size(); i++)
        visitados[i].setVisitado(false);

    while(true)
    {
        if(!visitados[i].getVisitado())
        {
            cout << "Visitando vertice " << visitados[i].id << endl;
            visitados[i].setVisitado(true); // marcando nó como visitado
            pilha.push(no);

            bool achou = false;
            vector<No*>::iterator it;

            //nessa parte eu quero fazer um vetor que analisa os visinhos  de cada vertice e veja se ele fou visitado ou não
            for(it = no.getAdjacentes().begin(); it != no.getAdjacentes().end(); it++)
            {
                if(!it.getVisitado())
                {
                    achou = true;
                    break;
                }
            }
            if (achou)
                no = it; //atualiza do vertice em análise

            else
            {
                // se todos os visinhos estão visitados ou não existem visinhos (folha)
                //remove da pilja
                pilha.pop();
                // se a pilha ficar vazia, então terminou a busca
                if (pilha.empty())
                    break;
                //se chegar aqui , pode pegar o elemento do topo
                no = pilha.top();
            }


        }
    }
}
*/

