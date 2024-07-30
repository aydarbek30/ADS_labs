#include <bits/stdc++.h>

using namespace std;

int n;

class Edge{
    public:
    int src;
    int dest;
    int weight;
    Edge(int src, int dest, int weight){
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class Graph{
    public:
    vector <Edge *> g;
    void addEdge(Edge * e){
        g.push_back(e);
    }

    void addEdge(int src, int dest, int weight){
        g.push_back(new Edge(src, dest, weight));
    }
};

void findCycle(Graph * g){
    bool visited[n];
    int dist[n];
    int parent[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[0] = 0;
    visited[0] = true;
    bool flag = true;

    for(int i = 1; i <= n - 1; i++){
        if(flag = false){
            break;
        }
        flag = false;

        for(int j = 0; j < g->g.size(); j++){
            int u = g->g[j]->src;
            int v = g->g[j]->dest;
            int w = g->g[j]->weight;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                flag = true;
                visited[v] = true;
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    int c = -1;
    for(int j = 0; j < g->g.size(); j++){
        int u = g->g[j]->src;
        int v = g->g[j]->dest;
        int w = g->g[j]->weight;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            c = v;
            break;
        }
    }

    if(c == -1){
        cout << "NO";
        return;
    }

    for(int i = 0; i < n; i++){
        c = parent[c];
    }
    stack <int> cycle;
    for(int v = parent[c];; v = parent[v]){
        if(v == -1){
            break;
        }
        cycle.push(v);
        if(v == c){
            break;
        }
    }

    cout << "YES" << endl << cycle.size() + 1 << endl;
    int none = -1;
    while(!cycle.empty()){
        if(none == -1){
            none = cycle.top();
        }
        cout << cycle.top() + 1 << ' ';
        cycle.pop();
    }

    cout << none + 1;
}

int main(){

    Graph * g = new Graph();
    cin >> n;

    for(int i = 0; i < n; i++){
        int arr[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        for(int j = 0; j < n; j++){
            if(arr[j] != 100000){
                g->addEdge(i, j, arr[j]);
            }
        }
    }

    findCycle(g);
    return 0;
}