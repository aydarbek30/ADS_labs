#include <iostream>
#include <algorithm>


using namespace std;

int binarySearch(int *a, int n, int x){
    if(a[0] > x){
        return -1;
    }
    int left = 0, right = n - 1;
    while(left <= right){
        int m = left + (right - left) / 2;
        if(a[m] < x){left = m + 1;}
        else{right = m - 1;}
    }
    return right;
}


int main(){

    int n, p, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);


    int b[n + 1];
    b[0] = 0;
    for(int i = 1; i <= n; i++){
        b[i] = b[i - 1] + a[i - 1];
    }

    cin >> p;
    for(int i = 0; i < p; i++){
        cin >> m;
        int index = binarySearch(a, n, m + 1);
        cout << index + 1 << ' ' << b[index + 1] << endl;
    }


    return 0;
}