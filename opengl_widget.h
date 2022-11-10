#pragma once

#include <QDebug>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector>
#include <QWheelEvent>
#include <fstream>
#include <vector>

#include "controller.h"
#include "settings.h"
class OpenGlWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit OpenGlWidget(QWidget *parent = nullptr);
  ~OpenGlWidget() {}

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 public:
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

  void initShaders();
  void initObj(vector<s21::vertex3d> vertices, int verticesCount,
               vector<int> indices, int edgesCount);

  QString getVerticesAmount() { return QString::number(verticesAmount); }
  QString getEdgesAmount() { return QString::number(edgesAmount); }
  void setMove(float x, float y, float z) {
    transforms.move_x += x;
    transforms.move_y += y;
    transforms.move_z += z;
  }

  void setScale(float x, float y, float z) {
    transforms.scale_x += x;
    transforms.scale_y += y;
    transforms.scale_z += z;
  }
  void setRotate(float x, float y, float z) {
    transforms.rotate_x += x;
    transforms.rotate_y += y;
    transforms.rotate_z += z;
  }
  s21::Settings mySettings;

 private:
  QMatrix4x4 progectionMatrix;
  QOpenGLShaderProgram program;

  QOpenGLBuffer arrayBuffer;
  QOpenGLBuffer indexBuffer;
  QVector2D mousePosition;
  QVector2D mousePositionToMove;

  struct AffineTransformations {
    float scale_x = 1.0;
    float scale_y = 1.0;
    float scale_z = 1.0;
    float move_x = 0.0;
    float move_y = 0.0;
    float move_z = 0.0;
    float rotate_x = 0.0;
    float rotate_y = 0.0;
    float rotate_z = 0.0;
    void reset() {
      move_x = move_y = move_z = rotate_x = rotate_y = rotate_z = 0;
      scale_x = scale_y = scale_z = 1;
    }
  };

  AffineTransformations transforms;
  int verticesAmount = 0;
  int edgesAmount = 0;
  bool move = false;
  double deltaExtremum = 0.0;
  int size = 0;
  struct VertexData {
    VertexData() {}
    explicit VertexData(QVector3D p) : position(p) {}
    QVector3D position;
  };
};
