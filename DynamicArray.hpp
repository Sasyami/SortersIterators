#ifndef LAB2PRJ_DYNAMICARRAY_HPP
#define LAB2PRJ_DYNAMICARRAY_HPP
#include "IndexOutOfRange.hpp"
template <class T> class DynamicArray{
private:
    T* array;
    size_t length;
public:
    class ArrayIterator{//random access iterator
    private:
        T* value;
    public:
        int curIndex;
        size_t maxIndex;
    public:
        ArrayIterator(T* start, size_t max_index,int cur_index = 0){
            if (max_index<cur_index||cur_index<0){
                value = nullptr;
            }else {
                value = start;
            }
            curIndex = cur_index;
            maxIndex = max_index;
        }
        T& operator *(){
            return *value;
        }
        ArrayIterator& operator ++ (){
            value++;
            curIndex++;
            if (curIndex>maxIndex){
                value = nullptr;
            }
            return *this;
        }
        bool operator < (const ArrayIterator& iterator){
            if (value<iterator.value){
                return true;
            }
            return false;
        }
        bool operator > (const ArrayIterator& iterator){
            if (value>iterator.value){
                return true;
            }
            return false;
        }
        bool operator <= (const ArrayIterator& iterator){
            if (value<=iterator.value){
                return true;
            }
            return false;
        }
        bool operator >= (const ArrayIterator& iterator){
            if (value<iterator.value){
                return true;
            }
            return false;
        }
        ArrayIterator& operator + (size_t number){
            auto* new_iterator = new ArrayIterator(value,maxIndex,curIndex+number);
            return *new_iterator;

        }
        ArrayIterator& operator -- (){
            value--;
            curIndex--;
            if (curIndex<0||curIndex>maxIndex){
                value = nullptr;
            }
            return *this;
        }
        ArrayIterator& operator - (size_t number){
            auto* new_iterator = new ArrayIterator(value,maxIndex,curIndex-number);
            return *new_iterator;
        }

    };
public:

    DynamicArray(T* items,size_t count){
        int i;

        length = count;




        this->array = new T[this->length];
        for (i = 0;i<count;i++){


            this->array[i] = items[i];

        }

    }
public:
    explicit DynamicArray(size_t size){
        this->array = new T[size];
        length = size;


    }
public:
    //Перегрузка оператора =
    DynamicArray<T>& operator=(const DynamicArray<T>& dynamicArray){
        if (this!=nullptr && this->array!=nullptr){
            delete[] this->array;
        }
        this->array = new T[dynamicArray.GetSize()];
        length = dynamicArray.GetSize();

        for (int i = 0;i<length;i++){
            this->Set(i,dynamicArray.Get(i)) ;
        }
        return *this;
    }
public:
    ~DynamicArray(){
        delete[] array;

        array = NULL;
    }
public:
    DynamicArray(const DynamicArray<T>& dynamicArray){
        this->array = new T[dynamicArray.GetSize()];
        length = dynamicArray.GetSize();

        for (int i = 0;i<length;i++){
            this->Set(i,dynamicArray.Get(i)) ;
        }
    }
public:
    T Get(size_t index) const{


        if ((index<0)||(index+1>length)){
            throw IndexOutOfRange(WrongIndex);
        }

        T value = array[index];

        return value;
    }
public:
    size_t GetSize() const{
        //std::cout << "Im get size da "<<this->current_elements << std::endl;
        return this->length;
    }
public:
    void Set(size_t index,T value){
        if ((index>length)||(index<0)){
            throw IndexOutOfRange(WrongIndex);
        }
        array[index] = value;
    }
public:
    void Resize(size_t newSize){
        int i;
        T* new_array = new T[newSize];
        for (i = 0;i<length;i++){
            new_array[i] = this->array[i];

        }
        this->array = new_array;
        this->length = newSize;

    }



};

#endif //LAB2PRJ_DYNAMICARRAY_HPP