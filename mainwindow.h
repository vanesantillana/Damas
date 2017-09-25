#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsScene *scene;
    Game juego;
    explicit MainWindow(QWidget *parent = 0);
    void startGame();
    ~MainWindow();

private slots:
    void on_btn_start_clicked();

    void on_btn_siguiente_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
