#include <bits/stdc++.h>

using namespace std;

void computeLPSArray(string text, int * lps){
    lps[0] = 0;
    int i = 1, len = 0;

    while(i < text.size()){
        if(text[i] == text[len]){
            lps[i++] = ++len;
            continue;
        }
        if(len != 0){
            len = lps[len - 1];
            continue;
        }
        lps[i++] = 0;
    }
}

int main(){

    string text;
    cin >> text;

    int lps[text.size()];

    computeLPSArray(text, lps);

    int cnt = 0;
    for(int i = 1; i < text.size(); i++){
        if(lps[i - 1] == 0){continue;}
        int len = i - lps[i - 1];
        if(i % len != 0){
            continue;
        }
        if((i / len) % 2 != 0){
            continue;
        }
        cnt++;
    }

    cout << cnt;
    return 0;
}