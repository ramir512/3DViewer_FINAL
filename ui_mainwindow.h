/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include "./opengl_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  OpenGlWidget *widget;
  QPushButton *openFile;
  QLabel *label;
  QLabel *labelFileName;
  QLabel *label_3;
  QLabel *labelVerticesCount;
  QLabel *label_5;
  QLabel *labelEdgesCount;
  QDoubleSpinBox *translateX;
  QDoubleSpinBox *translateY;
  QDoubleSpinBox *translateZ;
  QDoubleSpinBox *scaleX;
  QDoubleSpinBox *scaleY;
  QDoubleSpinBox *scaleZ;
  QSpinBox *rotateX;
  QSpinBox *rotateY;
  QSpinBox *rotateZ;
  QPushButton *translate;
  QPushButton *scale;
  QPushButton *rotate;
  QPushButton *projectionButton;
  QLabel *label_2;
  QPushButton *edgeColorButton;
  QLabel *label_4;
  QLabel *label_6;
  QSlider *horizontalSlider;
  QLabel *label_7;
  QLabel *label_8;
  QLabel *label_9;
  QLabel *label_10;
  QComboBox *pointType;
  QPushButton *pointColor;
  QSlider *pointThickness;
  QComboBox *lineType;
  QLabel *label_11;
  QPushButton *buttonBackColor;
  QLabel *label_12;
  QLabel *label_13;
  QPushButton *saveSettingsButton;
  QPushButton *pushButton_2;
  QPushButton *restoreSettingsButton;
  QPushButton *screenshotButton;
  QPushButton *GIFButton;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName("MainWindow");
    MainWindow->resize(953, 837);
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(0, 0, 127, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    QBrush brush2(QColor(0, 0, 0, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush2);
    QBrush brush3(QColor(208, 208, 208, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
    QBrush brush4(QColor(64, 65, 66, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
    QBrush brush5(QColor(46, 47, 48, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    QBrush brush6(QColor(85, 0, 255, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush6);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
    MainWindow->setPalette(palette);
    QFont font;
    font.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
    font.setPointSize(12);
    font.setBold(true);
    MainWindow->setFont(font);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    widget = new OpenGlWidget(centralwidget);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(10, 10, 600, 600));
    openFile = new QPushButton(centralwidget);
    openFile->setObjectName("openFile");
    openFile->setGeometry(QRect(830, 0, 101, 29));
    QPalette palette1;
    palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
    palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
    QBrush brush7(QColor(127, 127, 128, 255));
    brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
    palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
    openFile->setPalette(palette1);
    label = new QLabel(centralwidget);
    label->setObjectName("label");
    label->setGeometry(QRect(650, 0, 91, 20));
    label->setScaledContents(false);
    labelFileName = new QLabel(centralwidget);
    labelFileName->setObjectName("labelFileName");
    labelFileName->setGeometry(QRect(750, 60, 63, 20));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(650, 30, 91, 20));
    labelVerticesCount = new QLabel(centralwidget);
    labelVerticesCount->setObjectName("labelVerticesCount");
    labelVerticesCount->setGeometry(QRect(750, 0, 63, 20));
    label_5 = new QLabel(centralwidget);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(650, 60, 81, 20));
    labelEdgesCount = new QLabel(centralwidget);
    labelEdgesCount->setObjectName("labelEdgesCount");
    labelEdgesCount->setGeometry(QRect(750, 30, 63, 20));
    translateX = new QDoubleSpinBox(centralwidget);
    translateX->setObjectName("translateX");
    translateX->setGeometry(QRect(650, 90, 67, 29));
    translateX->setDecimals(1);
    translateX->setMinimum(-100.000000000000000);
    translateX->setMaximum(100.000000000000000);
    translateY = new QDoubleSpinBox(centralwidget);
    translateY->setObjectName("translateY");
    translateY->setGeometry(QRect(760, 90, 67, 29));
    translateY->setDecimals(1);
    translateY->setMinimum(-100.000000000000000);
    translateY->setMaximum(100.000000000000000);
    translateZ = new QDoubleSpinBox(centralwidget);
    translateZ->setObjectName("translateZ");
    translateZ->setGeometry(QRect(860, 90, 67, 29));
    translateZ->setDecimals(1);
    translateZ->setMinimum(-100.000000000000000);
    translateZ->setMaximum(100.000000000000000);
    scaleX = new QDoubleSpinBox(centralwidget);
    scaleX->setObjectName("scaleX");
    scaleX->setGeometry(QRect(650, 160, 67, 29));
    scaleX->setDecimals(1);
    scaleX->setMinimum(-100.000000000000000);
    scaleY = new QDoubleSpinBox(centralwidget);
    scaleY->setObjectName("scaleY");
    scaleY->setGeometry(QRect(760, 160, 67, 29));
    scaleY->setDecimals(1);
    scaleY->setMinimum(-100.000000000000000);
    scaleZ = new QDoubleSpinBox(centralwidget);
    scaleZ->setObjectName("scaleZ");
    scaleZ->setGeometry(QRect(860, 160, 67, 29));
    scaleZ->setDecimals(1);
    scaleZ->setMinimum(-100.000000000000000);
    rotateX = new QSpinBox(centralwidget);
    rotateX->setObjectName("rotateX");
    rotateX->setGeometry(QRect(650, 230, 48, 29));
    rotateY = new QSpinBox(centralwidget);
    rotateY->setObjectName("rotateY");
    rotateY->setGeometry(QRect(780, 230, 48, 29));
    rotateZ = new QSpinBox(centralwidget);
    rotateZ->setObjectName("rotateZ");
    rotateZ->setGeometry(QRect(880, 230, 48, 29));
    translate = new QPushButton(centralwidget);
    translate->setObjectName("translate");
    translate->setGeometry(QRect(650, 120, 281, 29));
    scale = new QPushButton(centralwidget);
    scale->setObjectName("scale");
    scale->setGeometry(QRect(650, 190, 281, 29));
    rotate = new QPushButton(centralwidget);
    rotate->setObjectName("rotate");
    rotate->setGeometry(QRect(650, 260, 281, 29));
    projectionButton = new QPushButton(centralwidget);
    projectionButton->setObjectName("projectionButton");
    projectionButton->setGeometry(QRect(650, 640, 291, 29));
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(650, 300, 281, 21));
    label_2->setAlignment(Qt::AlignCenter);
    edgeColorButton = new QPushButton(centralwidget);
    edgeColorButton->setObjectName("edgeColorButton");
    edgeColorButton->setGeometry(QRect(770, 340, 91, 29));
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(650, 340, 111, 20));
    label_6 = new QLabel(centralwidget);
    label_6->setObjectName("label_6");
    label_6->setGeometry(QRect(650, 370, 101, 20));
    horizontalSlider = new QSlider(centralwidget);
    horizontalSlider->setObjectName("horizontalSlider");
    horizontalSlider->setGeometry(QRect(770, 380, 161, 18));
    horizontalSlider->setMinimum(1);
    horizontalSlider->setMaximum(5);
    horizontalSlider->setPageStep(1);
    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalSlider->setTickPosition(QSlider::TicksBelow);
    horizontalSlider->setTickInterval(1);
    label_7 = new QLabel(centralwidget);
    label_7->setObjectName("label_7");
    label_7->setGeometry(QRect(650, 450, 281, 31));
    label_7->setAlignment(Qt::AlignCenter);
    label_8 = new QLabel(centralwidget);
    label_8->setObjectName("label_8");
    label_8->setGeometry(QRect(650, 490, 131, 20));
    label_9 = new QLabel(centralwidget);
    label_9->setObjectName("label_9");
    label_9->setGeometry(QRect(650, 520, 101, 20));
    label_10 = new QLabel(centralwidget);
    label_10->setObjectName("label_10");
    label_10->setGeometry(QRect(650, 560, 101, 20));
    pointType = new QComboBox(centralwidget);
    pointType->addItem(QString());
    pointType->addItem(QString());
    pointType->addItem(QString());
    pointType->setObjectName("pointType");
    pointType->setGeometry(QRect(770, 550, 91, 28));
    pointColor = new QPushButton(centralwidget);
    pointColor->setObjectName("pointColor");
    pointColor->setGeometry(QRect(770, 490, 91, 29));
    pointThickness = new QSlider(centralwidget);
    pointThickness->setObjectName("pointThickness");
    pointThickness->setGeometry(QRect(770, 530, 161, 20));
    pointThickness->setMinimum(1);
    pointThickness->setMaximum(10);
    pointThickness->setPageStep(1);
    pointThickness->setOrientation(Qt::Horizontal);
    pointThickness->setTickPosition(QSlider::TicksBelow);
    pointThickness->setTickInterval(1);
    lineType = new QComboBox(centralwidget);
    lineType->addItem(QString());
    lineType->addItem(QString());
    lineType->setObjectName("lineType");
    lineType->setGeometry(QRect(770, 400, 91, 28));
    label_11 = new QLabel(centralwidget);
    label_11->setObjectName("label_11");
    label_11->setGeometry(QRect(650, 410, 91, 20));
    buttonBackColor = new QPushButton(centralwidget);
    buttonBackColor->setObjectName("buttonBackColor");
    buttonBackColor->setGeometry(QRect(820, 680, 83, 29));
    label_12 = new QLabel(centralwidget);
    label_12->setObjectName("label_12");
    label_12->setGeometry(QRect(650, 600, 291, 31));
    QPalette palette2;
    palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
    palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    label_12->setPalette(palette2);
    label_12->setTextFormat(Qt::RichText);
    label_12->setAlignment(Qt::AlignCenter);
    label_13 = new QLabel(centralwidget);
    label_13->setObjectName("label_13");
    label_13->setGeometry(QRect(650, 680, 151, 20));
    saveSettingsButton = new QPushButton(centralwidget);
    saveSettingsButton->setObjectName("saveSettingsButton");
    saveSettingsButton->setGeometry(QRect(250, 640, 171, 29));
    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setObjectName("pushButton_2");
    pushButton_2->setGeometry(QRect(440, 640, 171, 29));
    restoreSettingsButton = new QPushButton(centralwidget);
    restoreSettingsButton->setObjectName("restoreSettingsButton");
    restoreSettingsButton->setGeometry(QRect(10, 640, 221, 29));
    screenshotButton = new QPushButton(centralwidget);
    screenshotButton->setObjectName("screenshotButton");
    screenshotButton->setGeometry(QRect(150, 680, 111, 81));
    GIFButton = new QPushButton(centralwidget);
    GIFButton->setObjectName("GIFButton");
    GIFButton->setGeometry(QRect(280, 680, 121, 81));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 953, 32));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName("statusbar");
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "3DViewer", nullptr));
    openFile->setText(
        QCoreApplication::translate("MainWindow", "Open file", nullptr));
    label->setText(
        QCoreApplication::translate("MainWindow", "Filename:", nullptr));
    labelFileName->setText(QString());
    label_3->setText(
        QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
    labelVerticesCount->setText(QString());
    label_5->setText(
        QCoreApplication::translate("MainWindow", "Edges:", nullptr));
    labelEdgesCount->setText(QString());
    translate->setText(
        QCoreApplication::translate("MainWindow", "Translate", nullptr));
    scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
    rotate->setText(
        QCoreApplication::translate("MainWindow", "Rotate", nullptr));
    projectionButton->setText(QCoreApplication::translate(
        "MainWindow", "Switch to orthogonal projection", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "Edges settings", nullptr));
    edgeColorButton->setText(
        QCoreApplication::translate("MainWindow", "Choose", nullptr));
    label_4->setText(
        QCoreApplication::translate("MainWindow", "Edge color", nullptr));
    label_6->setText(
        QCoreApplication::translate("MainWindow", "Thickness", nullptr));
    label_7->setText(QCoreApplication::translate("MainWindow",
                                                 "Vertices settings", nullptr));
    label_8->setText(
        QCoreApplication::translate("MainWindow", "Vertix color", nullptr));
    label_9->setText(
        QCoreApplication::translate("MainWindow", "Thickness", nullptr));
    label_10->setText(
        QCoreApplication::translate("MainWindow", "Type", nullptr));
    pointType->setItemText(
        0, QCoreApplication::translate("MainWindow", "NONE", nullptr));
    pointType->setItemText(
        1, QCoreApplication::translate("MainWindow", "CIRCLE", nullptr));
    pointType->setItemText(
        2, QCoreApplication::translate("MainWindow", "SQUARE", nullptr));

    pointColor->setText(
        QCoreApplication::translate("MainWindow", "Choose", nullptr));
    lineType->setItemText(
        0, QCoreApplication::translate("MainWindow", "SOLID", nullptr));
    lineType->setItemText(
        1, QCoreApplication::translate("MainWindow", "DASHED", nullptr));

    label_11->setText(
        QCoreApplication::translate("MainWindow", "Type", nullptr));
    buttonBackColor->setText(
        QCoreApplication::translate("MainWindow", "Choose", nullptr));
    label_12->setText(
        QCoreApplication::translate("MainWindow", "Main settings", nullptr));
    label_13->setText(
        QCoreApplication::translate("MainWindow", "Background color", nullptr));
    saveSettingsButton->setText(QCoreApplication::translate(
        "MainWindow", "Save user settings", nullptr));
    pushButton_2->setText(QCoreApplication::translate(
        "MainWindow", "Load user settings", nullptr));
    restoreSettingsButton->setText(QCoreApplication::translate(
        "MainWindow", "Restore default settings", nullptr));
    screenshotButton->setText(
        QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
    GIFButton->setText(
        QCoreApplication::translate("MainWindow", "GIF", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
