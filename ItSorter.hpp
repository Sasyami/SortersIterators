//
// Created by azari on 29.11.2022.
//

#ifndef MAIN_CPP_ITSORTER_HPP
#define MAIN_CPP_ITSORTER_HPP
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
template <class T, int cmp(T&,T&), class it>

class ItSorter{
private:
    void swap (it a, it b){
        T buf = *a;
        *a = *b;
        *b = buf;
    }
    it twoAttachedSortedSortV1(it begin1, it begin2, size_t len1,size_t len2){
        it point1 = begin1;
        it point2 = begin2;
        size_t point2Index = 0;
        size_t point1Index = 0;
        auto* buf = new T[len1+len2];
        for (auto i = 0;i<len1+len2;++i){
            if (point2Index>=len2){
                buf[i] = *point1;
                ++point1;
                ++point1Index;
                continue;
            }
            if (point1Index>=len1){
                buf[i] = *point2;
                ++point2;
                ++point2Index;
                continue;
            }
            if (cmp(*point2,*point1)<0){
                buf[i] = *point2;
                ++point2;
                ++point2Index;
            }else{
                buf[i] = *point1;
                ++point1;
                ++point1Index;
            }
        }
        it point = begin1;
        for (int i = 0;i<len1+len2;++i){
            *point = buf[i];
            ++point;
        }
        delete[] buf;
        /*for (size_t i = 0;i<len;++i){
            if (cmp(*begin2,*point1)<0){
                for (size_t j = point2Index;j<len;++j){
                    if (cmp(*point2,*point1)<0) {
                        ++point2;
                        ++point2Index;
                    }else{
                        break;
                    }


                }
                --point2;
                --point2Index;

                swap(point1,begin2);
                swap(begin2,point2);

            }
            ++point1;
            it buf = begin1;
            for (auto j = 0;j<2*len;j++){

                std::cout<<*buf<<" - sorting\n";
                ++buf;

            }
            std::cout<<*point1<<" - point1\n\n";
        }
        while(point2Index!=len){
            ++point2;
            ++point2Index;
        }*/
        return point;


    }
    it mergeSort(it begin, size_t cur_len){
        it end = begin;
        if (cur_len==1){
            return ++end;
        }
        if (cur_len==2) {

            ++end;

            if (cmp(*begin,*end) > 0) {
                swap(begin, end);
            }
            ++end;

            return end;

        }



        end = mergeSort(begin, cur_len / 2);
        it new_end = mergeSort(end, cur_len - cur_len / 2);
        twoAttachedSortedSortV1(begin,end,cur_len/2,cur_len-cur_len/2);

        return new_end;
    }

public:
    void qsort(it begin,it end){
        if (begin==end){
            return;
        }


        auto smallIndex = begin;
        T curValue;

        for (auto i = begin;i!=end;i++){
            if (cmp(*i,*end)<0){
                if(smallIndex!=i) {
                    curValue = *smallIndex;
                    *smallIndex = *i;
                    *i = curValue;
                }
                ++smallIndex;
            }

        }


        curValue = *smallIndex;
        *smallIndex = *end;
        *end = curValue;


        if (smallIndex!=begin) {
            qsort(begin, --smallIndex);
            ++smallIndex;
        }


        if (smallIndex!=end) {
            qsort(++smallIndex, end);
        }


    }
    void msort(it begin,size_t len){
        mergeSort(begin, len);
    }
    void bubblesort(it begin,it end,bool is_sorted = false){
        if (is_sorted){
            return;
        }
        it point1 = begin;
        it point2 = ++point1;
        --point1;
        bool is_sorted_now = true;
        while (point1!=end){

            if (cmp(*point1,*point2)>0){
                swap(point1,point2);
                is_sorted_now = false;
            }
            ++point1;
            ++point2;
        }

        bubblesort(begin,end,is_sorted_now);

    }

};
#endif //MAIN_CPP_ITSORTER_HPP
