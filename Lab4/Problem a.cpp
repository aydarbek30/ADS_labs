#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int value){
        val = value;
        right = NULL;
        left = NULL;
    }
};


Node * insert(Node * root, int val){
    if(root == NULL){
        Node * newNode = new Node(val);
        root = newNode;
    }
    if(root->val > val){
        root->left = insert(root->left, val);
    }
    else if(root->val < val){
        root->right = insert(root->right, val);
    }
    return root;
}

void printTree(Node * root){
    if(root == NULL){return;}
    printTree(root->left);
    cout << root->val << ' ';
    printTree(root->right);
}

bool hasPath(Node * root, string command){
    Node * cur = root;
    for(int i = 0; i < command.size(); i++){
        if(cur == NULL){return false;}
        if(command[i] == 'L'){cur = cur->left;}
        else{cur = cur->right;}
    }
    return cur != NULL;
}



int main(){
    int n, m, val;
    cin >> n >> m;

    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }


    string command;
    for(int i = 0; i < m; i++){
        cin >> command;
        if(hasPath(root, command)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}