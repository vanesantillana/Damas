#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

template<class Tab>

struct Node
{
    Tab tablero;
    vector<Node<Tab> *> childs;
    vector<int *> A,B;  //posiciones del tablero con fchas del oponente B y mias A
    int peso;

    Node(Tab t){
        tablero=t;
    }
    int calcularPeso(){
        return A.size()-B.size();
    }
    void insertChild(Node<Tab> *temp){
        childs.push_back(temp);
    }
};


#endif // NODE_H
