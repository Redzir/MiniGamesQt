#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>

#include "launcher.h"

int main(int argc, char *argv[]){
    using namespace core;

    QGuiApplication app = QGuiApplication(argc,argv);

    Launcher& launcher = Launcher::instance();

    QQmlApplicationEngine engine;
    launcher.setParent(&engine);

    qmlRegisterSingletonInstance("com.launcher",1,0,"Launcher",&launcher);

    const QUrl url(u"qrc:/MiniGamesQt/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
