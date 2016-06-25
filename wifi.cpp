#include "wifi.h"
#include <wsettings.h>
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
    QStringList args = QStringList() << m_settings.path_exec()<<m_settings.Interface_Create()
                                     << m_settings.Interface_Shared() << m_settings.APName()
                                     << m_settings.Password();

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
    QStringList args = QStringList() <<m_settings.path_exec()<<arg1<<m_settings.Interface_Create();
    if(!QProcess::startDetached(m_settings.path_exec(),args))
    {
        return false;
    }
    else
        return true;
}

