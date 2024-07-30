#include <iostream>
#include <queue>


using namespace std;


struct node{
    char value;
    bool rep;
    node * next;
    node * prev;
    node(int val){
        rep = false;
        value = val;
        next = NULL;
        prev = NULL;
    }
};


struct ll{
    int size;
    node * head;
    node * tail;
    ll(){
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void del(node * n){
        if(n->prev == NULL and n->next == NULL){
            head = tail = NULL;
        }
        else if(n->prev == NULL and n->next != NULL){
            head->next->prev = NULL;
            head = head->next;
        }
        else if(n->prev != NULL and n->next == NULL){
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        else{
            n->next->prev = n->prev;
            n->prev->next = n->next;
        }
        delete n;
    }

    void add(char value){
        if(head == NULL){
            node * newNode = new node(value);
            head = tail = newNode;
        }
        else{
            node * temp = head;
            while(temp != NULL){
                if(temp->value == value){
                    temp->rep = true;
                    return;
                }
                temp = temp->next;
            }
            node * newNode = new node(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void clear(){
        node * temp = head;
        while(temp != NULL){
            node * newTemp = temp;
            temp = temp->next;
            del(newTemp);
        }
    }

    char find(){
        node * temp = head;
        while(temp != NULL){
            if(temp->rep == false){
                return temp->value;
                break;
            }
            temp = temp->next;
        }
        return '1';
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->value << ' ' << temp->rep << endl;
            temp = temp->next;
        }
    }
};


int main(){
    int n, k;
    cin >> n;
    ll l;
    char c;
    queue <char> newOne;
    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> c;
            newOne.push(c);
        }
        while(!newOne.empty()){
            l.add(newOne.front());
            char res = l.find();
            if(res == '1'){
                cout << '-';
            }
            cout << res << ' ';
            newOne.pop();
        }
        cout << '\n';
        l.clear();
    }
    return 0;
}