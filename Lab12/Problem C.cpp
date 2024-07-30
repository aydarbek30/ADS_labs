#include <iostream>
#include <vector>

using namespace std;

int n, m;

int graph1[1000][1000], graph2[1000][1000];

int minDist(int * dist, bool * vis){
    int min = 1e9 + 7, minInd;
    for(int i = 0; i < n; i++){
        if(!vis[i] && dist[i] <= min){
            min = dist[i];
            minInd = i;
        }
    }
    return minInd;
}


int Djikstra(int g){
    int dist[n];
    bool vis[n];
    for(int i = 0; i < n; i++){
        dist[i] = 1e9 + 7;
        vis[i] = false;
    }

    dist[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int u = minDist(dist, vis);
        vis[u] = true;
        for(int j = 0; j < n; j++){
            if(!vis[j] && dist[u] != 1e9 + 7){
                if(graph1[u][j] && dist[j] > dist[u] + graph1[u][j]){
                    if(g == 2){
                        continue;
                    }
                    dist[j] = dist[u] + graph1[u][j];
                }
                if(graph2[u][j] && dist[j] > dist[u] + graph2[u][j]){
                    if(g == 1){
                        continue; 
                    }
                    dist[j] = dist[u] + graph2[u][j];
                }
            }
        }
    }

    if(dist[n - 1] == 1e9 + 7){
        return -1;
    }
    return dist[n - 1];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph1[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph1[x - 1][y - 1] = 1;
        graph1[y - 1][x - 1] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph1[i][j] == 0){
                graph2[i][j] = 1;
                graph2[j][i] = 1;
            }
            else{
                graph2[i][j] = 0;
                graph2[j][i] = 0;
            }
        }
    }

    int ans1 = Djikstra(1);
    int ans2 = Djikstra(2);

    if(ans1 == -1 or ans2 == -1){
        cout << -1;
        return 0;
    }

    cout << max(ans1, ans2);

    return 0;
}