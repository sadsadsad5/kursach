#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include <secondwindow.h>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QStringList>

int k,d,x3,x1,x2, d2,d1;


ThirdWindow::ThirdWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(answer()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(answer()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(answer()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(answer()));

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);


    k=1,x3=0,x1=0,x2=0;
    int b=rand()%20+1;
    d=b;
    QTextStream stream, stream1;
    QFile v(this->VOPR_PATH);
    QFile a(this->ANS_PATH);
    if(!v.exists()|| !a.exists())
    {
        QMessageBox::warning(this, "Error", "Сбой в программе\nФайлы не\
        найдены");
        exit(1);
    }
    stream.setDevice(&v);
    stream1.setDevice(&a);
    if ((v.open(QIODevice::ReadWrite | QIODevice::Text)) &&
    (a.open(QIODevice::ReadWrite | QIODevice::Text)) )
    {
        while((!stream.atEnd()) && (!stream1.atEnd()))
        {
            b--;
            QString vopr = stream.readLine();
            QString anss = stream1.readLine();
            if(vopr.isEmpty()|| anss.isEmpty())
            {
                QMessageBox::warning(this, "Error", "Сбой в \
                программе\nФайлы пусты");
                exit(1);
            }
            if(b==0)
            {
                ui->label->setText(vopr);
                QStringList lst = anss.split(" ");
                ui->pushButton->setText(lst.at(0));
                ui->pushButton_2->setText(lst.at(1));
                ui->pushButton_3->setText(lst.at(2));
                ui->pushButton_4->setText(lst.at(3));
                v.close();
                a.close();
                break;
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Конструктор Сбой в программе\nПовторите\
        попытку");
        exit(1);
    }
    k++;
}


ThirdWindow::~ThirdWindow()
{
    delete ui;
}


void ThirdWindow::answer()
{
    QPushButton *button = (QPushButton *)sender();
    int r=0, b=0;
    QString otv;
    otv=button->text();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    QTextStream stream2;
    QFile o(this->PRAVIL_PATH);
    stream2.setDevice(&o);
    if (o.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        while(!stream2.atEnd())
        {
            QString otvet = stream2.readLine();
            if(otvet==otv)
            {
                r++;
                o.close();
                break;
            }
        }
        o.close();
        if(r==0)
        {
            QMessageBox::StandardButton reply = QMessageBox::warning(this,
            "ОБЪЯВЛЕНИЕ", "Вы проиграли!\n\nЖелаете начать заново игру?",
            QMessageBox::Ok | QMessageBox::Cancel);
            if(reply==QMessageBox::Ok)
            {
                hide();
                SecondWindow *qw = new SecondWindow;
                qw->show();
            }
            else
            {
                exit(1);
            }

        }
        if(k==16)
        {
            QMessageBox::StandardButton rep = QMessageBox::question(this,
            "ОБЪЯВЛЕНИЕ", "ВЫ ВЫИГРАЛИ!\n\nЖелаете начать игру заново?",
            QMessageBox::Ok | QMessageBox::Cancel);

            if(rep==QMessageBox::Ok)
            {
                hide();
                SecondWindow *qw = new SecondWindow;
                qw->show();
            }

            else
            {
                exit(1);
            }

        }
        if(k<=15)
        {
            switch (k)

            {
            case 1:ui->label_2->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            break;
            case 2:ui->label_3->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_2->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 3:ui->label_4->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_3->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 4:ui->label_5->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_4->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 5:ui->label_6->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_5->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 6:ui->label_7->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_6->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 7:ui->label_8->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_7->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 8:ui->label_9->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_8->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 9:ui->label_10->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_9->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 10:ui->label_11->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_10->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 11:ui->label_12->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_11->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 12:ui->label_13->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_12->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 13:ui->label_14->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_13->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 14:ui->label_15->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_14->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            case 15:ui->label_16->setStyleSheet("color:rgb(255,255,255);\
            background-color:rgb(46, 52, 54)");
            ui->label_15->setStyleSheet("color:rgb(black);\
            background-color:rgb(222,218,213)");
            break;
            }
            QFile vop(this->VOPR_PATH);
            QFile an(this->ANS_PATH);
            QTextStream stream, stream1;
            stream.setDevice(&vop);
            stream1.setDevice(&an);
            if(k<=5)
                b=1+rand()%20;
            else if(k>5 && k<=10)
                b=21+rand()%20;
            else if(k>=11 && k<=15)
                b=41+rand()%22;
            d=b; // МОЖЕТ БЫТЬ ТУТ ЧЕЛИКСОН НАПОДЛЕВИЛ ЖиДКИМ
            if ((vop.open(QIODevice::ReadWrite | QIODevice::Text)) &&
            (an.open(QIODevice::ReadWrite | QIODevice::Text)) )
            {
                while((!stream.atEnd()) && (!stream1.atEnd()))
                {
                    b--;
                    QString vopr = stream.readLine();
                    QString anss = stream1.readLine();
                    if(b==0)
                    {
                        ui->label->setText(vopr);
                        QStringList lst = anss.split(" ");
                        ui->pushButton->setText(lst.at(0));
                        ui->pushButton_2->setText(lst.at(1));
                        ui->pushButton_3->setText(lst.at(2));
                        ui->pushButton_4->setText(lst.at(3));
                        vop.close();
                        an.close();
                        break;
                    }

                }
            }
            else
            {
                QMessageBox::warning(this, "Error", "Сбой в программе\n\
                Повторите попытку");
            }
            k++;
        }
    }
    else
        {
            QMessageBox::warning(this, "Error", "Answer Сбой в программе\nПовторите\
            попытку");
        }
}
void ThirdWindow::on_pushButton_8_clicked()
{
    exit(1);
}


void ThirdWindow::on_pushButton_7_clicked()
{
    if (x3==0){
        int d1=0;
        QTextStream stream3;
        QFile q(this->PRAVIL_PATH);
        stream3.setDevice(&q);
        if (q.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            while(!stream3.atEnd())
            {
                QString ot = stream3.readLine();
                d1++;
                if(d==d1)
                {
                    ot="Большинство считает, что правильный ответ:\
                    \n"+ot;
                    QMessageBox::information(this, "Подсказка", ot);
                    q.close();
                    break;
                }
            }
        }
        else {
            QMessageBox::warning(this, "Error", "Сбой в программе\n\
            Повторите попытку");
        }
        x3++;
    }
}


void ThirdWindow::on_pushButton_5_clicked()
{
    if (x1==0)
    {
        d2=0;
        QTextStream stream4;
        QFile p(this->PRAVIL_PATH);
        stream4.setDevice(&p);
        if (p.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            while(!stream4.atEnd())
            {
                QString ot1 = stream4.readLine();
                d2++;
                if(d==d2)
                {
                    ot1="Друг считает, что правильный ответ:\n"+ot1;
                    QMessageBox::information(this, "Подсказка1", ot1);
                    p.close();
                    break;
                }
            }
        }
        else
        {
            QMessageBox::warning(this, "Error", "Сбой в программе\n\
            Повторите попытку");
        }
        x1++;
    }
}



void ThirdWindow::on_pushButton_6_clicked()
{
    if (x2==0)
    {
        int b1=0, k1=k--;
        QFile vopr(this->VOPR_PATH);
        QFile anss(this->ANS_PATH);
        QTextStream stream5, stream6;
        stream5.setDevice(&vopr);
        stream6.setDevice(&anss);
        if(k1<=5)
            b1 = 1+rand()%20;
        else if(k1>5 && k1<=10)
            b1 = 21 + rand()%20;
        else if(k1>10 && k1<=15)
            b1 = 41 + rand()%22;
       d=b1;
       if ((vopr.open(QIODevice::ReadWrite | QIODevice::Text)) &&
       (anss.open(QIODevice::ReadWrite | QIODevice::Text)) )
       {
           while((!stream5.atEnd()) && (!stream6.atEnd()))
           {
               b1--;
               QString vopro = stream5.readLine();
               QString ans = stream6.readLine();
               if(b1==0)
               {
                   ui->label->setText(vopro);
                   QStringList lst = ans.split(" ");
                   ui->pushButton->setText(lst.at(0));
                   ui->pushButton_2->setText(lst.at(1));
                   ui->pushButton_3->setText(lst.at(2));
                   ui->pushButton_4->setText(lst.at(3));
                   vopr.close();
                   anss.close();
                   break;
               }
           }
       }
       else
       {
           QMessageBox::warning(this, "Error", "Сбой в программе\n\
           Повторите попытку");
       }
       x2++;
       k++;
    }
}

