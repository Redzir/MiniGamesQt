#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QString>
#include <QGuiApplication>
#include <QStringList>
#include <QQmlEngine>

namespace core
{
    class Launcher : public QObject
    {
        Q_OBJECT
        QML_SINGLETON
        QML_ELEMENT

        QString _currentUser = "";
        QVector<QString> _allUsers;

        Launcher();
    public:
        static Launcher& instance();
        ~Launcher();
        Q_INVOKABLE void setCurrentUser(const QString& currentUser)
        {
            _currentUser = currentUser;
        }
        Q_INVOKABLE QString getCurrentUser() const
        {
            return _currentUser;
        }
        //It creates a copy because QML doesn't work with references
        Q_INVOKABLE QStringList getAllUsers() const {
            return _allUsers;
        }
        Q_INVOKABLE void addNewUser(QString userName);

        Q_INVOKABLE void deleteUser(QString userName);

        Q_INVOKABLE bool isUserSelected() {
            return !_currentUser.trimmed().isEmpty();
        }
        Q_INVOKABLE bool hasUser(QString userName) {
            return _allUsers.contains(userName);
        }
    };
}



#endif // LAUNCHER_H
