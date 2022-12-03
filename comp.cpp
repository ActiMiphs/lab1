#include "comp.h"
#include "arrayseq.h"
#include "sequence.h"
#include <iostream>
#include "Isorter.h"
#include <iomanip>

using namespace std;

void copy(Sequence<int>*one,Sequence<int>*two){
    for(int i = 0; i<two->GetLenght();i++)
        one->Set(i,two->Get(i));
}
void compare() {
    int count;
    while (true) {
        cout << "What's the length?" << endl;
        cin >> count;
        try {
            if (count > 0)
                break;
        }
        catch (const exception &e) {
        }
        cout << "The Length can't be negative" << endl;
    }

    Sequence<int> *seq1 = new ArraySequence<int>(count);
    Sequence<int> *seq2 = new ArraySequence<int>(count);
    Isorter<int> *sorter = new Isorter<int>;
    seq1->Fillrand();
    copy(seq2,seq1);
    clock_t begin = clock();
    sorter->Bubble(seq1);
    clock_t end = clock();
    cout<<"Bubble sort time " << ((long double)(end - begin) / CLOCKS_PER_SEC) << endl;
    copy(seq1, seq2);
    begin = clock();
    sorter->Shaker(seq1); //mt
    end = clock();
    cout<<"Shaker sort time " << ((double)(end - begin) / CLOCKS_PER_SEC) << endl;
    copy(seq1, seq2);
    begin = clock();
    sorter->Insertion(seq1);
    end = clock();
    cout<<"Insertion sort time " << ((double)(end - begin) / CLOCKS_PER_SEC) << endl;
    copy(seq1, seq2);
    begin = clock();
    sorter->Selection(seq1);
    end = clock();
    cout<<"Selection sort time " << ((double)(end - begin) / CLOCKS_PER_SEC) << endl;
    copy(seq1, seq2);
    begin = clock();
    sorter->Heapsort(seq1);
    end = clock();
    cout<<"Heapsort sort time " << ((double)(end - begin) / CLOCKS_PER_SEC) << endl;
    copy(seq1, seq2);
    begin = clock();
    sorter->Shellsort(seq1);
    end = clock();
    cout<<"Shellsort sort time " << ((double)(end - begin) / CLOCKS_PER_SEC) << endl;
    copy(seq1, seq2);
    begin = clock();
    sorter->Quadraticsort(seq1);
    end = clock();
    cout<<"Quadratic sort time " << ((double)(end - begin) / CLOCKS_PER_SEC) << endl;}
