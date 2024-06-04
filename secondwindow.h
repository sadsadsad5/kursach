#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include "ui_secondwindow.h"


class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:

    //void on_pushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    QString LOG_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\log.txt";
    QString PASS_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\pass.txt";
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
