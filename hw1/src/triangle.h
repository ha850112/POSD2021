#include "shape.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "two_dimensional_vector.h"

using namespace std;

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
     x1=vec1.x();x2=vec2.x();y1=vec1.y();y2=vec2.y();
     l1=vec1.length();l2=vec2.length();
     l3= sqrt(pow((x1-x2),2)+pow((y1-y2),2));
     triperimeter=l1+l2+l3;
     triarea=abs(x1*y2+x2*0+0*y1-y1*x2-y2*0-0*x1)/2.0;
     strx1 = std::to_string(x1);
     strx2 = std::to_string(x2);
     stry1 = std::to_string(y1);
     stry2 = std::to_string(y2);
     triangleinfo ="Triangle (["+ strx1.erase(strx1.length()-4,strx1.length()-2)+ "," +stry1.erase(stry1.length()-4,stry1.length()-2)+"] ["+strx2.erase(strx2.length()-4,strx2.length()-2)+","+stry2.erase(stry2.length()-4,stry2.length()-2)+"])";
     if(!((l1+l2)>l3 && (l1+l3)>l2 && (l3+l2)>l1)){
          run=false;
          throw string ("This is not a triangle!");
      }
     }

    double area() const { 
      if(run) return triarea;
      else return -1;
      }

    double perimeter() const { 
      if(run) return triperimeter;
      else return -1;
    }

    std::string info() const {
     return  triangleinfo;
    }

    private:
    double triperimeter ,triarea;
    double l1,l2,l3,x1,x2,y1,y2;
    bool run=true; std::string triangleinfo ,strx1,strx2,stry1,stry2;
};