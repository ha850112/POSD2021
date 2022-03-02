#include<iostream> 
#include<string.h>
#include <string>
using namespace std;
#include "shape.h"
#include <cmath>

class Circle : public Shape {
public:
    Circle(double radius) :_radius(radius){ 
        if (_radius<=0){
            run=false;
            throw string ("not a circle");
        }
        strradius=std::to_string(radius);
        circleinfo="Circle ("+strradius.erase(strradius.length()-4,strradius.length()-2) +")";};

    double area() const { 
       if(run) return pow(_radius,2)*M_PI;
       else return -1;
    }

    double perimeter() const { 
       if(run) return _radius * 2* M_PI;
        else return -1;
        }

    std::string info() const {
        return circleinfo;
     }

    private:
    std::string circleinfo,strradius;
    double _radius;
    bool run=true; 
};
