#include <iostream>

using namespace std;


bool check(int * x, int * y, int n, int m, int k){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(m >= x[i] and m >= y[i]){
            cnt++;
        }
    }
    return cnt >= k;
}


int main(){ 
    int n, k;
    cin >> n >> k;


    int x[n], y[n];

    int x1, x2, y1, y2;


    int left = 1, right = -1;

    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x[i] = x2;
        y[i] = y2;
        if(x2 > right){
            right = x2;
        }
        if(y2 > right){
            right = y2;
        }
    }

    while(left <= right){
        int m = left + (right - left) / 2;
        if(check(x, y, n, m, k)){
            right = m - 1;
        }
        else{
            left = m + 1;
        }
    }

    cout << left;
    return 0;
}