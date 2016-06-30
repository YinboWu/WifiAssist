#ifndef WSETTINGS_H
#define WSETTINGS_H
#include "QString"
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QCoreApplication>
/**
 * @brief The WSettings class
 *
 */
class WSettings
{
public:
    WSettings();
    ~WSettings();

    QSettings *m_settings;

    QString _path_exec;
    QString _APName;
    QString _Password;
    QString _Interface_Create;
    QString _Interface_Shared;
    QString _AccessPoint;

    QString path_exec() const;
    void setPath_exec(const QString &path_exec);
    QString APName() const;
    void setAPName(const QString &APName);
    QString Password() const;
    void setPassword(const QString &Password);
    QString Interface_Create() const;
    void setInterface_Create(const QString &Interface_Create);
    QString Interface_Shared() const;
    void setInterface_Shared(const QString &Interface_Shared);
    QString AccessPoint() const;
    void setAccessPoint(const QString &AccessPoint);

    void setSettings(const QString &name,const QString &value);
    QString getSettings(const QString&name) const;

    void checkConfigFile();
    void setDefaultConfig();
};

#endif // WSETTINGS_H
