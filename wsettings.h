#ifndef WSETTINGS_H
#define WSETTINGS_H
#include "QString"

/**
 * @brief The WSettings class
 *
 */
class WSettings
{
public:
    WSettings();

    static QString getAPName();
    static QString setAPName(QString apname);

    static QString getAccessPoint();
    static QString setAccessPoint(QString accesspoint);

    static QString getPassword();
    static QString setPassword(QString password);
};

#endif // WSETTINGS_H
