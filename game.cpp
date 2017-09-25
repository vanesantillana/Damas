#include "game.h"

Game::Game(QGraphicsScene *scene,QBrush y,QBrush r,QBrush yo,QBrush maquina,QPen pen,int prof,bool gamer)
{
    profundidad=prof;
    firstGamer=gamer;
    tam=62;
    size=262;
    inicio=200;
    this->scene=scene;
    yellowBrush=y;
    redBrush=r;
    this->yo=yo;
    this->maquina=maquina;
    outlinePen=pen;
}

void Game::start()
{
    vector<vector<int> > tablero(8,vector<int>(8,-1));
    NTree<vector<vector<int> > > tree(tablero,profundidad);
    tree.cargarJugadas(tree.root);
    cout<<tree.minMax()->peso<<endl;
    llenar(tablero);
    print(tablero);

    /*dibuja*/
    Tablero();
    llenarTablero(tablero);
}

void Game::llenar(vector<vector<int> > &v1){
    int val;
    for(int a=0;a<v1.size();a++){
        for(int b=0;b<v1[a].size();b++){
            if(a<3)val=2;
            if(a>=3 and a<5) val=0;
            if(a>4) val=1;
            if(a%2==0){
                if(b%2==1)
                    v1[a][b]=val;

            }
            else

                if(b%2==0)
                    v1[a][b]=val;

        }
    }
}
void Game::print(vector<vector<int> > V){
    for(int a=0;a<V.size();a++){
        for(int b=0; b<V[a].size();b++){
            if(V[a][b]==-1)
                cout<<"-"<<" ";

            else
                cout<<V[a][b]<<" ";
        }
        cout<<endl;
    }
}

void Game::Tablero(){
    QBrush brush=redBrush;
    for (int y = -inicio; y < size; y+=tam) {
        for (int x = -inicio; x < size; x+=tam) {
            (brush==redBrush)?brush=yellowBrush:brush=redBrush;
            scene->addRect(x,y,tam,tam,outlinePen,brush);
        }
        (brush==redBrush)?brush=yellowBrush:brush=redBrush;
    }
}

void Game::llenarTablero(vector<vector<int> > fichas){
    int x,y;
    x=-inicio+2;
    y=-inicio+2;
    int tama=tam-4;
    for (int i = 0; i < fichas.size(); i++) {
        for (int j = 0; j < fichas.size(); j++) {
            if(fichas[i][j]==1)
                scene->addEllipse(x,y,tama,tama,outlinePen,yo);
            else if(fichas[i][j]==3){
                scene->addEllipse(x,y,tama,tama,outlinePen,yo);
                scene->addEllipse(x+10,y+10,tama-20,tama-20,outlinePen,yo);
            }
            else if(fichas[i][j]==2)
                scene->addEllipse(x,y,tama,tama,outlinePen,maquina);
            else if(fichas[i][j]==4){
                scene->addEllipse(x,y,tama,tama,outlinePen,maquina);
                scene->addEllipse(x+10,y+10,tama-20,tama-20,outlinePen,maquina);
            }
            x+=tam;
        }
        x=-inicio+2;
        y+=tam;
    }
}
