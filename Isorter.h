#include <iostream>
#include "sequence.h"

template <class T>
class Isorter{
private:
    
    void swap(Sequence<T>*seq,int a,int b){
        T temp = seq->Get(a);
        seq->Set(a,seq->Get(b));
        seq->Set(b,temp);
    }
    
    void heapify(Sequence<T>*seq, int n, int i){
        int largest = i;
            
            int l = 2 * i + 1;
            
            int r = 2 * i + 2;
          
            if (l < n && seq->Get(l) > seq->Get(largest))
                largest = l;
          
            if (r < n && seq->Get(r) > seq->Get(largest))
                largest = r;

            if (largest != i) {
                swap(seq, i, largest);
        
                heapify(seq, n, largest);
            }
    }
    
public:
    Isorter(){}
    ~Isorter(){}
    
    void shuffle(Sequence<T>*seq){
        srand(time(NULL));
        int n = seq->GetLenght();
        
        for (int i = n - 1; i > 0; i--){
                int j = rand() % (i + 1);
                swap(seq, i, j);
            }
    }
    void Bubble(Sequence<T>*seq){
        int n = seq->GetLenght();
        
        for(int i = 0; i<n-1;i++)
            for(int j=0;j<n-i-1;j++){
                if(seq->Get(j)>seq->Get(j+1)){
                    swap(seq,j,j+1);
                }
            }
    }
    void Shaker(Sequence<T>*seq){
        int n = seq->GetLenght();
        bool sort = true;
        do {
            sort = true;
            for (int i = 0; i < n; i++) {
              if (seq->Get(i) > seq->Get(i+1)) {
                swap (seq, i, i+1);
                sort = false;
              }
            }
            for (int i = 4; i >= 1; i--) {
              if (seq->Get(i) < seq->Get(i-1)) {
                swap (seq, i, i-1);
                sort = false;
              }
            }
          } while (sort == false);
    }
    void Insertion(Sequence<T>*seq){
        int n = seq->GetLenght();
        T key;
        int j;
            for (int i = 1; i < n; i++)
            {
                key = seq->Get(i);
                j = i - 1;
                while (j >= 0 && seq->Get(j) > key)
                {
                    swap(seq, j+1, j);
                    j = j - 1;
                }
                seq->Set(j+1, key);
            }
    }
   
    void Selection(Sequence<T>*seq){
        int n = seq->GetLenght();
        int min;
        for (int i = 0; i < n-1; i++)
            {
                min = i;
                for (int j = i+1; j < n; j++)
                if (seq->Get(j) < seq->Get(min))
                    min = j;
                swap(seq, min, i);
            }
    }
    
    void Shellsort(Sequence<T>*seq){
        int n = seq->GetLenght();
        for (int gap = n/2; gap > 0; gap /= 2)
            {
                for (int i = gap; i < n; i += 1)
                {
                    T temp = seq->Get(i);
                    int j;
                    for (j = i; j >= gap && seq->Get(j - gap) > temp; j -= gap)
                        seq->Set(j,seq->Get(j-gap));
                    seq->Set(j, temp);
                }
            }
    }
    
    void Heapsort(Sequence<T>*seq){
        int n = seq->GetLenght();
        for (int i = n / 2 - 1; i >= 0; i--)
                heapify(seq, n, i);
            for (int i = n - 1; i > 0; i--) {
                swap(seq, 0, i);
                heapify(seq, i, 0);
            }
    }
    
    void Quadraticsort(Sequence<T>*seq){
        int n = seq->GetLenght();
        for(int i = 0; i<n-1; i++){
            T m = seq->Get(i);
            int k = i;
            for(int j=i+1;j<n;j++)
                if(seq->Get(j)<m){
                    m = seq->Get(j);
                    k = j;
                }
                if(k!=i){
                    seq->Set(k, seq->Get(i));
                    seq->Set(i, m);
                }
                    
            }
        }
};

