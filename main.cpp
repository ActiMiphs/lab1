#include <iostream>
#include "sequence.h"
#include "arrayseq.h"
#include "Isorter.h"
#include "time.h"
#include "menu.hpp"
#include "test.h"
#include <chrono>
#include "comp.h"
#include <iomanip>

using namespace std;


template <typename T>
int check(Sequence<T>*seq){
    for(int i =0; i < seq->GetLenght()-1; i++){
        if(seq->Get(i)>seq->Get(i+1))
            return 1;
    }
    return 0;
}


int main() {
    srand(time(NULL));
    Sequence<int>*seq1 = NULL;
    Sequence<float>*seq2 = NULL;
    Isorter<int>*sorter1 = NULL;
    Isorter<float>*sorter2 = NULL;
    int type = 0;
    while(1){
        switch(menu_main()){
            case 1:
                if(seq1) delete seq1;
                if(seq2) delete seq2;

                if(sorter1)  delete sorter1;
                if(sorter2)  delete sorter2;
                type = menu_type();
                switch(type){
                    case 1:
                        seq1 = new ArraySequence<int>(getlen());
                        seq1->Fillrand();
                        sorter1 = new Isorter<int>();
                        break;
                    case 2:
                        seq2 = new ArraySequence<float>(getlen());
                        seq2->Fillrand();
                        sorter2 = new Isorter<float>;
                        break;
                }
                break;
            case 2:
                if(!seq1&&!seq2)
                    cout << "\nNo sequences" << endl;
                else{
                    switch(type){
                        case 1:
                            sorter1->shuffle(seq1);
                            break;
                        case 2:
                            sorter2->shuffle(seq2);
                    }
                }
                break;
            case 3:
                if(!seq1&&!seq2)
                    cout << "\nNo sequences" << endl;
                else{
                    switch(menu_sort()) {
                        case 1: {
                            clock_t begin = clock();
                            switch (type) {
                                case 1:
                                    sorter1->Bubble(seq1);
                                    break;
                                case 2:
                                    sorter2->Bubble(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                        case 2: {
                            clock_t begin = clock();
                            switch (type) {
                                case 1:
                                    sorter1->Shaker(seq1);
                                    break;
                                case 2:
                                    sorter2->Shaker(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                        case 3: {
                            clock_t begin = clock();
                            switch (type) {
                                case 1:
                                    sorter1->Insertion(seq1);
                                    break;
                                case 2:
                                    sorter2->Insertion(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                        case 4: {
                            clock_t begin = clock();
                            switch (type) {
                                case 1:
                                    sorter1->Selection(seq1);
                                    break;
                                case 2:
                                    sorter2->Selection(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                        case 5: {
                            clock_t begin = clock();
                            switch (type) {
                                case 1:
                                    sorter1->Shellsort(seq1);
                                    break;
                                case 2:
                                    sorter2->Shellsort(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                        case 6: {
                            clock_t begin = clock();

                            switch (type) {
                                case 1:
                                    sorter1->Heapsort(seq1);
                                    break;
                                case 2:
                                    sorter2->Heapsort(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                        case 7:{
                            clock_t begin = clock();
                            switch (type) {
                                case 1:
                                    sorter1->Quadraticsort(seq1);
                                    break;
                                case 2:
                                    sorter2->Quadraticsort(seq2);
                                    break;
                            }
                            clock_t end = clock();
                            cout<<"sorting time "<< ((double) (end - begin) / CLOCKS_PER_SEC)<<endl;
                            break;
                        }
                    }
                }
                break;
            case 4:
                if(!seq1&&!seq2)
                    cout << "\nNo sequences" << endl;
                else{
                    switch(type){
                        case 1:
                            seq1->Print();
                            break;
                        case 2:
                            seq2->Print();
                            break;
                    }
                }
                break;
            case 5:
                if(!seq1&&!seq2)
                    cout << "\nNo sequences" << endl;
                else{
                    switch(type){
                        case 1:
                            if(check(seq1)==0)
                                cout << "The sequence is sorted" <<endl;
                            else{
                                cout << "The sequence is not sorted" <<endl;
                            }
                            break;
                        case 2:
                            if(check(seq2)==0)
                                cout << "The sequence is sorted" <<endl;
                            else{
                                cout << "The sequence is not sorted" <<endl;
                            }
                            break;
                    }
                    break;
                }
                break;
            case 6:
                testing();
                break;
            case 7:
                compare();
                break;
            case 8:
                if(seq1) delete seq1;
                if(seq2) delete seq2;
                if(sorter1) delete sorter1;
                if(sorter2) delete sorter2;
                return 1;


        }
    }





    return 0;
}

