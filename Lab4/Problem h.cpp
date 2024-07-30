#include <iostream>
int sum = 0;


using namespace std;


struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int x){
        val = x;
        right = NULL;
        left = NULL;
    }
};


Node * insert(Node * root, int x){
    if(root == NULL){
        Node * newNode = new Node(x);
        return newNode;
    }
    if(x > root->val){
        root->right = insert(root->right, x);
    }
    else if(x < root->val){
        root->left = insert(root->left, x);
    }
    return root;
}

void cumulativeSum(Node * root){
    if(root == NULL){return;}
    cumulativeSum(root->left);
    int temp = root->val;
    root->val = sum;
    sum -= temp;
    cumulativeSum(root->right);
}

void printTree(Node * root){
    if(root == NULL){return;}
    printTree(root->right);
    cout << root->val << ' ';
    printTree(root->left);
}

int main(){
    int n, val;
    cin >> n;

    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
        sum += val;
    }

    cumulativeSum(root);
    printTree(root);


    return 0;

}