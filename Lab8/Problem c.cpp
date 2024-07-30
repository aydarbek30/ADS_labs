#include <iostream>

using namespace std;

int d = 26;

void countFilledLetters(string bigTape, string tape, int *a){

    long long h = 1, t = 0, p = 0;

    int i, j, textSize = bigTape.size(), patternSize = tape.size();

    for(i = 0; i < patternSize - 1; i++){
        h = (h * d) % int(1e9 + 7);
    }

    for(i = 0; i < patternSize; i++){
        p = (d * p + tape[i]) % int(1e9 + 7);
        t = (d * t + bigTape[i]) % int(1e9 + 7);
    }

    for(i = 0; i < textSize; i++){
        if(t == p){
            for(j = 0; j < patternSize; j++){
                if(bigTape[i + j] != tape[j]){
                    break;
                }
                a[i + j]++;
            }
        }
        if(i < textSize - patternSize){
            t = ((d * (t - bigTape[i] * h)) + bigTape[i + patternSize]) % int(1e9 + 7);
        }
        if(t < 0){
            t = t + int(1e9 + 7);
        }
    }
}

int main(){

    string bigTape, tape;
    int n;

    cin >> bigTape;
    
    int * a = new int[bigTape.size()];
    for(int i = 0; i < bigTape.size(); i++){
        a[i] = 0;
    }

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tape;
        countFilledLetters(bigTape, tape, a);
    }

    for(int i = 0; i < bigTape.size(); i++){
        if(a[i] == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}