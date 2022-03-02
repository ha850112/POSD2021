#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"

TEST(Triangle, TestTriangle) {
  TwoDimensionalVector t1(0, 0);
  TwoDimensionalVector t2(3, 12.433);
  TwoDimensionalVector t3(17.56789, -4);
  Triangle triangle( t2, t3);
  
  ASSERT_NEAR(115.2107, triangle.area(),0.01);
  ASSERT_NEAR(52.767, triangle.perimeter(),0.01);
  ASSERT_EQ("Triangle ([3.00,12.43] [17.56,-4.00])", triangle.info());

}
TEST(Triangle, TestTrianglefail) {
    TwoDimensionalVector t1(0, 0);
    TwoDimensionalVector t2(5, 0);
    
    try{
          
            Triangle triangle4(t1,t2);
             FAIL(); 
          }catch(std::string e){
            EXPECT_EQ(std::string("This is not a triangle!"), e);
          }
    }

