
#ifndef arrayseq_h
#define arrayseq_h

#include "sequence.h"
#include "array.h"

template <class T>
class ArraySequence : public Sequence<T>{
private:
    DynamicArray<T>* items;
public:
   
    
    ArraySequence()
    :items(new DynamicArray <T> ()){};
    ArraySequence(int count)
    :items(new DynamicArray <T> (count)){};
    ArraySequence(const DynamicArray<T>& other)
    :items(new DynamicArray <T> (other)){};
    ArraySequence(T*itemss, int count)
    :items(new DynamicArray<T>(itemss,count)){};
    
    
    virtual ~ArraySequence(){
        delete items;
    }
    virtual T GetFirst() override{
        return this->items->Get(0);
    }
    virtual T GetLast ()override{
        return this->items->Get((this->items->GetSize())-1);
    }
    virtual T Get(int i) override{
        return this->items->Get(i);
    }
    
    virtual int GetLenght() override{
        return this->items->GetSize();
    }
    virtual void Set(int i, T x) override{
        this->items->Set(i, x);
    }
    virtual void Print() override{
        this->items->Print();
    }
    virtual void Append(T x) override{ // shireet zayka
        this->items->Append(x);
    }
    virtual void Prepend(T x) override{
        this->items->Prepend(x);
    }
    
    virtual void InsertAt(T pip, int p) override{
        this->items->InsertAt(pip, p);
    }
    virtual void Fillrand() override{
        this->items->Fillrand();
    }
    virtual void Fillkey() override{
        this->items->Fillkey();
    }
    
  
};

#endif /* arrayseq_h */
