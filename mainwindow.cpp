#include "mainwindow.h"
#include "secondwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    SecondWindow *a1 = new SecondWindow();
    a1->show();
}

