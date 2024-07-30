#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    int min = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[min] > a[i]){
            min = i;
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(i == min){
            continue;
        }
        cnt += a[min] + a[i];
    }

    cout << cnt;
    return 0;
}