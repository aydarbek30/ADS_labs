#include <iostream>
#include <algorithm>

using namespace std;


long long cnt(long long *a, int n, long long x){
    int cnt = 0;
    long long local = 0;
    for(int i = 0; i < n; i++){
        if(local + a[i] > x){
            cnt++;
            local = 0;
        }
        local += a[i];
    }
    return cnt;
}


int main(){
    int n, k;
    cin >> n >> k;
    long long a[n];
    long long left = 1, right = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        right += a[i];
        left = max(left, a[i]);
    }


    long long ans = -1;
    while(left <= right){
        long long m = left + (right - left) / 2;
        long long local_cnt = cnt(a, n, m);
        if(local_cnt == k - 1){
            ans = m;
        }
        if(local_cnt <= k - 1){right = m - 1;}
        else{left = m + 1;}
    }

    cout << left;
    return 0;
}