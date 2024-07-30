#include <iostream>
#include <stack>


using namespace std;


struct node{
    int val;
    node * next;
    node(int value){
        val = value;
        next = NULL;
    }
};


struct ll{
    node * head;
    int size;
    int max;
    ll(){
        head = NULL;
        size = 0;
        max = 0;
    }

    void add(int x){
        node * temp = head;
        x--;
        if(temp == NULL){
            node * newNode = new node(0);
            temp = newNode;
            head = temp;
        }
        for(int i = 0; i < x; i++){
            if(temp != NULL){
                if(temp->next == NULL){
                    node * newNode = new node(0);
                    temp->next = newNode;
                }
                temp = temp->next;
            }
            else{
                node * newNode = new node(0);
                temp = newNode;
                head = temp;
            }
        }
        temp->val++;
        if(max < temp->val){
            max = temp->val;
        }
    }

    void findMode(){
        stack <int> ans;
        int cnt = 0;
        node * temp = head;
        while(temp != NULL){
            if(temp->val == max){
                ans.push(cnt + 1);
            }
            cnt++;
            temp = temp->next;
        }
        while(!ans.empty()){
            cout << ans.top() << ' ';
            ans.pop();
        }
    }

    void reverse(){
        node * curr = head;
        node * prev = NULL;
        node * next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};


int main(){
    int n, k;
    ll l;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        l.add(k);
    }
    l.findMode();
    return 0;
}


