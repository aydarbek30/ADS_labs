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

    void add_back(string value){
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

    void add_front(string value){
        node * newNode = new node(value);
        if(head == NULL and tail == NULL){
            head = tail = newNode;
        }
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    string erase_front(){
        string value = "error";
        if(head != NULL){
            value = head->x;
            del(head);
        }
        return value;
    }

    string erase_back(){
        string value = "error";
        if(tail != NULL){
            value = tail->x;
            del(tail);
        }
        return value;
    }

    string front(){
        if(head != NULL){
            return head->x;
        }
        return "error";
    }

    string back(){
        if(tail != NULL){
            return tail->x;
        }
        return "error";
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
        size--;
        delete n;
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->x << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    void clear(){
        node * temp = head;
        while(temp != NULL){
            node * newTemp = temp;
            temp = temp->next;
            del(newTemp);
        }
    }
};


int main(){

    ll l;
    while(true){
        string command;
        cin >> command;
        if(command == "exit"){
            cout << "goodbye";
            break;
        }
        else if(command == "clear"){
            l.clear();
            cout << "ok" << endl;
        }
        else if(command == "front"){
            cout << l.front() << endl;
        }
        else if(command == "back"){
            cout << l.back() << endl;
        }
        else if(command == "erase_back"){
            cout << l.erase_back() << endl;
        }
        else if(command == "erase_front"){
            cout << l.erase_front() << endl;
        }
        else{
            string value;
            cin >> value;
            if(command == "add_back"){
                l.add_back(value);
            }
            else{
                l.add_front(value);
            }
            cout << "ok" << endl;
        }
    }
    return 0;
}