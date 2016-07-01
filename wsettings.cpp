#include "wsettings.h"

WSettings::WSettings()
{        
       setConfigAttrName();
       checkConfigFile();
}

WSettings::~WSettings()
{
    delete this->m_settings;
}

void WSettings::setConfigAttrName()
{
    _path_exec = "PATH";
    _APName = "APNAME";
    _Password = "PASSWORD";
    _Interface_Create = "INTERFACE_CREATED";
    _Interface_Shared = "INTERFACE_SHARED";
    _AccessPoint = "ACCESSPOINT";
}

void WSettings::setSettings(const QString &name,const QString &value)
{
    QString fullpath = "/settings/"+name;
    m_settings->setValue(fullpath,value);
}

QString WSettings::getSettings(const QString&name) const
{
    QString fullpath = "/settings/"+name;
    return m_settings->value(fullpath).toString();
}

QString WSettings::AccessPoint() const
{
    return this->getSettings(_AccessPoint);
}

void WSettings::setAccessPoint(const QString &AccessPoint)
{
    this->setSettings(_AccessPoint,AccessPoint);
}

QString WSettings::Interface_Shared() const
{
    return this->getSettings(this->_Interface_Shared);
}

void WSettings::setInterface_Shared(const QString &Interface_Shared)
{
   this->setSettings(this->_Interface_Shared,Interface_Shared);
}

QString WSettings::Interface_Create() const
{
    return this->getSettings(this->_Interface_Create);
}

void WSettings::setInterface_Create(const QString &Interface_Create)
{
    this->setSettings(this->_Interface_Create,Interface_Create);
}

QString WSettings::Password() const
{
    return this->getSettings(this->_Password);
}

void WSettings::setPassword(const QString &Password)
{
    this->setSettings(this->_Password,Password);
}

QString WSettings::APName() const
{
    return this->getSettings(this->_APName);
}

void WSettings::setAPName(const QString &APName)
{
    this->setSettings(this->_APName,APName);
}

QString WSettings::path_exec() const
{
    return this->getSettings(this->_path_exec);
}

void WSettings::setPath_exec(const QString &path_exec)
{
    this->setSettings(this->_path_exec,path_exec);
}

void WSettings::checkConfigFile()
{
    //default config file "~/.WifiAssist/config.ini"
    //check is path exists
    QDir dir;
    QString config_path = dir.homePath()+"/.WifiAssist";
    QString filename = config_path+"/config.ini";
    dir.setPath(config_path);


    //if not exist,mkdir and Then set default config file.
    if(!dir.exists())
    {
        dir.mkdir(config_path);
    }

    QFile file;
    file.setFileName(filename);
    if(!file.exists())
    {
        m_settings = new QSettings(filename,QSettings::IniFormat);
        setDefaultConfig();
    }
    else
        m_settings = new QSettings(filename,QSettings::IniFormat);
}

void WSettings::setDefaultConfig()
{
    this->setPassword("1234567890");
    this->setAccessPoint("192.168.12.1");
    this->setAPName("WifiAssistForLinux");
    this->setInterface_Create("wlan0");
    this->setInterface_Shared("eth0");

    QString absolute_path = QCoreApplication::applicationDirPath()+"/bin/wifi.sh";
    this->setPath_exec(absolute_path);
}


