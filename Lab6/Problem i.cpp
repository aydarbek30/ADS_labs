#include <iostream>

using namespace std;


void heapify(char arr[], int size, int index){
    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && arr[left] > arr[max]){
        max = left;
    }

    if(right < size && arr[right] > arr[max]){
        max = right;
    }

    if(index != max){
        swap(arr[index], arr[max]);
        heapify(arr, size, max);
    }
}

void heapSort(char arr[], int size){
    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(arr, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main(){
    string s;
    cin >> s;

    char arr[s.size()];
    for(int i = 0; i < s.size(); i++){
        arr[i] = s[i];
    }

    heapSort(arr, s.size());

    for(int i = 0; i < s.size(); i++){
        cout << arr[i];
    }

    return 0;
}