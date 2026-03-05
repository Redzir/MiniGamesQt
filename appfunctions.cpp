#include "appfunctions.h"

#include <QTranslator>
#include <QLocale>
#include <QGuiApplication>

void core::setLocale(const QString &locale)
{
    QTranslator translator;
    const QString baseName = "MiniGamesQt_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
       QGuiApplication::instance()->installTranslator(&translator);
    }
}
