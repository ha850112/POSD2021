#include "../../src/builder/shape_parser.h"
#include "../../src/compound_shape.h"
#include "../../src/iterator/iterator.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"

TEST(Parser, BuildCircle){
    ShapeParser* s = new ShapeParser("./test/data/circle.txt");
    s->parse();
    ASSERT_NEAR(3.14 ,s->getShape()->area() ,0.01);
    delete s;
}

TEST(ShapeParser, BuildRectangle){
    ShapeParser* s = new ShapeParser("./test/data/rectangle.txt");
    s->parse();
    ASSERT_NEAR( 3.14*4.00, 0.001,s->getShape()->area());
    delete s;
}

TEST(ShapeParser, BuildTriangle){
    ShapeParser* s = new ShapeParser("./test/data/triangle.txt");
    s->parse();
    TwoDimensionalVector t1(3.0, 0.0);
    TwoDimensionalVector t2(0.0, 4.0);
    Triangle triangle(t1, t2);
    ASSERT_NEAR(triangle.area(), s->getShape()->area(),  0.001);

    delete s;
}


TEST(ShapeParser, BuildEmptyCompound){
    ShapeParser* s = new ShapeParser("./test/data/empty_compound.txt");
    s->parse();
    ASSERT_EQ(0,s->getShape()->area());
    ASSERT_EQ(typeid(CompoundShape),typeid(*(s->getShape()) ) );
    delete s;
}

TEST(ShapeParser, BuildSimpleCompound){
    ShapeParser* s = new ShapeParser("./test/data/simple_compound.txt");
    s->parse();
    ASSERT_NEAR( 1.0*1.0*M_PI + 3.14*4.00 + 3*4/2 ,s->getShape()->area(),0.01);
    
    Iterator *it=s->getShape()->createIterator();
    ASSERT_EQ(typeid(Circle),typeid( *(it->currentItem()) ));
    it->next();
    ASSERT_EQ(typeid(Rectangle),typeid( *(it->currentItem()) ));
    it->next();
    ASSERT_EQ(typeid(Triangle),typeid( *(it->currentItem()) ));

    delete s;
    delete it;
}

TEST(ShapeParser, BuildComplexCompound){
    ShapeParser* s = new ShapeParser("./test/data/complex_compound.txt");
    s->parse();
    
    Iterator *it=s->getShape()->createIterator();
    ASSERT_EQ(typeid(Circle),typeid( *(it->currentItem()) ));
    it->next();
    ASSERT_EQ(typeid(Triangle),typeid( *(it->currentItem()) ));
    it->next();
    ASSERT_EQ(typeid(CompoundShape),typeid( *(it->currentItem()) ));

    Iterator *it2= it->currentItem()->createIterator();
    ASSERT_NEAR(1.0*1.0*M_PI + 3.14*4.00 + 3*4/2 ,it->currentItem()->area(),0.01);//CompoundShape {Circle (1.0) Rectangle (3.14 4.00) Triangle ([3,0] [0,4])}
    ASSERT_EQ(typeid(Circle),typeid( *(it2->currentItem()) ));
    it2->next();
    ASSERT_EQ(typeid(Rectangle),typeid( *(it2->currentItem()) ));
    it2->next();
    ASSERT_EQ(typeid(Triangle),typeid( *(it2->currentItem()) ));

    it->next();
    ASSERT_EQ(typeid(Rectangle),typeid( *(it->currentItem()) ));

    delete it2;
    delete it;
    delete s;
}
