#include "View.h"

#include <time.h>

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include "./ui_mainwindow.h"
MainWindow::MainWindow(s21::Controller *myController, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->label_2->setStyleSheet("background-color: red");
  ui->label_7->setStyleSheet("background-color: red");
  ui->label_12->setStyleSheet("background-color: red");
  controller = myController;
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_openFile_clicked() {
  QString path;
  path = QFileDialog::getOpenFileName(this, "Open File", "/Objects/", "*.obj");
  if (path == nullptr) {
    return;
  }
  std::string filePath = path.toStdString();
  controller->loadObj(filePath);

  vector<s21::vertex3d> vertices = controller->getVertices();
  vector<int> indices = controller->getIndices();
  int verticesAmount = controller->getVerticesAmount();
  int edgesAmount = controller->getEdgesAmount();

  ui->widget->initObj(vertices, verticesAmount, indices, edgesAmount);
  QFileInfo fileinfo(path);
  QString filename = fileinfo.fileName();
  ui->labelFileName->setText(filename);
  ui->labelVerticesCount->setText(ui->widget->getVerticesAmount());
  ui->labelEdgesCount->setText(ui->widget->getEdgesAmount());
  ui->widget->update();
}

void MainWindow::on_translate_clicked() {
  ui->widget->setMove(ui->translateX->text().toDouble() / 100.0,
                      ui->translateY->text().toDouble() / 100.0,
                      ui->translateZ->text().toDouble() / 100.0);
  ui->widget->update();
}

void MainWindow::on_scale_clicked() {
  ui->widget->setScale(ui->scaleX->text().toDouble() / 100.0,
                       ui->scaleY->text().toDouble() / 100.0,
                       ui->scaleZ->text().toDouble() / 100.0);
  ui->widget->update();
}

void MainWindow::on_rotate_clicked() {
  ui->widget->setRotate(ui->rotateX->text().toDouble(),
                        ui->rotateY->text().toDouble(),
                        ui->rotateZ->text().toDouble());
  ui->widget->update();
}

void MainWindow::on_projectionButton_clicked() {
  if (ui->widget->mySettings.projectionType == true) {
    ui->widget->mySettings.projectionType = false;
    ui->projectionButton->setText("Switch to orthogonal projection");
  } else {
    ui->widget->mySettings.projectionType = true;
    ui->projectionButton->setText("Switch to perspective projection");
  }
  ui->widget->update();
}

void MainWindow::on_edgeColorButton_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    ui->widget->mySettings.edgeColor = color;
    ui->widget->update();
  }
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
  ui->widget->mySettings.thickness = ui->horizontalSlider->value();
  ui->widget->update();
}

void MainWindow::on_pointType_currentTextChanged(const QString &arg1) {
  ui->widget->mySettings.pointType = ui->pointType->currentIndex();
  ui->widget->update();
}

void MainWindow::on_pointColor_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    ui->widget->mySettings.pointColor = color;
    ui->widget->update();
  }
}

void MainWindow::on_pointThickness_valueChanged(int value) {
  ui->widget->mySettings.pointThickness = ui->pointThickness->value();
  ui->widget->update();
}

void MainWindow::on_lineType_currentTextChanged(const QString &arg1) {
  ui->widget->mySettings.lineType = ui->lineType->currentIndex();
  ui->widget->update();
}

void MainWindow::on_buttonBackColor_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    ui->widget->mySettings.backgroundColor = color;
    ui->widget->update();
  }
}

void MainWindow::on_restoreSettingsButton_clicked() {
  ui->widget->mySettings.setDefault();
  qDebug() << "set default";
  ui->widget->update();
}

void MainWindow::on_saveSettingsButton_clicked() {
  ui->widget->mySettings.saveUserSettings();
  ui->widget->update();
}

void MainWindow::on_pushButton_2_clicked() {
  ui->widget->mySettings.loadUserSettings();
  ui->widget->update();
}

void MainWindow::on_screenshotButton_clicked() {
  QPixmap screen = ui->widget->grab();
  QString screenFileName = QFileDialog::getSaveFileName(
      this, "Save image", "./Screenshots", ".jpeg");
  if (!screenFileName.isEmpty() && !screenFileName.isNull()) {
    screen.save(screenFileName + ".jpeg");
  }
}

void MainWindow::on_GIFButton_clicked() {
  gifCount = 0;
  timer = new QTimer;
  connect(timer, &QTimer::timeout, this, &MainWindow::onTimeOut);
  timer->start(100);
  Gif = new QGifImage;
  Gif->setDefaultDelay(10);
}

void MainWindow::onTimeOut() {
  if (gifCount < 50) {
    QImage screen = ui->widget->grabFramebuffer();
    //        QImage screen2 = screen.scaled(640, 480, Qt::KeepAspectRatio);
    Gif->addFrame(screen);
    gifCount++;
  } else {
    timer->stop();
    QMessageBox::information(
        NULL, QObject::tr("Информация"),
        "GIF file was successfully written\nNow you can save it");
    QString screenFileName = QFileDialog::getSaveFileName(
        this, "Save GIF", "./Gif/object.gif", ".gif");
    Gif->save(screenFileName);
    gifCount = 0;
  }
}
