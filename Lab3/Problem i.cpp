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
    return -1;
}

int main(){

    int n, k;
    cin >> n;


    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    cin >> k;
    if(binarySearch(a, n, k) != -1){
        cout << "Yes";
        return 0;
    }

    cout << "No";

    return 0;
}