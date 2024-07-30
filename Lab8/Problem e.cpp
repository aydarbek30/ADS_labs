#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int n;
    cin >> n; 

    long long letter;
    string ans = "";

    long long hash;
    for(int i = 0; i < n; i++){
        cin >> letter;
        if(i == 0){
            ans += char(97 + letter);
        }
        else{
            ans += char((letter - hash) / pow(2, i) + 97);
        }
        hash = letter;
    }

    cout << ans;

    return 0;
}