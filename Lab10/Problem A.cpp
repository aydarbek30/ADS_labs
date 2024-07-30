#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1000][1000];

queue <pair <int, int> > check;

void checkAdj(int x, int y){
    if(x - 1 >= 0 && arr[x - 1][y] == 1){
        arr[x - 1][y] = 2;
        check.push(make_pair(x - 1, y));
    }
    if(x + 1 < n && arr[x + 1][y] == 1){
        arr[x + 1][y] = 2;
        check.push(make_pair(x + 1, y));
    }
    if(y - 1 >= 0 && arr[x][y - 1] == 1){
        arr[x][y - 1] = 2;
        check.push(make_pair(x, y - 1));
    }
    if(y + 1 < m && arr[x][y + 1] == 1){
        arr[x][y + 1] = 2;
        check.push(make_pair(x, y + 1));
    }
}

void fill(){
    int cnt = 0;
    while(!check.empty()){
        int size = check.size();
        for(int i = 0; i < size; i++){
            int x = check.front().first;
            int y = check.front().second;
            check.pop();
            checkAdj(x, y);
        }
        if(!check.empty()){
            cnt++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                cout << -1;
                return;
            }
        }
    }
    cout << cnt;
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                check.push(make_pair(i, j));
            }
        }
    }

    fill();
    return 0;
}