#include "updater.h"
#include "ui_updater.h"
#include <QDesktopWidget>

Updater::Updater(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Updater)
{
    ui->setupUi(this);
    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);

    this->setWindowFlags(Qt::FramelessWindowHint);//没有标题栏

    //隐藏菜单栏和工具栏
    //this->ui->menuBar->hide();
    //this->ui->mainToolBar->hide();

    //固定高和宽：
    this->setFixedSize(400,200);

    //设置背景颜色（两种方法都可以）
    //this->setStyleSheet("QMainWindow{background:rgb(240,250,250)}");
    QPalette pal;
    pal.setColor(QPalette::Background,QColor(255,245,225) );
    this->setPalette(pal);
    this->setAutoFillBackground(true);
}

Updater::~Updater()
{
    delete ui;
}
