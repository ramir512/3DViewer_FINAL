#include "opengl_widget.h"

#include <QDebug>

#include "model.h"
#include "obj_data.h"
OpenGlWidget::OpenGlWidget(QWidget *parent)
    : QOpenGLWidget(parent), indexBuffer(QOpenGLBuffer::IndexBuffer) {}

void OpenGlWidget::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  initShaders();
}

void OpenGlWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  float aspect = w / (float)h;
  progectionMatrix.setToIdentity();
}

void OpenGlWidget::paintGL() {
  QColor bgcolor = mySettings.backgroundColor;  // SETTINGS COLOR
  glClearColor(bgcolor.redF(), bgcolor.greenF(), bgcolor.blueF(),
               bgcolor.alphaF());
  qDebug() << bgcolor.redF() << '\n' << bgcolor.blueF();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  QMatrix4x4 MVPmatrix;
  MVPmatrix.setToIdentity();
  MVPmatrix.translate(transforms.move_x, transforms.move_y, transforms.move_z);
  if (mySettings.projectionType) {  // SETTINGS PROJECTION
    progectionMatrix.setToIdentity();
    progectionMatrix.ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 100.0f);
  } else {
    progectionMatrix.setToIdentity();
    float aspect = 1.0;
    progectionMatrix.perspective(45, aspect, 0.1, 1000.0);
    MVPmatrix.translate(0, 0, -2);
    // MVPmatrix.perspective(45, aspect, 0.01, 10000.0);
  }
  QQuaternion rotation;
  rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.0, 1.0, 0.0),
                                           transforms.rotate_x) *
             rotation;
  rotation = QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0),
                                           transforms.rotate_y) *
             rotation;
  rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.0, 1.0),
                                           transforms.rotate_z) *
             rotation;
  MVPmatrix.rotate(rotation);
  MVPmatrix.scale(transforms.scale_x, transforms.scale_y, transforms.scale_z);
  program.bind();
  program.setUniformValue("qt_ModelViewProjectionMatrix",
                          progectionMatrix * MVPmatrix);
  arrayBuffer.bind();
  int vertLoc = program.attributeLocation("qt_Vertex");
  program.enableAttributeArray(vertLoc);
  program.setAttributeBuffer(vertLoc, GL_FLOAT, 0, 3, sizeof(VertexData));
  indexBuffer.bind();
  QColor edgecolor = mySettings.edgeColor;  // SETTINGS EDGE COLOR
  float edgesColor[4] = {edgecolor.redF(), edgecolor.greenF(),
                         edgecolor.blueF(), edgecolor.alphaF()};
  program.setUniformValueArray(program.uniformLocation("color"), edgesColor, 1,
                               4);
  glLineWidth(mySettings.thickness);   // SETTINGS LINE WIDTH
  int lineType = mySettings.lineType;  // SETTINGS LINE TYPE
  if (lineType == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  } else if (lineType == 0) {
    glDisable(GL_LINE_STIPPLE);
  }
  glDrawElements(GL_LINES, size, GL_UNSIGNED_INT, 0);  // COUNT VERTICES

  int pointType = mySettings.pointType;  // POINT TYPE SETTIGNS
  if (pointType != 0) {
    QColor vertexcolor = mySettings.pointColor;  // VERTEX COLOR SETTINGS
    float vertexColor[4] = {vertexcolor.redF(), vertexcolor.greenF(),
                            vertexcolor.blueF(), vertexcolor.alphaF()};
    program.setUniformValueArray(program.uniformLocation("color"), vertexColor,
                                 1, 4);
    glPointSize(mySettings.pointThickness);  // SETTINGS POINT SIZE
    if (pointType == 1) {
      glDisable(GL_TRIANGLE_STRIP);
      glEnable(GL_POINT_SMOOTH);
    } else if (pointType == 2) {
      glDisable(GL_POINT_SMOOTH);
      glEnable(GL_TRIANGLE_STRIP);
    }
    glDrawArrays(GL_POINTS, 0, indexBuffer.size());
  }
}

void OpenGlWidget::mouseMoveEvent(QMouseEvent *event) {
  if (!move) {
    float delta_x, delta_y;
    delta_x = event->pos().x() - mousePositionToMove.x();
    delta_y = event->pos().y() - mousePositionToMove.y();
    mousePositionToMove = QVector2D(event->pos());
    transforms.rotate_x += delta_x;
    transforms.rotate_y += delta_y;
  } else {
    float delta_x, delta_y;
    delta_x = event->pos().x() - mousePositionToMove.x();
    delta_y = event->pos().y() - mousePositionToMove.y();
    mousePositionToMove = QVector2D(event->pos());
    transforms.move_x += delta_x / 1000;
    transforms.move_y += delta_y / -1000;
  }
  update();
}

void OpenGlWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    mousePositionToMove = QVector2D(event->pos());
    move = true;
  } else {
    mousePositionToMove = QVector2D(event->pos());
    move = false;
  }
  event->accept();
}

void OpenGlWidget::wheelEvent(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    transforms.move_z += 0.1;
  } else {
    transforms.move_z -= 0.1;
  }
  update();
}

void OpenGlWidget::initShaders() {
  if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                       ":/Resources/vshader.vsh"))
    close();
  if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                       ":/Resources/fshader.fsh"))
    close();
  if (!program.link()) close();
}

void OpenGlWidget::initObj(vector<s21::vertex3d> vertices, int verticesCount,
                           vector<int> indices, int edgesCount) {
  QVector<VertexData> vertexes;
  QVector<GLuint> indexes;
  transforms.reset();
  verticesAmount = verticesCount;
  edgesAmount = edgesCount;
  for (int i = 0; i < vertices.size(); i++) {
    VertexData position(QVector3D(vertices[i].x, vertices[i].y, vertices[i].z));
    vertexes.push_back(position);
  }
  for (int i = 0; i < indices.size(); i++) {
    indexes.push_back(indices[i] - 1);
  }
  size = indexes.size();
  qDebug() << size;
  arrayBuffer.create();
  arrayBuffer.bind();
  arrayBuffer.allocate(vertexes.constData(),
                       vertexes.size() * sizeof(VertexData));
  arrayBuffer.release();

  indexBuffer.create();
  indexBuffer.bind();
  indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
  indexBuffer.release();
}
