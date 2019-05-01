#include <istream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "No.h"
#include "Aresta.h"
#include "Grafo.h"
#include <vector>
#include <fstream>
#include <cstdio>


using namespace std;

int lerOuConstruirMenu()
{
    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Voce deseja ler um arquivo de grafos ou montar seu proprio grafo?" << endl;
    cout << "[1] Ler" << endl;
    cout << "[2] Construir" << endl;
    cin >> opcao;
    return opcao;
}

int tipoDeRepresentacaoMenu()
{
    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Escolha o tipo de representacao: " << endl;
    cout << "[1] Matriz de Adjacencia" << endl;
    cout << "[2] Lista de Adjacencia" << endl;
    cout << "[-1] Para encerrar o programa" << endl;
    cout << endl;
    cin >> opcao;
    return opcao;
}

int noMenu()
{
    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Selecione uma opcao: " << endl;
    cout << "[1] Adicionar No" << endl;
    cout << "[2] Adicionar vizinhos a um No" << endl;
    cout << "[3] Adicionar arestas a um no" << endl;
    cout << "[4] Lista de vertices do grafo" << endl;
    cout << "[5] Representar o grafo" << endl;
    cout << "[6] Lista de adjacentes a um no" << endl;
    cout << "[7] Remover uma aresta" << endl;
    cout << "[8] Remover um vertice" << endl;
    cout << "[9] Criar grafo complementar e representa-lo por Lista de Adjacencia" << endl;
    cout << "[10] Criar grafo complementar e representa-lo por Matriz de Adjacencia" << endl;
    cout << "[11] Busca em profundidade" << endl;


    cin >> opcao;
    return opcao;
}
int tipodeGrafo()
{

    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Selecione uma opcao: " << endl;
    cout << "[1] Grafo ponderado" << endl;
    cout << "[2] Grafo direcionado" << endl;
    cout << "[-1] Para encerrar o programa" << endl;
    cin >> opcao;
    return opcao;
}

Grafo* criaGrafoComplementar(Grafo* grafo)
{
    bool direcionado = false; /// grafo->ehDirecionado();
    Grafo* grafoComplementar = new Grafo();
    for(int i = 0; i < grafo->listaNo.size(); i++)
    {
        No* noOriginal = grafo->listaNo[i];
        No* noComplementar = noOriginal;
        for(int j = 0; j < grafo->listaNo.size() && i!=j; j++)
        {
            if(noOriginal->verificaAdjacencia(grafo->listaNo[j]))
            {
                noComplementar->removeAdjacente(grafo->listaNo[j]);
                grafo->listaNo[j]->removeAdjacente(noComplementar);

            }
            else
            {
                noComplementar->adicionaNoAdjacente(grafo->listaNo[j], direcionado);
            }
        }
        grafoComplementar->adicionaVertice(noComplementar);
    }

    return grafoComplementar;
}

int main()
{
    int id = 0;
    int idAdj = 0;
    int opcao = 0;
    bool direcionado;
    bool ponderado;
    vector< No > vertices;
    Grafo *grafo = new Grafo();

    if(lerOuConstruirMenu() == 2)
    {
        int opcaorepresenta = tipodeGrafo();
        if(opcaorepresenta == 1 )
        {
            cout<< "Digite [1] para grafo podenrado ou [0] para grafo nao podenrado" << endl ;
            cin >> ponderado;
        }
        if(opcaorepresenta == 2 )
        {
            cout<< "Digite [1] para grafo direcionado ou [0] para grafo nao direcionado" << endl;
            cin >>direcionado;
        }
        cout << "Criando seu Grafo " << endl;
        while(id != -1)
        {
            opcao = noMenu();
            if(opcao == 1)
            {
                cout << "Adicione um vertice informando seu id ou aperte [-1] para terminar o grafo" << endl;
                cin >> id;
                if(id == -1)
                    break;
                No *vertice = new No(id);
                grafo->adicionaVertice(vertice);
            }
            else if(opcao == 2)
            {
                cout << "Digite o id do no que voce quer acessar: " << endl;
                cin >> id;
                if(id == -1)
                    break;
                while(!grafo->verificaId(id))
                {
                    cout << "Id invalido, esse no nao foi encontrado no grafo, digite outro id: " << endl;
                    cin >> id;
                    if(id == -1)
                        break;
                }
                cout << "Voce esta no vertice " << grafo->getNo(id)->id << ", digite um vertice adjacente a esse: " << endl;
                cin >> idAdj;
                if(id == idAdj)
                {
                    cout<<"Nao e permitido self-loop"<<endl;
                }
                else
                {
                    grafo->getNo(id)->adicionaNoAdjacente(grafo->getNo(idAdj),direcionado);
                }

            }
            else if(opcao == 3)
            {

            }
            else if(opcao == 4)
            {
                grafo->printNos();
            }
            else if(opcao == 5)
            {
                int opcaorepresenta = tipoDeRepresentacaoMenu();
                if(opcaorepresenta == 1)
                {
                    cout << "Matriz de adjacencia: " << endl;
                    grafo->matrizAdjacencia(direcionado);
                }
                else if(opcaorepresenta == 2)
                {
                    cout<<"Lista de adjacencia: "<<endl;
                    grafo->printListaAdjacencia();
                }
                else if(opcaorepresenta == -1)
                {
                    break;
                }

            }
            else if(opcao == 6)
            {
                grafo->printAdjacentesAoNo();
            }

            else if(opcao == 7)
            {
                grafo->removeAresta();
            }

            else if(opcao == 8)
            {
                grafo->removeVertice();
            }

            else if(opcao == 9)
            {
                criaGrafoComplementar(grafo)->printListaAdjacencia();
            }

            else if(opcao == 10)
            {
                criaGrafoComplementar(grafo)->matrizAdjacencia(direcionado);
            }

            else if(opcao == 11)
            {
                grafo->caminhamentoEmProfundidade(1);
            }

            else
                cout << "Digite uma opcao valida" << endl;
        }
    }

    return 0;
}
