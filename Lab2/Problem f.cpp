#include <iostream>


using namespace std;


struct node{
    int x;
    node * next;
    node * prev;
    node(int value){
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

    void add(int value){
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

    void insert(int x, int i){
        int cnt = 0;
        node * temp = head;
        node * newNode = new node(x);
        while(temp != NULL){
            if(cnt == i){
                if(cnt == 0){
                    head = newNode;
                    temp->prev = head;
                    head->next = temp;
                }
                else{
                    node * prev = temp->prev;
                    prev->next = newNode;
                    newNode->prev = prev;
                    newNode->next = temp;
                    temp->prev = newNode;
                }
                break;
            }
            cnt++;
            temp = temp->next;
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
    int n;
    cin >> n;
    ll l;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        l.add(t);
    }
    int x, pos;
    cin >> x >> pos;
    l.insert(x, pos);
    l.print();
    return 0;
}