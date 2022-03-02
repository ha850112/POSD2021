#pragma once  
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include "../../src/shape.h"
#include "../../src/builder/scanner.h"
#include "../../src/builder/shape_builder.h"

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        std::ifstream myFile;
        myFile.open(filePath);
        std::stringstream ss;
        ss << myFile.rdbuf();
        std::string txt(ss.str());
        scanner = new Scanner(txt);
        builder = new ShapeBuilder();
        myFile.close();
    }

    ~ShapeParser() {
        delete scanner;
        delete builder;
    }

    void parse() {
        std::string next;
        while (!scanner->isDone()){
            next= scanner->next();
             
             if(next=="Circle"){
                double radius = 0.0;
                while(scanner->next() != "(");
                radius = scanner->nextDouble();
                while(scanner->next() != ")");

                builder->buildCircle(radius);
            }else if(next=="Rectangle"){
                double length = 0.0;
                double width = 0.0;
                while(scanner->next() != "(");
                length = scanner->nextDouble();
                scanner->next();
                width = scanner->nextDouble();
                while(scanner->next() != ")");

                builder->buildRectangle(length, width);
            }else if(next=="Triangle"){
                double x1,y1,x2,y2 = 0;
                while(scanner->next() != "(");
                while(scanner->next() != "[");
                x1 = scanner->nextDouble();
                while(scanner->next() != ",");
                y1 = scanner->nextDouble();
                while(scanner->next() != "]");
                while(scanner->next() != "[");
                x2 = scanner->nextDouble();
                while(scanner->next() != ",");
                y2 = scanner->nextDouble();
                while(scanner->next() != "]");
                while(scanner->next() != ")");

                builder->buildTriangle(x1, y1, x2, y2);
            }else if(next=="CompoundShape"){
                while(scanner->next() != "{");
                builder->buildCompoundBegin();
            }else if(next=="}"){
                builder->buildCompoundEnd();
            }
        }
        
    }

    Shape* getShape() {
         return builder->getShape();
    }

private:
    Scanner* scanner;
    ShapeBuilder* builder;
};

