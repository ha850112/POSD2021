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
   Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(1.0,2.0));
    CompoundShape* cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    Iterator*it=cs1->createIterator();
    ASSERT_EQ(c,it->currentItem());
    it->next();
    ASSERT_EQ(t,it->currentItem());
    it->next();
    ASSERT_EQ(r,it->currentItem());
    delete cs1;
    delete it;
}

TEST(casecompoundshape,deleteshape){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(1.0,2.0));
    CompoundShape* cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    
    CompoundShape* cs2=new CompoundShape();
    Shape* c2=new Circle(2.0);
    Shape* c3=new Circle(3.0);
    Shape* r2=new Rectangle(3.0,4.0);
    cs2->addShape(c2);
    cs2->addShape(c3);
    cs2->addShape(r2);
    
    cs1->addShape(cs2);
    cs1->deleteShape(c);
    cs1->deleteShape(c2);
    Iterator*it=cs1->createIterator();
    ASSERT_EQ(t,it->currentItem());
    it->next();
    ASSERT_EQ(r,it->currentItem());
    it->next();
    ASSERT_EQ(cs2,it->currentItem());
    Iterator*it2=cs2->createIterator();
    ASSERT_EQ(c3,it2->currentItem());
    it2->next();
    ASSERT_EQ(r2,it2->currentItem());
    delete cs1;
    delete it;
    //delete cs2;
}
