#ifndef MODEL_H
#define MODEL_H
#include <string>

#include "obj_data.h"
namespace s21 {
class ModelFacade {
 private:
  ObjData* data;

 public:
  ModelFacade() { data = data->getInstance(); }
  void loadObj(const std::string fileName) {  // CHECK IF NOT LOAD?
    data->clearData();
    data->loadData(fileName);
  }
  vector<vertex3d> getVertices() const { return data->getVertices(); }
  vector<int> getIndices() const { return data->getIndices(); }

  int getVerticesAmount() const { return data->getVerticesAmount(); }
  int getEdgesAmount() const { return data->getEdgesAmount(); }
};

}  // namespace s21

#endif  // MODEL_H
