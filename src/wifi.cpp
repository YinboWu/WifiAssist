#include "wifi.h"
#include <src/wsettings.h>
#include <iostream>
Wifi::Wifi()
{
}

/**
*lzjqsdd
*/
bool Wifi::startWifi()
{
    WSettings m_settings;
    QString _g = "-g";
    QStringList args = QStringList() << m_settings.Interface_Create()
                                     << m_settings.Interface_Shared() << m_settings.APName()
                                     << m_settings.Password()
                                     << _g << m_settings.AccessPoint();

    //use pkexec for first version,there is some questions unsolved with gksu.
    if(!QProcess::startDetached(m_settings.path_exec(),args))
    {
        return false;
    }
    else
    {
        return true;
    }
}
/**
*lzjqsdd
*/
bool Wifi::stopWifi()
{
    WSettings m_settings ;
    QString arg1 = "--stop";
    QStringList args = QStringList() <<arg1<<m_settings.Interface_Create();
    if(!QProcess::startDetached(m_settings.path_exec(),args))
    {
        return false;
    }
    else
        return true;
}

/*
 * use when update config,e.g. change wifi name or password or access point
*/
void Wifi::restartWifi()
{
    stopWifi();
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<3000)
        QCoreApplication::processEvents();
    startWifi();
}


