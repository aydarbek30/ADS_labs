#include <iostream>

using namespace std;


struct node{
    int val;
    node * next;
    node * prev;

    node(int x){
        val = x;
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

    void add_back(int value){
        node * newNode = new node(value);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void add_front(int value){
        node * newNode = new node(value);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insert(int value, int pos){
        node * temp = head;
        int cnt = 0;
        while(temp != NULL){
            if(cnt == pos){
                node * newNode = new node(value);
                if(temp->prev != NULL){
                    temp->prev->next = newNode;
                    newNode->prev = temp->prev;
                }
                temp->prev = newNode;
                newNode->next = temp;
                if(cnt == 0){
                    head = newNode;
                }
                return;
            }
            temp = temp->next;
            cnt++;
        }
        add_back(value);
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->val << ' ';
            temp = temp->next;
        }
        if(head == NULL){
            cout << -1;
        }
        cout << '\n';
    }

    void del(node * n){
        node * ans = n;
        if(n->prev == NULL and n->next == NULL){
            head = tail = NULL;
        }
        else if(n->prev == NULL and n->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else if(n->prev != NULL and n->next == NULL){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            n->next->prev = n->prev;
            n->prev->next = n->next;
        }
        delete n;
    }

    int remove(int pos){
        int cnt = 0;
        node * temp = head;
        while(temp != NULL){
            if(cnt == pos){
                int ans = temp->val;
                del(temp);
                return ans;
            }
            cnt++;
            temp = temp->next;
        }
    }

    void replace(int pos1, int pos2){
        while(pos1 < pos2){
            int val1 = remove(pos1);
            int val2 = remove(pos1);
            insert(val1, pos1);
            insert(val2, pos1);
            pos1++;
        }
        while(pos1 > pos2){
            int val1 = remove(pos1);
            int val2 = remove(pos1 - 1);
            insert(val1, pos1 - 1);
            insert(val2, pos1);
            pos1--;
        }
    }

    void reverse(){
        node * curr = head;
        node * prev = NULL;
        node * next = NULL;
        tail = curr;
        while(curr != NULL){
            next = curr->next;
            curr->prev = next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;    
    }

    void cyclic_left(int x){
        for(int i = 0; i < x; i++){
            add_back(head->val);
            del(head);
        }
    }

    void cyclic_right(int x){
        for(int i = 0; i < x; i++){
            add_front(tail->val);
            del(tail);
        }
    }
};


int main(){

    ll l;
    int com;
    int value, pos1, pos2, x;
    
    while(true){
        cin >> com;
        if(com == 0){
            break;
        }
        if(com == 1){
            cin >> value >> pos1;
            l.insert(value, pos1);
        }
        if(com == 2){
            cin >> pos1;
            l.remove(pos1);
        }
        if(com == 3){
            l.print();
        }
        if(com == 4){
            cin >> pos1 >> pos2;
            l.replace(pos1, pos2);
        }
        if(com == 5){
            l.reverse();
        }
        if(com == 6){
            cin >> x;
            l.cyclic_left(x);
        }
        if(com == 7){
            cin >> x;
            l.cyclic_right(x);
        }
    }
    return 0;
}