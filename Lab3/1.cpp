#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    char arr[s.size()];
    for(int i = 0; i < s.size(); i++){
        arr[i] = s[i];
    }

    for(int i = 0; i < s.size(); i++){
        cout << arr[i];
    }

    return 0;
}