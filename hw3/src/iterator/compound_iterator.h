#pragma once
#include"iterator.h"
#include"../shape.h"
template<class ForwardIterator>
// you should define a template class or type `ForwardIterator`
class CompoundIterator : public Iterator{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin),_end(end) {
        first();
     }

    void first() override { 
        _current=_begin;
    }

    Shape* currentItem() const override { 
         if(isDone()){
        throw std::string ("end!");
      }
        return *_current;
       
    }

    void next() override {
        if(isDone()){
        throw std::string ("end!");
      }
        _current ++;
     }

    bool isDone() const override { 
        return _current == _end;
    }

    
    private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};