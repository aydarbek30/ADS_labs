#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
 
class Graph {
    vector<vector<int> > edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }
 
    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());
 
        DSU s(V);
        int ans = 0;
        for (auto edge: edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
 
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
 
        cout << ans;
    }
};
 
int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    Graph g(n);

    string type;
    int l, r, price;

    for(int i = 0; i < m; i++){
        cin >> type >> l >> r >> price;
        if(type == "both"){
            g.addEdge(l, r, price * min(x, y));
            g.addEdge(r, l, price * min(x, y));
        }
        else if(type == "big"){
            g.addEdge(l, r, price * x);
            g.addEdge(r, l, price * x);
        }
        else{
            g.addEdge(l, r, price * y);
            g.addEdge(r, l, price * y);
        }
    }
    g.kruskals_mst();
    return 0;
}