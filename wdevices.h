#ifndef WDEVICES_H
#define WDEVICES_H
#include <QStringList>
#include <QProcess>
#include <QMessageBox>

class WDevices
{
public:
    WDevices();
    QString getDevicesList();

    QString _path_exec;
    QString _APName;
    QString _Password;
    QString _Interface_Create;
    QString _Interface_Shared;
    QString _AccessPoint;
};

#endif // WDEVICES_H
