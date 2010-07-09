#include <QtGui/QApplication>

namespace herbal {

class HerbalApplication : public QApplication {
  Q_OBJECT

  bool applicationRunning;

public:

  HerbalApplication(int& argc, char** argv);
  HerbalApplication(int& argc, char** argv, std::string windowTitle);
  HerbalApplication(int& argc, char** argv, const QString& id);
  HerbalApplication(int& argc, char** argv, Type type);

  bool initialize();
  bool isApplicationRunning() { return applicationRunning; }

  QString applicationID() const { return connectionPeer->applicationId(); }
};


}//namespace Herbal
