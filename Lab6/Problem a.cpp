#include <iostream>

using namespace std;

bool cmp(char c1, char c2){
    bool isLowercaseVowel1 = (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u');
    bool isLowercaseVowel2 = (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u');
    if(isLowercaseVowel1 && !isLowercaseVowel2){
        return true;
    }
    if(!isLowercaseVowel1 && isLowercaseVowel2){
        return false;
    }
    return c1 < c2;
}

void heapify(char a[], int size, int index ){
    int min = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    
    if(l < size && cmp(a[l], a[min])){
        min = l;
    }

    if(r < size && cmp(a[r], a[min])){
        min = r;
    }

    if(min != index){
        swap(a[min], a[index]);
        heapify(a, size, min);
    }
}

void heapSort(char a[], int size){
    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(a, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}


int main(){
    int n;
    cin >> n;

    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    heapSort(a, n);
    for(int i = n - 1; i >= 0; i--){
        cout << a[i];
    }

    return 0;
}