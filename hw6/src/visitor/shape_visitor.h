#pragma once

class Circle;
class Rectangle;
class Triangle;
class CompoundShape;


// you don't need to modify the class
class ShapeVisitor {
   public:
    virtual ~ShapeVisitor(){};

    virtual void visitCircle(Circle* circle) = 0;

    virtual void visitRectangle(Rectangle* rectangle) = 0;

    virtual void visitTriangle(Triangle* triangle) = 0;
    
    virtual void visitCompoundShape(CompoundShape* compoundShape) = 0;

   protected:
    ShapeVisitor(){};
};