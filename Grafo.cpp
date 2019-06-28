#include "Grafo.h"
#include "stdio.h"
#include <vector>
#include <algorithm>
#include <stack> //Biblioteca para pilhas
#include <iomanip>
#include <chrono>
#include <random>
#include <map>
#include <limits>

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
        ///cout << "Esse id ja esta sendo utilizado, digite um id valido" << endl;
    }
    else
    {
        listaNo.push_back(no);
        cout << "****** No adicionado com sucesso *****" << endl;
    }
}

bool Grafo::verificaId(int id)
{

    for(unsigned int i = 0 ; i < listaNo.size() ; i++)
    {
            if(listaNo[i]->id == id)
            {
                return true;
            }
        return false;
    }
    return false;
}

No * Grafo::getNo(int id)
{
    if(verificaId(id))
    {
        for(unsigned int i = 0 ; i < listaNo.size() ; i++)
        {
            if(listaNo[i]->id  == id)
                return listaNo[i];
        }
    }
return NULL;
}

void Grafo::printNos()
{
    cout << "Lista de vertices do grafo: " << endl;
    for(unsigned int i = 0 ; i < listaNo.size() ; i++)
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



Aresta * Grafo::getAresta(int id1, int id2)
{
    for(unsigned int i = 0 ; i < this->arestas.size();i++)
    {
        if((this->arestas[i]->no1->id == id1 ||
                this->arestas[i]->no1->id == id2) &&
                (this->arestas[i]->no2->id == id1 ||
                 this->arestas[i]->no2->id == id2))
            return this->arestas[i];
    }
    return NULL;
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
    for(unsigned int i = 0; i < listaNo.size(); i++)
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

/**
 * Inicia o caminhamento em profundidade, que chama a fun��o auxiliar aprofunda(No* no)
 * @return void
*/
void Grafo::caminhamentoEmProfundidade() ///funcao principal, que chama a funcao que, de fato, faz o caminhamento
{
    setVisitadoEmTodosNos(false);
    for(unsigned int i = 0; i < listaNo.size(); i++)
    {
        if(!listaNo[i]->getVisitado())
        {
            aprofunda(listaNo[i]);
        }
    }
    cout << endl;
}

void Grafo::aprofunda(No* no)
{
    no->setVisitado(true);
    cout << "Visitando no " << no->id << endl;
    for(unsigned int i = 0; i < no->nosAdjacentes.size(); i++)
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

void Grafo::aprofunda_ComponenteConexa(No* no)
{
    no->setVisitado(true);
    cout << no->id << " - ";
    for(unsigned int i = 0; i < no->nosAdjacentes.size(); i++)
    {
        No* adjacenteAtual = no->nosAdjacentes[i];
        if(!adjacenteAtual->getVisitado())
        {
            aprofunda_ComponenteConexa(adjacenteAtual);
        }
    }
}

/**
 * Inicia o caminhamento em largura, que chama a fun��o auxiliar caminhaEmLargura(vector<No*> fila)
 * @param id id do n� a partir do qual o caminhamento come�a
 * @return void
*/
void Grafo::caminhamentoEmLargura(int id)   ///funcao principal, que chama a funcao que, de fato, faz o caminhamento
{
    setVisitadoEmTodosNos(false);

    No *noInicial = getNo(id);
    vector<No*> *fila = new vector<No*>;
    fila->push_back(noInicial);

    caminhaEmLargura(*fila); ///chama funcao auxiliar, que faz o caminhamento em largura
}

/**
 * Fun��o que faz, de fato, o caminhamento
 * @param fila estrutura que vai armazenar os n�s que ser�o visitados
 * @return void
*/
void Grafo::caminhaEmLargura(vector<No*> fila)
{
    while(!fila.empty())
    {
        No *noAtual = fila.front();
        cout << "Visitando o no " << noAtual->id << endl;
        noAtual->setVisitado(true);
        for(unsigned int i = 0 ; i < noAtual->nosAdjacentes.size();i++)
        {
            if(!noAtual->nosAdjacentes[i]->getVisitado())
            {
                int contador = count(fila.begin(), fila.end(), noAtual->nosAdjacentes[i]); /// verifica se adjacenteAoAtual est� na fila
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
    for(unsigned int i = 0  ; i <listaNo.size(); i++)
    {
        listaNo[i]->setVisitado(visitado);
    }
}

void Grafo::componentesConexas()
{
    cout << "Componentes conexas: " << endl;
    setVisitadoEmTodosNos(false);
       for(unsigned int i = 0  ; i <listaNo.size(); i++)
    {
        if(!listaNo[i]->getVisitado())
        {
            cout << endl << "Componente conexa comencando em " << listaNo[i]->id << ": ";
            aprofunda_ComponenteConexa(listaNo[i]);
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
        peso = getNo(conferePeso);
        cout<<"O peso do vertice "<<conferePeso<<" e: "<<peso->getPeso()<<endl;
    }
    else
    {
        cout<<"O Vertice inserido nao existe no grafo"<<endl;
    }
}
void Grafo::imprimePesoAresta()
{
   /* int confereIdADj = 0;
    int confereId = 0 ;
    cout<<"Digite o primeiro vertice"<<endl;
    cin>>confereId;
    cout<<"Digite o segundo vertice"<<endl;
    cin>>confereIdADj;
    if(possuiAresta(confereId, confereIdADj))
    {
        cout<<"O peso da aresta entra os vertices ["<<confereId
            <<"] ["<<confereIdADj<<"] e: "<<auxImprimePesoAresta(confereId)<<endl;
    }
    else
    {
        cout<<"Um dos vertices inseridos no programa nao possui aresta"<<endl;
    }*/
}

/*int Grafo::auxImprimePesoAresta(int id1)
{
No *elemento = getNo(id1);
return elemento->getPesoAresta();
}*/

bool Grafo::possuiAresta(int id1, int id2)
{
    No *elemento = getNo(id1);
    for(unsigned int i = 0; i< elemento->nosAdjacentes.size(); i++)
    {
        if(elemento->nosAdjacentes[i]->id == id2)
        {
            return true;
        }
    }
    return false;

}



void Grafo::ordenacaoTopologica()
{
    int n = listaNo.size(); //vertices
    int m =0; // arestas
    int grafo[n];
    int grau[n];
    int lista[n]; // dos v�rtices de grau zero
    int listaPos = 0; //posi��o de inser��o na lista
    No *atual;
    atual = NULL;

    for(int i = 0; i<n; i++)
    {
        m = m+ listaNo[i]->getGrau();
        grafo[i] = listaNo[i]->id;
        grau[i]=listaNo[i]->getGrau();
        lista[i]=0;
    }

    while(listaPos < n)
    {
        ///--------------------------------quando o grau minimo n�o � 0 -------------------------------------------///
        while(grauMinimo(grau,n)!= 0 && grauMinimo(grau,n)>0)
        {
            for(int i = 0; i< n; i++)
            {
                if(grau[i] == grauMinimo(grau,n))  /// se o grau for o grau minimo
                {
                    lista[listaPos] = grafo[i]; ///coloco o vertice na posi��o listaPos da lista
                    listaPos++; /// atualizo listaPos para a proxima inser��o
                    for(int t = 0; t < n; t++)
                    {
                        if(listaNo[t]->id == grafo[i])
                            atual = listaNo[t]; /// No atual recebe o No com o id
                    }

                    for(unsigned int j = 0; j< atual->nosAdjacentes.size(); j++) /// para todos os adjacentes ao no com grau m�nimo
                    {
                        for( int k =0; k<n; k++)  ///percorro todos os vevrtices do grafo[] procurando alguem com aquele id
                        {
                            if(grafo[k] == atual->nosAdjacentes[j]->id)/// se o vetice tiver aquele id
                                grau[k] = grau[k]- 1;///diminuo 1 do grau do vertice que est� na posi��o k, sabendo que recebia uma aresta do vertce atual
                        }

                    }

                    grafo[i] = -1; // retiro o vertice do grafo[]
                    grau[i] = -1; // coloco um grau nulo para as proximas itera��es
                }
            }
        }


        ///--------------------------------quando o grau minimo � 0 -------------------------------------------///
        for(int i = 0; i< n; i++)
        {
            if(grau[i] == 0)  /// se o grau for 0
            {
                lista[listaPos] = grafo[i]; ///coloco o vertice na posi��o listaPos da lista
                listaPos++; /// atualizo listaPos para a proxima inser��o
                for(int t = 0; t < n; t++)
                {
                    if(listaNo[t]->id == grafo[i])
                        atual = listaNo[t]; /// No atual recebe o No com o id
                }

                for(unsigned int j = 0; j< atual->nosAdjacentes.size(); j++) /// para todos os adjacentes ao no com grau 0
                {
                    for(int k =0; k<n; k++)  ///percorro todos os vevrtices do grafo[] procurando alguem com aquele id
                    {
                        if(grafo[k] == atual->nosAdjacentes[j]->id)/// se o vetice tiver aquele id
                            grau[k] = grau[k]- 1;///diminuo 1 do grau do vertice que est� na posi��o k, sabendo que recebia uma aresta do vertce atual
                    }

                }


                grafo[i] = -1; // retiro o vertice do grafo[]
                grau[i] = -1; // coloco um grau nulo para as proximas itera��es
            }
        }
    }
    cout << "lista em ordenacao topologica: [ ";
    for(int i =0; i<n; i++)
    {
        cout << lista[i] << " ";
    }
    cout << "]"<<endl;

}


int Grafo::grauMinimo(int graus[], int n)
{
    int grauMin =numeric_limits<int>::max();

    for (int i =0; i<n ; i++)
    {
        if(graus[i]<grauMin)
            grauMin = graus[i];
    }

    return grauMin;
}

void Grafo::printSequenciaDeGraus()
{
    vector<int> graus;
    for(unsigned int i = 0 ; i < listaNo.size() ; i++)///preenche o vector graus com o grau de cada no
    {
        graus.push_back(listaNo[i]->getGrau());
    }

    sort(graus.begin(), graus.end(), greater<int>()); ///ordena o vector graus

    cout << "Sequencia de graus: " << endl;

    cout << "<";
    for(unsigned int j = 0 ; j < graus.size() ; j++)
    {
        cout << graus[j] << ", ";
    }
    cout << ">" << endl;
}


/**
 * Fun��o principal do algoritmo guloso, que busca os v�rtices de menores graus, para minimizar a redu��o da lista de v�rtices candidatos a cada itera��o
 @return void
*/
void Grafo::algoritmoGuloso()
{
    vector<No*> *solucaoGulosa = new vector<No*>; ///vector que vai armazenar os nos da solucao
    vector<No*> nosCandidatos = listaNo; ///A lista de candidatos inicialmente corresponde a todos os vertices do grafo
    vector<int> idsDosNosSolucao;

    while(!nosCandidatos.empty())
    {
        No* candidatoAtual = getNoDeMenorGrau(nosCandidatos);   ///O melhor candidato � o n� de menor grau
        solucaoGulosa->push_back(candidatoAtual);
        nosCandidatos = atualizaNosCandidatos(candidatoAtual, nosCandidatos); ///precisamos atualizar a lista dos n�s candidatos a cada itera��o
        idsDosNosSolucao.push_back(candidatoAtual->id);
    }

    printSolucaoGulosa(idsDosNosSolucao);   ///fun��o auxiliar para imprimir os ids dos n�s da solu��o
}

/**
 * Remove da lista de candidatos aqueles que s�o adjacentes ao �ltimo selecionado
 * @param candidatoSelecionado ultimo candidato adicionado � solu��o
 * @param nosCandidatos vetor de candidatos, que ser� atualizado pela fun��o
 * @return nosCandidatos
*/
vector<No*> Grafo::atualizaNosCandidatos(No* candidatoSelecionado, vector<No*> nosCandidatos)
{
    for(unsigned int a = 0; a < nosCandidatos.size(); a++)   ///tira o ultimo candidato selecionado da lista de candidatos
    {
        if(nosCandidatos[a]->id == candidatoSelecionado->id)
            nosCandidatos.erase(nosCandidatos.begin() + a);
    }

    vector<No*> adjacentesAoSelecionado = candidatoSelecionado->nosAdjacentes;
    for(unsigned int i = 0; i < nosCandidatos.size(); i++) /// o conjunto deve ser independente: nao pode conter elementos adjacentes!
    {
        for(unsigned int j = 0; j < adjacentesAoSelecionado.size(); j++)
        {
            if(nosCandidatos[i]->id == adjacentesAoSelecionado[j]->id)
            {
                nosCandidatos.erase(nosCandidatos.begin() + i);
            }
        }
    }
    return nosCandidatos;
}

/**
 * Retorna o v�rtice de menor grau dentre aqueles que est�o na lista de candidatos
 * @param nosCandidatos
 * @return noMenorGrau
*/
No* Grafo::getNoDeMenorGrau(vector<No*> nosCandidatos)
{
    No* noMenorGrau = nosCandidatos[0];
    for(unsigned int i = 0 ; i < nosCandidatos.size();i++)
    {
        if(nosCandidatos[i]->getGrau() < noMenorGrau->getGrau())
            noMenorGrau = nosCandidatos[i];
    }
    return noMenorGrau;
}

/**
 * Imprime a solu��o encontrada pelo algoritmo guloso
 * @param solucao vetor contendo os id's dos n�s da solu��o
 * @return void
*/
void Grafo::printSolucaoGulosa(vector<int> solucao)
{
    cout << "Solucao atraves do Algoritmo Guloso: ";

    cout << "[ ";
    for(unsigned int i = 0 ; i < solucao.size() ; i++)
    {
        cout << solucao[i] << ", ";
    }
    cout << "]" << endl;
    cout << "Cardinalidade da solucao gulosa: " << solucao.size() << endl;

}

/**
 * Inicia o Algoritmo Guloso Randomizado, e recebe como input do usu�rio, via linha de comando, o par�metro alfa o n�mero m�ximo de itera��es
 * @return void
*/
void Grafo::iniciaAlgoritmoGulosoRandomizado()
{
    float alfa;
    int maximoIteracoes;
    cout << "Digite o parametro alfa (entre 0 e 1): ";
    cin >> alfa;
    cout << "Digite o numero maximo de iteracoes: ";
    cin >> maximoIteracoes;
    cout << endl;

    vector<int> idsDosNosDaMelhorSolucao = algoritmoGulosoRandomizado(alfa, maximoIteracoes);

    printSolucaoGulosaRandomizada(idsDosNosDaMelhorSolucao);
}

/**
 * Fun��o respons�vel por criar as estruturas e v�riaveis necess�rias para o Guloso Randomizado
 * @param alfa
 * @param maximoIteracoes
 * @return idsDosNosDaMelhorSolucao
*/
vector<int> Grafo::algoritmoGulosoRandomizado(float alfa, int maximoIteracoes)
{
    auto start = std::chrono::high_resolution_clock::now(); ///Grava o tempo em que o algoritmo come�ou
    cout<<start<<endl;
    vector<int> idsDosNosDaMelhorSolucao = getSolucaoRandomizada(alfa); ///obtem uma solu��o inicial aleatoria, de acordo com o par�metro alfa
    int maiorCardinalidade = idsDosNosDaMelhorSolucao.size();

    for(int i = 0; i < maximoIteracoes; i++)
    {
        cout << "Iteracao " << i << endl;
        vector<int> idsDosNosDaSolucaoAtual = getSolucaoRandomizada(alfa);
        int cardinalidadeAtual = idsDosNosDaSolucaoAtual.size();

        if(cardinalidadeAtual > maiorCardinalidade) /// se a cardinalidade da solu��o atual for maior do que a maior encontrada at� agora, passa ser a atual maior
        {
            idsDosNosDaMelhorSolucao = idsDosNosDaSolucaoAtual;
            maiorCardinalidade = cardinalidadeAtual;
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();    ///Grava o tempo em que o algoritmo terminou
    auto elapsed = finish - start;  ///Obtem o tempo total, em nanosegundos (10^-9)
    float tempo = elapsed.count()/1000000000;
    cout << "Tempo levado para obter a solucao gulosa randomizada: " << tempo << "s" << endl;

    return idsDosNosDaMelhorSolucao;
}

/**
 * Overload da fun��o do Randomizado para ser chamada pelo reativo -- a diferen�a est� no fato de que esta recebe e altera a vari�vel mediaDasSolucoes, usada pelo reativo
 * @param alfa
 * @param maximoIteracoes
 * @param mediaDasSolucoes vari�vel passada pela fun��o do Reatiovo, e que ser� alterada no final dessa fun��o
 * @return idsDosNosDaMelhorSolucao
*/
vector<int> Grafo::algoritmoGulosoRandomizado(float alfa, int maximoIteracoes, float *mediaDasSolucoes)
{

    vector<int> idsDosNosDaMelhorSolucao = getSolucaoRandomizada(alfa);
    float maiorCardinalidade = idsDosNosDaMelhorSolucao.size();
    float somaSolucoes = maiorCardinalidade;
    for(int i = 0; i < maximoIteracoes; i++)
    {
        vector<int> idsDosNosDaSolucaoAtual = getSolucaoRandomizada(alfa);
        int cardinalidadeAtual = idsDosNosDaSolucaoAtual.size();
        somaSolucoes += cardinalidadeAtual;

        if(cardinalidadeAtual > maiorCardinalidade)
        {
            idsDosNosDaMelhorSolucao = idsDosNosDaSolucaoAtual;
            maiorCardinalidade = cardinalidadeAtual;
        }
    }
    *mediaDasSolucoes = (somaSolucoes/(maximoIteracoes+1));
    return idsDosNosDaMelhorSolucao;
}

/**
 * Fun��o que obtem, de fato, uma solu��o randomizada, que ser� retornada a fun��o "algoritmoGulosoRandomizado"
 * @param alfa
 * @return idsDosNosSolucao
*/
vector<int> Grafo::getSolucaoRandomizada(float alfa)
{
    vector<No*> *solucaoGulosaRandomizada = new vector<No*>;
    vector<No*> nosCandidatos = listaNo;
    vector<int> idsDosNosSolucao;

    while(!nosCandidatos.empty())
    {
        int timer = 0;
        vector<No*> candidatosOrdenadosPeloGrau = getVetorMenorGrau(nosCandidatos);
        vector<No*> melhoresCandidatos = getPorcentagem(candidatosOrdenadosPeloGrau, alfa);
        int tamanhoDosMelhoresCandidatos = melhoresCandidatos.size();

        int indiceAleatorio = gerarNumeroAleatorio(0, tamanhoDosMelhoresCandidatos-1, timer);
        No* candidatoAtual = melhoresCandidatos.at(indiceAleatorio);

        solucaoGulosaRandomizada->push_back(candidatoAtual);
        nosCandidatos = atualizaNosCandidatos(candidatoAtual, nosCandidatos);
        idsDosNosSolucao.push_back(candidatoAtual->id);

        timer++;
    }

    return idsDosNosSolucao;
}

/**
 * Retorna um n�mero aleat�rio entre os limites passados como par�metro
 * @param limite_inf
 * @param limite_sup
 * @param timer semente para gerar n�mero aleat�rio
 * @return n�mero inteiro aleat�rio
*/
int Grafo::gerarNumeroAleatorio(int limite_inf, int limite_sup, int timer)
{
    if(limite_inf == limite_sup && limite_sup == 0)
        return 0;

    srand(time(NULL)+timer);
    return (limite_inf + (rand() % limite_sup));
}

/**
 * Imprime a solu��o do Guloso Randomizado
 * @param solucao vetor contendo os id's dos n�s da solu��o
 * @return void
*/
void Grafo::printSolucaoGulosaRandomizada(vector<int> solucao)
{
    cout << "Solucao atraves do Algoritmo Guloso Randomizado: ";

    cout << "[ ";
    for(unsigned int i = 0 ; i < solucao.size() ; i++)
    {
        cout << solucao[i] << ", ";
    }
    cout << "]" << endl;

    cout << "Cardinalidade da solucao gulosa randomizada: " << solucao.size() << endl;
}

/**
 * Obtem um vetor com os n�s ordenados de acordo com o grau, do menor para o maior
 * @param nosCandidatos vetor contendo os id's dos n�s candidatos
 * @return vetorOrdenadoPeloGrau
*/
vector<No*> Grafo::getVetorMenorGrau(vector<No*> nosCandidatos)
{
    vector<No*> vetorOrdenadoPeloGrau = nosCandidatos;
    No* aux;
    unsigned int i, j;

    for(i = 1; i < vetorOrdenadoPeloGrau.size(); i++)
    {
        j = i;

        while((j != 0) && (vetorOrdenadoPeloGrau[j]->getGrau() < vetorOrdenadoPeloGrau[j - 1]->getGrau()))
        {
            aux = vetorOrdenadoPeloGrau[j];
            vetorOrdenadoPeloGrau[j] = vetorOrdenadoPeloGrau[j - 1];
            vetorOrdenadoPeloGrau[j - 1] = aux;
            j--;
        }
    }
    return vetorOrdenadoPeloGrau;
}

/**
 * Obtem uma por��o dos n�s candidatos ordenados pelo grau, de acordo com o par�metro alfa
 * Alfa == 0: retorna apenas o melhor candidato (equivale � fun��o gulosa padr�o)
 * Alfa == 1: retorna todos os elementos (equivale a uma busca completamente aleat�ria)
 * @param candidatosOrdenadosPeloGrau
 * @param alfa
 * @return vetorOrdenadoPeloGrau
*/
vector<No*> Grafo::getPorcentagem(vector<No*> candidatosOrdenadosPeloGrau, float alfa)
{
    int tamanhoCandidatos = candidatosOrdenadosPeloGrau.size();
    vector<No*> listaDosPrimeiros;

    int indice = static_cast<int> (tamanhoCandidatos *alfa);

    if(alfa == 1)
    {
        indice = tamanhoCandidatos-1;
    }

    for(int i = 0; i <= indice; i++)
    {
        listaDosPrimeiros.push_back(candidatosOrdenadosPeloGrau[i]);
    }

    return listaDosPrimeiros;
}

/**
 * Inicializa o Randomizado Reativo, e recebe como input do usu�rio o numero m�ximo de itera��es pro reativo e para os randomizados que ser�o chamados, al�m do n�mero de alfas
 * Possui como bloco padr�o 100 itera��es
 * @return void
*/
void Grafo::algoritmoGulosoRandomizadoReativo()
{
    auto start = std::chrono::high_resolution_clock::now();

    int atualMaiorCardinalidade;
    vector<int> solucaoReativa;
    float pmediaSolucoes;
    float *mediaSolucoes = &pmediaSolucoes;
    *mediaSolucoes = 0;

    int maximoIteracoesReativo;
    cout << "Digite o numero maximo de iteracoes do reativo: ";
    cin >> maximoIteracoesReativo;

    int maximoIteracoesRandomizado;
    cout << "Digite o numero maximo de iteracoes do randomizado: ";
    cin >> maximoIteracoesRandomizado;

    int numeroDeAlfas;
    cout << "Digite o numero de alfas: ";
    cin >> numeroDeAlfas;

    cout << "numeroDeAlfas: " << numeroDeAlfas << endl;

    Alfa alfas[numeroDeAlfas];   ///Declara��o do array de Alfas
    preencheAlfas(alfas, numeroDeAlfas, maximoIteracoesRandomizado); ///Preenche o array com alfas com iguais probabilidades de serem escolhidos

    vector<int> solucaoInicial = alfas[0].idsMelhorSolucao;
    atualMaiorCardinalidade = alfas[0].melhorSolucao;

    for(int n = 1; n < numeroDeAlfas; n++)    /// Determina qual dos alfas possui a melhor solu��o e atualiza o vetor solucaoInicial e a vari�vel atualMaiorCardinalidade
    {
        if(alfas[n].melhorSolucao > atualMaiorCardinalidade)
        {
            solucaoInicial = alfas[n].idsMelhorSolucao;
            atualMaiorCardinalidade = alfas[n].melhorSolucao;
        }
    }

    for(int i = 0; i < maximoIteracoesReativo; i++)
    {
        cout << endl << "**Iteracao do reativo** " << i << endl;

        Alfa alfa = getAlfaAleatorio(alfas, numeroDeAlfas);
        vector<int> idsDaSolucaoRandomizada = algoritmoGulosoRandomizado(alfa.valorAlfa, maximoIteracoesRandomizado, mediaSolucoes);
        int cardinalidadeDaSolucaoAtual = idsDaSolucaoRandomizada.size();

        if(cardinalidadeDaSolucaoAtual > atualMaiorCardinalidade)   /// verifica se obtivemos uma solu��o melhor do que as j� encontradas
        {
            atualMaiorCardinalidade = cardinalidadeDaSolucaoAtual;
            solucaoReativa = idsDaSolucaoRandomizada;
            cout << "Maior cardinalidade atualizada: " << atualMaiorCardinalidade << endl;
        }

        alfa.melhorSolucao = cardinalidadeDaSolucaoAtual;
        alfa.mediaSolucoes = *mediaSolucoes;
        alfa.numeroDeVezesEscolhidoTotal += 1;
        alfas[alfa.indice] = alfa;  /// atualiza as propriedades do alfa usado

        if(i%100 == 0 && i > 0)  ///BLOCO
        {
            cout << "Iteracao " << i << endl;

            for(int i = 0; i < numeroDeAlfas; i++)
            {
                cout << "Alfa " << i << ": ";
                cout << "Probabilidade de ser escolhido ate agora era: " << alfas[i].probabilidadeDeSerEscolhido << ". ";
                cout << "Foi escolhido " << alfas[i].numeroDeVezesEscolhidoTotal << " vezes." << endl;
            }

            atualizaProbabilidadeDosAlfas(alfas, numeroDeAlfas, atualMaiorCardinalidade);
        }
    }
    cout << endl << "-------RESULTADO DO REATIVO-------" << endl;
    cout << "Maior cardinalidade encontrada: " << atualMaiorCardinalidade << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    auto elapsed = finish - start;
    float tempo = elapsed.count()/1000000000;
    cout << "Tempo levado para obter a solucao gulosa randomizada reativa: " << tempo << "s" << endl;
}

/**
 * Sorteia e retorna um Alfa de acordo com probabilidades diferentes
 * @param alfas array com os alfas
 * @param numeroDeAlfas
 * @return Alfa
*/
Grafo::Alfa Grafo::getAlfaAleatorio(Alfa *alfas, int numeroDeAlfas)
{
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); /// semente para a gera��o de um �ndice
    default_random_engine generator(seed);

    vector<int> probabilidades; /// Vetor que ir� armazenar a probabilidade de cada Alfa
    for(int i=0; i<numeroDeAlfas; i++)
    {
        probabilidades.insert(probabilidades.begin()+i, alfas[i].probabilidadeDeSerEscolhido);  /// Atrav�s deste vetor iremos sortear o �ndice de um dos alfas
    }
    discrete_distribution<> distribution(probabilidades.begin(), probabilidades.end()); /// Distribui��o discreta utilizada para fazer o sorteio com diferentes probabilidades
    int indiceAleatorio = distribution(generator);  /// Gera o �ndice aleat�rio
    Alfa alfaAleatorio = alfas[indiceAleatorio];

    return alfaAleatorio;
}

/**
 * Preenche as struct alfa no in�cio do Guoso Randomizado Reativo, com probabilidades iguais
 * @param alfas array com os alfas
 * @param numeroDeAlfas
 * @param maximoIteracoesRandomizado
 * @return void
*/
void Grafo::preencheAlfas(Alfa *alfas, int numeroDeAlfas, int maximoIteracoesRandomizado)
{

    float probabilidadeInicial = 100/numeroDeAlfas;
    cout << "Probabilidade inicial: " << probabilidadeInicial << endl;
    float valorInicial = 0.0;
    float mediaDasSolucoes;
    for(int i=0; i< numeroDeAlfas; i++)
    {
        Alfa alfa;
        alfa.probabilidadeDeSerEscolhido = probabilidadeInicial;
        alfa.valorAlfa = valorInicial;

        vector<int> solucaoAlfa = algoritmoGulosoRandomizado(alfa.valorAlfa, maximoIteracoesRandomizado, &mediaDasSolucoes);
        alfa.idsMelhorSolucao = solucaoAlfa;
        alfa.mediaSolucoes = mediaDasSolucoes;
        alfa.melhorSolucao = solucaoAlfa.size();

        alfa.Qi = 0.0;
        alfa.numeroDeVezesEscolhidoTotal = 0;
        alfa.indice = i;

        alfas[i] = alfa; /// atualiza o array de alfas
        valorInicial += (1.0 - valorInicial)/numeroDeAlfas; /// incrementa o valor que ser� atribu�do a cada alfa, de acordo com o n�mero de alfas passado pelo usu�rio
    }
}

/**
 * Calcula o valor Qi, utilizado para atualizar as probabilidades de cada alfa
 * @param melhorSolucaoGeral cardinalidade da melhor solu��o geral
 * @param mediaSolucoes media das solu��es para o alfa espec�fico
 * @return Qi
*/
float Grafo::calculaQi(int melhorSolucaoGeral, float mediaSolucoes)
{
    int f = melhorSolucaoGeral;
    float Ai = mediaSolucoes;
    float Qi = pow(f/Ai, 10);   /// Par�metro de amplifica��o == 10 (padr�o)

    return Qi;
}

/**
 * Atualiza a probabilidade de cada alfa ser escolhido
 * @param alfas
 * @param numeroDeAlfas
 * @param melhorSolucaoGeral
 * @return Qi
*/
void Grafo::atualizaProbabilidadeDosAlfas(Alfa *alfas, int numeroDeAlfas, int melhorSolucaoGeral)
{
    float SomaQi = 0.0;
    for(int j = 0; j < numeroDeAlfas; j++)  ///Primeiro, calculamos o Qi de cada Alfa
    {
        alfas[j].Qi = calculaQi(melhorSolucaoGeral, alfas[j].mediaSolucoes);

        SomaQi += alfas[j].Qi;
    }
    cout << "SomaQi: " << SomaQi << endl;

    for(int j = 0; j < numeroDeAlfas; j++)  /// Agora calculamos a possibilidade de cada Alfa
    {
        float P = alfas[j].Qi/SomaQi*100;
        alfas[j].probabilidadeDeSerEscolhido = P;
        cout << "DEPOIS DE ATUALIZAR:Probabilidade do alfa "<< j << ": " << alfas[j].probabilidadeDeSerEscolhido << endl;
    }
}


void Grafo::preenche(No  *v, stack<No*>& pilha)
{
    v->setVisitado(true);
    for(unsigned int i=0; i < v->nosAdjacentes.size(); i++)
    {
        No* adjacenteAtual = v->nosAdjacentes[i];
        if(!adjacenteAtual->getVisitado())
        {
            /// cout << "\tNo " << adjacenteAtual->id << " nao foi visitado ainda!" << endl; *BUSCANORMAL*
            preenche(adjacenteAtual, pilha);
        }

    }
    pilha.push(v);

}

void Grafo::DFS(No *v)
{
    v->setVisitado(true);
    cout << "" << v->id << endl;

    for(unsigned int i=0; i<v->nosAdjacentes.size(); i++)
    {
        No* adjacenteAtual = v->nosAdjacentes[i];
        if(!adjacenteAtual->getVisitado())
        {
            /// cout << "\tNo " << adjacenteAtual->id << " nao foi visitado ainda!" << endl; *BUSCANORMAL*
            DFS(adjacenteAtual);

        }

    }
}

Grafo* Grafo::obterGrafoTransposto()
{
    Grafo *transposto = new Grafo();

    for(unsigned int i =0; i < listaNo.size(); i++)
    {
        transposto->adicionaVertice(new No(i));
    }

    for(unsigned  int i =0; i < listaNo.size(); i++)
    {
        for(unsigned int j =0; j < listaNo.size(); j++)
        {
            if(this->getNo(i)->verificaAdjacencia(this->getNo(j)))
            {
                transposto->getNo(j)->adicionaNoAdjacente(transposto->getNo(i), true, 0);
            }
        }
    }

    return transposto;
}

void Grafo::imprimirComponentesFortementeConexas()
{
    stack<No*> pilha;

    setVisitadoEmTodosNos(false);

    for(unsigned  int i=0; i < listaNo.size(); i++)
    {
        if(!listaNo[i]->getVisitado())

        {
            preenche(listaNo[i], pilha);

        }
    }

    // cria o grafo transposto
    Grafo *t = new Grafo();
    t = obterGrafoTransposto();

    // marca todos como n�o visitados novamente
    setVisitadoEmTodosNos(false);

    // processa os v�rtices de acordo com a pilha
    while(!pilha.empty())
    {

        // obt�m o elemento do topo
        No *v = pilha.top();

        //remove o elemento
        pilha.pop();

        // imprime cada componente fortemente conexa
        if(v->getVisitado() == false)
        {
            cout <<"Componente conexa: " << endl;
            t->DFS(v);
            cout << "\n";
        }

    }
}
void Grafo::matrizDistancia()
{
    int n = listaNo.size(); ///numero devertices
    int id1, id2;
    id1=id2=0;
    Aresta* aresta;
    int pesoAresta=0;

    /// ------------------------Entendendo o código abaixo -----------------------------------------------------------------
    /// caso seja adjacente, pega a distancia (peso) da aresta entre 2 nohs, caso nao seja, seta 9999999999
    /// com grafos orientados, quando um nó a, é direcionado ao b, se tentarmos pegar a adjacencia de b para a, seria como se
    /// fossem não adjacentes, sendo assim, a distancia será setada como 9999999999
    /// caminho de um noh ao mesmo noh recebem 0
    /// --------------------------------------------------------------------------------------------------------------------
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                mDistancia[i][j]=0;
            }
            else if(listaNo[i]->verificaAdjacencia(listaNo[j]) && i!=j) /// no caso, ainda precisamos implementar uma funcao que
            {
                /// verifica se existe um caminho entre 2 nohs, e nao apenas
                id1=listaNo[i]->id;                               /// se os 2 sao adjacentes... sendo assim, este metodo
                id2=listaNo[j]->id;                               /// matrizDistancia, ainda nao funciona como deveria
                aresta = getAresta(id1, id2);
                pesoAresta= aresta->peso;
                mDistancia[i][j]=pesoAresta;
            }
            else
            {
                mDistancia[i][j] = numeric_limits<int>::max();
            }
        }
    }
}

/// Encontra o menor caminho entre todos os pares usando o algorítmo de Floyd Warshall
void Grafo:: floyd()
{
    int V = listaNo.size();

    ///primeiro chamamos a função matrizDistancia para popular a matriz mDistancia
    matrizDistancia();

    ///matriz que conterá as menores distâncias entre todos os pares de vértices
    int dist[V][V], i, j, k;

    ///inicializando os valores de dist com os mesmos valores de mDistancia
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = mDistancia[i][j];

    /*Adiciona todos os vértices, um por um, no set de vertices intermediarios

    --->antes de começar a iteração, nos temos menores distancias entre todos os pares de
    vértices de forma que as menores distancias consederam apenas os vértices no set {0, 1, 2, .. k-1} como
     vértices intermediarios

     ---> Após o fim de uma iteração, o vertice k eh adicionado ao set de vertices intemediario e o set
     se torna {0, 1, 2, .. k} */


    for (k = 0; k < V; k++)
    {
        /// pega todos os vertices como fonte, um a um
        for (i = 0; i < V; i++)
        {
            /// pega todos os vertices como destinacao para a fonte selecionada
            for (j = 0; j < V; j++)
            {
                /// se o indice k eh o caminho mais curto de i a j, entao atualizamos o valor de dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    ///imprimie a solucao de Floyd
    cout<<"A seguinte matriz apresenta as menores distancias entre cada par de vertices" << endl;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == 99999)
                cout<<"inf"<<"   ";
            else
                cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }
}

/// Verifica se um grafo eh conexo ou nao
bool Grafo::ehConexo()
{
    for(auto no : this->listaNo)
    {
        if(no->arestas.empty())
            return false;
        else
            return true;
    }
    return true;

}





