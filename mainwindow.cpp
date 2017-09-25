#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

void MainWindow::startGame()
{
    QBrush yellowBrush(QColor(232, 193, 98));
    QBrush redBrush(QColor(160,82,45));
    QBrush yo(QColor(235, 189, 48));//blanco
    QBrush maquina(QColor(66,21,18)); //negro
    QPen outlinePen(Qt::black);
    scene=new QGraphicsScene(this);
    ui->tableroView->setScene(scene);
    int tam=62;
    int size=262;
    int inicio=200;
    QBrush brush=redBrush;
    for (int y = -inicio; y < size; y+=tam) {
        for (int x = -inicio; x < size; x+=tam) {
            (brush==redBrush)?brush=yellowBrush:brush=redBrush;
            scene->addRect(x,y,tam,tam,outlinePen,brush);
        }
        (brush==redBrush)?brush=yellowBrush:brush=redBrush;
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_btn_start_clicked()
{
    QBrush yellowBrush(QColor(232, 193, 98));
    QBrush redBrush(QColor(160,82,45));
    QBrush yo(QColor(235, 189, 48));//blanco
    QBrush maquina(QColor(66,21,18)); //negro
    QPen outlinePen(Qt::black);
    scene=new QGraphicsScene(this);
    ui->tableroView->setScene(scene);

    int p=ui->spin_profundo->value();
    if(ui->radio_m->isChecked()){
        Game juego(scene,yellowBrush,redBrush,yo,maquina,outlinePen,p,true);
        juego.start();
    }

}
