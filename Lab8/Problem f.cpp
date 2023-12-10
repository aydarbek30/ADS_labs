#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    
    long long q = 9007199254740881;
    string s; 
    cin >> s;
    
    unordered_set <long long> hashes;
    int count = 0;

    for(int i = 0; i < s.size(); i++){
        long long hash = 0;
        for(int j = i; j < s.size(); j++){
            hash = (hash * 256 + s[j]) % q;
            if(hashes.find(hash) == hashes.end()){
                count++;
                hashes.insert(hash);
            }
        }
    }

    cout << count;
}
