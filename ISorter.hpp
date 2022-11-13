//
// Created by azari on 08.11.2022.
//

#ifndef MAIN_CPP_ISORTER_HPP
#define MAIN_CPP_ISORTER_HPP
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
template <class T>
class ISorter{
private:
    T Min(LinkedListSequence<T>* list,size_t len, int cmp(T,T)){
        if (list==nullptr || len == 0){
            throw IndexOutOfRange(WrongInput);
        }
        T Min = list->Get(0);
        for (int i = 1;i<len;i++){
            if (cmp(list->Get(i),Min)<0){
                Min = list->Get(i);
            }
        }
        return Min;
    }
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

    void qsort(ArraySequence<T>* seq,size_t start,size_t end,int cmp(T,T) ){
        if (start >= end){
            return;
        }

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
        qsort(seq,left,end,cmp);
        qsort(seq,start,right,cmp);


    }
    void qsort(LinkedListSequence<T>* List, LinkedListNode<T>* first, LinkedListNode<T>* last,int cmp(T,T)){
        if (last == nullptr || first == nullptr || first == last) {
            return;
        }
        //std::cout<<first->GetValue()<<" "<<first->GetNext()<<" to "<<last->GetValue()<<" "<<last->GetPrev()->GetValue()<<std::endl;
        LinkedListNode<T> *new_last = last;
        bool is_sorted = true;
        auto* i = first;
        auto* first_prev = first->GetPrev();
        while(i!=last){
            //std::cout<<i->GetValue()<<std::endl;
            if (cmp(i->GetValue(), last->GetValue())>0) {
                is_sorted = false;
                auto* t = i->GetNext();
                i->GetPrev()->SetNext(i->GetNext());
                if (i->GetNext() != nullptr) {
                    i->GetNext()->SetPrev(i->GetPrev());
                }
                i->SetNext(new_last->GetNext());
                if (new_last->GetNext() != nullptr) {
                    new_last->GetNext()->SetPrev(i);
                }
                new_last->SetNext(i);
                i->SetPrev(new_last);
                new_last = i;
                //std::cout<<new_last->GetValue()<<" new_last gv"<<std::endl;
                i = t;
            }else{
                i = i->GetNext();
            }
        }
        /*std::cout<<"\n";
        for (int t = 0;t<List->GetLength();t++){
            std::cout<<List->Get(t)<<" ";
        }
        std::cout<<"\n";*/

        if(first_prev->GetNext()!=last) {

            qsort(List, first_prev->GetNext(), last->GetPrev(),cmp);
        }

        qsort(List, last, new_last,cmp);

    }
public:
    void qsort(ArraySequence<T>* seq, int cmp(T,T)){
        qsort(seq,0,seq->GetLength()-1,cmp);
    }
    void qsort(LinkedListSequence<T>* List,int cmp(T,T)){
        List->Prepend(Min(List,List->GetLength(),cmp));
        //std::cout<<List->list->FirstNode->GetNext()->GetValue()<<" - first that we need, "<<List->list->LastNode->GetValue()<<" last"<<std::endl;
        qsort(List,List->list->FirstNode->GetNext(),List->list->LastNode,cmp);
        List->Delete(0);
    }
};
#endif //MAIN_CPP_ISORTER_HPP
