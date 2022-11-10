#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

namespace s21 {
class Controller {
 private:
  ModelFacade* model;

 public:
  Controller(ModelFacade* m) : model(m) {}
  void loadObj(const std::string fileName) { model->loadObj(fileName); }
  vector<vertex3d> getVertices() { return model->getVertices(); }
  vector<int> getIndices() const { return model->getIndices(); }

  int getVerticesAmount() const { return model->getVerticesAmount(); }
  int getEdgesAmount() const { return model->getEdgesAmount(); }
};
}  // namespace s21

#endif  // CONTROLLER_H
