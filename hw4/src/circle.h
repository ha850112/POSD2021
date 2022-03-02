#pragma once
using namespace std;
#include <cmath>
#include "shape.h"
#include <cmath>
#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"


class Circle : public Shape {
   public:
     Circle(double radius) :_radius(radius){ 
        if (_radius<=0){
            run=false;
            throw string ("not a circle");
        }
    }
    double area() const { 
       if(run) return pow(_radius,2)*M_PI;
       else return -1;
    }

    double perimeter() const { 
       if(run) return _radius * 2* M_PI;
        else return -1;
        }

    std::string info() const {
        int n = snprintf(NULL, 0 ,"Circle (%.2f)", _radius);
        char s[n+1];
        snprintf(s, sizeof(s), "Circle (%.2f)", _radius);
        return s;
     }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCircle(this);
    }

    Iterator* createIterator() override { 
     return new NullIterator();
    }

   private:
    std::string circleinfo,strradius;
    double _radius;
    bool run=true; 
};