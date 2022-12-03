#include <iostream>



using namespace std;


template<typename T>
struct item{
    T data;
    struct item* next;
};

template <class T>
class LinkedList {
private:
    item<T> *head;
    item<T> *tail;
public:
    
    LinkedList(){
        head == NULL;
        tail == NULL;
        }
    
    LinkedList(int p){
        head = new item<T>;
        item<T> *ptr = head;
        ptr->data = 0;
        for (int i = 1; i<p; i++){
            ptr->next = new item<T>;
            ptr->next->data = 0;
            ptr = ptr->next;
        }
        tail = ptr;
        tail->next = NULL;
    }
    
    
    
    LinkedList<T>*GetSubList(int start, int end){
        if(start>end)
            throw out_of_range("start can't be more than end");
        if(start<0||end>this->GetLength())
            throw out_of_range("index out of bound");
        LinkedList<T>* temp = new LinkedList<T>();
        item<T> *ptr1 = this->head;
        item<T> *ptr2 = NULL;
        for(int i =0; i<start;i++){
            ptr1 = ptr1->next;
        }
        temp->head = new item<T>;
        temp->head->data = ptr1->data;
        ptr2 = temp->head;
        for(int i = start; i<end;i++){
            ptr2->next = new item<T>;
            ptr2->next->data = ptr1->next->data;
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        temp->tail = ptr2;
        temp->tail->next = NULL;
        return temp;
    }
    
    LinkedList<T>* Concat(LinkedList<T> *list){
        item<int> *temp = this->tail;
        temp->next = list->head;
        this->tail = list->tail;
        this->tail->next = NULL;
        return this;
    }
    
  
    LinkedList(LinkedList <T>& other){
        head = new item<T>;
        item<T> *ptr1 = head;
        item<T> *ptr2 = other.head;
        while(ptr2){
            ptr1->data = ptr2->data;
            ptr1->next = new item<T>;
            tail = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        tail->next = NULL;
    }
    
    LinkedList(T* items, int count){
        if(count<0)
            throw out_of_range("index out of bound");
        head = new item<T>;
        head->data = items[0];
        item<T> *ptr = head;
        for (int i = 1; i<count; i++){
            ptr->next = new item<T>;
            ptr->next->data = items[i];
            ptr = ptr->next;
        }
        tail = ptr;
        tail->next = NULL;
    }
    
    
    ~LinkedList(){
        item<T>*ptr = head, *ptr_prev = NULL;
        while(ptr){
            ptr_prev = ptr;
            ptr = ptr->next;
            delete ptr_prev;
        }
    }
    
    void Print(){
        item <T> *ptr = head;
        cout<<"(";
        while(ptr){
            cout << ptr->data;
            if(ptr->next==NULL)
            cout << "";
            else
                cout << (", ");
            ptr = ptr->next;
        }
        cout << ")";
        cout << "\n";
    }
    
    T GetFirst(){
        return head->data;
    }
    
    T GetLast(){
        item<T>*ptr = head;
        while(ptr->next){
            ptr=ptr->next;
        }
        return ptr->data;
        
    }
    
    int GetLength(){
        item<T> *ptr = head;
        int i=0;
        while(ptr){
            i++;
            ptr = ptr->next;
        }
        return i;
        
    }

    void append(T thing){
        item <T>*tmp = new item<T>;
        tmp->data = thing;
        tail->next = tmp;
        tmp->next = NULL;
        tail = tmp;
    }
    void prepend(T thing){
        item <T>*tmp = new item<T>;
        tmp->data = thing;
        item <T>*ptr = head;
        head = tmp;
        tmp->next = ptr;
    }
    T Get(int p){
        if(p<0||p>=this->GetLength())
            throw out_of_range("out of bound");
        item<T> *ptr = head;
        for(int i =0;i<p;i++){
            ptr = ptr->next;
        }
        return ptr->data;
    }
    void Set(int i, T x){
        if(i<0||i>=this->GetLength())
            throw out_of_range("out of bound");
        item<T> *ptr = head;
        for(int p =0;p<i;p++){
            ptr = ptr->next;
        }
        ptr->data = x;
        
        
    }
    
    void InsertAt(T pip, int p){
        if(p<0||p>=this->GetLength())
            throw out_of_range("out of bound");
        item<T> *ptr = head, *ptr_prev = NULL;
        item<T>*tmp = new item<T>;
        tmp->data = pip;
        for(int i = 0; i < p; i++){
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        tmp->next = ptr;
        if(ptr_prev){
            ptr_prev->next = tmp;
        }
        else{
            head = tmp;
        }
        if(!ptr){
            tail=tmp;
        }
    }
    
    void Fillrand(){
        item<T> *ptr = head;
        while(ptr){
            ptr->data = -30000 + static_cast<T>(rand()/(static_cast<T>(RAND_MAX)/(60000)));
            ptr= ptr->next;
        }
    }
    void Fillkey(){
        item<T> *ptr = head;
        while(ptr){
            cin >> ptr->data;
            ptr= ptr->next;
        }
    }
    
    LinkedList & operator = (LinkedList &other){
        if(head){
            item<T>*ptr = this->head;
            item<T>*ptr_prev = nullptr;
            while(ptr){
                ptr_prev = ptr;
                ptr=ptr->next;
                delete ptr_prev;
            }
        }
        this->head = new item<T>;
        this->head->data = other.head->data;
        item<T>*ptr_other = other.head;
        item<T>*ptr = this->head;
        while(ptr_other){
            ptr_other = ptr_other->next;
            ptr->next = new item<T>;
            ptr->next->data = ptr_other->data;
            ptr->next = ptr->next->next;
        }
        this->tail=ptr->next;
        
    }
    
};

