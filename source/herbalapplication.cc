#include "herbalapplication.h"

#include <QtGui/QWidget>
#include <QtGui/QFileOpenEvent>

namespace herbal {

HerbalApplication::HerbalApplication(int& argc, char** argv) : QApplication(argc, argv) {

}

HerbalApplication::HerbalApplication(int &argc, char **argv, const QString &id) : QApplication() {

}

bool HerbalApplication::initialize() {

  return true;
}

}
