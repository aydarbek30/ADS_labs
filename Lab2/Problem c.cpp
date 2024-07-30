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
    void del(node * n){
        size--;
        if(n->next == NULL and n->prev == NULL){
            head = tail = NULL;
        }
        else if(n->next == NULL and n->prev != NULL){
            tail = n->prev;
            tail->next = NULL;
        }
        else if(n->next != NULL and n->prev == NULL){
            head = n->next;
            head->prev = NULL;
        }
        else{
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        delete n;
    }
    void delSecond(){
        node * temp = head;
        int cnt = 0;
        while(temp->next != NULL){
            cnt++;
            if(cnt % 2 == 0){
                node * new_temp = temp->next;
                del(temp);
                temp = new_temp;
                continue;
            }
            temp = temp->next;
        }
        cnt++;
        if(cnt % 2 == 0){
            del(tail);
        }
    }
    void print(){
        node * temp = head;
        while(temp != tail){
            cout << temp->x << ' ';
            temp = temp->next;
        }
        cout << tail->x;
    }
};


int main(){
    int n;
    cin >> n;
    ll l;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        l.add(t);
    }
    l.delSecond();
    l.print();
    return 0;
}