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
        cout << "****** No adicionado com sucesso *****" << endl;
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

void Grafo::caminhamentoEmProfundidade(int id) ///funcao principal, que chama a funcao que, de fato, faz o caminhamento
{
    setVisitadoEmTodosNos(false);
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
    cout << no->id << " "; ///para busca em profundidade normal, descomentar as linhas com a tag BUSCANORMAL
    for(int i = 0; i < no->nosAdjacentes.size() ; i++)
    {
        No* adjacenteAtual = no->nosAdjacentes[i];
        if(!adjacenteAtual->getVisitado())
        {
            /// cout << "\tNo " << adjacenteAtual->id << " nao foi visitado ainda!" << endl; *BUSCANORMAL*
            aprofunda(adjacenteAtual);
        }
        else
        {
            /// cout << "\tNo " << adjacenteAtual->id << " ja foi visitado!" << endl; *BUSCANORMAL*
        }

    }
}

void Grafo::caminhamentoEmLargura(int id)   ///funcao principal, que chama a funcao que, de fato, faz o caminhamento
{
    setVisitadoEmTodosNos(false);

    No *noInicial = getNo(id);
    vector<No*> *fila = new vector<No*>;
    fila->push_back(noInicial);

    caminhaEmLargura(*fila); ///chama funcao auxiliar, que faz o caminhamento em largura
}

void Grafo::caminhaEmLargura(vector<No*> fila)
{
    while(!fila.empty())
    {
        No *noAtual = fila.front();
        cout << "Visitando o no " << noAtual->id << endl;
        noAtual->setVisitado(true);

        for(int i = 0; i < noAtual->nosAdjacentes.size(); i++)
        {
            if(!noAtual->nosAdjacentes[i]->getVisitado())
            {
                int contador = count(fila.begin(), fila.end(), noAtual->nosAdjacentes[i]);
                if(contador == 0) /// nao permite adicionar um mesmo elemento mais de uma vez na fila
                {
                    fila.push_back(noAtual->nosAdjacentes[i]);
                    cout << "Adicionando na fila o no " << noAtual->nosAdjacentes[i]->id << endl;
                }
            }
        }
        fila.erase(fila.begin());
    }
}

void Grafo::setVisitadoEmTodosNos(bool visitado)
{
    for(int i = 0; i < listaNo.size(); i++)
    {
        listaNo[i]->setVisitado(visitado);
    }
}

void Grafo::componentesConexas()
{
    cout << "Componentes conexas: " << endl;
    for(int i = 0; i < listaNo.size(); i++)
    {
        if(!listaNo[i]->getVisitado())
        {
            cout << endl << "Componente conexa comencando em " << listaNo[i]->id << " : ";
            aprofunda(listaNo[i]);
        }
    }
    cout << endl;
}

void Grafo::adicionaVerticePonderado(No *no, int peso)
{

    if(verificaId(no->id))
    {
        cout << "Esse id ja esta sendo utilizado, digite um id valido" << endl;
    }
    else
    {
        listaNo.push_back(no);
        cout << "****** No adicionado com sucesso *****" << endl;
        no->setPeso(peso);
        cout << "****** Peso no vertice adicionado com sucesso *****"<<endl;

    }
}

void Grafo::imprimePesoVertice()
{
    No *peso;
    int conferePeso;
    cout<<"Digite o vertice que deseja saber o peso"<<endl;
    cin>> conferePeso;
    if(verificaId(conferePeso))
    {
        peso = getVertice(conferePeso);
        cout<<"O peso do vertice "<<conferePeso<<" e: "<<endl;
    }
    else
    {
        cout<<"O Vertice inserido nao existe no grafo"<<endl;
    }
}
void Grafo::imprimePesoAresta()
{
    int confereIdADj = 0;
    int confereId = 0 ;
    cout<<"Digite o primeiro vertice"<<endl;
    cin>>confereId;
    cout<<"Digite o segundo vertice"<<endl;
    cin>>confereIdADj;
    /*   if(possuiAresta(confereId, confereIdADj))
       {
           cout<<"A aresta existe"<<endl;
           //getAresta(confereId,confereIdADj);
       }  else
       {
           cout<<"Os vertices inseridos no programa nao possui aresta"<<endl;
       }*/
}

No * Grafo::getVertice(int id)
{


}

void Grafo::ordenacaoTopologica()
{
    int n = listaNo.size(); //vertices
    int m =0; // arestas
    int grafo[n];
    int grau[n];
    int lista[n]; // dos vértices de grau zero
    int listaPos = 0; //posição de inserção na lista
    No *atual;
    atual = NULL;
    int cont =0;

    for(int i = 0; i<n; i++)
    {
        m = m+ listaNo[i]->getGrau();
        grafo[i] = listaNo[i]->id;
        grau[i]=listaNo[i]->getGrau();
        lista[i]=0;
    }

while(listaPos < n){
    for(int i = 0; i< n; i++)
    {
        if(grau[i] == 0)  // se o grau for 0
        {
            lista[listaPos] = grafo[i];// coloco o vertice na posição listaPos da lista
            listaPos++; // atualizo listaPos para a proxima inserção
            for(int t = 0; t < n; t++)
            {
                if(listaNo[t]->id == grafo[i])
                    atual = listaNo[t]; // No atual recebe o No com o id
            }

            for(int j = 0; j< atual->nosAdjacentes.size(); j++) // para todos os adjacentes ao no com grau 0
            {
                for(int k =0; k<n; k++)  //percorro todos os vevrtices do grafo[] procurando alguem com aquele id
                {
                    if(grafo[k] == atual->nosAdjacentes[j]->id)// se o vetice tiver aquele id
                        grau[k] = grau[k]- 1;// diminuo 1 do grau do vertice que está na posição k, sabendo que recebia uma aresta do vertce atual
                }

            }


            grafo[i] = -1; // retiro o vertice do grafo[]
            grau[i] = -1; // coloco um grau nulo para as proximas iterações
        }



    }}
    cout<<"lista em ordenacao topologica: [ ";
        for(int i =0; i<n; i++)
        {
            cout << lista[i] << " ";
        }
        cout << "]"<<endl;

}





