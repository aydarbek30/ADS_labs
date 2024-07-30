#include <bits/stdc++.h>

using namespace std;

class Graph{
    vector <list <int> > graph;
    vector <int> colors;
    int V;
    public:
    Graph(int V){
        this->V = V;
        this->graph.resize(V);
        this->colors.resize(V, false);
    }

    void addEdge(int v1, int v2){
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    void changeColor(int v){
        colors[v] = 1; 
    }

    int BFS(int v){
        queue <int> check;
        vector <bool> visited;
        int dist = 0;
        check.push(v);
        visited.resize(this->V, false);
        visited[v] = true;


        while(!check.empty()){
            int size = check.size();
            for(int i = 0; i < size; i++){
                int s = check.front();
                check.pop();
                if(colors[s] == 1){
                    return dist;
                }
                for(auto adj: graph[s]){
                    if(!visited[adj]){
                        visited[adj] = true;
                        check.push(adj);
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};

int main(){

    int n, m, q;

    cin >> n >> m >> q;

    Graph * g = new Graph(n);

    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        g->addEdge(v1, v2);
    }

    int com, v;
    for(int i = 0; i < q; i++){
        cin >> com >> v;
        v--;
        if(com == 1){
            g->changeColor(v);
        }
        else{
            cout << g->BFS(v) << endl;
        }
    }
    return 0;
}