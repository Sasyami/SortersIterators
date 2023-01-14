//
// Created by azari on 14.10.2022.
//
//
// Created by User on 14.05.2022.
//

#ifndef LAB2PRJ_LINKEDLISTSEQUENCE_HPP
#define LAB2PRJ_LINKEDLISTSEQUENCE_HPP
#include "IndexOutOfRange.hpp"
#include "Sequence.hpp"
#include <iostream>
#include "LinkedList.hpp"
template <class T> class LinkedListSequence: public Sequence<T>{
private:
    LinkedList<T>* list;

public:
    LinkedListSequence (T* items, int count){

        list = new LinkedList<T>(items,count);
    }
public:
    LinkedListSequence (){
        list = new LinkedList<T>();
    }
    LinkedListSequence(Sequence<T>* _seq){
        list = new LinkedList<T>();
        for (auto i = 0;i<_seq->GetLength();i++){
            list->Append(_seq->Get(i));
        }
    }
public:
    explicit LinkedListSequence (const LinkedList <T> & outer_list){
        list = new LinkedList<T>(outer_list);
    }
public:
    ~LinkedListSequence() = default;    //delete list;
public:
    LinkedListSequence<T>& operator=(const LinkedList <T> & outer_list){
        if (this!=nullptr && this->list!=nullptr){
            delete this->list;
        }
        list = new LinkedList<T>(outer_list);
        return *this;
    }
    typename LinkedList<T>::iteratorL beginLS(){
        return list->beginL();
    }
    typename LinkedList<T>::iteratorL endLS(){
        return list->endL();
    }
public:
    T GetFirst() const override{
        return list->GetFirst();
    }
public:
    T GetLast() const override{
        return list->GetLast();
    }
public:
    T Get(size_t i) const override{
        return list->Get(i);
    }
    LinkedListNode<T>* GetNode(size_t i){
        return list->GetNode(i);
    }
public:
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override{
        auto* new_list = new LinkedListSequence<T> (*this->list->GetSubList(startIndex,endIndex));
        return new_list;
    }
public:
    size_t GetLength() override{
        return list->GetLength();
    }
public:
    void Append(T item) override{
        list->Append(item);
    }
public:
    void Prepend(T item) override{
        list->Prepend(item);
    }
public:
    void InsertAt(T item, size_t index) override{
        list->InsertAt(item,index);
    }
public:
    Sequence <T>* Concat(Sequence <T> *outer_list) override{
        for( int i = 0;i<outer_list->GetLength();i++){
            list->Append(outer_list->Get(i));
        }
        return this;
    }
public:
    void Set(T item,size_t index) override{
        list->Set(item,index);
    }
    void Delete(size_t index){
        LinkedListNode<T>* node = list->FirstNode;
        for (size_t i = 0;i<index;i++){
            node = node->GetNext();
        }
        list->Delete(node);

    }
    friend QuickListSorter<T>;
    typename LinkedList<T>::iteratorL begin(){
        return list->begin();
    }
    typename LinkedList<T>::iteratorL end(){
        return list->end();
    }
    typename LinkedList<T>::iteratorL rend(){
        return list->rend();
    }
    typename LinkedList<T>::iteratorL rbegin(){
        return list->rbegin();
    }

};
#endif //LAB2PRJ_LINKEDLISTSEQUENCE_HPP