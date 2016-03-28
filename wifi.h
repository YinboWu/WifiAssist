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

    WSettings m_settings;

    QString _path_exec;
    QString _APName;
    QString _Password;
    QString _Interface_Create;
    QString _Interface_Shared;
    QString _AccessPoint;


    bool startWifi();
    bool stopWifi();
    void useWPA1();
    void useWPA2();


    void setPath_exec(const QString &path_exec);

    QString APName() const;
    void setAPName(const QString &APName);

    void setPassword(const QString &Password);

    QString Interface_Create() const;
    void setInterface_Create(const QString &Interface_Create);

    QString Interface_Shared() const;
    void setInterface_Shared(const QString &Interface_Shared);

    QString AccessPoint() const;
    void setAccessPoint(const QString &AccessPoint);
    QString Password() const;
};

#endif // WIFI_H
