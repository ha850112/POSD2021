#include "../../src/circle.h"
#include "../../src/compound_shape.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/visitor/shape_info_visitor.h"
#include "../../src/iterator/iterator.h"

TEST(caseCircle,Visitcircle){
    Shape* circle=new Circle(1.0);
    ShapeInfoVisitor visitor; 
    circle->accept(&visitor);
    ASSERT_EQ("Circle (1.00)\n",visitor.getResult());
    delete circle;
}

TEST(caseRectangle,VisitRectangle){
    Shape* rectangle=new Rectangle(3.14,4.00);
    ShapeInfoVisitor visitor; 
    rectangle->accept(&visitor);
    ASSERT_EQ("Rectangle (3.14 4.00)\n",visitor.getResult());
    delete rectangle;
}

TEST(caseTriangle,VisitTriangle){
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape* triangle=new Triangle( t2, t3);
    ShapeInfoVisitor visitor; 
    triangle->accept(&visitor);
    ASSERT_EQ("Triangle ([3.00,12.43] [17.56,-4.00])\n",visitor.getResult());
    delete triangle;
}


TEST(caseCompoundshape,VisitCompoundshape){
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(1.1));
  cs1->addShape(new Rectangle(3.14 ,4));
  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Circle(12.34567));
  cs2->addShape(cs1);
  ShapeInfoVisitor visitor;
  cs2->accept(&visitor);
  ASSERT_EQ("CompoundShape {\n  Circle (12.35)\n  CompoundShape {\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n" ,visitor.getResult());
}