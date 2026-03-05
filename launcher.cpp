#include "launcher.h"

#include "appfunctions.h"

namespace {
    const QString DEFAULT_LOCALE = "ru_RU";
}

core::Launcher::Launcher()
    :_user("")
{}

core::Launcher &core::Launcher::instance()
{
    static Launcher self;
    return self;
}

void core::Launcher::init()
{
    setLocale(DEFAULT_LOCALE);
}




