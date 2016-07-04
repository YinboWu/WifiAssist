#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <wsettings.h>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    //initUILanguage
    initUILanguageShow();

    //init UI information
    initUIValue();

    //create SystemTrayIcon Control
   // this->createSystemTrayMenu();
}

MainWindow::~MainWindow()
{
    wifi.stopWifi();
    delete ui;
}

void MainWindow::initUIValue()
{
    ui->lineEdit_name->setText(m_wsettings.APName());
    ui->lineEdit_pwd ->setText(m_wsettings.Password());
    ui->lineEdit_ap->setText(m_wsettings.AccessPoint());

    //get interface list
    QStringList interface_list = m_wsettings.getInterfaceList();
    ui->comboBox_createdinterface->addItems(interface_list);
    ui->comboBox_shareinterface->addItems(interface_list);

    ui->comboBox_createdinterface->setCurrentText(m_wsettings.Interface_Create());
    ui->comboBox_shareinterface->setCurrentText(m_wsettings.Interface_Shared());
}

void MainWindow::initUILanguageShow()
{
    //default language:zh_CN
    ui->label_ap->setText("接入点");
    ui->label_name->setText("名称");
    ui->label_pwd->setText("密码");
    ui->label_shareinterface->setText("共享网卡");
    ui->label_createdinterface->setText("热点网卡");
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
        //弹出气泡提示
        //m_trayIcon.showMessage(titlec,textc,QSystemTrayIcon::Information,5000);

        QMenu m_menu;
        m_menu.addAction("StartWifi");
        m_menu.addAction("StopWifi");
        m_trayIcon.setContextMenu(&m_menu);

        m_trayIcon.show();
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
    //if config not changed,return
    if(ui->lineEdit_name->text() == m_wsettings.APName())
        return;

    ui->lineEdit_name->setEnabled(false);
    m_wsettings.setAPName(ui->lineEdit_name->text());
    if(QString::compare(ui->pushButton->text(),"STOP") == 0)
    {
        ui->pushButton->setText("Restaring...");
        wifi.restartWifi();
        ui->pushButton->setText("STOP");
    }
}

void MainWindow::on_pushButton_pwd_clicked()
{
    ui->lineEdit_pwd->setEnabled(true);
}

void MainWindow::on_lineEdit_pwd_editingFinished()
{
    if(ui->lineEdit_pwd->text() == m_wsettings.Password())
        return;


    ui->lineEdit_pwd->setEnabled(false);
    m_wsettings.setPassword(ui->lineEdit_pwd->text());
    if(QString::compare(ui->pushButton->text(),"STOP") == 0)
    {
        ui->pushButton->setText("Restaring...");
        wifi.restartWifi();
        ui->pushButton->setText("STOP");
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
}

void MainWindow::on_pushButton_save_clicked()
{
    QString apoint = this->ui->lineEdit_ap->text();
    QString interface_created = this->ui->comboBox_createdinterface->currentText();
    QString interface_shared = this->ui->comboBox_shareinterface->currentText();
    if(apoint.size() == 0)
    {
        QMessageBox::information(this,"Settings","Access Point Can't Be Empty!",QMessageBox::Ok);
        return;
    }
    if(interface_created.size() == 0)
    {
        QMessageBox::information(this,"settings","Wifi Interface Can't Be Empty!",QMessageBox::Ok);
        return;
    }
    if(interface_shared.size() == 0)
    {
        QMessageBox::information(this,"settings","Shared Interface Can't Be Empty!",QMessageBox::Ok);
        return;
    }

    if(!interface_created.startsWith("wl"))
    {
        QMessageBox::StandardButton stdbtn = QMessageBox::warning(NULL,"Settings",
                                 "This Wifi Interface May not work,Still Use it?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(stdbtn == QMessageBox::No)
            return;
    }
    if(!(interface_shared.contains("eth") || interface_shared.contains("en")))
    {
        QMessageBox::StandardButton stdbtn = QMessageBox::warning(NULL,"Settings",
                                "This Shared Interface May not work,Still Use it?",
                                QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(stdbtn == QMessageBox::No)
            return;
    }

    m_wsettings.setAccessPoint(apoint);
    m_wsettings.setInterface_Create(interface_created);
    m_wsettings.setInterface_Shared(interface_shared);
    QMessageBox::information(this,"Settings","Apply Success!",QMessageBox::Ok);

}

void MainWindow::on_lineEdit_name_returnPressed()
{

}

void MainWindow::on_lineEdit_name_textChanged(const QString &arg1)
{

}
