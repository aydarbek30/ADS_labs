#include <iostream>
#include <stack>
#include <queue>


using namespace std;


int main(){
    int n;
    cin >> n;

    queue <int> values;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        values.push(t);
    }


    stack <int> ans;
    while(!values.empty()){
        stack <int> deleted;
        int nearest = -1;
        while(!ans.empty()){
            if(ans.top() <= values.front()){
                nearest = ans.top();
                break;
            }
            int t = ans.top();
            ans.pop();
            deleted.push(t);
        }
        while(!deleted.empty()){
            ans.push(deleted.top());
            deleted.pop();
        }
        ans.push(values.front());
        values.pop();
        cout << nearest << ' ';
    }
    return 0;
}