#include <iostream>

using namespace std;


struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
    }
};


struct ll{
    node * head;
    node * tail;
    ll(){
        head = NULL;
        tail = NULL;
    }

    void add(int x){
        node * newNode = new node(x);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int findMaxSum(){
        int ans = head->val;
        node * newHead = head;
        while(newHead != NULL){
            node * newTail = newHead;
            int localAns = 0;
            while(newTail != NULL){
                localAns += newTail->val;
                newTail = newTail->next;
                if(ans < localAns){
                    ans = localAns;
                }
            }
            newHead = newHead->next;
        }
        return ans;
    }
};


int main(){
    int n, k;
    cin >> n;

    ll l;
    for(int i = 0; i < n; i++){
        cin >> k;
        l.add(k);
    }

    cout << l.findMaxSum();
    return 0;
}