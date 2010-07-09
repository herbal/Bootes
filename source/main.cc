#include "herbalapplication.h"

#include <QtCore/QTranslator>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkProxyFactory>

#ifdef Q_OS_MAC
#  define SHARE_PATH "/../Resources"
#else
#  define SHARE_PATH "/../share/bootes"
#endif

int main(int argc, char *argv[])
{
  herbal::HerbalApplication herbalApp(argc, argv, (QLatin1String("Application Name")));

  QTranslator translator;
  QTranslator qtTranslator;

  // Must be done before any QSettings class is created
  QSettings::setPath(QSettings::IniFormat, QSettings::SystemScope,
                     QCoreApplication::applicationDirPath()+QLatin1String(SHARE_PATH));

  // Work around bug in QSettings which gets triggered on Windows & Mac only
#if defined(Q_OS_MAC)
  QSettings::setPath(QSettings::IniFormat, QSettings::UserScope,
                     QDir::homePath()+"/.config");
#endif
#if defined(Q_OS_WIN)
  QSettings::setPath(QSettings::IniFormat, QSettings::UserScope,
                     qgetenv("appdata"));
#endif

  const QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                           QLatin1String("Herbal Software"), QLatin1String("Bootes"));



  // Make sure we honor the system's proxy settings
  QNetworkProxyFactory::setUseSystemConfiguration(true);

  return herbalApp.exec();
}
