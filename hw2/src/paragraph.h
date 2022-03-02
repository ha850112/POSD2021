#include <string>
#include "article.h"
#include <list>
#include <typeinfo>
#include "list_item.h"
#include "text.h"
#define MAX 50

class Paragraph : public Article {
   public:
    Paragraph(int level, std::string text): _level(level),_text(text){
        if(_level<1 || _level>6){
        throw std::string ("A paragraph can only have a level between 1 and 6");
        }
    }

    ~Paragraph() {}

    std::string getText() const override {
    std::string text1=std::string(_level,'#')+" "+_text;

     if (hasitem==0){
         return text1+"\n";
     }
     else{
        text1 +="\n";
         for(int i=0;i<len;i++){
            text1 = text1+can[i]->getText();
            if(i<len-1){
                text1+="\n";
            }
        }
        return text1;

     }
    
    }
    

    int getLevel() const override {
       return  _level;
    }

    void add(Article* content) override {
        if (typeid(*content)==typeid(Paragraph)){
         if (content->getLevel()<=_level){
             throw std::string("New paragraphs have to be higher level than the previous ones");
         }  
         else {
             can[len]= content;
             len++;
             hasitem=true;
         }
        }
        else{
            can[len]= content;
             len++;
             hasitem=true;
        }
        
        
    }

    private:
    int _level;                  
    std::string _text;
    Article* can[MAX];
    int len =0;
    bool hasitem = false;
};