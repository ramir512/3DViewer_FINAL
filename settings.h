#ifndef SETTINGS_H
#define SETTINGS_H
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QVector>
#include <fstream>

namespace s21 {
struct Settings {
  std::string const configfile = "./settings.conf";
  bool projectionType = false;  // false - orthogonal; true - perspective.
  QColor edgeColor = {242, 255, 50};
  GLfloat thickness = 1.0f;
  int pointType = 0;
  int pointThickness = 0;
  QColor pointColor = {0, 0, 0};
  int lineType = 0;
  QColor backgroundColor = {18, 18, 18};
  void setDefault() {
    projectionType = false;  // false - orthogonal; true - perspective.
    edgeColor = {242, 255, 50};
    thickness = 1.0f;
    pointType = 0;
    pointThickness = 0;
    pointColor = {200, 200, 200};
    lineType = 0;
    backgroundColor = {18, 18, 18};
  }
  void saveUserSettings() {
    std::ofstream file(configfile, std::ios::out);
    file << projectionType << '\n';
    file << edgeColor.redF() << ' ' << edgeColor.greenF() << ' '
         << edgeColor.blueF() << ' ' << edgeColor.alphaF() << '\n';
    file << pointType << '\n';
    file << pointThickness << '\n';
    file << pointColor.redF() << ' ' << pointColor.greenF() << ' '
         << pointColor.blueF() << ' ' << pointColor.alphaF() << '\n';
    file << lineType << '\n';
    file << backgroundColor.redF() << ' ' << backgroundColor.greenF() << ' '
         << backgroundColor.blueF() << ' ' << backgroundColor.alphaF() << '\n';

    file.close();
  }
  void loadUserSettings() {
    std::ifstream in(configfile, std::ios::in);
    in >> projectionType;
    float cR, cG, cB, cA;
    in >> cR >> cG >> cB >> cA;
    edgeColor = QColor(cR * 255, cG * 255, cB * 255, cA * 255);
    in >> thickness;
    in >> pointType;
    in >> pointThickness;
    in >> cR >> cG >> cB >> cA;
    pointColor = QColor(cR * 255, cG * 255, cB * 255, cA * 255);
    in >> lineType;
    in >> cR >> cG >> cB >> cA;
    backgroundColor = QColor(cR * 255, cG * 255, cB * 255, cA * 255);
    in.close();
  }
};
}  // namespace s21
#endif  // SETTINGS_H
