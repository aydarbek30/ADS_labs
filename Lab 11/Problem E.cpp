#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph{
    public:
    vector <vector <int> > g;
    vector <int> parent;
    int V;

    Graph(int size){
        V = size;
        for(int i = 0; i < V; i++){
            vector <int> t;
            g.push_back(t);
        }
        fillParent();
    }

    void fillParent(){
        for(int i = 0; i < V; i++){
            parent.push_back(i);
        }
    }

    void addEdge(int u, int v){
        if(u < v){
            g[u].push_back(v);
        }
        else{
            g[v].push_back(u);
        }
    }

    int findParent(int v){
        if(v == parent[v]){
            return v;
        }
        return parent[v] = findParent(parent[v]);
    }

    bool unite(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v){
            return false;
        }
        parent[u] = v;
        return true;
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    Graph * g = new Graph(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g->addEdge(u, v);
    }

    int cnt = -1;
    stack <int> ans;
    for(int i = n - 1; i >= 0; i--){
        cnt++;
        ans.push(cnt);
        for(int j = 0; j < g->g[i].size(); j++){
            if(g->unite(i, g->g[i][j])){
                cnt--;
            }
        }
    }
    
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}