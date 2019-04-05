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

void printMatrizAdjacencia(int qntVertices)
{
    int matriz[qntVertices][qntVertices];
    for(int i = 0; i< qntVertices; i++)
    {
        if(i == 0)
        {
            cout << "   ";
            for(int i = 0; i < qntVertices; i++)
            cout << "[" << i << "]";
            cout << endl;
        }

        for(int j = 0; j < qntVertices; j++)
        {
            if(j == 0)
                cout << "[" << i << "] ";
            matriz[i][j] = 0;
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int id = 0;
    int opcao = 0;
    vector< No > vertices;
    Grafo *grafo = new Grafo();

    cout << "-------------------------------------------------------MENU-------------------------------------------------------" << endl;
    cout << "Escolha o tipo de representacao: " << endl;
    cout << "[1] Matriz de Adjacencia" << endl;
    cout << "[2] Lista de Adjacencia" << endl;
    cout << "[-1] Para encerrar o programa" << endl;
    cout << endl;

    cout << "Criando seu Grafo " << endl;
    while(id != -1)
    {
        cout << "Adicione um vertice informando seu id: " << endl;
        cin >> id;
        if(id == -1)
            break;
        No *vertice = new No(id);
        grafo->adicionaVertice(vertice);
    }

    cout << "Matriz de adjacência" << endl;
    grafo->printMatrizAdjacencia();
    return 0;
}
