#include <iostream>
#include <algorithm>

using namespace std;


void order(int * arr, int l, int r){
    if(l > r){
        return;
    }
    int mid = l + (r - l) / 2;
    cout << arr[mid] << ' ';
    order(arr, l, mid - 1);
    order(arr, mid + 1, r);
}


int main(){
    int n;
    cin >> n;

    int size = 1;
    for(int i = 0; i < n; i++){
        size *= 2;
    }
    size--;
    n = size;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    order(a, 0, n - 1);
    return 0;
}