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

void Grafo::printAdjacentesAoNo()
{
    cout << "Digite o id do no desejado: ";
    int id;
    cin >> id;
    No* noDesejado = getNo(id);
    noDesejado->printAdjacentes();
}

void Grafo::removeAresta()
{
    cout << "Digite o id do vertice de uma das extremidades da aresta a ser excluida: " << endl;

    int idNo1;
    cin >> idNo1;
    No *no1 = getNo(idNo1);

    no1->printAdjacentes();

    cout << "Digite o id da outra extremidade da aresta que voce quer remover: " << endl;

    int idNo2;
    cin >> idNo2;
    No* no2 = getNo(idNo2);

    no1->removeAdjacente(no2);
    no2->removeAdjacente(no1);

    cout << "Aresta removida com sucesso!" << endl;

    if(no1->nosAdjacentes.size() == 0)
    {
        auxRemoveVertice(no1);
        cout << "Como o vertice de id " << no1->id
        << " nao tem mais arestas, ele foi removido! (O grafo nao suporta subgrafos desconexos)" << endl;
    }

    if(no2->nosAdjacentes.size() == 0)
    {
        auxRemoveVertice(no2);
        cout << "Como o vertice de id " << no2->id
        << " nao tem mais arestas, ele foi removido! (O grafo nao suporta subgrafos desconexos)" << endl;
    }
}

void Grafo::removeVertice()
{
    cout << "Digite o id do vertice a ser removido: ";
    int id;
    cin >> id;
    No* noASerRemovido = getNo(id);
    removeTodasAdjacenciasDeUmNo(noASerRemovido);

    auxRemoveVertice(noASerRemovido);
}

void Grafo::auxRemoveVertice(No* noASerRemovido)
{
    for(int i = 0; i < listaNo.size(); i++)
    {
        if(listaNo[i] == noASerRemovido)
        {
            listaNo.erase(listaNo.begin() + i);
        }
    }
}

void Grafo::removeTodasAdjacenciasDeUmNo(No* noASerRemovido)
{
    while(!noASerRemovido->nosAdjacentes.empty())   /// vai retirando os nos adjacentes ate o vetor nosAdjacentes estiver vazio
    {
        noASerRemovido->nosAdjacentes.pop_back();
    }
}

void Grafo::caminhamentoEmProfundidade(int id)
{
    No *no = getNo(id);
    for(int i = 0; i < listaNo.size(); i++)
    {
        listaNo[i]->setVisitado(false);
    }
    for(int i = 0; i < listaNo.size(); i++)
    {
        if(!listaNo[i]->getVisitado())
        {
            aprofunda(listaNo[i]);
        }
    }

}

void Grafo::aprofunda(No* no)
{
    no->setVisitado(true);
    cout << "Visitando o no  " << no->id << endl;
    for(int i = 0; i < no->nosAdjacentes.size() ; i++)
    {
        No* adjacenteAtual = no->nosAdjacentes[i];
        if(!adjacenteAtual->getVisitado())
        {
            cout << "\tNo " << adjacenteAtual->id << " nao foi visitado ainda!" << endl;
            aprofunda(adjacenteAtual);
        }
        else
        {
            cout << "\tNo " << adjacenteAtual->id << " ja foi visitado!" << endl;
        }

    }
}

void Grafo::caminhamentoEmLargura(int id)
{
    No *noInicial = getNo(id);
    for(int i = 0; i < listaNo.size(); i++)
    {
        listaNo[i]->setVisitado(false);
    }

    vector<No*> *fila = new vector<No*>;

    fila->push_back(noInicial);

    while(!fila->empty())
    {
        No *noAtual = fila->front();
        cout << "Visitando o no " << noAtual->id << endl;
        noAtual->setVisitado(true);

        for(int i = 0; i < noAtual->nosAdjacentes.size(); i++)
        {
            if(!noAtual->nosAdjacentes[i]->getVisitado())
            {
                int contador = count(fila->begin(), fila->end(), noAtual->nosAdjacentes[i]);
                if(contador == 0) /// nao permite adicionar um mesmo elemento mais de uma vez na fila
                {
                    fila->push_back(noAtual->nosAdjacentes[i]);
                    cout << "Adicionando na fila o no " << noAtual->nosAdjacentes[i]->id << endl;
                }
            }
        }
        fila->erase(fila->begin());
    }
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

