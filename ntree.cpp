#include "ntree.h"

NTree::NTree(int ** r, int p)
{
    root=new Node(r);
    profundidad=p;
    calcularJugadas(root);
}

void NTree::calcularJugadas(Node *p)
{

}
