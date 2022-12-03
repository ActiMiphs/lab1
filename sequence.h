#ifndef sequence_h
#define sequence_h

template <class T> class Sequence{
public:
    virtual ~Sequence() {};
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int i) = 0;
    virtual int GetLenght() = 0;
    virtual void Print() = 0;
    virtual void Append(T x) = 0;
    virtual void Prepend(T x) = 0;
    virtual void InsertAt(T pip, int p) = 0;
    virtual void Fillrand() = 0;
    virtual void Fillkey() = 0;
    virtual void Set(int i, T x) = 0;
    
};
#endif 
