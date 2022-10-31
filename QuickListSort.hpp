//
// Created by azari on 14.10.2022.
//

#ifndef MAIN_CPP_QUICKLISTSORT_HPP
#define MAIN_CPP_QUICKLISTSORT_HPP
#include "IndexOutOfRange.hpp"
#include "LinkedList.hpp"
template <class T>
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
template <class T>
class QuickListSorter{
private:

    void Sort(LinkedListSequence<T>* List, LinkedListNode<T>* first, LinkedListNode<T>* last,int cmp(T,T)) {
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

            Sort(List, first_prev->GetNext(), last->GetPrev(),cmp);
        }

        Sort(List, last, new_last,cmp);
    }
public:
    void Sort(LinkedListSequence<T>* List,int cmp(T,T)){
        List->Prepend(Min(List,List->GetLength(),cmp));
        //std::cout<<List->list->FirstNode->GetNext()->GetValue()<<" - first that we need, "<<List->list->LastNode->GetValue()<<" last"<<std::endl;
        Sort(List,List->list->FirstNode->GetNext(),List->list->LastNode,cmp);
        List->Delete(0);

    }

};
#endif //MAIN_CPP_QUICKLISTSORT_HPP
