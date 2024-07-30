#include <iostream>
#include <cmath>


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
            size++;
        }
        else{
            if(head->x != value){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
                size++;
            }
        }
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->x << '\n';
            temp = temp->next;
        }
    }
};


int main(){
    int n;
    cin >> n;
    ll l;
    string t;
    for(int i = 0; i < n; i++){
        cin >> t;
        l.add(t);
    }
    cout << "All in all: " << l.size << endl;
    cout << "Students:" << endl;
    l.print();
    return 0;
}