#include <iostream>

using namespace std;

int d = 26;

int countSubStrings(string text, int l, int r){

    int textSize = text.size();
    int patternSize = r - l + 1;

    int ans = 0;

    long long h = 1;
    long long t = 0;
    long long p = 0;

    int i, j;

    for(i = 0; i < patternSize - 1; i++){
        h = (h * d) % int(1e9 + 7);
    }

    for(i = 0; i < patternSize; i++){
        p = (p * d + (text[l + i]) - 'a') % int(1e9 + 7);
        t = (t * d + (text[i] - 'a')) % int(1e9 + 7);

    }

    for(i = 0; i < textSize; i++){
        if(t == p){
            for(j = 0; j < patternSize; j++){
                if(text[i + j] != text[l + j]){
                    break;
                }
            }
            if(j == patternSize){
                ans++;
            }
        }
        if(i < textSize - patternSize){
            t = ((d * (t - (text[i] - 'a') * h)) + (text[i + patternSize]) - 'a') % int(1e9 + 7);
        }
        if(t < 0){
            t = t + int(1e9 + 7);
        }
    }
    return ans;
}

int main(){

    string pattern;
    cin >> pattern;

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << countSubStrings(pattern, l, r) << endl;
    }
    return 0;
}