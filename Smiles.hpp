//
// Created by azari on 19.09.2022.
//

#ifndef LABWORK_SMILES_HPP
#define LABWORK_SMILES_HPP
#include <iostream>
#include <string>
void DeleteSmiles(std::string* str){
    int i =0;
    while (i!= str->length()){
        if ((i+2<str->length())
        &&(str->operator[](i) == ':'
        &&str->operator[](i+1) == '-'
        &&(str->operator[](i+2) == ')'||str->operator[](i+2) == '('))){
            str->erase(i,3);
        }
        else if((i-1>=0)&&(i+1<str->length())
        &&(str->operator[](i-1) == ':'
        &&str->operator[](i) == '-'
        &&(str->operator[](i+1) == ')'||str->operator[](i+1) == '('))){
            i = i-1;
            str->erase(i,3);

        }else if((i-2>=0)
        &&(str->operator[](i-1) == ':'
        &&str->operator[](i) == '-'
        &&(str->operator[](i+1) == ')'||str->operator[](i+1) == '('))){
            i = i -2;
            str->erase(i,3);
        }else{
            i = i+1;
        }
    }
}
#endif //LABWORK_SMILES_HPP
