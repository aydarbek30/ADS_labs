#include <iostream>
#include <cmath>


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

    int find(int x){
        int cnt = 0;
        node * temp = head;
        int diff = abs(temp->x - x);
        int ans = 0;
        while(temp != NULL){
            if(abs(temp->x - x) < diff){
                diff = abs(temp->x - x);
                ans = cnt;
            }
            temp = temp->next;
            cnt++;
        }
        return ans;
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
    int k;
    cin >> k;
    cout << l.find(k);
    return 0;
}