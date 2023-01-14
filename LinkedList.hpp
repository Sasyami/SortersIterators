//
// Created by azari on 17.09.2022.
//
#ifndef LAB2PRJ_LINKEDLIST_HPP
#define LAB2PRJ_LINKEDLIST_HPP
#include "IndexOutOfRange.hpp"
template <class k>
class LinkedListSequence;
template <class l>
class QuickListSorter;

template <class T>
class LinkedListNode{
public:
    virtual ~LinkedListNode() = default;
    virtual LinkedListNode* GetNext() = 0;
    virtual LinkedListNode* GetPrev() = 0;
    virtual void SetNext (LinkedListNode<T>* node) = 0;
    virtual void SetPrev (LinkedListNode<T>* node) = 0;
    virtual void SetValue (T value) = 0;
    virtual T& GetValue() = 0;

};
template <class T>
class LinkedList{
private:

    class LinkedListNodeInternal: public LinkedListNode<T>{
    private:
        LinkedListNode<T>* NextNode;
        LinkedListNode<T>* PrevNode;
        T value;
    public:
        LinkedListNodeInternal() {
            this->value = 0;
            this->NextNode = nullptr;
            this->PrevNode = nullptr;

        }
        explicit LinkedListNodeInternal(T a){
            value = a;
            NextNode = nullptr;
            PrevNode = nullptr;
        }
    public:

        ~LinkedListNodeInternal() {
            if (!NextNode) {
                delete NextNode;
                NextNode = NULL;
            }

            if (!PrevNode) {
                delete PrevNode;
                PrevNode = NULL;
            }



        }
        LinkedListNode<T>* GetNext() override {
            return this->NextNode;
        }
        LinkedListNode<T>* GetPrev() override {
            return this->PrevNode;
        }
        T& GetValue() override {
            //std::cout << "I am LinkedListNodeInternal GetValue" << std::endl;
            return this->value;
        }
        void SetNext (LinkedListNode<T>* node) override {


            this->NextNode = node;

        }
        void SetPrev (LinkedListNode<T>* node) override {


            this->PrevNode = node;

        }

        void SetValue (T Value) override {
            this->value = Value;
        }
    public:
    };
private:
    LinkedListNodeInternal* FirstNode;
    LinkedListNodeInternal* LastNode;
public:
    class iteratorL{
    private:
        LinkedListNode<T>* value;
        LinkedListNode<T>* last_node;
        bool is_reversed;
    public:
        //type = bidirectional
        T& operator *(){

            return value->GetValue();
        }
        explicit iteratorL(LinkedListNode<T>* _value, LinkedListNode<T>* _last_node = nullptr,bool _reverse = false){
            value = _value;
            last_node = _last_node;
            is_reversed = _reverse;
        }
        iteratorL(const iteratorL& newIter){
            value = newIter.value;
            last_node = newIter.last_node;
            is_reversed = newIter.is_reversed;
        }
        iteratorL& operator ++(){
            if (is_reversed){
                value = value->GetPrev();
            }else {
                value = value->GetNext();
            }
            return *this;
        }
        iteratorL operator ++(int){
            auto* retIter = new iteratorL(value);

            if (is_reversed){
                value = value->GetPrev();
            }else {
                value = value->GetNext();
            }
            return *retIter;
        }
        iteratorL& operator --(){
            if (value == nullptr){
                value = last_node;
                return *this;
            }
            if (is_reversed){
                value = value->GetNext();
            }else {
                value = value->GetPrev();
            }

            return *this;
        }
        iteratorL operator --(int){
            auto* retIter = new iteratorL(value);
            if (is_reversed){
                value = value->GetNext();
            }else {
                value = value->GetPrev();
            }
            return *retIter;
        }
        bool operator ==(const iteratorL& anotherIter){
            return anotherIter.value == value;
        }
        bool operator !=(const iteratorL& anotherIter){
            return anotherIter.value != value;
        }

    };
    iteratorL begin(){
        return iteratorL(FirstNode,LastNode);
    }
    iteratorL end(){
        return iteratorL(nullptr,LastNode);
    }
    iteratorL rbegin(){
        return iteratorL(LastNode,FirstNode,true);
    }
    iteratorL rend(){
        return iteratorL(nullptr,FirstNode,true);

    }
    ~LinkedList(){
        LinkedListNode<T>* current = FirstNode;
        LinkedListNode<T>* next;
        while (current!=NULL){
            next = current->GetNext();
            delete current;
            current = next;
            delete next;
        }
        //delete next;
    }

public:
    LinkedList (){

        /*auto* LLNI1 = new LinkedListNodeInternal;
        auto* LLNI2 = new LinkedListNodeInternal;
        LLNI1->SetValue((T)0);
        LLNI2->SetValue((T)0);
        LLNI1->SetNext(LLNI2);
        LLNI2->SetNext(nullptr);
        LLNI2->SetPrev(LLNI1);
        LLNI1->SetPrev(nullptr);
        this->FirstNode = LLNI1;
        this->LastNode = LLNI2;*/
        FirstNode = nullptr;
        LastNode = nullptr;

    }
public:
    LinkedList (T* items, int count){

        int i;
        if (items == NULL){
            throw IndexOutOfRange(WrongInput);
        }
        auto* first = new LinkedListNodeInternal;
        first->SetValue(items[0]);
        this->FirstNode = first;
        LinkedListNode<T>* prev = first;

        for (i = 1;i<count-1;i++){
            //std::cout<<count<<" - count\n";
            //std::cout<<items[i]<<"\n";
            if (!items[i]&&items[i]!=0){
                throw IndexOutOfRange(WrongIndex);
            }
            auto node = new LinkedListNodeInternal;
            node->SetValue(items[i]);
            prev->SetNext(node);
            node->SetPrev(prev);
            prev = node;

        }
        auto* last = new LinkedListNodeInternal;
        last->SetPrev(prev);
        prev->SetNext(last);
        last->SetValue(items[count-1]);
        this->LastNode = last;

    }
public:
    LinkedList (const LinkedList<T> & list){//

        auto* Node = new LinkedListNodeInternal;
        auto* prev = new LinkedListNodeInternal;
        LinkedListNode<T>* NodeSource = list.FirstNode;
        this->FirstNode = Node;
        while (NodeSource!=NULL){

            Node->SetValue(NodeSource->GetValue());
            prev->SetNext(Node);
            Node->SetPrev(prev);
            prev = Node;
            Node = new LinkedListNodeInternal;
            NodeSource = NodeSource->GetNext();
        }
        prev->SetNext(NULL);
        this->LastNode = prev;

    }
public:
    T GetFirst(){//

        if (this->FirstNode!=nullptr) {

            T t = (this->FirstNode)->GetValue();


            return t;
        }
        else{
            throw IndexOutOfRange(EmptyList);
        }

    }
public:
    T GetLast(){
        if ((this->FirstNode!=nullptr)) {
            return this->LastNode->GetValue();
        }
        else{
            throw IndexOutOfRange(EmptyList);
        }
    }
public:
    T Get(size_t index){
        int i;

        if ((this->FirstNode==nullptr)||(this->LastNode==nullptr)) {
            throw IndexOutOfRange(EmptyList);//new IndexOutOfRangeException();
        }
        LinkedListNode<T>* current = this->FirstNode;
        for (i = 1;i<=index;i++){
            if (current->GetNext()!=nullptr) {
                current = current->GetNext();
            }
            else{
                throw IndexOutOfRange(WrongIndex);
            }
        }
        return current->GetValue();
    }
    LinkedListNode<T>* GetNode(size_t index){
        int i;

        if ((this->FirstNode==nullptr)||(this->LastNode==nullptr)) {
            throw IndexOutOfRange(EmptyList);//new IndexOutOfRangeException();
        }
        LinkedListNode<T>* current = this->FirstNode;
        for (i = 1;i<=index;i++){
            if (current->GetNext()!=nullptr) {
                current = current->GetNext();
            }
            else{
                throw IndexOutOfRange(WrongIndex);
            }
        }
        return current;
    }
public:
    LinkedList<T>* GetSubList(size_t startIndex, size_t endIndex){
        int i;

        auto* new_list = new LinkedList;
        auto* first = new LinkedListNodeInternal;
        first->SetPrev(nullptr);
        first->SetValue(this->Get(startIndex));
        LinkedListNodeInternal* node;
        LinkedListNodeInternal* prev;
        prev = first;
        for (i = startIndex+1;i<=endIndex;i++){
            node = new LinkedListNodeInternal;
            node->SetValue(this->Get(i));
            node->SetPrev(prev);
            prev->SetNext(node);
            prev = node;
        }
        prev->SetNext(nullptr);
        new_list->FirstNode = first;
        new_list->LastNode = prev;
        return new_list;

    }
public:
    size_t GetLength(){
        int i= 0;
        LinkedListNode<T>* node = this->FirstNode;
        while (node!=nullptr){
            node = node->GetNext();
            i++;
        }
        return i;
    }
public:
    void Append (T item){
        auto* node = new LinkedListNodeInternal;
        node->SetValue(item);
        node->SetNext(nullptr);
        if (FirstNode==nullptr){
            node->SetPrev(nullptr);
            FirstNode = node;
        }
        if (LastNode == nullptr){
            FirstNode->SetNext(node);
            node->SetPrev(FirstNode);
        }
        this->LastNode->SetNext(node);
        node->SetPrev(this->LastNode);
        this->LastNode = node;
    }
public:
    void Prepend (T item){
        auto* node = new LinkedListNodeInternal;
        node->SetValue(item);
        node->SetPrev(nullptr);
        this->FirstNode->SetPrev(node);
        node->SetNext(this->FirstNode);
        this->FirstNode = node;
    }
public:
    void InsertAt(T item, size_t index){
        if (index==0){
            this->Prepend(item);
        }
        else{
            if (this->LastNode == nullptr){
                throw IndexOutOfRange(EmptyList);
            }
            int i;
            LinkedListNode<T>* prev;
            auto* current = new LinkedListNodeInternal;

            LinkedListNode<T>* node = this->FirstNode;
            for (i = 1;i<=index;i++){
                if (node==nullptr){
                    throw IndexOutOfRange(WrongIndex);
                }
                prev = node;
                node = node->GetNext();

            }
            //prev = node->GetPrev();
            current->SetPrev(prev);
            current->SetNext(node);
            current->SetValue(item);
            prev->SetNext(current);
            if (node!=nullptr) {
                node->SetPrev(current);
            }
        }
    }
public:
    void Set(T item, size_t index){
        if (index==0){
            this->Prepend(item);
        }
        else{
            if (this->LastNode == nullptr){
                throw IndexOutOfRange(EmptyList);
            }
            int i;



            LinkedListNode<T>* node = this->FirstNode;
            for (i = 1;i<index;i++){
                if (node==nullptr){
                    throw IndexOutOfRange(WrongIndex);
                }
                node = node->GetNext();

            }

            node->SetValue(item);

        }
    }
public:
    LinkedList<T>* Concat(LinkedList<T> *list){ //Переделать
        if ((list==NULL)||(list->FirstNode==NULL)||(this->LasNode==NULL)){
            throw IndexOutOfRange (EmptyList);
        }
        this->LastNode->SetNext(list->FirstNode);
        list->FirstNode->SetPrev(this->LastNode);
        this->LastNode = list->LastNode;
        return this;

    }
    void Delete(LinkedListNode<T>* node){
        if (node==FirstNode){
            FirstNode = new LinkedListNodeInternal(node->GetNext()->GetValue());
            FirstNode->SetNext(node->GetNext()->GetNext());
            delete node;
            return;
        }
        if (node==LastNode){
            LastNode = new LinkedListNodeInternal(node->GetPrev()->GetValue());
            LastNode->SetPrev(node->GetPrev()->GetPrev());
            delete node;
            return;
        }
        //std::cout<<node->GetNext()<<" "<<node->GetPrev()<<std::endl;
        node->GetPrev()->SetNext(node->GetNext());
        node->GetNext()->SetPrev(node->GetPrev());
        delete node;
    }
    /*void SetNewFirst(LinkedListNode<T>* new_head){
        auto* new_first = new LinkedListNodeInternal(new_head->GetValue());
        new_first->SetNext(FirstNode->GetNext());
        FirstNode = new_first;
    }*/
    friend LinkedListSequence<T>;
    friend QuickListSorter<T>;

};
#endif //LAB2PRJ_LINKEDLIST_HPP
