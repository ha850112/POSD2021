#include <string>
#ifndef ARTICLE_H
#define ARTICLE_H

class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual int getLevel() const {
        return _level ;
    };

    virtual void add(Article* dpFormat){
        throw std::string ("You can't add anything to a ListItem or Text");
    };

    
    private:
     int _level = 0;
};

#endif