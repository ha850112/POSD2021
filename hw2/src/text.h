#include "article.h"
#include <string>
#ifndef TEXT_H
#define TEXT_H

class Text : public Article {
   public:
    Text(std::string text) :_text(text){}

    std::string getText() const {
        return _text;
    };

    
    private:
    std::string _text;
};

#endif