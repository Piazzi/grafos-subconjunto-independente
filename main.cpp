#include <iostream>
#include <stdlib.h>
#include "No.h"
#include "No.cpp"
#include "Aresta.h"
#include "Grafo.h"
#include "Grafo.cpp"

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
    int qntVertices = 0;
    int representacao = 0;

    cout << "-------------------------------------------------------MENU-------------------------------------------------------" << endl;
    cout << "Escolha o tipo de representacao: " << endl;
    cout << "[1] Matriz de Adjacencia" << endl;
    cout << "[2] Lista de Adjacencia" << endl;
    cin >> representacao;
    cout << endl;
    cout << "Digite o numero de vertices: " << endl;
    cin >> qntVertices;

    if(representacao == 1)
    printMatrizAdjacencia(qntVertices);

    return 0;
}
