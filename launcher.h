#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QString>
#include <QGuiApplication>
#include <memory>

namespace core
{
    class Launcher
    {
        QString _user;

        Launcher();
    public:
        static Launcher& instance();
        void init();
        void setUser(const QString& user)
        {
            _user = user;
        }
        QString getUser() const
        {
            return _user;
        }
    };


}



#endif // LAUNCHER_H
