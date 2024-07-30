#include <iostream>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        if(arr[a][b] == 0){
            cout << "NO" << endl;
            continue;
        }
        if(arr[a][c] == 0){
            cout << "NO" << endl;
            continue;
        }
        if(arr[b][c] == 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}