#ifndef WIFI_H
#define WIFI_H
#include <QString>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include "wsettings.h"

class Wifi
{
public:
    Wifi();
    bool startWifi();
    bool stopWifi();
    void useWPA1();
    void useWPA2();
};

#endif // WIFI_H
