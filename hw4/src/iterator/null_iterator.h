#pragma once
#include "iterator.h"
#include "../shape.h"

class NullIterator : public Iterator {
public:
    void first() override {
        throw std::string ("no element");
       
     }

    Shape* currentItem() const override { 
        throw std::string ("no element");
        return nullptr;
    }

    void next() override { 
        throw std::string ("no element");
    }

    bool isDone() const override {
        return true;
     }


};