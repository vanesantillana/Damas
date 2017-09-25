#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

template<class Tab>

struct Node
{
    Tab tablero;
    vector<Node<Tab> *> childs;
    vector<int *> A,B;  //posiciones del tablero con fichas del oponente B y mias A
    int peso;

    Node(Tab t){
        tablero=t;
        peso=0;
    }
    int calcularPeso(){
        peso=A.size()-B.size();
        return peso;
    }
    void insertChild(Node<Tab> *temp){
        childs.push_back(temp);
    }
    void insertChilds(vector<Tab> jugadas){
        for (int i = 0; i < jugadas.size(); i++) {
            Node<Tab>* temp=new Node<Tab>(jugadas[i]);
            childs.push_back(temp);
        }
    }
};


#endif // NODE_H
