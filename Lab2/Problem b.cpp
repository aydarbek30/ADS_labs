#include <iostream>


using namespace std;


struct node{
    string x;
    node * next;
    node * prev;
    node(string value){
        x = value;
        next = NULL;
        prev = NULL;
    }
};


struct ll{
    node * head;
    node * tail;
    int size;
    ll(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void add(string value){
        node * newNode = new node(value);
        if(head == NULL and tail == NULL){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        size++;
    }


    void del(node * n){
        if(n->prev == NULL and n->next == NULL){
            head = tail = NULL;
        }
        else if(n->prev == NULL and n->next != NULL){
            head = n->next;
            head->prev = NULL;
        }
        else if(n->prev != NULL and n->next == NULL){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        delete n;
    }

    void cyclicShift(int k){
        for(int i = 0; i < k; i++){
            node * newNode = head;
            add(head->x);
            del(head);
        }
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->x << ' ';
            temp = temp->next;
        }
    }
};


int main(){
    int n, k;
    cin >> n >> k;
    ll l;
    string t;
    for(int i = 0; i < n; i++){
        cin >> t;
        l.add(t);
    }
    l.cyclicShift(k);
    l.print();
    return 0;
}