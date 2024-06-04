#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include "ui_thirdwindow.h"


class ThirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void answer();


    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    QString LOG_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\log.txt";
    QString PASS_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\pass.txt";
    QString ANS_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\ans.txt";
    QString VOPR_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\vopr.txt";
    QString PRAVIL_PATH = "C:\\Users\\HOME\\OneDrive\\Рабочий стол\\timurik_kursach\\pravil.txt";
    Ui::ThirdWindow *ui;
};


#endif // THIRDWINDOW_H
