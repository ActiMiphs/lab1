
#include "test.h"
#include <unistd.h>
#include <iostream>
#include "sequence.h"
#include "listseq.h"
#include "arrayseq.h"
#include "Isorter.h"

template <typename T>
T* fill_rand(T*arr, int k){
    for(int i = 0; i<k; i++){
        arr[i] = -10 + static_cast<T>(rand()/(static_cast<T>(RAND_MAX)/(20)));
    }
    return arr;
}

template <typename T>
int test_Getfirst(Sequence<T>*one , T* arr){
    if(one->GetFirst() != arr[0]){
        return 1;
    }
    return 0;
}

template <typename T>
int test_Getlast(Sequence<T>*one , T* arr, int k){
    if(one->GetLast() != arr[k-1]){

        return 1;
    }
    return 0;
}


template <typename T>
int test_Append(Sequence<T>*one){
    T k = -10 + static_cast<T>(rand()/(static_cast<T>(RAND_MAX)/(20)));
    one->Append(k);
    if(one->GetLast()!=k){
        return 1;
    }
    return 0;
}


template <typename T>
int test_Prepend(Sequence<T>*one){
    T k = -10 + static_cast<T>(rand()/(static_cast<T>(RAND_MAX)/(20)));
    one->Prepend(k);
    if(one->GetFirst()!=k){
        return 1;
    }
    return 0;
}


template <typename T>
int test_Insertat(Sequence<T>*one){
    T k = -10 + static_cast<T>(rand()/(static_cast<T>(RAND_MAX)/(20)));
    int p = rand()%(one->GetLenght());
    one->InsertAt(k, p);
    if(one->Get(p)!=k){
        return 1;
    }
    return 0;
}

template <typename T>
int check(Sequence<T>*seq){
    for(int i =0; i < seq->GetLenght()-1; i++){
        if(seq->Get(i)>seq->Get(i+1))
            return 1;
    }
    return 0;
}
void test_result(string name, int result){
    if(result==1)
        cout<< "Error "<< name<<endl;
    else
        cout << "Success "<< name <<endl;
}



void testing(){
    srand(time(NULL));

    Sequence<int>* seq1 = NULL;
    Sequence<double>* seq2 = NULL;
    Isorter<int>*sort1 = NULL;
    Isorter<double>*sort2 = NULL;


    int *arri = new int[5];
    double *arrd = new double[5];

    arri = fill_rand(arri, 5);
    arrd = fill_rand(arrd, 5);




    seq1 = new ArraySequence<int>(arri, 5);

    
    test_result("Getfirst, array int",test_Getfirst(seq1, arri));
    usleep(500000);;
    test_result("Getlast, array int", test_Getlast(seq1, arri, 5));
    usleep(500000);
    test_result("Append array int", test_Append(seq1));
    usleep(500000);
    test_result("Prepend array int", test_Prepend(seq1));
    usleep(500000);
    test_result("Insert array int", test_Insertat(seq1));
    usleep(500000);
    delete seq1;


    seq2 = new ArraySequence<double>(arrd, 5);

    
    test_result("Getfirst, array double",test_Getfirst(seq2, arrd));
    usleep(500000);;
    test_result("Getlast, array double", test_Getlast(seq2, arrd, 5));
    usleep(500000);
    test_result("Append array double", test_Append(seq2));
    usleep(500000);
    test_result("Prepend array double", test_Prepend(seq2));
    usleep(500000);
    test_result("Insert array double", test_Insertat(seq2));
    usleep(500000);
    delete seq2;


    seq1 = new LinkedListSequence<int>(arri, 5);

    test_result("Getfirst, list int",test_Getfirst(seq1, arri));
    usleep(500000);;
    test_result("Getlast, list int", test_Getlast(seq1, arri, 5));
    usleep(500000);
    test_result("Append list int", test_Append(seq1));
    usleep(500000);
    test_result("Prepend list int", test_Prepend(seq1));
    usleep(500000);
    test_result("Insert list int", test_Insertat(seq1));
    usleep(500000);
    delete seq1;



    seq2 = new LinkedListSequence<double>(arrd, 5);


    test_result("Getfirst, list double",test_Getfirst(seq2, arrd));
    usleep(500000);;
    test_result("Getlast, list double", test_Getlast(seq2, arrd, 5));
    usleep(500000);
    test_result("Append list double", test_Append(seq2));
    usleep(500000);
    test_result("Prepend list double", test_Prepend(seq2));
    usleep(500000);
    test_result("Insert list double", test_Insertat(seq2));
    usleep(500000);
    usleep(500000);

    delete seq2;
    
    delete[] arri;
    delete[] arrd;
    
    
    
    
    
    arri = new int[100];
    arri = fill_rand(arri, 100);
    
    
    seq1 = new ArraySequence<int>(arri, 100);
    sort1 = new Isorter<int>();
    sort1->Bubble(seq1);
    cout<<endl;
    test_result("Bubble sort int",check(seq1));
    usleep(500000);
    sort1->shuffle(seq1);
    sort1->Heapsort(seq1);
    test_result("Heap sort int",check(seq1));
    usleep(500000);
    sort1->shuffle(seq1);
    sort1->Insertion(seq1);
    test_result("insertion sort int",check(seq1));
    usleep(500000);
    sort1->shuffle(seq1);
    sort1->Quadraticsort(seq1);
    test_result("Quadratic sort int",check(seq1));
    usleep(500000);
    sort1->shuffle(seq1);
    sort1->Selection(seq1);
    test_result("Selection sort int",check(seq1));
    usleep(500000);
    sort1->shuffle(seq1);
    sort1->Shaker(seq1);
    test_result("Shaker sort int",check(seq1));
    usleep(500000);
    sort1->shuffle(seq1);
    sort1->Shellsort(seq1);
    test_result("Shell sort int",check(seq1));
    usleep(500000);
    
    delete sort1;
    delete[]arri;
    delete seq1;
    
    
    arrd = new double[100];

    
    arrd = fill_rand(arrd, 100);
    
    
    seq2 = new ArraySequence<double>(arrd, 100);
    sort2 = new Isorter<double>();
    sort2->Bubble(seq2);
    cout<<endl;
    test_result("Bubble sort double",check(seq2));
    usleep(500000);
    sort2->shuffle(seq2);
    sort2->Heapsort(seq2);
    test_result("Heap sort double",check(seq2));
    usleep(500000);
    sort2->shuffle(seq2);
    sort2->Insertion(seq2);
    test_result("insertion sort double",check(seq2));
    usleep(500000);
    sort2->shuffle(seq2);
    sort2->Quadraticsort(seq2);
    test_result("Quadratic sort double",check(seq2));
    usleep(500000);
    sort2->shuffle(seq2);
    sort2->Selection(seq2);
    test_result("Selection sort double",check(seq2));
    usleep(500000);
    sort2->shuffle(seq2);
    sort2->Shaker(seq2);
    test_result("Shaker sort double",check(seq2));
    usleep(500000);
    sort2->shuffle(seq2);
    sort2->Shellsort(seq2);
    test_result("Shell sort double",check(seq2));
    usleep(500000);
    
    delete sort2;
    delete[]arrd;
    delete seq2;

}
