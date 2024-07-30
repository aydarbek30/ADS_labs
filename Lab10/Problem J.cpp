#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    vector <list <int> > adjacent;
    int size;
    public:
    Graph(int v){
        adjacent.resize(v);
        size = v;
    }

    void addEdge(int v1, int v2){
        adjacent[v1].push_back(v2);
    }

    int countBigFams(vector <bool> &visited, int root){
        int cnt = 0;

        queue <int> check;
        check.push(root);
        visited[root] = true;
        while(!check.empty()){
            int toDel = check.size();
            for(int i = 0; i < toDel; i++){
                int s = check.front();
                check.pop();
                for(auto adj: adjacent[s]){
                    if(visited[adj]){
                        continue;
                    }
                    if(adjacent[adj].size() > adjacent[s].size()){
                        cnt++;
                    }
                    check.push(adj);
                    visited[adj] = true;
                }
            }
        }
        return cnt;
    }
};

int main(){

    int n, m;
    cin >> n >> m;

    Graph * g = new Graph(n); 

    int v1, v2;
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        v1--;v2--;
        g->addEdge(v1, v2);
    }

    int ans = 0;
    vector <bool> visited;
    visited.resize(n);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans += g->countBigFams(visited, i);
            ans++;
        }
    }

    cout << ans;
    return 0;
}