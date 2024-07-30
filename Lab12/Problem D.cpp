#include <iostream>
#include <algorithm>

using namespace std;

int n;

pair <long long, long long> coords[1000];

long long graph[1000][1000];

long long minDist(long long dist[], bool spSet[]){
    long long min = __LONG_LONG_MAX__, minIndex;

    for(int i = 0; i < n; i++){
        if(!spSet[i] && min > dist[i]){
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

long long Dijkstra(){
    long long dist[n];
    bool spSet[n];

    for(int i = 0; i < n; i++){
        dist[i] = __LONG_LONG_MAX__;
        spSet[i] = false;
    }

    dist[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int u = minDist(dist, spSet);
        spSet[u] = true;
        for(int j = 0; j < n; j++){
            if(!spSet[j] &&  dist[j] > max(dist[u], graph[u][j])){
                    dist[j] = max(dist[u], graph[u][j]);
                }
        }
    }

    return dist[n - 1];
}

int main(){

    cin >> n;
    long long x, y;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        coords[i] = make_pair(x, y);
        for(int j = 0; j <= i; j++){
            graph[i][j] = abs(x - coords[j].first) + abs(y - coords[j].second);
            graph[j][i] = graph[i][j];
        }
    }

    cout << Dijkstra();

    return 0;
}