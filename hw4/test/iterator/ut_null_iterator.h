#include <gtest/gtest.h>
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/iterator/null_iterator.h"

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
