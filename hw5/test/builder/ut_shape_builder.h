#include <string>
#include <cmath>
#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"
#include "../../src/iterator/iterator.h"

class CaseBuilder : public ::testing::Test {
protected:

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCircle(1.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(1*1*M_PI, result->area(), 0.01);
    delete builder;
}

TEST_F(CaseBuilder, BuildRectangle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildRectangle(1.0,2.0);
    Shape* result = builder->getShape();
    ASSERT_EQ(1.0*2.0, result->area());
    delete builder;
}

TEST_F(CaseBuilder, BuildTriangle) {
    ShapeBuilder* builder = new ShapeBuilder();
    double x1 = 1.0;
    double y1 = 2.0;
    double x2 = 2.0;
    double y2 = 2.0;
    builder->buildTriangle(x1,y1,x2,y2);
    Shape* result = builder->getShape();
    ASSERT_EQ(1.0, result->area());
    delete builder;
}

TEST_F(CaseBuilder, BuildCompound) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCompoundBegin();
    builder->buildRectangle(1.0,2.0);
    builder->buildCircle(1.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR(5.14, result->area(),0.01);
    delete builder;
}

TEST_F(CaseBuilder, BuildComplexCompound){
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCompoundEnd();
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR(3.14, result->createIterator()->currentItem()->area(),0.01);//Circle(1.0);
    
    Iterator* it = result->createIterator();
    it->next();
    ASSERT_NEAR(12.56,it->currentItem()->area(),0.01);//Circle(2.0);
    delete builder;
    delete it;
}
