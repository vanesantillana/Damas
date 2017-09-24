#ifndef NODE_H
#define NODE_H

#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int tablero[8][8];
    vector<Node *> childs;
    vector<int *> A,B;  //posiciones del tablero con fchas del oponente y mias
    int peso;

    Node(int **);
    int calcularPeso(bool);
    void insertChild(Node *);
};

Node::Node(int ** tablero)
{
    this->tablero=tablero;
}

int Node::calcularPeso(bool nivel)
{
    if(nivel)
        return A.size()-B.size();
    return B.size()-A.size();
}

void Node::insertChild(Node *temp)
{
    childs.push_back(temp);
}
#endif // NODE_H
