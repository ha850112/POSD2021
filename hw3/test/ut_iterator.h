#include <gtest/gtest.h>
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"
#include "../src/iterator/null_iterator.h"

//circle
TEST(NullIterator,NullIterator_circle__first){
    Circle c(1.0);
    Iterator* it=c.createIterator();
    try
    {
        it->first();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }
    delete it;         
}

TEST(NullIterator,NullIterator_circle__next){
    Circle c(1.0);
    Iterator* it=c.createIterator();
    try
    {        
        it->next();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    } 
    delete it;        
}

TEST(NullIterator,NullIterator_circle__currentItem){
    Circle c(1.0);
    Iterator* it=c.createIterator();
    try
    {        
        it->currentItem();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }   
    delete it;      
}

TEST(NullIterator,NullIterator_circle__isDone){
    Circle c(1.0);
    Iterator* it=c.createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}


//rectangle

TEST(NullIterator,NullIterator_Rectangle__first){
    Rectangle r(1.0,2.0);
    Iterator* it=r.createIterator();
    try
    {
        it->first();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }     
    delete it;    
}

TEST(NullIterator,NullIterator_Rectangle__next){
    Rectangle r(1.0,2.0);
    Iterator* it=r.createIterator();
    try
    {        
        it->next();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }       
    delete it;  
}

TEST(NullIterator,NullIterator_Rectangle__currentItem){
    Rectangle r(1.0,2.0);
    Iterator* it=r.createIterator();
    try
    {        
        it->currentItem();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }      
    delete it;   
}

TEST(NullIterator,NullIterator_Rectangle__isDone){
    Rectangle r(1.0,2.0);
    Iterator* it=r.createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

//triangle

TEST(NullIterator,NullIterator_Triangle__first){
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Triangle t( t2, t3);
    Iterator* it=t.createIterator();
    try
    {
        it->first();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    } 
    delete it;        
}

TEST(NullIterator,NullIterator_Triangle__next){
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Triangle t( t2, t3);
    Iterator* it=t.createIterator();
    try
    {        
        it->next();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }   
    delete it;      
}

TEST(NullIterator,NullIterator_Triangle__currentItem){
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Triangle t( t2, t3);
    Iterator* it=t.createIterator();
    try
    {        
        it->currentItem();
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("no element",e);          
    }    
    delete it;     
}

TEST(NullIterator,NullIterator_Triangle__isDone){
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Triangle t( t2, t3);
    Iterator* it=t.createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

//counpondShape

TEST(Compound_iterator,first){
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
    it->first();
    ASSERT_EQ(c,it->currentItem());
    delete cs1;
    delete it;
}

TEST(Compound_iterator,next){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(1.0,2.0));
    CompoundShape *cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    Iterator*it=cs1->createIterator();
    ASSERT_EQ(c,it->currentItem());
    it->next();
    ASSERT_EQ(t,it->currentItem());
    it->next();
    ASSERT_EQ(r,it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
    delete cs1;
    delete it;
}

TEST(Compound_iterator,next_exception){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(1.0,2.0));
    CompoundShape *cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    Iterator*it=cs1->createIterator();
    ASSERT_EQ(c,it->currentItem());
    it->next();
    ASSERT_EQ(t,it->currentItem());
    it->next();
    ASSERT_EQ(r,it->currentItem());
    try
    {
        it->next();
    }
    catch(std::string e)
    {
        ASSERT_EQ("end!",e);
    }
    delete cs1;
    delete it;
}

TEST(Compound_iterator,currentItem){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(1.0,2.0));
    Shape*r1=(new Rectangle(3.0,2.0));
    Shape*c1=(new Circle(8.0));
    CompoundShape *cs1= new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    cs1->addShape(r1);
    cs1->addShape(c1);
    Iterator*it=cs1->createIterator();
    ASSERT_EQ(c,it->currentItem());
    it->next();
    ASSERT_EQ(t,it->currentItem());
    it->next();
    ASSERT_EQ(r,it->currentItem());
    it->next();
    ASSERT_EQ(r1,it->currentItem());
    it->next();
    ASSERT_EQ(c1,it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
    try
    {
        it->currentItem();
    }
    catch(std::string e)
    {
        ASSERT_EQ("end!",e);
    }
    delete cs1;
    delete it;
    
}

TEST(Compound_iterator,isdone){
    Shape*c=(new Circle(1.0));
    TwoDimensionalVector t2(3, 12.433);
    TwoDimensionalVector t3(17.56789, -4);
    Shape*t=(new Triangle(t2,t3));
    Shape*r=(new Rectangle(1.0,2.0));
    Shape*r1=(new Rectangle(3.0,2.0));
    Shape*c1=(new Circle(8.0));
    CompoundShape *cs1=new CompoundShape();
    cs1->addShape(c);
    cs1->addShape(t);
    cs1->addShape(r);
    cs1->addShape(r1);
    cs1->addShape(c1);
    Iterator*it=cs1->createIterator();
    ASSERT_EQ(c,it->currentItem());
    it->next();
    ASSERT_EQ(t,it->currentItem());
    it->next();
    ASSERT_EQ(r,it->currentItem());
    it->next();
    ASSERT_EQ(r1,it->currentItem());
    it->next();
    ASSERT_EQ(c1,it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
    delete cs1;
    delete it;
    
}






