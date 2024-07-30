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
    if(x > root->val){
        root->right = insert(root->right, x);
    }
    else if(x < root->val){
        root->left = insert(root->left, x);
    }
    return root;
}


int countHeight(Node * root){
    if(root == NULL){return 0;}
    if(root->left == NULL and root->right == NULL){return 1;}
    else if(root->left == NULL){return countHeight(root->right) + 1;}
    else if(root->right == NULL){return countHeight(root->left) + 1;}
    return max(countHeight(root->right), countHeight(root->left)) + 1;
}


void countLevelSums(Node * root, int * arr, int level){
    if(root == NULL){return;}
    arr[level] += root->val;
    if(root->left != NULL){
        countLevelSums(root->left, arr, level + 1);
    }
    if(root->right != NULL){
        countLevelSums(root->right, arr, level + 1);
    }
}

int main(){
    int n, val;
    cin >> n;

    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }
    
    int size = countHeight(root);
    cout << size << endl;
    int ans[size];
    for(int i = 0; i < size; i++){
        ans[i] = 0;
    }
    countLevelSums(root, ans, 0);
    for(int i = 0; i < size; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}