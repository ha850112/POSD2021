#pragma once
#include <iostream>
#include <cmath>
#include <list>
#include <string>
#include "shape.h"
#include"./iterator/iterator.h"
#include"./iterator/compound_iterator.h"
class CompoundShape : public Shape {
public:
    ~CompoundShape() {
        for(Shape*s:_shapes){
            delete s;
        }
     }

    double area() const override { 
        double totalarea = 0.0;
        for (std::list<Shape*>::const_iterator it = _shapes.begin() ; it != _shapes.end(); it++){
              totalarea += (*it)->area();
            }
        return totalarea;
    }

    double perimeter() const override {
        double totalperimeter = 0.0;
        for (std::list<Shape*>::const_iterator it = _shapes.begin();it!=_shapes.end();it++){
              totalperimeter += (*it)->perimeter();
            }
        return totalperimeter;
     }

    std::string info() const override {
        std::string totalinfo="CompoundShape\n" ;
        for (std::list<Shape*>::const_iterator it = _shapes.begin();it!=_shapes.end();it++){
            if(it==_shapes.begin()){totalinfo+="{\n";}
            totalinfo+=(*it)->info()+"\n";
           if(it== --_shapes.end()){
            totalinfo+= "}\n";
            totalinfo.resize(totalinfo.length()-1);
            }
            
        }
        
    return totalinfo;
    }

    Iterator* createIterator() override { 
        return new CompoundIterator<std::list<Shape*>::const_iterator>(_shapes.begin(),_shapes.end());
    }

    void addShape(Shape* shape) override {
    _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override { 
    _shapes.remove(shape);  
    }


    private:
    std::list<Shape*> _shapes;
    
    
};