#include <iostream>

using namespace std;


void heapify(int a[], int size, int index ){
    int min = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    
    if(l < size && a[l] > a[min]){
        min = l;
    }

    if(r < size && a[r] > a[min]){
        min = r;
    }

    if(min != index){
        swap(a[min], a[index]);
        heapify(a, size, min);
    }
}

void heapSort(int a[], int size){
    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(a, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

int binaryRight(int arr[], int size, int val){
    int l = 0, r = size - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] <= val){l = m + 1;}
        else{r = m - 1;}
    }
    return r;
}

int binaryLeft(int arr[], int size, int val){
    int l = 0, r = size - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] >= val){r = m - 1;}
        else{l = m + 1;}
    }
    return l;
}

int main(){

    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    heapSort(arr1, n);
    heapSort(arr2, m);

    for(int i = 0; i < m; i++){
        int cnt1 = binaryRight(arr1, n, arr2[i]) - binaryLeft(arr1, n, arr2[i]) + 1;
        int cnt2 = binaryRight(arr2, m, arr2[i]) - binaryLeft(arr2, m, arr2[i]) + 1;
        for(int j = 0; j < min(cnt1, cnt2); j++){
            cout << arr2[i] << ' ';
        }
        i += cnt2 - 1;
    }

    return 0;
}