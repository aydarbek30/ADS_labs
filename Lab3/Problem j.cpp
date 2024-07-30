#include <iostream>


using namespace std;


bool check(int *a, int n, int m, int f){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += a[i] / m;
        if(a[i] % m){
            cnt += 1;
        }
    }
    return cnt <= f;
}


int main(){
    int n, f;
    cin >> n >> f;
    int a[n];
    int left = 1, right = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(right == -1){
            right = a[i] - 1;
        }
        if(a[i] > right){
            right = a[i] - 1;
        }
    }


    while(left <= right){
        int m = left + (right - left) / 2;
        if(check(a, n, m, f)){
            right = m - 1;
        }
        else{
            left = m + 1;
        }
    }

    cout << left;

    return 0;
}