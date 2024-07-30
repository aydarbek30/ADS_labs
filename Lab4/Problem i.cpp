#include <iostream>


using namespace std;


struct Node{
    int val;
    int mul;
    Node * right;
    Node * left;
    Node(int x){
        val = x;
        mul = 1;
        right = NULL;
        left = NULL;
    }
};


struct Node * insert(Node * root, int x){
    if(root == NULL){
        Node * newNode = new Node(x);
        return newNode;
    }
    if(root->val == x){
        root->mul++;
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

void printTree(Node * root){
    if(root == NULL){return;}
    printTree(root->left); 
    cout << root->val << ' ';
    printTree(root->right);
}

int cntMul(Node * root, int x){
    if(root == NULL){return 0;}
    if(root->val == x){
        return root->mul;
    }
    if(x > root->val){
        return cntMul(root->right, x);
    }
    if(x < root->val){
        return cntMul(root->left, x);
    }
    return 0;
}

struct Node * minValueNode(Node * root){
    Node * cur = root;
    while(cur != NULL and cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

struct Node * del(Node * root, int x){
    if(root == NULL){return NULL;}
    if(x > root->val){
        root->right = del(root->right, x);
        return root;
    }
    else if(x < root->val){
        root->left = del(root->left, x);
        return root;
    }
    else{
        if(root->mul >= 1){
            root->mul--;
        }
        return root;
    }
    return root;
}

int main(){
    int n;
    cin >> n;


    Node * root = NULL;
    string s;
    int val;
    for(int i = 0; i < n; i++){
        cin >> s >> val;
        if(s == "insert"){root = insert(root, val);}
        else if(s == "cnt"){cout << cntMul(root, val) << endl;}
        else if(s == "delete"){root = del(root, val);}
    }

    return 0;
}