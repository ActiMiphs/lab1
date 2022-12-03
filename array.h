#include <iostream>
#include <cassert>


using namespace std;


template <class T>

class DynamicArray{
private:
    int capacity;
    T* arr;
    int size;
public:
    
    DynamicArray()
    :capacity(10)
    , size(0){
        
    }
    
    DynamicArray(int i, int b){
        this->capacity = i;
        this->size = b;
    }
    
    
    DynamicArray(int sz)
    : capacity(10)
    , size(sz)
    {
        if (size < 0){
            throw out_of_range("index out of bounds");
            return;
            
        }
        if (size > capacity) capacity += size;
        arr = new T[capacity];
        for(int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& other)
    : capacity(other.capacity), arr(new T[capacity]), size(other.size)
    {
        for(int i = 0; i <size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    DynamicArray(T*items, int count)
    : capacity(count+1), arr(new T[capacity]), size(count){
        for(int i = 0; i < size; ++i) {
            arr[i] = items[i];
        }
    }
    
    ~DynamicArray() {
        delete[] arr;
    }

    int GetSize() const {
        return size;
    }

    int GetCapacity() const {
        return capacity;
    }

    T Get(int i) const {
       if (i < 0 || i > size)
            throw out_of_range("index out of bounds");
        
        return arr[i];
    }

   
    void Set(int i, T x) {
        if (i < 0 || i > size) throw out_of_range("index out of bounds");
        arr[i] = x;
    }

    void Print() const {
        if (this -> size == 0) {
            cout << "()";
        } else {
            cout << "(";
            cout << arr[0];
            for (int i = 1; i < size; ++i) {
                cout << ", " << arr[i];
            }
            cout << ")";
            cout << "\n";
        }
    }


   void Append (T x) {
       if (size >= capacity) {
          capacity = 2 * capacity;
          T* new_arr = new T[capacity];

          for(int i = 0; i < size; ++i) {
             new_arr[i] = arr[i];
          }

          delete[] arr;

          arr = new_arr;
       }
       assert(size < capacity);
       arr[size] = x;
       size++;
   }
    
    void Prepend(T x){
        if (size >= capacity) {
            capacity = 2 * capacity;
        }
           T* new_arr = new T[capacity];
            new_arr[0] = x;
            for(int i = 1; i<=size;i++){
                new_arr[i] = arr[i-1];
            }
            delete[] arr;
            arr = new_arr;
        
            size++;
    }
    
    void Resize(int k){
        if (k>capacity){
            capacity = 2 * capacity;
        }
        if(k>size){
            T* new_arr = new T[capacity];
            for(int i =0; i < size; i++){
                new_arr[i] = arr[i];
            }
            for(int i = size; i<k;i++){
                new_arr[i] = 0;
            }
            delete[]arr;
            arr= new_arr;
            size = k;
        }
        if(k<size){
            T* new_arr = new T[capacity];
            for(int i =0; i < k; i++){
                new_arr[i] = arr[i];
            }
            delete[]arr;
            arr = new_arr;
            size = k;
        }
    }
    
    void InsertAt(T pip, int p){
        
    
        if(p<0||p>this->GetSize()) throw out_of_range("index out of bounds");
       
        if (size >= capacity) {
            capacity = 2 * capacity;
            
        }
           T* new_arr = new T[capacity];
        for(int i = 0; i<p; i++){
            new_arr[i] = arr[i];
        }
        new_arr[p] = pip;
        
        for(int i = p+1; i<=size;i++){
            new_arr[i] = arr[i-1];
        }
        delete[]arr;
        arr = new_arr;
        size++;
            
    }
    void Fillrand(){
        for(int i = 0; i<size; i++){
            arr[i] = -10000 + static_cast<T>(rand()/(static_cast<T>(RAND_MAX)/(20000)));
        }
    }
    void Fillkey(){
        cout << "Enter your elements" << endl;
        for(int i = 0; i<size; i++){
            cin >> arr[i];
        }
    }
    DynamicArray& operator = (const DynamicArray &other){
        this->capacity = other.GetCapacity();
        this->size = other.GetSize();
        if(arr){
            delete[] arr;
        }
        this->arr = new T[other.capacity];
        for(int i = 0; i<size; i++){
            this->arr[i] = other.arr[i];
        }
        return *this;
    }
};

