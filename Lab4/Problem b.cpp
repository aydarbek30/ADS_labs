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
        return root;
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

int countSize(Node * root){
    if(root->right == NULL and root->left == NULL){
        return 1;
    }
    if(root->right == NULL and root->left != NULL){
        return countSize(root->left) + 1;
    }
    else if(root->right != NULL and root->left == NULL){
        return countSize(root->right) + 1;
    }
    return countSize(root->right) + countSize(root->left) + 1;
}

int main(){
    int n, val;
    cin >> n;

    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }

    int x;
    cin >> x;
    Node * cur = root;
    while(cur->val != x){
        if(x > cur->val){
            cur = cur->right;
        }
        else if(x < cur->val){
            cur = cur->left;
        }
    }

    cout << countSize(cur);
    return 0;
}