#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    vector <int> visited;
    visited.resize(2 * max(a, b) + 1, -1);

    queue <int> check;
    visited[a] = 0;
    check.push(a);
    while(!check.empty()){
        int s = check.front();
        check.pop();
        if(s == b){
            break;
        }
        if(s < b){
            if(visited[2 * s] == -1 || visited[2 * s] > visited[s] + 1){
                visited[2 * s] = visited[s] + 1;
                check.push(2 * s);
            }
        }
        if(s !=0 && (visited[s - 1] == -1 || visited[s - 1] > visited[s] + 1)){
            visited[s - 1] = visited[s] + 1;
            check.push(s - 1);
        }
    }
    
    stack <int> ans;
    ans.push(b);
    while(ans.top() != a){
        if(visited[ans.top() + 1] + 1 == visited[ans.top()]){
            ans.push(ans.top() + 1);
        }
        else if(ans.top() % 2 == 0){
            ans.push(ans.top() / 2);
        }
    }

    if(ans.size() == 0){
        cout << 0;
        return 0;
    }
    ans.pop();
    cout << ans.size() << endl;
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}