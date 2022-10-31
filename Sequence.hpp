//
// Created by azari on 08.10.2022.
//

#ifndef MAIN_CPP_SEQUENCE_HPP
#define MAIN_CPP_SEQUENCE_HPP
#include <iostream>
template <class T> class Sequence{
public:
    virtual ~Sequence()= default;;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(size_t index) const = 0;
    virtual Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) = 0;
    virtual size_t GetLength() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, size_t index) = 0;
    virtual Sequence <T>* Concat(Sequence <T> *list) = 0;
    virtual void Set(T item,size_t index) = 0;
};
#endif //MAIN_CPP_SEQUENCE_HPP
