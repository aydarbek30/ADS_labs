#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector <int> g [100001];
int colors[100001];
vector <int> path;

void DFS(int v){
    colors[v] = 1;
    
    for(int i = 0; i < g[v].size(); i++){
        if(colors[g[v][i]] == 0){
            DFS(g[v][i]);
        }
        if(colors[g[v][i]] == 1){
            cout << "Impossible";
            exit(0);
        }
    }

    path.push_back(v + 1);
    colors[v] = 2;
}

int main(){

    int n, m;
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < n; i++){
        colors[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    for(int i = 0; i < n; i++){
        if(colors[i] == 0){
            DFS(i);
        }
    }

    cout << "Possible" << endl;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << ' ';
    }
    return 0;
}