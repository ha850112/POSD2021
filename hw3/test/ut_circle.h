#include <gtest/gtest.h>
#include"../src/circle.h"

TEST(Casecircle,TESTcircle){
 Circle c(1.10);
 ASSERT_NEAR(3.8013239, c.area(),0.001);
 ASSERT_NEAR(6.911498, c.perimeter(),0.001);
 ASSERT_EQ("Circle (1.10)", c.info());
}

TEST (Circle, TestCirclefail)
{

 try {
    Circle(0);
  }catch(std::string e) {
      ASSERT_EQ("not a circle", e);
  }
      ASSERT_NO_THROW(Circle(1));
}

TEST(Circle,addshape){
   Circle c(1.0);
   try{
       c.addShape(new Circle(2.0));
       FAIL();
    }catch(std::string e){
        ASSERT_EQ("Only compound shape can add shape!",e);
    } 
}

TEST(Circle,deleteshape){
   Circle c(1.0);
   Circle *c1=&c;
   try{
       c.deleteShape(c1);
       FAIL();
    }catch(std::string e){
        ASSERT_EQ("Only compound shape can delete shape!",e);
    } 
}

