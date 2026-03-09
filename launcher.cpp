#include "launcher.h"

#include <memory>


#include <QFile>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QDir>

#include "appfunctions.h"

namespace {
    const QString CONFIG_FILE_NAME = "config.ini";
}

core::Launcher::Launcher()
{
    setLocale(QLocale::system().name());

    QDir().mkpath("users");
    QDir dir("users");
    for (const QString& dir : dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        _allUsers.append(dir);
    }

    QFile configFile(CONFIG_FILE_NAME);
    if (configFile.open(QIODevice::ReadWrite)){
        QTextStream stream(&configFile);
        QRegularExpression re("^(?<param>\\w+)\\s*[=]+\\s*(?<value>.+)$");
        QRegularExpressionMatch match;

        while(!stream.atEnd()){
            QString line = stream.readLine();
            match = re.match(line);
            QString param = match.captured("param");
            QString value = match.captured("value");

            if (param=="current_user") {
                _currentUser = value;
            }
            else if (param=="locale") {
                setLocale(value);
            }
        }
    }
    if (_allUsers.isEmpty()){
        _currentUser = "";
    }
    else if (!isUserSelected()){
        _currentUser = _allUsers[0];
    }
}

core::Launcher &core::Launcher::instance()
{
    static Launcher self;
    return self;
}

core::Launcher::~Launcher()
{
    QFile configFile(CONFIG_FILE_NAME);
    if (!configFile.open(QIODevice::WriteOnly)){
        configFile.open(QIODevice::Append);
    }
    QTextStream out(&configFile);
    out << "current_user = " << _currentUser << '\n';
}

void core::Launcher::addNewUser(QString userName)
{
    _allUsers.append(userName);
    QDir().mkpath("users/"+userName);
}

void core::Launcher::deleteUser(QString userName)
{
    _allUsers.erase(_allUsers.begin()+_allUsers.indexOf(userName));
    if (_currentUser==userName) {
        _currentUser="";
    }
    QDir().rmdir("users/"+userName);
}




