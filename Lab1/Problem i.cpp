#include <iostream>
#include <queue>


using namespace std;

queue <int> fill(string s, char c){
    queue <int> ans;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c){
            ans.push(i);
        }
    }
    return ans;
}

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;


    queue <int> sak = fill(s, 'S');
    queue <int> kat = fill(s, 'K');

    while(!sak.empty() and !kat.empty()){
        if(sak.front() < kat.front()){
            sak.push(sak.front() + s.size());
            sak.pop();
            kat.pop();
            continue;
        }
        kat.push(kat.front() + s.size());
        kat.pop();
        sak.pop();
    }

    if(!sak.empty()){
        cout << "SAKAYANAGI";
        return 0;
    }

    cout << "KATSURAGI";
    return 0;
}