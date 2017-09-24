#ifndef NTREE_H
#define NTREE_H

#include "node.h"

class NTree
{
public:
    Node * root;
    int profundidad;
    NTree(int**,int);
    void calcularJugadas(Node*);
    Node* minMax(Node*);
};

#endif // NTREE_H
