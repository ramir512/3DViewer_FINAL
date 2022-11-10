#include <gtest/gtest.h>
#include "model.h"

using namespace s21;

TEST(Smartcalc, Model) {

  ModelFacade model;
  model.loadObj("Obj_files/cow.obj");
  EXPECT_EQ(model.getVerticesAmount(), 4583);
  EXPECT_EQ(model.getEdgesAmount(), 8706);

}

TEST(Smartcalc, Model2) {

ModelFacade model;
model.loadObj("Obj_files/ak47.obj");
EXPECT_EQ(model.getVerticesAmount(), 8859);
EXPECT_EQ(model.getEdgesAmount(), 24000);

}

TEST(Smartcalc, Model3) {

ModelFacade model;
model.loadObj("Obj_files/alf.obj");
EXPECT_EQ(model.getVerticesAmount(), 3618);
EXPECT_EQ(model.getEdgesAmount(), 7018);

}

TEST(Smartcalc, Model4) {

ModelFacade model;
model.loadObj("Obj_files/bottle.obj");
EXPECT_EQ(model.getVerticesAmount(), 26105);
EXPECT_EQ(model.getEdgesAmount(), 65480);

}

TEST(Smartcalc, Model5) {

ModelFacade model;
model.loadObj("Obj_files/cooper.obj");
EXPECT_EQ(model.getVerticesAmount(), 18447);
EXPECT_EQ(model.getEdgesAmount(), 38422);

}

TEST(Smartcalc, Model6) {

ModelFacade model;
model.loadObj("Obj_files/dragon.obj");
EXPECT_EQ(model.getVerticesAmount(), 64656);
EXPECT_EQ(model.getEdgesAmount(), 194035);

}

TEST(Smartcalc, Model7) {

ModelFacade model;
model.loadObj("Obj_files/domik.obj");
EXPECT_EQ(model.getVerticesAmount(), 219693);
EXPECT_EQ(model.getEdgesAmount(), 438869);

}

TEST(Smartcalc, Model8) {

ModelFacade model;
model.loadObj("Obj_files/naruto.obj");
EXPECT_EQ(model.getVerticesAmount(), 48419);
EXPECT_EQ(model.getEdgesAmount(), 147146);

}

TEST(Smartcalc, Model9) {

ModelFacade model;
model.loadObj("Obj_files/frog.obj");
EXPECT_EQ(model.getVerticesAmount(), 48882);
EXPECT_EQ(model.getEdgesAmount(), 146640);

}

TEST(Smartcalc, Model10) {

ModelFacade model;
model.loadObj("Obj_files/teddy.obj");
EXPECT_EQ(model.getVerticesAmount(), 1598);
EXPECT_EQ(model.getEdgesAmount(), 4788);

}
