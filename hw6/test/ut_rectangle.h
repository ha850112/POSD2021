#include "iostream"
#include "../src/rectangle.h"

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

TEST(Rectangle,addshape){
   Rectangle r(1.0,2.0);
   Rectangle r1(2.0,2.0);
   Rectangle * r3 =&r1;
   try{
       r.addShape(r3);
       FAIL();
    }catch(std::string e){
        ASSERT_EQ("can't add shape",e);
    } 
}

TEST(Rectangle,deleteshape){
   Rectangle r(1.0,2.0);
   Rectangle * r3 =&r;
   try{
       r.deleteShape(r3);
       FAIL();
    }catch(std::string e){
        ASSERT_EQ("can't delete shape",e);
    } 
}

TEST(caseRectangle,AcceptRectangle){
    Shape* rectangle=new Rectangle(3.14,4.00);
    ShapeInfoVisitor visitor; 
    rectangle->accept(&visitor);
    ASSERT_EQ("Rectangle (3.14 4.00)\n",visitor.getResult());
    delete rectangle;
}
