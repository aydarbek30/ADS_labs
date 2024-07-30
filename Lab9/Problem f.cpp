#include <bits/stdc++.h>

using namespace std;

void computeLPCArray(string s, int m, int * lps){
    int i = 1;
    int len = 0;
    lps[0] = 0;
    while(i < m){
        if(s[i] == s[len]){
            lps[i++] = ++len;
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

vector <int> KMP(string text, string pattern){
    int m = pattern.size();
    int n = text.size();

    int lps[m];
    int i = 0, j = 0;

    vector <int> ans;

    computeLPCArray(pattern, m, lps);

    while((n - i) >= (m - j)){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j == m){
            ans.push_back(i - j);
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return ans;
}

int main(){
    string text;
    string pattern;
    cin >> text >> pattern;

    vector <int> ans = KMP(text, pattern);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1<< ' ';
    }
    return 0;

}