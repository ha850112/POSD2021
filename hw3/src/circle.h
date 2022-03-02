#include<iostream> 
#include<string.h>
#include <string>
using namespace std;
#include "shape.h"
#include <cmath>
#include"./iterator/iterator.h"
#include"./iterator/null_iterator.h"
#pragma once
class Circle : public Shape {
public:
    Circle(double radius) :_radius(radius){ 
        if (_radius<=0){
            run=false;
            throw string ("not a circle");
        }
        // strradius=std::to_string(radius);
        // circleinfo="Circle ("+strradius.erase(strradius.length()-4,strradius.length()-2) +")";};
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

    Iterator* createIterator() override { 
     return new NullIterator();
    }

    private:
    std::string circleinfo,strradius;
    double _radius;
    bool run=true; 
};
