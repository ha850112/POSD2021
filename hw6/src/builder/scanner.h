#pragma once
#include <string>
#include <vector>

class Scanner {
public:
    Scanner(std::string input) : _input(input){

    }

    std::string next() {
       std::string result = "";

        if(isDone()) throw std::string ("end of scan!");

        while(isspace(_input[pos])) pos++;

        while(!isDone() && result.empty()){

            if(isalpha(_input[pos])){//字母
                int start = pos;
                while(isalpha(_input[pos])) pos++;
                for(auto token : tokenList){
                    if(_input.compare(start,pos - start,token)==0){
                        result = token;
                        break;
                    }
                }
            }
            else if(ispunct(_input[pos])){//標點符號
                for(auto token : tokenList){
                    if(_input.compare(pos, 1, token) == 0){
                        result = token;
                        break;
                    }
                }
                pos++;
            }
            else if(isdigit(_input[pos])) break;//數字
        }

        if(isDone() && result.empty()) throw std::string ("end of scan!");

        return result;
    }

    double nextDouble() {
        if(isDone()){
            throw std::string("end of scan!");
        }
        
        while(isspace(_input[pos])||isalpha(_input[pos])||ispunct(_input[pos])) {
            pos++;
        }
        std::string s = "";
        int point=0;//小數點
        while(isdigit(_input[pos])||_input[pos]=='.'){
           if(_input[pos]=='.') point++ ;
           if(point>=2) {
            break; 
            }
           
           s+=_input[pos];
           pos++;
        }
        if(isDone()&& s.empty()){
            throw std::string("end of scan!");
        }
        return std::stod(s);
    }



    bool isDone() {
        while(pos<_input.length() && isspace(_input[pos])) {
            pos++;
        }
        return pos>=_input.length();
    }


private:
    std::string _input;
    std::string::size_type pos = 0;
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
};