#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;



vector <int> cycle;
vector <int> parents;



class Graph{
    public:
    int size;
    vector <vector <int> > g;
    Graph(int V){
        size = V;
        g.resize(V);
    }

    void addEdge(int v1, int v2){
        g[v1].push_back(v2);
    }

    void DFS(vector <int> & colors, int v,  int parent){
        if(colors[v] == 2){
            return;
        }

        if(colors[v] == 1){
            int cur = parent;
            if(cycle.size() != 0){
                return;
            }
            cycle.push_back(cur);
            while(cur != -1 && cur != v){
                cur = parents[cur];
                cycle.push_back(cur);
            }
            return;
        }

        parents[v] = parent;

        colors[v] = 1;
        for(int i = 0; i < g[v].size(); i++){
            DFS(colors, g[v][i], v);
        }

        colors[v] = 2;
    }

    void print(){
        for(int i = 0; i < g.size(); i++){
            cout << i << ": ";
            for(int j = 0; j  < g[i].size(); j++){
                cout << g[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

void printColors(vector <int> colors){
    for(int i = 0; i < colors.size(); i++){
        cout << colors[i] << ' ';
    }
    cout << endl;
}


bool hasCycle(Graph * g, vector <int> &colors, int start, int u, int u1){
    colors[start] = 1;

    for(int i = 0; i < g->g[start].size(); i++){
        if(colors[g->g[start][i]] == 2){
            continue;
        }
        if(start == u && g->g[start][i] == u1){
            continue;
        }
        if(colors[g->g[start][i]] == 1){
            return true;
        }
        if(hasCycle(g, colors, g->g[start][i], u, u1)){
            return true;
        }
    }

    colors[start] = 2;
    return false;
}



int main(){
    int n, m;
    cin >> n >> m;

    Graph * g = new Graph(n);
    vector <int> colors;
    colors.resize(n, 0);
    parents.resize(n, -1);
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        v1--;v2--;
        g->addEdge(v1, v2);
    }

    for(int i = 0; i < n; i++){
        if(cycle.size() != 0){
            break;
        }
        if(colors[i] == 0){
            g->DFS(colors, i, -1);
        }
    } 

    if(cycle.size() == 0){
        cout << "YES";
        return 0;
    }
    reverse(cycle.begin(), cycle.end());
    cycle.push_back(cycle[0]);

    for(int i = 0; i < cycle.size() - 1; i++){
        int v1 = cycle[i];
        int v2 = cycle[i + 1];
        vector <int> colors;
        colors.resize(n, 0);
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(colors[j] == 2){
                continue;
            }
            if(hasCycle(g, colors, j, v1, v2)){
                flag = false;
            }
        }
        if(flag){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}