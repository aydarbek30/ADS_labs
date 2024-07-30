#include <iostream>

using namespace std;

int upper(char a[], int size, char value){
    int l = 0, r = size - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] <= value){l = m + 1;}
        else{r = m - 1;}
    }
    return r;
}

int main(){
    
    int n;
    cin >> n;
    char a[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    char k;
    cin >> k;
    int ans = upper(a, n, k);
    if(ans == -1){cout << a[0]; return 0;}
    if(ans == n - 1){
        cout << a[0];
        return 0;
    }
    if(a[ans] == k && ans < n - 1){
        cout << a[ans + 1];
        return 0;
    }

    if(a[ans] != k){
        cout << a[ans];
    }

    return 0;
}