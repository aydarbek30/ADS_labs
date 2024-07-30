#include <iostream>
#include <queue>

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

Node * insert(Node * root, int x, int y, int z){
    queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(temp->val == x){
            Node * newNode = new Node(y);
            if(z == 0){
                temp->right = newNode;
            }
            else{
                temp->left = newNode;
            }
            return root;
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        if(temp->left != NULL){
            q.push(temp->left);
        }
    }
    return root;
}


void printTree(Node * root){
    if(root == NULL){return;}
    printTree(root->left);
    cout << root->val << ' ';
    printTree(root->right);
}

int countHeight(Node * root){
    if(root == NULL){return 0;}
    int leftHeight = countHeight(root->left);
    int rightHeight = countHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void countWidth(Node * root, int * width, int level){
    if(root == NULL){return;}
    width[level]++;
    countWidth(root->right, width, level + 1);
    countWidth(root->left, width, level + 1);
}

bool isPowerOfTwo(int n){
    if(n == 1){return true;}
    if(n % 2 == 1){return false;}
    return isPowerOfTwo(n / 2);
}


int main(){
    int n, x, y, z;
    cin >> n;
    
    Node * root = new Node(1);
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y >> z;
        root = insert(root, x, y, z);
    }

    int height = countHeight(root);
    int ans[height];
    for(int i = 0; i < height; i++){
        ans[i] = 0;
    }


    countWidth(root, ans, 0);
    ans[0] = 1;
    int maxWidth = 1;
    for(int i = 0; i < height; i++){
        if(ans[i] > maxWidth){
            maxWidth = ans[i];
        }
    }


    cout << maxWidth;


    return 0;
}