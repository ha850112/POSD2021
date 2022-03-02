#include "../src/utility.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"
#include "../src/iterator/null_iterator.h"



TEST(utility,AreaConstraint){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(50.0,2.0));
    CompoundShape* cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);

    Shape* result = selectShape(cs1, [](Shape* shape){
        return shape->area() > 50.0 && shape->area() < 110.0;//回傳bool type
    });

    ASSERT_EQ(r, result);
    delete cs1;
}

TEST(utility,PerimeterConstraint){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(50.0,2.0));
    CompoundShape* cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    Shape* result = selectShape(cs1, [](Shape* shape){
        return shape->perimeter() > 100.0 && shape->perimeter() < 200.0;
    });

    ASSERT_EQ(r, result);
    delete cs1;
}



