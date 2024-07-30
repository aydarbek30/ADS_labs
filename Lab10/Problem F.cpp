#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int val;
    Node * next;

    Node(int x){
        val = x;
        next = NULL;
    }
};

struct LinkedList{
    Node * head;
    Node * tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void add(int x){
        Node * newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
};

void find(vector <LinkedList * > graph, int v1, int v2){
    vector <bool> visited;
    for(int i = 0; i < graph.size(); i++){
        visited.push_back(false);
    }

    visited[v1] = true;
    queue <int> check;
    check.push(v1);
    while(!check.empty()){
        int s = check.front();
        check.pop();
        if(s == v2){
            cout << "YES";
            return;
        }
        Node * head = graph[s]->head;
        while(head != NULL){
            if(!visited[head->val]){
                visited[head->val] = true;
                check.push(head->val);
            }
            head = head->next;
        }
    }
    cout << "NO";
}

int main(){

    int n, m;
    cin >> n >> m;

    vector <LinkedList * > graph;
    for(int i = 0; i < n; i++){
        graph.push_back(new LinkedList());
    }

    for(int i = 0; i < m; i++){
        int first, second;
        cin >> first >> second;
        first--;
        second--;
        graph[first]->add(second);
        graph[second]->add(first);
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;

    find(graph, v1, v2);
    return 0;
}