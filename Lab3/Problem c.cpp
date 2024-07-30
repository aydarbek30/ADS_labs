#include <iostream>
#include <algorithm>


using namespace std;


int lower(int *a, int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int m = left + (right - left) / 2;
        if(a[m] >= x){right = m - 1;}
        else{left = m + 1;}
    }
    return left;
}

int upper(int *a, int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int m = left + (right - left) / 2;
        if(a[m] <= x){left = m + 1;}
        else{right = m - 1;}
    }
    return right;
}


int main(){
    int n, q;
    cin >> n >> q;


    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    sort(a, a + n);

    int l1, r1, l2, r2;
    for(int i = 0; i < q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2){
            int t = l1;
            l1 = l2;
            l2 = t;
            t = r1;
            r1 = r2;
            r2 = t;
        }
        if(l2 <= r1){
            l2 = r1 + 1;
        }
        int cnt = upper(a, n, r1) - lower(a, n, l1) + 1;
        if(l2 <= r2){
            cnt += upper(a, n, r2) - lower(a, n, l2) + 1;
        }
        cout << cnt << endl;
    }
    return 0;
}