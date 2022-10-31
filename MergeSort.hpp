//
// Created by azari on 29.09.2022.
//

#ifndef MAIN_CPP_MERGESORT_HPP
#define MAIN_CPP_MERGESORT_HPP
#include <iostream>
#include "ArraySequence.hpp"

template <class T>
class MergeSort{
public:
    void Sort(ArraySequence<T>* seq,size_t start,size_t end, int cmp(T,T)){//не просто компарить а сортировать
        if (start==end){
            return;
        }
        Sort(seq,(start+end)/2+1,end,cmp);
        Sort(seq,start,(start+end)/2,cmp);

        size_t first_half = start;
        size_t last_half = (start+end)/2+1;
        T* buffer = new T[end-start+1];
        for (size_t i = 0;i<end-start+1;i++){
            if (first_half>(start+end)/2){
                buffer[i] = seq->Get(last_half);
                last_half++;
                continue;
            }
            if (last_half>end){
                buffer[i] = seq->Get(first_half);
                first_half++;
                continue;
            }
            if (cmp(seq->Get(first_half),seq->Get(last_half))<0){
                buffer[i] = seq->Get(first_half);
                first_half++;
            }else{
                buffer[i] = seq->Get(last_half);
                last_half++;
            }
        }
        for (size_t i = start;i<end+1;i++){
            seq->Set(buffer[i-start],i);
        }
        delete[] buffer;


    }
};
#endif //MAIN_CPP_MERGESORT_HPP
