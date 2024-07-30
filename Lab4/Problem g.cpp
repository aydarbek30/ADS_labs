#include <iostream>

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
    if(root->val == x){return root;}
    else if(x > root->val){
        root->right = insert(root->right, x);
    }
    else{
        root->left = insert(root->left, x);
    }
    return root;
}


int countHeight(Node * root){
    if(root == NULL){return 0;}
    return max(countHeight(root->right), countHeight(root->left)) + 1;
}

int countDist(Node * root){
    if(root == NULL){return 0;}
    int ifJoined = countHeight(root->right) + countHeight(root->left) + 1;
    return max(ifJoined, max(countDist(root->left), countDist(root->right)));
}


int main(){
    int n, val;
    cin >> n;


    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }


    cout << countDist(root);
    return 0;
}