//
// Created by azari on 30.09.2022.
//

#ifndef MAIN_CPP_ZOO_HPP
#define MAIN_CPP_ZOO_HPP
#include <iostream>
#include <string.h>
class Animal{
public:
    size_t weight =0;
    //char* name = nullptr;
    std::string name;
    size_t age = 0;
    virtual void Say() = 0;
};
class Kangooroo: public Animal{

public:
    Kangooroo(size_t wght,size_t ag,const std::string& nme){
        name += std::string(nme);
        weight = wght;
        age = ag;
    }
    void Say() override{
        std::cout<<"SHHHHHHhHrukhehhehhe"<<std::endl;
    }
};
class Squirrel: public Animal{
public:
    Squirrel(size_t wght,size_t ag,const std::string& nme){
        name += std::string(nme);
        weight = wght;
        age = ag;
    }
    void Say() override{
        std::cout<<"CkCKCkckkkckckkKCkKCk"<<std::endl;
    }
};
class Cat:public Animal{
public:
    Cat(size_t wght,size_t ag,const std::string& nme){
        name += std::string(nme);
        weight = wght;
        age = ag;
    }
    void Say() override{
        std::cout<<"Meeeeeeeeeeeaaaaaaaaaaaaaaaaaaaaaaaaaooo"<<std::endl;
    }
};
#endif //MAIN_CPP_ZOO_HPP
