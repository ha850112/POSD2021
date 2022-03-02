#include "iostream"
#include "../src/rectangle.h"
using namespace std;

TEST(Rectangle, TestRectangle){
  Rectangle rectangle(3.14, 4);
  ASSERT_NEAR(12.56, rectangle.area(),0.01);
  ASSERT_NEAR(14.28, rectangle.perimeter(),0.01);
  ASSERT_EQ("Rectangle (3.14 4.00)", rectangle.info());
}

TEST(Rectangle, TestRectanglefail){
  try {
    Rectangle(0, 1);
  }catch(std::string e) {
      ASSERT_EQ("This is not a rectangle!", e);
  }
  ASSERT_NO_THROW(Rectangle(1, 1));
}