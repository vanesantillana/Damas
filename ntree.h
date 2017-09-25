#ifndef NTREE_H
#define NTREE_H

#include "node.h"
template<typename Tab>
class NTree
{
public:
    Node<Tab> * root;
    int profundidad;

    //(tablero inicial, profundidad)
    NTree(Tab r, int p){
        root=new Node<Tab>(r);
        profundidad=p;
        calcularJugadas(root);
    }
    void calcularJugadas(Node<Tab> *r){

    }
    Node<Tab>* minMax(Node<Tab> *r)
    {

    }
    //(tablero actual, mis jugadas[true] o del oponente[false])
    vector<Tab> movimientos(Tab r, bool)
    {

    }

};

#endif // NTREE_H
