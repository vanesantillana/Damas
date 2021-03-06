#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QBrush yellowBrush(QColor(232, 193, 98));
    QBrush redBrush(QColor(160,82,45));
    QBrush yo(QColor(235, 189, 48));//blanco
    QBrush maquina(QColor(66,21,18)); //negro
    QPen outlinePen(Qt::black);
    int tam=62;
    QGraphicsScene *scene1=new QGraphicsScene(this);
    ui->maquinaView->setScene(scene1);
    scene1->addEllipse(0,0,tam,tam,outlinePen,maquina);

    QGraphicsScene *scene2=new QGraphicsScene(this);
    ui->yoView->setScene(scene2);
    scene2->addEllipse(0,0,tam,tam,outlinePen,yo);

    scene=new QGraphicsScene(this);
    ui->tableroView->setScene(scene);
    juego.scene=scene;
    juego.outlinePen=outlinePen;
    juego.maquina=maquina;
    juego.yo=yo;
    juego.yellowBrush=yellowBrush;
    juego.redBrush=redBrush;
    ui->btn_siguiente->setVisible(false);
}

void MainWindow::startGame()
{
    int tam=62;
    int size=262;
    int inicio=200;
    QBrush brush=juego.redBrush;
    for (int y = -inicio; y < size; y+=tam) {
        for (int x = -inicio; x < size; x+=tam) {
            (brush==juego.redBrush)?brush=juego.yellowBrush:brush=juego.redBrush;
            scene->addRect(x,y,tam,tam,juego.outlinePen,brush);
        }
        (brush==juego.redBrush)?brush=juego.yellowBrush:brush=juego.redBrush;
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_btn_start_clicked()
{
    int p=ui->spin_profundo->value();
    if(ui->radio_yo->isChecked()){
        juego.atributos(p,true);
        juego.start();
        ui->btn_siguiente->setVisible(true);
    }
    else{
        ui->btn_siguiente->setVisible(false);

    }

}

void MainWindow::on_btn_siguiente_clicked()
{
    int x,y,a,b;
    x=ui->i_x->value();
    y=ui->i_y->value();
    a=ui->f_x->value();
    b=ui->f_y->value();
    juego.moverficha(x,y,a,b);
    juego.print(juego.tablero);
    juego.start();
}
