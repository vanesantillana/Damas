#ifndef NTREE_H
#define NTREE_H

#include "node.h"

#define INF 50;
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
    }
    void cargarJugadas(Node<Tab> *r,int n=1){
        bool jugador;
        if(n<=profundidad){
            (n%2==0)? jugador=true:jugador=false;
            vector<Tab> jugadas=movimientos(r->tablero,jugador);
            r->insertChilds(jugadas);
            cout<<"inserte: "<<r->childs.size()<<" nivel: "<<n<<endl;
            for (int i = 0; i < r->childs.size(); i++) {
                cargarJugadas(r->childs[i],n+1);
            }
        }
    }
    Node<Tab>* minMax(){
        int value=minMaxOperation(root);
        for (int i = 0; i < root->childs.size(); i++) {
            if(root->childs[i]->peso==value)
                return root->childs[i];
        }
    }
    int minMaxOperation(Node<Tab> *r,bool minmax=true){
        int beastValue;
        if(r->childs.size()==0){
            beastValue=r->calcularPeso();
        }
        else if(minmax){
            beastValue=-INF;
            for (int i = 0; i < r->childs.size(); i++) {
                int value=minMaxOperation(r->childs[i],false);
                beastValue=max(beastValue,value);
            }
        }
        else{
            beastValue=INF;
            for (int i = 0; i < r->childs.size(); i++) {
                int value=minMaxOperation(r->childs[i],true);
                beastValue=min(beastValue,value);
            }
        }
        return beastValue;
    }
    //(tablero actual, mis jugadas[true] o del oponente[false])


};

#endif // NTREE_H
