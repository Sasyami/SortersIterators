//
// Created by azari on 13.01.2023.
//

#ifndef MAIN_CPP_TESTS_HPP
#define MAIN_CPP_TESTS_HPP
#include <iostream>
#include "DynamicArray.hpp"
#include "Smiles.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "Zoo.hpp"
#include "LinkedListSequence.hpp"
#include "QuickListSort.hpp"
#include "ISorter.hpp"
#include "ItSorter.hpp"
#include <cstdlib>
#include <chrono>
#include <algorithm>
int comparator(int& i1,int& i2){
    return i1-i2;
}
int cmprtrTest(const void* i1,const void* i2){
    return *(int*)i1-*(int*)i2;
}
template <class T>
class Tester{
public:
    ArraySequence<T>* array;
    LinkedListSequence<T>* list;
    Tester(){
        array = nullptr;
        list = nullptr;
    }
public:
    void testQuickSort(int numberOfElements){


        srand(time(NULL));
        auto base_array = new T[numberOfElements];
        for (int i =0;i<numberOfElements;++i){
            base_array[i] = rand()%1000;
        }

        array = new ArraySequence<T>(base_array,numberOfElements);

        list = new LinkedListSequence<T>(base_array,numberOfElements);


        ItSorter<int,comparator, typeof(array->begin())> arrayItSorter;
        const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
        arrayItSorter.qsort(array->begin(),--array->end());
        const auto end = std::chrono::steady_clock::now();


        std::cout<< "Array Qsort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

        ItSorter<int,comparator, typeof(list->begin())> listItSorter;
        const auto _start = std::chrono::steady_clock::now();
        listItSorter.qsort(list->begin(),--list->end());
        const auto _end = std::chrono::steady_clock::now();//почему нельзя end = ?

        std::cout<< "List Qsort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;
        delete list;
        delete array;
    }
    void testMergeSort(int numberOfElements){


        srand(time(NULL));
        auto base_array = new T[numberOfElements];
        for (int i =0;i<numberOfElements;++i){
            base_array[i] = rand()%1000;
        }

        array = new ArraySequence<T>(base_array,numberOfElements);

        list = new LinkedListSequence<T>(base_array,numberOfElements);


        ItSorter<int,comparator, typeof(array->begin())> arrayItSorter;
        const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
        arrayItSorter.msort(array->begin(),array->GetLength());
        const auto end = std::chrono::steady_clock::now();


        std::cout<< "Array Msort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

        ItSorter<int,comparator, typeof(list->begin())> listItSorter;
        const auto _start = std::chrono::steady_clock::now();
        listItSorter.msort(list->begin(),list->GetLength());
        const auto _end = std::chrono::steady_clock::now();//почему нельзя end = ?

        std::cout<< "List Msort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;
        delete list;
        delete array;
    }
    void testBubbleSort(int numberOfElements){


        srand(time(NULL));
        auto base_array = new T[numberOfElements];
        for (int i =0;i<numberOfElements;++i){
            base_array[i] = rand()%1000;
        }

        array = new ArraySequence<T>(base_array,numberOfElements);

        list = new LinkedListSequence<T>(base_array,numberOfElements);


        ItSorter<int,comparator, typeof(array->begin())> arrayItSorter;
        const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
        arrayItSorter.bubblesort(array->begin(),--array->end());
        const auto end = std::chrono::steady_clock::now();


        std::cout<< "Array bubblesort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

        ItSorter<int,comparator, typeof(list->begin())> listItSorter;
        const auto _start = std::chrono::steady_clock::now();
        listItSorter.bubblesort(list->begin(),--list->end());
        const auto _end = std::chrono::steady_clock::now();//почему нельзя end = ?

        std::cout<< "List bubblesort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;
        delete list;
        delete array;
    }
    void testSort(int numberOfSort){

        auto numberOfElements  = 10;
        srand(time(NULL));
        auto base_array = new T[numberOfElements];
        for (int i =0;i<numberOfElements;++i){
            base_array[i] = rand()%1000;
            std::cout<<base_array[i]<<" ";
        }
        std::cout<<"\n";

        array = new ArraySequence<T>(base_array,numberOfElements);

        list = new LinkedListSequence<T>(base_array,numberOfElements);
        if (numberOfSort == 1){
            ItSorter<int,comparator, typeof(array->begin())> arrayItSorter;
            const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
            arrayItSorter.qsort(array->begin(),--array->end());
            const auto end = std::chrono::steady_clock::now();

            for (int i = 0;i<numberOfElements;++i){
                std::cout<<array->operator[](i)<<" ";
            }
            std::cout<<"\n";
            std::cout<< "Array Qsort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

            ItSorter<int,comparator, typeof(list->begin())> listItSorter;
            const auto _start = std::chrono::steady_clock::now();
            listItSorter.qsort(list->begin(),--list->end());
            const auto _end = std::chrono::steady_clock::now();//почему нельзя end = ?

            std::cout<< "List Qsort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

        }
        if (numberOfSort == 2){
            ItSorter<int,comparator, typeof(array->begin())> arrayItSorter;
            const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
            arrayItSorter.msort(array->begin(),array->GetLength());
            const auto end = std::chrono::steady_clock::now();

            for (int i = 0;i<numberOfElements;++i){
                std::cout<<array->operator[](i)<<" ";
            }
            std::cout<<"\n";
            std::cout<< "Array Msort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

            ItSorter<int,comparator, typeof(list->begin())> listItSorter;
            const auto _start = std::chrono::steady_clock::now();
            listItSorter.msort(list->begin(),list->GetLength());
            const auto _end = std::chrono::steady_clock::now();//почему нельзя end = ?

            std::cout<< "List Msort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

        }

        if (numberOfSort == 3){
        ItSorter<int,comparator, typeof(array->begin())> arrayItSorter;
        const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
        arrayItSorter.bubblesort(array->begin(),--array->end());
        const auto end = std::chrono::steady_clock::now();

        for (int i = 0;i<numberOfElements;++i){
                std::cout<<array->operator[](i)<<" ";
            }std::cout<<"\n";
        std::cout<< "Array bubblesort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;

        ItSorter<int,comparator, typeof(list->begin())> listItSorter;
        const auto _start = std::chrono::steady_clock::now();
        listItSorter.bubblesort(list->begin(),--list->end());
        const auto _end = std::chrono::steady_clock::now();//почему нельзя end = ?

        std::cout<< "List bubblesort of "<<numberOfElements<<" elements took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<std::endl;
        }

        delete list;
        delete array;
    }

};
#endif //MAIN_CPP_TESTS_HPP
