#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "controller.h"
#include "qgifimage.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *myController, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  void on_openFile_clicked();

  void on_translate_clicked();

  void on_scale_clicked();

  void on_rotate_clicked();

  void on_projectionButton_clicked();

  void on_edgeColorButton_clicked();

  void on_horizontalSlider_valueChanged(int value);

  void on_pointType_currentTextChanged(const QString &arg1);

  void on_pointColor_clicked();

  void on_pointThickness_valueChanged(int value);

  void on_lineType_currentTextChanged(const QString &arg1);

  void on_buttonBackColor_clicked();

  void on_restoreSettingsButton_clicked();

  void on_saveSettingsButton_clicked();

  void on_pushButton_2_clicked();

  void on_screenshotButton_clicked();

  void on_GIFButton_clicked();

 private:
  void onTimeOut();
  Ui::MainWindow *ui;
  s21::Controller *controller;
  QTimer *timer;
  QGifImage *Gif;
  int gifCount;
};
#endif  // MAINWINDOW_H
