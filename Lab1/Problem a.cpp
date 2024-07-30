#include <iostream>
#include <deque>

using namespace std;


deque <int> fill(int n){
    deque <int> ans;
    for(int i = n; i >= 1; i--){
        ans.push_back(i);
        for(int j = 0; j < i % ans.size(); j++){
            int t = ans.front();
            ans.pop_front();
            ans.push_back(t);
        }
    }
    return ans;
}


deque <int> reverse(deque <int> d){
    deque <int> ans;
    int k = d.size();
    for(int i = 0; i < k; i++){
        int t = d.back();
        d.pop_back();
        ans.push_back(t);
    }
    return ans;
}

void print_deque(deque <int> d){
    int k = d.size();
    for(int i = 0; i < k; i++){
        cout << d.front() << ' ';
        d.pop_front();
    }
    cout << endl;
}


int main(){
    int n;
    cin >> n;


    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        print_deque(reverse(fill(k)));
    }

    return 0;

}