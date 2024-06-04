//#include "ui_secondwindow.h"
#include <QWidget>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include "secondwindow.h"
#include "thirdwindow.h"




SecondWindow::SecondWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}


SecondWindow::~SecondWindow()
{
    delete ui;
}




void SecondWindow::on_pushButton_clicked()
{
    int pr=0;
    QTextStream stream, stream2;
    QString login=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();
    QFile f1(this->LOG_PATH);
    QFile f2(this->PASS_PATH);
    if(!f1.exists() || !f2.exists())
    {
        QMessageBox::warning(this, "Error", "Сбой в программе\nФайлы не\
        найдены");
        exit(1);
    }

    stream.setDevice(&f1);
    stream2.setDevice(&f2);
    if ((f1.open(QIODevice::ReadWrite | QIODevice::Text)) &&
    (f2.open(QIODevice::ReadWrite | QIODevice::Text)))
    {
        while((!stream.atEnd()) && (!stream2.atEnd()))
        {
        QString log = stream.readLine();
        QString pas = stream2.readLine();
        if(login==log && pas==pass)
            {
                pr++;
                hide();
                ThirdWindow *a2 = new ThirdWindow();
                a2->show();
                f1.close();
                f2.close();
                break;
            }
        }
    }
    if(pr==0)
    {
        QMessageBox::warning(this, "Error", "Вы ввели неверный логин\
        или пароль\nПовторите попытку");
        f1.close();
        f2.close();
    }

}


void SecondWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Справка " , "∗∗∗Кто хочет стать \
    миллионером?∗∗∗\n\nИгра предназначена для развивития логического \
    мышления," " интеллектуальных способностей . \n\n∗ПРАВИЛА∗\n\nДля \
    того , чтобы выиграть , необходимо правильно ответить "
    "на 15 вопросов . Каждый вопрос имеет 4 варианта ответа , из которых \
    только один является верным . Вы ""можете воспользоваться 3 \
    подсказками.Каждую подсказку можно использовать только один раз за \
    всю ""игру . Подсказка Замена вопроса − заменяет вопрос . Подсказка \
    Звонок другу − помощь ""друга−компьютера . Подсказка Помощь зала − \
    помощь зрителей . \n\n\nРазработчик : Тимур Лемешевский\n" ) ;
}


void SecondWindow::on_pushButton_4_clicked()
{
    exit(1);
}


void SecondWindow::on_pushButton_2_clicked()
{
    QString lo=ui->lineEdit->text();
    QString pa=ui->lineEdit_2->text();
    if(lo.isEmpty()|| pa.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Заполните поля пароль и\
        логин");
    }
    else
    {
        QFile fi1(this->LOG_PATH);
        QFile fi2(this->PASS_PATH);
        if (!fi1.exists() || !fi2.exists())
        {
            QMessageBox::warning(this, "Error", "Сбой в программе\nФайлы не\
            найдены");
            exit(1);
        }
        if ((fi1.open(QIODevice::Append | QIODevice::Text)) &&
        (fi2.open(QIODevice::Append | QIODevice::Text)))
        {
            QTextStream stream1(&fi1);
            stream1 << lo << "\n";
            fi1.flush();
            fi1.close();
            QTextStream stream2(&fi2);
            stream2 << pa << "\n";
            fi2.flush();
            fi2.close();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Сбой в программе");
        }
        hide();
        ThirdWindow *a2 = new ThirdWindow();
        a2->show();
    }
}

