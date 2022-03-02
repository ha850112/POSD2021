#pragma once
#include "../shape.h"
#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"
#include "../compound_shape.h"
#include <stack>
#include <list>
 
class ShapeBuilder {
public:

    static ShapeBuilder* getInstance() {
        //  if(!_instance)
        //     _instance = new ShapeBuilder();
        // return _instance;
        static ShapeBuilder Instance;
        return &Instance;
    }

    ~ShapeBuilder() {}
    
    void buildCircle(double radius) {
      ShapeStack.push(new Circle(radius));
    }

    void buildRectangle(double length, double width) {
        ShapeStack.push(new Rectangle(length,width));
    }

    void buildTriangle(double x1, double y1, double x2, double y2) {
        TwoDimensionalVector t1(x1,y1);
        TwoDimensionalVector t2(x2,y2);
        ShapeStack.push(new Triangle(t1,t2));
    }

    void buildCompoundBegin() {
        ShapeStack.push(new CompoundShape());
    }

    void buildCompoundEnd() {
        std::list<Shape*>shapelist;
        while(typeid(*ShapeStack.top())!=typeid(CompoundShape)||(typeid(*ShapeStack.top())==typeid(CompoundShape) && !(ShapeStack.top()->createIterator()->isDone()))){
            shapelist.push_back(ShapeStack.top());
            ShapeStack.pop();
        }
        Shape* compound = ShapeStack.top();
        for(auto it = shapelist.rbegin() ; it != shapelist.rend() ; it++){
            compound->addShape(*it);
        }
    }

    void reset() {
        while(!ShapeStack.empty()){
            ShapeStack.pop();
        }
    }
    
    Shape* getShape() {
        return ShapeStack.top();
    }

    
 private:
    std::stack<Shape*>ShapeStack;
    //static ShapeBuilder* _instance;
    ShapeBuilder(){};
};
  //ShapeBuilder * ShapeBuilder::_instance = nullptr;
