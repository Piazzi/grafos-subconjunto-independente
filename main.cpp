#include <istream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "No.h"
#include "No.cpp"
#include "Aresta.h"
#include "Grafo.h"
#include "Grafo.cpp"
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
    cin >> opcao;
    return opcao;
}

int main()
{
    int id = 0;
    int opcao = 0;
    vector< No > vertices;
    Grafo *grafo = new Grafo();

    if(lerOuConstruirMenu() == 2)
    {
        cout << "Criando seu Grafo " << endl;
        while(id != -1)
        {
            if(noMenu()== 1)
            {
                cout << "Adicione um vertice informando seu id ou aperte [-1] para terminar o grafo" << endl;
                cin >> id;
                if(id == -1)
                    break;
                No *vertice = new No(id);
                grafo->adicionaVertice(vertice);
            }
            else if(noMenu() == 2)
            {
                cout << "Digite o id do no que voce quer acessar: " << endl;
                cin >> id;
                while(!grafo->verificaId(id))
                {
                    cout << "Id invalido, esse no nao foi encontrado no grafo, digite outro id: " << endl;
                    cin >> id;
                }
            }
            else
                cout << "Digite uma opcao valida" << endl;
        }
        if(tipoDeRepresentacaoMenu() == 1)
        {
           cout << "Matriz de adjacencia" << endl;
            grafo->printMatrizAdjacencia();
        }
        else
        {

        }
    }

    return 0;
}
