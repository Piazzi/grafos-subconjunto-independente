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
    cout << "[12] Busca em largura" << endl;
    cout << "[13] Componentes Conexas" << endl;
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
    int peso = 0;
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
        // Menu do tipo de representação do grafo
        switch(opcaorepresenta)
        {
        case 1:
            cout<< "Digite [1] para grafo ponderado ou [0] para grafo nao ponderado" << endl ;
            cin >> ponderado;
        case 2:
            cout<< "Digite [1] para grafo direcionado ou [0] para grafo nao direcionado" << endl;
            cin >>direcionado;
        }

        // Menu de opções para o grafo
        cout << "Criando seu Grafo " << endl;
        while(id != -1)
        {
            opcao = noMenu();
            switch(opcao)
            {
            case 1:
            {
                cout << "Adicione um vertice informando seu id ou aperte [-1] para terminar o grafo" << endl;
                cin >> id;
                if(id == -1)
                    break;
                if(ponderado)
                {
                    cout << "Adicione o peso do vertice" << endl;
                    cin >> peso;
                    No *vertice = new No(id);
                    grafo->adicionaVerticePonderado(vertice, peso);
                }
                else
                {
                    No *vertice = new No(id);
                    grafo->adicionaVertice(vertice);
                }

            }
            break;
            case 2:
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
                break;
            case 3:
                break;
            case 4:
                grafo->printNos();
                break;
            case 5:
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
            break;
            case 6:
                grafo->printAdjacentesAoNo();
                break;
            case 7:
                grafo->removeAresta();
                break;
            case 8:
                grafo->removeVertice();
                break;
            case 9:
                criaGrafoComplementar(grafo)->printListaAdjacencia();
                break;
            case 10:
                criaGrafoComplementar(grafo)->matrizAdjacencia(direcionado);
                break;
            case 11:
                grafo->caminhamentoEmProfundidade(1);
                break;
            case 12:
                grafo->caminhamentoEmLargura(1);
                break;
            case 13:
                grafo->componentesConexas();
                break;
            default:
                cout << "Digite uma opcao valida" << endl;
                break;
            }
        }
    }

    return 0;
}
