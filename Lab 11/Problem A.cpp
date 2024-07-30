#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long nodes, m;
unsigned long long l, r, w;
unsigned long long p[200002];
pair<unsigned long long, pair<unsigned long long, unsigned long long> > prs[200002];
unsigned long long ans = 0;

unsigned long long getParent(unsigned long long v){
    if(v == p[v]) return v;
    return p[v] = getParent(p[v]);
}

unsigned long long merge(unsigned long long u, unsigned long long v){
    u = getParent(u);
    v = getParent(v);
    if(u == v){
        return v;
    }
    p[u] = v;
    ans += w;
    return v;
}

int main(){
    cin >> nodes >> m;
    for(unsigned long long i = 0; i < m ;i++){
        cin >> l >> r >> w;
        prs[i] = make_pair(w, make_pair(l, r));
    }
    for(unsigned long long i = 1; i <= nodes; i++){
        p[i] = i;
    }
    sort(prs, prs + m);
    for(unsigned long long i = 0; i < m; i++){
        unsigned long long l = prs[i].second.first;
        unsigned long long r = prs[i].second.second;
        w = prs[i].first;
        for(unsigned long long j = l + 1; j <= r; j++){
            j = merge(l, j);
            if(j > r){
                break;
            }
        }
    }
    cout << ans;

    return 0;
}