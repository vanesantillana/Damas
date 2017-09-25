#ifndef GAME_H
#define GAME_H

#include "ntree.h"
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>

class Game
{
public:
    int profundidad;
    bool firstGamer;
    int puntuacion[4];
    int inicio,tam,size;
    QGraphicsScene *scene;
    QBrush yellowBrush,redBrush,yo,maquina;
    QPen outlinePen;

    Game(QGraphicsScene *,QBrush,QBrush,QBrush,QBrush,QPen,int, bool);
    void start();
    void llenar(vector<vector<int> > &);
    void print(vector<vector<int> >);
    void Tablero();
    void llenarTablero(vector<vector<int> >);
    void jugada(bool);

};

#endif // GAME_H
