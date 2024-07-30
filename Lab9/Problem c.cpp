#include <iostream>

using namespace std;

void computeLPSArray(string s, int * arr){

    int i = 1, len = 0;
    arr[0] = 0;
    while(i < s.size()){
        if(s[i] == s[len]){
            len++;
            arr[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = arr[len - 1];
            }
            else{
                arr[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string text, string pattern){

    int i = 0, j = 0;
    int n = text.size(), m = pattern.size();

    int lps[m];
    computeLPSArray(pattern, lps);

    while((n - i) >= (m - j)){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            return i - j;
        }
        if(i < n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }

    return -1;
}

int main(){

    string text;
    string cyclicShift;

    cin >> text >> cyclicShift;

    int ans = KMP(text + text, cyclicShift);
    if(ans == -1){
        cout << -1;
        return 0;
    }

    cout << text.size() - ans;
    return 0;
}