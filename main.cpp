#include <QApplication>

#include "View.h"
#include "controller.h"
#include "model.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::ModelFacade model;
  s21::Controller controller(&model);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}

// 1. MVC + facade. model includes settings and data.
