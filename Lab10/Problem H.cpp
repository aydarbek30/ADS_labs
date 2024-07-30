#include <iostream>

using namespace std;

string arr[100];
int n, m;

bool visit[100][100];

void DFS(int x, int y){
    visit[x][y] = true;
    if(x - 1 >= 0 && !visit[x - 1][y] && arr[x - 1][y] == '1'){
        DFS(x - 1, y);
    }
    if(x + 1 < n && !visit[x + 1][y] && arr[x + 1][y] == '1'){
        DFS(x + 1, y);
    }
    if(y - 1 >= 0 && !visit[x][y - 1] && arr[x][y - 1] == '1'){
        DFS(x, y - 1);
    }
    if(y + 1 < m && !visit[x][y + 1] && arr[x][y + 1] == '1'){
        DFS(x, y + 1);
    }
}

int countIslands(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;  j++){
            if(!visit[i][j] && arr[i][j] == '1'){
                DFS(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visit[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << countIslands() << endl;

    return 0;
}