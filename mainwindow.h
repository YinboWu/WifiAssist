#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wifi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Wifi wifi;
    QString path;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_name_clicked();

    void on_lineEdit_name_editingFinished();

    void on_pushButton_pwd_clicked();

    void on_lineEdit_pwd_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
