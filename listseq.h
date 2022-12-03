
#ifndef listseq_h
#define listseq_h
#include "sequence.h"
#include "list.h"

template <class T>
class LinkedListSequence : public Sequence<T>{
private:
    LinkedList<T>*items;
public:
    
    LinkedListSequence()
        :items(new LinkedList<T>()){};
    LinkedListSequence(int p)
        :items(new LinkedList<T>(p)){};
    LinkedListSequence(LinkedList<T>& one, LinkedList<T>& two)
        :items(new LinkedList<T>(one, two)){};
    LinkedListSequence(LinkedList<T>& other,int startIndex, int endIndex)
        :items(new LinkedList<T>(other, startIndex, endIndex)){};
    LinkedListSequence(LinkedList <T>& other)
        :items(new LinkedList<T>(other)){};
    LinkedListSequence(T* itemss, int count)
        :items(new LinkedList<T>(itemss, count)){};

    virtual ~LinkedListSequence(){
        delete items;
    }
    
   virtual void Print() override{
        this->items->Print();
    }
    virtual T GetFirst() override{
        return this->items->GetFirst();
    }
    virtual T GetLast() override{
        return this->items->GetLast();
    }
    virtual int GetLenght() override{
        return this->items->GetLength();
    }
   virtual void Append(T x) override{
        this->items->append(x);
    }
    virtual void Prepend(T x) override{
        this->items->prepend(x);
    }
    virtual T Get(int i) override{
        return this->items->Get(i);
    }
    virtual void Set(int i, T x) override{
        this->items->Set(i, x);
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

#endif /* listseq_h */
