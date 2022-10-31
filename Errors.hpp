//
// Created by azari on 17.09.2022.
//

#ifndef UNTITLED_ERRORS_HPP
#define UNTITLED_ERRORS_HPP
#include <iostream>
#define WrongInput 0
class Error:std::exception{
private:
    static std::string ErrorMessage (int message){
        if (message == 0){
            return "Wrong Input";
        }
        else{
            return "Wrong Code";
        }
    }
public:

    explicit Error(int msg):exception(){
        std::cout<<Error::ErrorMessage(msg)<<std::endl;
    }
};
#endif //UNTITLED_ERRORS_HPP
