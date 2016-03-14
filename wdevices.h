#ifndef WDEVICES_H
#define WDEVICES_H
#include <QStringList>
#include <QProcess>
#include <QMessageBox>

class WDevices
{
public:
    WDevices();
    QStringList getDevicesList();
};

#endif // WDEVICES_H
