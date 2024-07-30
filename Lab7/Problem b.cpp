#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int left = 0;
    int right = 0;
    while(left < n && right < m){
        if(a[left] < b[right]){
            cout << a[left] << ' ';
            left++;
        }
        else{
            cout << b[right] << ' ';
            right++;
        }
    }

    while(left < n){
        cout << a[left] << ' ';
        left++;
    }

    while(right < m){
        cout << b[right] << ' ';
        right++;
    }
    return 0;
}