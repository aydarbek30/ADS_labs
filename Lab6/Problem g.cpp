#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector <pair <string, string> > v;
    string oldName, newName;
    for(int i = 0; i < n; i++){
        bool flag = true;
        cin >> oldName >> newName;
        for(int j = 0; j < v.size(); j++){
            if(v[j].second == oldName){
                v[j].second = newName;
                flag = false;
                break;
            }
        }
        if(flag){
            v.push_back(make_pair(oldName, newName));
        }
    }

    cout << v.size() << endl; 
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}