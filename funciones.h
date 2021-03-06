#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <bits/stdc++.h>
using namespace std;
template <class T>
void llenar(T &v1){
    int val;
    for(int a=0;a<v1.size();a++){
        for(int b=0;b<v1[a].size();b++){
            if(a<3)val=4;
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

bool checkCoord(int a,int b){
    if(a>=0 and a<8 and b>=0 and b<8)
        return true;
    return false;
}

template <class T>
vector<T> moviPeon(T V,int xT,int yT,bool mio) {
    int  peon, reyna, peonEnemigo, reynaEnemigo, iniPeon, finPeon;
    vector<T> respPeon;
    vector<T>peonCome;
    cout<<"Entro a la funci"<<endl;
    int A[4][2] = {{1,  1},{1,  -1},{-1, 1},{-1, -1}};
    if (mio) {
        peon = 1;
        reyna = 3;
        peonEnemigo = 2;
        reynaEnemigo = 4;
        iniPeon = 2;
        finPeon = 4;
    } else {
        peon = 2;
        reyna = 4;
        peonEnemigo = 1;
        reynaEnemigo = 3;
        iniPeon = 0;
        finPeon = 2;
    }
    int cont=0;
    for (int x = iniPeon; x < finPeon; x++) {
        int posX = xT + A[x][0], posY = yT + A[x][1];
        if (checkCoord(posX, posY)){
            //cout<<"a: "<<a<<" b: "<<b<<endl;
            if (V[posX][posY] == peonEnemigo or V[posX][posY] == reynaEnemigo) {
                cout<<"enemigooo"<<endl;
                int posXT = posX + A[x][0], posYT = posY + A[x][1];
                if(checkCoord(posXT,posYT) and V[posXT][posYT] == 0) {
                    cout<<"Espacio para atacar enemigo"<<endl;
                    T tempV=V;
                    tempV[xT][yT]=0;
                    tempV[posX][posY]=0;
                    tempV[posXT][posYT]=peon;
                    vector<T>casoEspecialPeon=moviPeon(tempV,posXT,posYT,mio);
                    if(casoEspecialPeon.size()!=0){

                        for(int it=0;it<casoEspecialPeon.size();it++)
                            peonCome.push_back(casoEspecialPeon[it]);
                    }
                    else
                        peonCome.push_back(tempV);

                    cont++;
                }
            }
            else if (V[posX][posY] == 0) {
                T tempV=V;
                tempV[xT][yT] = 0;
                tempV[posX][posY] = peon;
                respPeon.push_back(tempV);
            }

        }
    }

    if(peonCome.size()>0)
        return peonCome;
    else
        return respPeon;
}
template <class T>
T jugadaReyna(T Vect,int xT,int yT,bool mio) {
    int reyna, peonEnemigo, reynaEnemigo, peon;
    T respReyna=Vect;
    int A[4][2] = {{1,  1},
                   {1,  -1},
                   {-1, 1},
                   {-1, -1}};
    if (mio) {
        peon = 1;
        reyna = 3;
        peonEnemigo = 2;
        reynaEnemigo = 4;

    } else {
        peon = 2;
        reyna = 4;
        peonEnemigo = 1;
        reynaEnemigo = 3;

    }
    for (int c = 0; c < 4; c++) {
        int xTemp=xT,yTemp=yT;
        int vecX=A[c][0],vecY=A[c][1];
        while(checkCoord(xTemp+vecX,yTemp+vecY)) {
            int xTempNext=xTemp+A[c][0],yTempNext=yTemp+A[c][1];
            if(Vect[xTempNext][yTempNext]==peonEnemigo or Vect[xTempNext][yTempNext]==reynaEnemigo){
                if(checkCoord(xTempNext+vecX,yTempNext+vecY) and Vect[xTempNext+vecX][yTempNext+vecY]==0){

                    Vect[xTemp][yTemp]=0;
                    Vect[xTempNext][yTempNext]=0;
                    Vect[xTempNext+vecX][yTempNext+vecY]=reyna;
                    Vect=jugadaReyna(Vect,xTempNext+vecX,yTempNext+vecY,mio);

                }
            }
            else if(!checkCoord(xTempNext,yTempNext) and Vect[xTempNext][yTempNext]==peon or Vect[xTempNext][yTempNext]==reyna){
                return Vect;
            }
            xTemp=xTempNext+vecX;
            yTemp=yTempNext+vecY;
        }
    }
    return Vect;
}

template <class T>
vector<T> moviReyna(T V,int xT,int yT,bool mio) {
    int  reyna, peonEnemigo, reynaEnemigo,peon;
    vector<T> respReyna;
    vector<T>reynaCome;
    int A[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
    if (mio) {
        peon=1;
        reyna = 3;
        peonEnemigo = 2;
        reynaEnemigo = 4;

    } else {
        peon=2;
        reyna = 4;
        peonEnemigo = 1;
        reynaEnemigo = 3;

    }
    for (int x = 0; x < 4; x++) {
        int xTemp=xT,yTemp=yT;
        int vecX=A[x][0],vecY=A[x][1];
        while(checkCoord(xTemp+vecX,yTemp+vecY)){
            int xTempNext=xTemp+A[x][0],yTempNext=yTemp+A[x][1];
            if(V[xTempNext][yTempNext]==peonEnemigo or V[xTempNext][yTempNext]==reynaEnemigo){
                if(checkCoord(xTempNext+vecX,yTempNext+vecY) and V[xTempNext+vecX][yTempNext+vecY]==0){
                    T vTemp=V;
                    vTemp[xTemp][yTemp]=0;
                    vTemp[xTempNext][yTempNext]=0;
                    vTemp[xTempNext+vecX][yTempNext+vecY]=reyna;
                    vTemp=jugadaReyna(vTemp,xTempNext+vecX,yTempNext+vecY,mio);
                    reynaCome.push_back(vTemp);
                }
            }
            else if(V[xTempNext][yTempNext]==0){
                T vTemp=V;
                vTemp[xTemp][yTemp]=0;
                vTemp[xTempNext][yTempNext]=reyna;
                respReyna.push_back(vTemp);
            }
            else break;
            xTemp=xTempNext+vecX;
            yTemp=yTempNext+vecY;

        }


    }
    if(reynaCome.size()>0)
        return reynaCome;
    else
        return respReyna;

}


template <class T>
void print(T V){
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

template <class T>
vector<T> movimientos(T movIni,bool mio){
    vector<T> res;
    int modulo,peon,reyna,peonEnemigo,reynaEnemigo,iniPeon,finPeon;
    int A[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
    if(mio){modulo=1;peon=1;reyna=3;}
    else{modulo=0;peon=2;reyna=4;}
    for(int a=0;a<movIni.size();a++) {
        for (int b = 0; b < movIni[a].size(); b++) {
            int currentMov=movIni[a][b];
            if(currentMov!=(-1)){
                if(currentMov%2==modulo and currentMov!=0){
                    if(currentMov==peon){ //MOV PEON
                        vector<T> peonRes=moviPeon(movIni,a,b,mio);
                        for(int aT=0;aT<peonRes.size();aT++){
                            res.push_back(peonRes[aT]);
                        }
                    }
                    else if(currentMov==reyna) {
                        vector<T> reynaRes=moviReyna(movIni,a,b,mio);
                        for(int aT=0;aT<reynaRes.size();aT++){
                            res.push_back(reynaRes[aT]);
                        }
                    }
                        /*
                    else if(currentMov==reyna){
                        vector<T>tempRes;
                        for(int x=0;x<4;x++) {
                            int currentX=a+A[x][0],currentY=b+A[x][1];
                            while(checkCoord(currentX,currentY) and movIni[currentX][currentY]==0) {
                                //cout<<"X: "<<currentX<<" Y: "<<currentY<<endl;
                                T temp = movIni;
                                if(movIni[currentX][currentY]==0) {
                                    temp[a][b] = 0;
                                    temp[currentX][currentY] = reyna;
                                }
                                else if(movIni[currentX][currentY]==peonEnemigo or movIni[currentX][currentY]==reynaEnemigo ){
                                    int tempCurrentX=currentX,tempCurrentY=currentY;
                                    if( checkCoord(tempCurrentX+A[x][0],tempCurrentY + A[x][1]) and movIni[tempCurrentX+A[x][0]][tempCurrentY + A[x][1]]==0){
                                        temp[tempCurrentX][tempCurrentY]=0;
                                        temp[tempCurrentX+A[x][0]][tempCurrentY + A[x][1]]=4;
                                        tempRes=movimientos(temp,mio);
                                    }
                                }
                                res.push_back(temp);
                                currentX = currentX + A[x][0];
                                currentY = currentY + A[x][1];
                            }
                        }*/
                    }
                }
            }
        }

    return res;
}
typedef vector< vector<int> > vector2d;

template <class T>
void calcPeso(int &A,int &B, T V){
    A=B=0;
    for(int a=0;a<V.size();a++){
        for(int b=0; b<V[a].size();b++){
            if(V[a][b]==2 or V[a][b]==4)
                B++;
            else if(V[a][b]==1 or V[a][b]==3)
                A++;
        }
    }
}


#endif // FUNCIONES_H
