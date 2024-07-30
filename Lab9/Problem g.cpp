#include <bits/stdc++.h>

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

int main(){
    string text;
    cin >> text;

    int arr[text.size()];

    computeLPSArray(text, arr);

    int l = text.size() - arr[text.size() - 1];

    cout << l;
    return 0;
}