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
#include <time.h>
#include "tests.hpp"
#include <cstdlib>
int cmprtr(int& i1,int& i2){
    return i1-i2;
}
int WeightCmp(Animal* a1, Animal* a2){
    return a1->weight-a2->weight;
}
void SquirellInfo(ArraySequence<Animal*> *seq){
    for (int i = 0;i<seq->GetLength();i++){
        if (dynamic_cast<Squirrel*>((seq->Get(i)))!=nullptr){
            std::cout<<dynamic_cast<Squirrel*>((seq->Get(i)))->weight<<" - weight, "
            <<dynamic_cast<Squirrel*>((seq->Get(i)))->age<<" - age, "
            <<dynamic_cast<Squirrel*>((seq->Get(i)))->name<<" - name"<<std::endl;
        }
    }
}
void KangorooNames(ArraySequence<Animal*> *seq){
    for (int i = 0;i<seq->GetLength();i++){
        if (dynamic_cast<Kangooroo*>((seq->Get(i)))!=nullptr){
            std::cout<<dynamic_cast<Kangooroo*>((seq->Get(i)))->name<<std::endl;
        }
    }
}
int main() {
    int massive[] ={6,4,2,3,5,0,1,1,1,9};
    auto* Aseq = new ArraySequence<int>(massive,6);
    auto* LLseq = new LinkedListSequence<int>(massive,6);
    /*LLseq->Delete(2);
    LLseq->InsertAt(10,9);*/
    QuickListSorter<int> ListSorter;
    ISorter<int> Sorter;
    MergeSort<int> MergeSorter;
    ItSorter<int,cmprtr, typeof(LLseq->begin())> ItSorter;
    /*DynamicArray<int>::ArrayIterator new_it = Aseq->beginAS();
    //ListSorter.Sort(LLseq,cmprtr);
    //MergeSorter.Sort(Aseq,0,9,cmprtr);
    //Sorter.qsort(Aseq, cmprtr);
    //auto* DA = new DynamicArray<int>(massive,10);
    //DynamicArray<int>::ArrayIterator iterator = Aseq->begin();
    //std::cout<<*(--(Aseq->rend()))<<std::endl;*/

    ItSorter.bubblesort(LLseq->begin(),--LLseq->end());

    //std::cout<<(stop-start)<<"\n"<<std::endl;

    for (int & i : *LLseq){

        std::cout<<i<<"\n";

    }
    /*auto* mass = new int[1000];
    srand(NULL);
    for (int i = 0;i<1000;i++){
        mass[i] = rand()%1000;
    }
    const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    qsort(mass,1000,4,cmprtrTest);
    const auto end = std::chrono::steady_clock::now();

    std::cout<< "Calculations took "<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();*/
    Tester<int> test;
    test.testSort(1);
    test.testQuickSort(10000);
    test.testMergeSort(10000);
    test.testBubbleSort(100);
    //std::cout<<"\n";

    /*
    auto* kru1 = new Kangooroo (20,30,"Jopa");
    auto* kru2 = new Kangooroo (15,6,"Brat Jopbi");
    auto* cat1 = new Cat (43,10,"Kotleta");
    auto* cat2 = new Cat (14,88,"Hitler");
    auto* sqi2 = new Squirrel (19,37,"Stalin");
    auto* sqi1 = new Squirrel (5,18,"Prizivnik");
    ArraySequence<Animal*> seq;
    seq.Append(kru1);
    seq.Append(sqi2);
    seq.Append(cat2);
    seq.Append(kru2);
    seq.Append(cat1);
    seq.Append(sqi1);
    SquirellInfo(&seq);
    QuickSort<Animal*> AnimalSorter;
    AnimalSorter.Sort(&seq,0,5, WeightCmp);
    KangorooNames(&seq);*/

    return 0;

}
