#include <iostream>


using namespace std;


int binarySearch(int *a, int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}

int main(){

    int n, k, t;
    cin >> n >> k;


    int a[n];
    cin >> a[0];
    for(int i = 1; i < n; i++){
        cin >> t;
        a[i] = a[i - 1] + t;
    }


    for(int i = 0; i < k; i++){
        cin >> t;
        cout << binarySearch(a, n, t) + 1 << endl;
    }

    return 0;
}