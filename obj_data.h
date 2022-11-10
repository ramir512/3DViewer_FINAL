#ifndef OBJ_DATA_H
#define OBJ_DATA_H

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
namespace s21 {
struct vertex3d {
  float x;
  float y;
  float z;
};
class ObjData {
  vector<vertex3d> vertices;
  vector<float> minmaxvals;
  vector<int> indices;
  static ObjData* instance;
  int verticesAmount;
  int edgesAmount;

 protected:
  ObjData() {
    minmaxvals.push_back(std::numeric_limits<float>::max());
    minmaxvals.push_back(std::numeric_limits<float>::min());
    verticesAmount = 0;
    edgesAmount = 0;
  }
  ObjData(const ObjData& root) = delete;
  ObjData& operator=(const ObjData&) = delete;
  ~ObjData() { delete instance; }

 public:
  static ObjData* getInstance() {
    if (!instance) {
      instance = new ObjData();
    }
    return instance;
  }
  vector<int>& getIndices() { return this->indices; }
  vector<vertex3d>& getVertices() { return this->vertices; }
  void clearData() {
    vertices.clear();
    indices.clear();
    minmaxvals.clear();
    minmaxvals.push_back(std::numeric_limits<float>::max());
    minmaxvals.push_back(std::numeric_limits<float>::min());
    verticesAmount = 0;
    edgesAmount = 0;
  }
  void loadData(const std::string filename) {
    std::ifstream ifile(filename);
    std::string fdata;
    while (ifile.good()) {
      fdata.push_back(ifile.get());
    }
    ifile.close();
    initData(fdata);
    normalizeData();
    verticesAmount = vertices.size();
    edgesAmount = indices.size() / 4;
  }
  void initData(const std::string& fdata) {
    std::string line;
    for (int i = 0; i < fdata.size(); i++) {
      line.push_back(fdata.at(i));
      if (fdata.at(i) == '\n') {
        parse_line(line);
        line.clear();
      }
    }
  }
  int getVerticesAmount() { return verticesAmount; }
  int getEdgesAmount() { return edgesAmount; }

  void parse_line(const std::string line) {
    vertex3d curr_c;
    for (int i = 0; i < line.size(); i++) {
      if (line.at(0) == 'v' && line.at(1) == ' ') {
        i += 2;
        while (line.at(i) == ' ') {
          i++;
        }
        char crd[16];
        crd[15] = '\n';
        for (int p = 0; p < 15; p++) {
          crd[p] = 0;
        }
        for (int j = 0; j < 15; j++, i++) {  // coord x
          crd[j] = line.at(i);
          if (line.at(i) == ' ') {
            i++;
            curr_c.x = atof(crd);
            for (int p = 0; p < 15; p++) {
              crd[p] = 0;
            }
            break;
          }
        }
        for (int j = 0; j < 15; j++, i++) {  // coord y
          crd[j] = line.at(i);
          if (line.at(i) == ' ') {
            i++;
            curr_c.y = atof(crd);
            for (int p = 0; p < 15; p++) {
              crd[p] = 0;
            }
            break;
          }
        }
        for (int j = 0; j < 15; j++, i++) {  // corrd z
          crd[j] = line.at(i);
          if (line.at(i) == ' ' || line.at(i) == '\n') {
            curr_c.z = atof(crd);
            for (int p = 0; p < 15; p++) {
              crd[p] = 0;
            }
            break;
          }
        }
        minmaxvals[0] = std::min(minmaxvals[0], curr_c.x);
        minmaxvals[1] = std::max(minmaxvals[1], curr_c.x);
        minmaxvals[0] = std::min(minmaxvals[0], curr_c.y);
        minmaxvals[1] = std::max(minmaxvals[1], curr_c.y);
        minmaxvals[0] = std::min(minmaxvals[0], curr_c.z);
        minmaxvals[1] = std::max(minmaxvals[1], curr_c.z);

        vertices.push_back(curr_c);
        return;
      } else if (line.at(0) == 'f' && line.at(1) == ' ') {
        vector<int> indices_c;
        i += 1;
        while (line.at(i) != '\n') {
          i++;
          char crd[16];
          for (int p = 0; p < 15; p++) {
            crd[p] = 0;
          }
          crd[15] = '\n';
          for (int j = 0; j <= 15; j++, i++) {
            if (line.at(i) == ' ' || line.at(i) == '\n') {
              if (indices_c.size() != 0 && indices_c.size() % 2 == 0) {
                indices_c.push_back(indices_c.back());
              }
              indices_c.push_back(atoi(crd));
              for (int p = 0; p < 15; p++) {
                crd[p] = 0;
              }
              break;
            }
            if (line.at(i) == '/') {
              if (indices_c.size() != 0 && indices_c.size() % 2 == 0) {
                indices_c.push_back(indices_c.back());
              }
              indices_c.push_back(atoi(crd));
              while (true) {
                i++;
                if (line.at(i) == ' ' || line.at(i) == '\n') {
                  break;
                }
              }
              break;
            }
            crd[j] = line.at(i);
          }
        }
        indices_c.push_back(indices_c.back());
        indices_c.push_back(indices_c.front());
        indices.insert(indices.end(), indices_c.begin(), indices_c.end());
      }
    }
  }
  void display() {
    for (auto i : vertices) {
      cout << i.x << ' ' << i.y << ' ' << i.z << endl;
    }
    for (auto i : indices) {
      cout << i << endl;
    }
  }
  void normalizeData() {
    float factor = fmax(fabs(minmaxvals[0]), fabs(minmaxvals[1])) * 1.2;
    for (int i = 0; i < vertices.size(); i++) {
      vertices[i].x /= factor;
      vertices[i].y /= factor;
      vertices[i].z /= factor;
    }
  }
};
}  // namespace s21

#endif
