//
// Created by azari on 24.09.2022.
//

#ifndef LABWORK_QSORT_HPP
#define LABWORK_QSORT_HPP
#include <iostream>
template <class T>
void QuickSort(int* massive, size_t start,size_t end){
    if (start == end){
        return;
    }
    int curr_element = massive[(start+end)/2];
    int swap_element;
    size_t left = start;
    size_t right = end;
    size_t most_left = left;
    size_t most_right = right;
    while (left<right){
        if (massive[left]<curr_element){
            //std::cout<<massive[left]<<" - "<<left<<" - left"<<std::endl;
            left++;
        }
        if (massive[right]>=curr_element){
            //std::cout<<massive[right]<<" - "<<right<<" - right"<<std::endl;
            right--;
        }
        if (massive[right]<curr_element&&curr_element<=massive[left]){
            swap_element = massive[right];
            massive[right] = massive[left];
            massive[left] = swap_element;
            left++;
            right--;
        }


    }
    if (left >= most_right){
        return;
    }
    if (right <= most_left){
        return;
    }
    //std::cout<<left<<" - "<<right<<std::endl;
    //std::cout<<curr_element<<"-curr"<<std::endl;
    QuickSort<T>(massive,left,most_right );
    QuickSort<T>(massive,most_left,right );

}
#endif //LABWORK_QSORT_HPP
