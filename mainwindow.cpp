#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->textEdit_name->setText(wifi.APName());
    //ui->textEdit_pwd ->setText(wifi.Password());

    ui->lineEdit_name->setText(wifi.APName());
    ui->lineEdit_pwd ->setText(wifi.Password());

    ui->lineEdit_ap->setText(settings.AccessPoint());

    wifi.setPath_exec(QDir::currentPath()+"/wifi.sh");
}

MainWindow::~MainWindow()
{
//    wifi.stopWifi();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString text = ui->pushButton->text();
    if(QString::compare(text,"START") == 0)
    {
        if(wifi.startWifi())
            ui->pushButton->setText("STOP");
    }
    else if(QString::compare(text,"STOP") == 0)
    {
        if(wifi.stopWifi())
            ui->pushButton->setText("START");
    }
    else
    {
        QMessageBox::warning(NULL,"Error","Wrong!");
    }
}

void MainWindow::on_pushButton_name_clicked()
{
    ui->lineEdit_name->setEnabled(true);
}

void MainWindow::on_lineEdit_name_editingFinished()
{
    ui->lineEdit_name->setEnabled(false);
}

void MainWindow::on_pushButton_pwd_clicked()
{
    ui->lineEdit_pwd->setEnabled(true);
}

void MainWindow::on_lineEdit_pwd_editingFinished()
{
    ui->lineEdit_pwd->setEnabled(false);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
}

void MainWindow::on_pushButton_save_clicked()
{
}
