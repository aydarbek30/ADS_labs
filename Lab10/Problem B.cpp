#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a[100][100];
int n;
vector <int> visited;

int findShortestPath(int start, int end){
    visited[start] = 0;
    queue <int> toCheck;
    toCheck.push(start);
    while(!toCheck.empty()){
        int s = toCheck.front();
        toCheck.pop();
        for(int i = 0; i < n; i++){
            if(a[i][s] == 1 && visited[i] == -1){
                visited[i] = visited[s] + 1;
                toCheck.push(i);
                if(i == end){
                    return visited[i];
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        visited.push_back(-1);
    }

    int start, end;
    cin >> start >> end;
    start--; end--;
    cout << findShortestPath(start, end);
    return 0;
}