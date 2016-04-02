#include "myqlcd.h"
#include "myqlcdplugin.h"

#include <QtPlugin>

MyQlcdPlugin::MyQlcdPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MyQlcdPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MyQlcdPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MyQlcdPlugin::createWidget(QWidget *parent)
{
    return new MyQlcd(parent);
}

QString MyQlcdPlugin::name() const
{
    return QLatin1String("MyQlcd");
}

QString MyQlcdPlugin::group() const
{
    return QLatin1String("");
}

QIcon MyQlcdPlugin::icon() const
{
    return QIcon();
}

QString MyQlcdPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MyQlcdPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MyQlcdPlugin::isContainer() const
{
    return false;
}

QString MyQlcdPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MyQlcd\" name=\"myQlcd\">\n</widget>\n");
}

QString MyQlcdPlugin::includeFile() const
{
    return QLatin1String("myqlcd.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(myqlcdplugin, MyQlcdPlugin)
#endif // QT_VERSION < 0x050000
