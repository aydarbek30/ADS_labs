#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool cmp(string s1, string s2){
    return s1.size() <= s2.size();
}

void merge(string arr[], int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;

    string * left = new string[sub1];
    string * right = new string[sub2];

    for(int i = 0; i < sub1; i++){
        left[i] = arr[l + i];
    }

    for(int i = 0; i < sub2; i++){
        right[i] = arr[m + i + 1];
    }

    int leftInd = 0;
    int rightInd = 0;
    int mergeInd = l;

    while(leftInd < sub1 && rightInd < sub2){
        if(cmp(left[leftInd], right[rightInd])){
            arr[mergeInd] = left[leftInd];
            leftInd++;
        }
        else{
            arr[mergeInd] = right[rightInd];
            rightInd++;
        }
        mergeInd++;
    }

    while(leftInd < sub1){
        arr[mergeInd] = left[leftInd];
        leftInd++;
        mergeInd++;
    }

    while(rightInd < sub2){
        arr[mergeInd] = right[rightInd];
        rightInd++;
        mergeInd++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(string arr[], int l, int r){
    if(l >= r){return;}

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int fill(string arr[], string s){
    string local = "";
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            arr[cnt] = local;
            local = "";
            cnt++;
            continue;
        }
        local += s[i];
    }
    arr[cnt] = local;
    cnt++;
    return cnt;
}

int sto(string s){
    int ans = 0;
    if(s[0] == '0'){
        return int(s[1]) - 48;
    }

    for(int i = 0; i < s.size(); i++){
        ans += pow(10, s.size() - i - 1) * (int(s[i]) - 48);
    }
    return ans;
}

int main(){

    string s1;
    getline(cin, s1);
    string s;

    int n = sto(s1);

    for(int i = 0; i < n; i++){
        string arr[51];
        getline(cin, s);
        int size = fill(arr, s);
        mergeSort(arr, 0, size - 1);
        for(int j = 0; j < size; j++){
            cout << arr[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}