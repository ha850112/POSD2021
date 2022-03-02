#include "../src/two_dimensional_vector.h"
#include<gtest/gtest.h>

TEST(TwoDimensionalVector, TestTwoDimensionalVector){
  TwoDimensionalVector t1(3, 4), t2(8, 4);
  ASSERT_EQ(3, t1.x());
  
  ASSERT_EQ(4, t1.y());
  
  ASSERT_EQ(5, t1.length());
  
  ASSERT_EQ(40, t1.dot(t2));
  
  ASSERT_EQ(-20, t1.cross(t2));
  ASSERT_EQ(-5, t1.subtract(t2).x());
  ASSERT_EQ(0, t1.subtract(t2).y());
  ASSERT_EQ("[3.00,4.00]", t1.info());
}