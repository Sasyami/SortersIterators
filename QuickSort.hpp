//
// Created by azari on 24.09.2022.
//

#ifndef LABWORK_QUICKSORT_HPP
#define LABWORK_QUICKSORT_HPP
#include <iostream>
#include "ArraySequence.hpp"

template <class T>
class QuickSort{
private:
    T* MaxMin (ArraySequence<T>* seq,size_t length,int cmp(T,T)){// ошибка при длине 0
        T Max = seq->Get(0);
        T Min = seq->Get(0);
        for (size_t i = 0; i<length;i++){
            if (cmp(seq->Get(i),Max)>0){
                Max = seq->Get(i);
            }
            if (cmp(seq->Get(i),Min)<0){
                Min = seq->Get(i);
            }
        }
        auto* maxminarray = new T[2];
        maxminarray[0] = Max;
        maxminarray[1] = Min;
        return maxminarray;
    }
    T Average(T* array,T length){
        return (MaxMin(array,length)[0]- MaxMin(array,length)[1])/2;

    }
public:

    void Sort(ArraySequence<T>* seq,size_t start,size_t end,int cmp(T,T)){
        if (start >= end){
            return;
        }
        //T base = Average(array,end-start+1);
        //T base = MediumSeeker(array,(end-start+1));
        //T base = (MaxMin(seq,end-start+1,cmp)[0]+ MaxMin(seq,end-start+1,cmp)[1])*0.5;//за:удобно против: не для всех Т есть деление на интовую 2. Второй вариант выбирать посередине, если совпало с экстремумом, то брать конец или начало
        //T Max = MaxMin(seq,end-start+1,cmp)[0];
        //std::cout<<base<<std::endl;
        T base = seq->Get((start+end)/2);
        if (cmp(base,MaxMin(seq,end-start+1,cmp)[0])==0){
            base = seq->Get(end);
        }
        T swap_element;
        size_t left = start;
        size_t right = end;
        //std::cout<<"base = "<<base<<std::endl;

        while (left<right){
            if (cmp(seq->Get(left),base)<=0){//comp

                left++;


            }
            if (cmp(seq->Get(right),base)>0){//comp
                right--;

            }
            if (cmp(seq->Get(right),base)<=0&&cmp(seq->Get(left),base)>0&&right>left){//comp
                swap_element= seq->Get(right);
                seq->Set(seq->Get(left),right);
                seq->Set(swap_element,left);
                left++;
                right--;
            }
        }



        if (start == left){
            return;
        } if (end == right){
            return;
        }
        if (right==left){
            if (cmp(seq->Get(right),base)>0){
                right--;
            }else{
                left++;
            }
        }
        Sort(seq,left,end,cmp);
        Sort(seq,start,right,cmp);
        //std::cout<<"base = "<<base<<std::endl;
        //auto* DA = new DynamicArray(array,10);
        //for (int i = 0;i<DA->GetSize();i++){
        //    std::cout<<DA->Get(i)<<" ";
        //}
        //std::cout<<"\n";
    }
};
#endif //LABWORK_QUICKSORT_HPP
