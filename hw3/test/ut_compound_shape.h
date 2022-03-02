#include "../src/compound_shape.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/circle.h"
#include "../src/two_dimensional_vector.h"
#include <gtest/gtest.h>

TEST(casecompoundshape,area){
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.0));
    cs1->addShape(new Rectangle(2 ,2));
    ASSERT_NEAR(7.141 ,cs1->area() ,0.001);
    delete cs1;
}

TEST(casecompoundshape,perimeter){
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.0));
    cs1->addShape(new Rectangle(2 ,2));
    ASSERT_NEAR(14.283 ,cs1->perimeter() ,0.001);
    delete cs1;
}

TEST(casecompoundshape,info_addshape){
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(1.1));
  cs1->addShape(new Rectangle(3.14 ,4));
  ASSERT_EQ("CompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}",cs1->info());
  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Circle(12.34567));
  cs2->addShape(cs1);

  ASSERT_EQ("CompoundShape\n{\nCircle (12.35)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}",cs2->info()); 
  delete cs1;
}

TEST(casecompoundshape,deleteshape){
    CompoundShape *cs1 =new CompoundShape();
    Shape*c=new Circle(1.1);
    cs1->addShape(c);
    cs1->addShape(new Rectangle(3.14 ,4));
    cs1->deleteShape(c);
    ASSERT_EQ("CompoundShape\n{\nRectangle (3.14 4.00)\n}",cs1->info());
    delete cs1;
}




