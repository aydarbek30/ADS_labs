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
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){

    int t;
    cin >> t;
    int a[t];
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }

    int n, m;
    cin >> n >> m;
    int matrix[n * m];
    for(int i = 0; i < n; i++){
        if(i % 2){
            for(int j = m - 1; j >= 0; j--){
                cin >> matrix[i * m + j];
            }
        }
        else{
            for(int j = 0; j < m; j++){
                cin >> matrix[i * m + j];
            }
        }
    }

    for(int i = 0; i < t; i++){
        int cnt = binarySearch(matrix, n * m, a[i]);
        if(cnt == -1){
            cout << cnt << endl;
            continue;
        }
        int x = cnt / m;
        int y = cnt % m;
        if(x % 2){
            y = m - y - 1;
        }
        cout << x << ' ' << y << endl;
    }

    return 0;
}