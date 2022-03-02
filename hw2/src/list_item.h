#include <string>
#include "article.h"
#ifndef LIST_ITEM_H
#define LIST_ITEM_H

class ListItem : public Article {
   public:
    ListItem(std::string text): _text(text){}

    std::string getText() const {
        return "- "+_text;
    }

    private:
    std::string _text;
};

#endif