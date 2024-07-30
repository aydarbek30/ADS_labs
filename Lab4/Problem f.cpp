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

int countTriangles(Node *root){
    if(root == NULL){return 0;}
    if(root->right == NULL and root->left == 0){return 0;}
    if(root->right != NULL and root->left == NULL){
        return countTriangles(root->right);
    }
    if(root->right == NULL and root->left != NULL){
        return countTriangles(root->left);
    }
    return 1 + countTriangles(root->left) + countTriangles(root->right);
}

int main(){
    int n, val;
    cin >> n;

    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }


    cout << countTriangles(root);

    return 0;
}