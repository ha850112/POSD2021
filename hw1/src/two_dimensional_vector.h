#ifndef TWO_DIMENSIONAL_vector_H
#define TWO_DIMENSIONAL_vector_H
#include<string>
#include<cmath>
using namespace std;
class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y):_x(x),_y(y){
    infox=std::to_string(_x);
    infoy=std::to_string(_y);
    TwoDimensionalVectorinfo="["+infox.erase(infox.length()-4,infox.length()-2)+","+infoy.erase(infoy.length()-4,infoy.length()-2)+"]";
    }

    double x() const { return _x;}

    double y() const { return _y; }

    double length() const {return sqrt(_x*_x+_y*_y);}

    double dot(TwoDimensionalVector vec) const {
        return _x*vec.x()+_y*vec.y();
    }

    double cross(TwoDimensionalVector vec) const { 
        return _x*vec.y()-_y*vec.x();
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const { 
    
        double new_x(_x-vec.x()), new_y(_y-vec.y());
        TwoDimensionalVector res(new_x, new_y);
        return res;
    
    }

    std::string info() const { 
         
         return TwoDimensionalVectorinfo;
    }
    private:
    std::string TwoDimensionalVectorinfo,infox,infoy;
    double _x, _y;
};
#endif