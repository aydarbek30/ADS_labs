#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

long long hash_(string s){
    long long hash = 0;
    long long h = 1;
    for(int i = 0; i < s.size(); i++){
        hash += (((s[i] - 47) % int(1e9 + 7)) * h) % int(1e9 + 7);
        h *= 11;
        h = h % int(1e9 + 7);
    }
    return hash % int(1e9 + 7);
}

int main(){

    map <string, bool> nums;
    int n;
    cin >> n;

    vector <string> nums1;

    for(int i = 0; i < 2 * n; i++){
        string s;
        cin >> s;
        nums[s] = true;
        nums1.push_back(s);
    }

    int cnt = 0;
    for(int i = 0; i < 2 * n; i++){
        stringstream ss;
        long long hash = hash_(nums1[i]);
        ss<<hash;
        string local;
        ss>>local;
        if(nums[local]){
            cout << "Hash of string \"" << nums1[i] <<  "\" is " << hash << endl;
            cnt++;
        }
        if(cnt == n){
            break;
        }
    }
    return 0;
}