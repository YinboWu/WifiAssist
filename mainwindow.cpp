#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <wsettings.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->lineEdit_name->setText(m_wsettings.APName());
    ui->lineEdit_pwd ->setText(m_wsettings.Password());
    ui->lineEdit_ap->setText(m_wsettings.AccessPoint());
    ui->lineEdit_shareinterface->setText(m_wsettings.Interface_Shared());

    this->createSystemTrayMenu();

}

MainWindow::~MainWindow()
{
    wifi.stopWifi();
    delete ui;
}

void MainWindow::createSystemTrayMenu()
{
    //Check if System Support SystemTrayIcon.
    //Linux:X11
    if(QSystemTrayIcon::isSystemTrayAvailable())
    {

        m_trayIcon.setIcon(QIcon("img/WifiAssit.ico"));
        m_trayIcon.setToolTip((tr("WifiAssist Running...")));
        QString titlec=tr("WifiAssist Info");
        QString textc=tr("Click For Detaili Options");
        m_trayIcon.show();

        //弹出气泡提示
        m_trayIcon.showMessage(titlec,textc,QSystemTrayIcon::Information,5000);

        QMenu m_menu;
        m_menu.addAction("StartWifi");
        m_menu.addAction("StopWifi");
        m_trayIcon.setContextMenu(&m_menu);
     }
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
    WSettings m_setting;
    QString apoint = this->ui->lineEdit_ap->text();
    if(apoint.size()!=0)
    {
        m_setting.setAccessPoint(apoint);
        QMessageBox::information(this,"settings","Apply Success!",QMessageBox::Ok);
    }
    else
    {
             QMessageBox::information(this,"settings","Access Point Can't Be Empty!",QMessageBox::Ok);
    }
}
