#pragma once
#include <string>
#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"
#include "../iterator/iterator.h"


class ShapeInfoVisitor : public ShapeVisitor {
   public:
    void visitCircle(Circle* circle) {
        result+=circle->info()+"\n";
    }
    void visitRectangle(Rectangle* rectangle) {
        result+=rectangle->info()+"\n";
    }
    void visitTriangle(Triangle* triangle) {
        result+=triangle->info()+"\n";
    }
    
    void visitCompoundShape(CompoundShape* compoundShape) {
        result+=compoundShape->info()+"{\n";
        depth++;
        Iterator* it=compoundShape->createIterator();
        for(it->first() ; !it->isDone() ; it->next()){
            result+= std::string(depth*2,' ');
            //result+= std::string(depth,' ');
            it->currentItem()->accept(this);
        }
         result+= std::string(--depth*2,' ');
         //result+= std::string(depth,' ');
         result+="}\n";
    }
    
    std::string getResult() {
        return result;
    }

   private:
    int depth = 0;
    std::string result = "";
};