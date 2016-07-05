#ifndef WIFI_H
#define WIFI_H
#include <QString>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include "wsettings.h"
#include <QElapsedTimer>

class Wifi
{
public:
    Wifi();
    bool startWifi();
    bool stopWifi();
    void useWPA1();
    void useWPA2();

    void restartWifi();
};

#endif // WIFI_H
