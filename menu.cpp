#include "menu.hpp"
#include <iostream>
using namespace std;



int menu_main(){
    int choice = -1;
        while (true) {
            string input;
            cout << "\nOperation:" << endl;
            cout << "1.create new" << endl;
            cout << "2.shuffle" << endl;
            cout << "3.sort" << endl;
            cout << "4.print" << endl;
            cout << "5.auto check" << endl;
            cout << "6.tests" << endl;
            cout << "7.comparison" << endl;
            cout << "8.exit"<<endl;
            cin >> input;
            try {
                choice = stoi(input);
                if (choice > 0 && choice < 9) {
                    break;
                }
            } catch (const exception& e) {
            }
            cout << "Invalid input" << endl;
        }
    return choice;
}





int menu_sort(){
    int choice = -1;
        while (true) {
            string input;
            cout << "\nOperation:" << endl;
            cout << "1.Bubble sort" << endl;
            cout << "2.Shaker sort" << endl;
            cout << "3.Insertion sort" << endl;
            cout << "4.Selection sort" << endl;
            cout << "5.Shell sort" << endl;
            cout << "6.Heap sort" <<endl;
            cout << "7.Quadratic sort" <<endl;
            cout << "8.exit"<<endl;
            cin >> input;
            try {
                choice = stoi(input);
                if (choice > 0 && choice < 9) {
                    break;
                }
            } catch (const exception& e) {
            }
            cout << "Invalid input" << endl;
        }
    return choice;
}
int menu_type(){
    int choice = -1;
        while (true) {
            string input;
            cout << "\nOperation:" << endl;
            cout << "1.int" << endl;
            cout << "2.float" << endl;
            cout << "3.exit"<<endl;
            cin >> input;
            try {
                choice = stoi(input);
                if (choice > 0 && choice < 4) {
                    break;
                }
            } catch (const exception& e) {
            }
            cout << "Invalid input" << endl;
        }
    return choice;
}
int getlen(){
    int l;
    cout << "whats the length?" << endl;
    cin >> l;
    if(l<=0)
        do{
            cout << "whats the length?" << endl;
            cin >> l;
        }while(l<=0);
    return l;
}
int get_type(){
    int choice = -1;
        while (true) {
            string input;
            cout << "\ntype:" << endl;
            cout << "1.array" << endl;
            cout << "2.list" << endl;
            cout << "3.exit"<<endl;
            cin >> input;
            try {
                choice = stoi(input);
                if (choice > 0 && choice < 4) {
                    break;
                }
            } catch (const exception& e) {
            }
            cout << "Invalid input" << endl;
        }
    return choice;
}
