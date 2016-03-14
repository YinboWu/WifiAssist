#include "wdevices.h"

WDevices::WDevices()
{

}

QStringList WDevices::getDevicesList()
{
    QProcess pingProcess;
    QString exe = "arp";
    pingProcess.start(exe);
    pingProcess.waitForFinished();
    QString output(pingProcess.readAll());


     QMessageBox::warning(NULL,"Warning",output.trimmed());
}

