#include <iostream>

using namespace std; 

void computeLPSArray(string text, int * lps){

    int i = 1, len = 0;
    lps[0] = 0;

    while(i < text.size()){
        if(text[i] == text[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool KMP(string text, string pattern){

    int i = 0, j = 0;
    int n = text.size();
    int m = pattern.size();

    int lps[m];
    computeLPSArray(pattern, lps);

    while((n - i) >= (m - j)){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            return true;
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
    return false;
}

int main(){
    string pattern, text;

    cin >> pattern >> text;

    string new_pattern = pattern;
    int cnt = 1;
    while(new_pattern.size() < text.size()){
        new_pattern += pattern;
        cnt++;
    }

    if(new_pattern.size() >= text.size()){
        if(KMP(new_pattern, text)){
            cout << cnt;
            return 0;
        }
    }
    new_pattern += pattern;
    cnt++;

    if(KMP(new_pattern, text)){
        cout << cnt;
        return 0;
    }

    cout << -1;
    return 0;
}