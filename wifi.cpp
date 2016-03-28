#include "wifi.h"

Wifi::Wifi()
{
    m_settings.setAccessPoint("192.168.13.1");
    m_settings.setAPName("WifiAssistForLinux");
    m_settings.setInterface_Create("wlan0");
    m_settings.setInterface_Shared("eth0");
    m_settings.setPassword("1234567890");
//    setPath_exec("/home/lzjqsdd/github/create_ap/create_ap");
}

QString Wifi::Password() const
{
    return _Password;
}

void Wifi::setAccessPoint(const QString &AccessPoint)
{
    _AccessPoint = AccessPoint;
}

QString Wifi::AccessPoint() const
{
    return _AccessPoint;
}

QString Wifi::Interface_Shared() const
{
    return _Interface_Shared;
}

void Wifi::setInterface_Shared(const QString &Interface_Shared)
{
    _Interface_Shared = Interface_Shared;
}

QString Wifi::Interface_Create() const
{
    return _Interface_Create;
}

void Wifi::setInterface_Create(const QString &Interface_Create)
{
    _Interface_Create = Interface_Create;
}

void Wifi::setPassword(const QString &Password)
{
    _Password = Password;
}

QString Wifi::APName() const
{
    return _APName;
}

void Wifi::setAPName(const QString &APName)
{
    _APName = APName;
}

void Wifi::setPath_exec(const QString &path_exec)
{
    _path_exec = path_exec;
}

bool Wifi::startWifi()
{
     QStringList args = QStringList() <<_path_exec<<_Interface_Create << _Interface_Shared << _APName << _Password;
     if(!QProcess::startDetached("pkexec",args))
    {
      //   QMessageBox::warning(NULL,"Warning","can't started!");
         return false;
     }
     else
     {
       //  QMessageBox::warning(NULL,"Warning","Create Success!");
         return true;
     }
}

bool Wifi::stopWifi()
{
    QStringList args = QStringList() <<_path_exec<<"--stop"<<_Interface_Create;
    if(!QProcess::startDetached("pkexec",args))
    {
        //QMessageBox::warning(NULL,"Warning","can't started!");
        return false;
    }
    else
       // QMessageBox::warning(NULL,"Warning","Create Success!");
        return true;
}

