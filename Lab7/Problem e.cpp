#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector <int> &v){
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans += v[i];
    }
    return ans;
}

bool cmp(vector <int> v1, vector <int> v2){
    int sums1 = sum(v1), sums2 = sum(v2);
    if(sums1 == sums2){
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] == v2[i]){
                continue;
            }
            return v1[i] > v2[i];
        }
    }
    return sums1 < sums2;
}

void merge(vector <vector <int> > &v, int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;

    vector <vector <int> > * left = new vector <vector <int> > ();
    vector <vector <int> > * right = new vector <vector <int> > ();

    for(int i = 0; i < sub1; i++){
        left->push_back(v[l + i]);
    }

    for(int i = 0; i < sub2; i++){
        right->push_back(v[m + i + 1]);
    }

    int leftInd = 0;
    int rightInd = 0;
    int mergeInd = l;

    while(leftInd < sub1 && rightInd < sub2){
        if(cmp(left->at(leftInd), right->at(rightInd))){
            v[mergeInd] = left->at(leftInd);
            leftInd++;
        }
        else{
            v[mergeInd] = right->at(rightInd);
            rightInd++;
        }
        mergeInd++;
    }

    while(leftInd < sub1){
        v[mergeInd] = left->at(leftInd);
        mergeInd++;
        leftInd++;
    }

    while(rightInd < sub2){
        v[mergeInd] = right->at(rightInd);
        mergeInd++;
        rightInd++;
    }

    delete left;
    delete right;
}

void mergeSort(vector <vector <int> > &v, int l, int r){
    if(l >= r){return;}

    int m = l + (r - l) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}

int main(){

    int n, m, t;
    cin >> n >> m;

    vector <vector <int> > v;
    for(int i = 0; i < n; i++){
        vector <int> local;
        for(int j = 0; j < m; j++){
            cin >> t;
            local.push_back(t);
        }
        v.push_back(local);
    }

    mergeSort(v, 0, n - 1);

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}