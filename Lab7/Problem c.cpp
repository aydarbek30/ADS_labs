#include <iostream>

using namespace std;

void merge(int array[], int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;

    int *leftArray = new int[sub1];
    int *rightArray = new int[sub2];

    for(int i = 0; i < sub1; i++){
        leftArray[i] = array[l + i];
    }

    for(int i = 0; i < sub2; i++){
        rightArray[i] = array[m + i + 1];
    }

    int indexLeft = 0;
    int indexRight = 0;
    int indexMerge = l;
    
    while(indexLeft < sub1 && indexRight < sub2){
        if(leftArray[indexLeft] <= rightArray[indexRight]){
            array[indexMerge] = leftArray[indexLeft];
            indexLeft++;
        }
        else{
            array[indexMerge] = rightArray[indexRight];
            indexRight++;
        }
        indexMerge++;
    }

    while(indexLeft < sub1){
        array[indexMerge] = leftArray[indexLeft];
        indexLeft++;
        indexMerge++;
    }

    while(indexRight < sub2){
        array[indexMerge] = rightArray[indexRight];
        indexRight++;
        indexMerge++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int l, int r){
    if(l >= r){
        return;
    }

    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
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

    mergeSort(arr1, 0, n - 1);
    mergeSort(arr2, 0, m - 1);

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