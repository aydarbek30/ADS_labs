#include <iostream>

using namespace std;

int d = 26;
long long q = int(1e9 + 7);

int countOnSamePosition(string text1, string text2, string pattern){

    int count = 0;
    int textSize = text1.size();
    int patternSize = pattern.size();


    long long h = 1, t1 = 0, t2 = 0, p = 0;

    int i, j;

    for(i = 0; i < patternSize - 1; i++){
        h = (h * d) % int(1e9 + 7);
    }

    for(i = 0; i < patternSize; i++){
        p = (p * d + (pattern[i] - 'a')) % int(1e9 + 7);
        t1 = (t1 * d + (text1[i] - 'a')) % int(1e9 + 7);
        t2 = (t2 * d + (text2[i] - 'a')) % int(1e9 + 7);
    }

    for(i = 0; i < textSize - patternSize + 1; i++){
        if(t1 == p and t2 == p){
            count++;
        }

        if(i < textSize - patternSize){
            t1 = ((d * (t1 - (text1[i] - 'a') * h)) + (text1[i + patternSize] - 'a')) % int(1e9 + 7);
            t2 = ((d * (t2 - (text2[i] - 'a') * h)) + (text2[i + patternSize] - 'a')) % int(1e9 + 7);
        }
        if(t1 < 0){
            t1 = t1 + int(1e9 + 7);
        }
        if(t2 < 0){
            t2 = t2 + int(1e9 + 7);
        }
    }

    return count;
}

int main(){

    string text1, text2, pattern;

    cin >> text1 >> text2 >> pattern;

    cout << countOnSamePosition(text1, text2, pattern);

    return 0;
}