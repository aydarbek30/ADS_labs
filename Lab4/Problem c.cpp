#include <iostream>


using namespace std;


struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int x){
        this->val = x;
        right = NULL;
        left = NULL;
    }
};


Node * insert(Node * root, int x){
    if(root == NULL){
        Node * newNode = new Node(x);
        root = newNode;
        return root;
    }
    if(x > root->val){
        root->right = insert(root->right, x);
    }
    else if(x < root->val){
        root->left = insert(root->left, x);
    }
    return root;
}

void printSubtree(Node * root){
    if(root == NULL){return;}
    cout << root->val << ' ';
    printSubtree(root->left);
    printSubtree(root->right);
}

Node * findValue(Node * root, int x){
    if(root->val == x){
        return root;
    }
    if(x > root->val){
        if(root->right == NULL){return NULL;}
        return findValue(root->right, x);
    }
    if(x < root->val){
        if(root->left == NULL){return NULL;}
        return findValue(root->left, x);
    }
    return NULL;
}

int main(){
    int n, val;
    cin >> n;

    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }

    int k;
    cin >> k;
    printSubtree(findValue(root, k));
    return 0;
}