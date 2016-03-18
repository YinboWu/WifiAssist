#include "wdevices.h"
#include <QString>
#include <QStringList>
#include <QProcess>
WDevices::WDevices()
{

}

QString WDevices::getDevicesList()
{
    QStringList args = QStringList() <<_path_exec<<"--all-sta";
    if(!QProcess::startDetached("pkexec",args))
   {
        return "";
    }
    else
    {
        return "";
    }
}

