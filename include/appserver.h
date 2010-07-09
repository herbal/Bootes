#ifndef APPSERVER_H
#define APPSERVER_H

#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>

namespace herbal {

class AppServer : public QObject {
  Q_OBJECT

  QString applicationID;
  QString socketName;

  QLocalServer* appServer;
  //FileLock* fileLock;

public:
  QString applicationID() const { return applicationID; }

};

} //namespace herbal

#endif // APPSERVER_H
