#include <iostream>

using namespace std;

void computeLPSArray(string pattern, int * lps){
    int i = 1, len = 0;
    lps[0] = 0;

    while(i < pattern.size()){
        if(pattern[i] == pattern[len]){
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

int countSubString(string text, string pattern){
    int m = pattern.size();
    int n = text.size();

    int lps[m];
    computeLPSArray(pattern, lps);

    int i = 0, j = 0;
    int cnt = 0;
    while((n - i) >= (m - j)){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            cnt++;
            j = lps[j - 1];
        }
        else if(i < n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }

    return cnt;
}

int main(){
    string pat, text;
    int n;
    cin >> pat >> n >> text;

    if(countSubString(text, pat) >= n){
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}