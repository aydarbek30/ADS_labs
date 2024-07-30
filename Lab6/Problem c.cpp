#include <iostream>
#include <cmath>

using namespace std;

void heapify(int arr[], int size, int index){
    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && arr[left] > arr[max]){max = left;}

    if(right < size && arr[right] > arr[max]){max = right;}

    if(max != index){
        swap(arr[max], arr[index]);
        heapify(arr, size, max);
    }
}

void heapSort(int arr[], int size){
    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(arr, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);

    int min = abs(arr[1] - arr[0]);
    for(int i = 1; i < n; i++){
        if(min > abs(arr[i] - arr[i - 1])){
            min = abs(arr[i] - arr[i - 1]);
        }
    }

    for(int i = 1; i < n; i++){
        if(abs(arr[i] - arr[i - 1]) == min){
            cout << arr[i - 1] << ' ' << arr[i] << ' ';
        }
    }
    return 0;
}