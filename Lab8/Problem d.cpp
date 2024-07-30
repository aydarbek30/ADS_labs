#include <iostream>
#include <vector>

using namespace std;

int d = 26;

int count(string text, string pattern){

    int ans = 0;

    int textSize = text.size();
    int patternSize = pattern.size();

    int i, j;
    long long p = 0;
    long long t = 0;
    long long h = 1;

    for(i = 0; i < patternSize - 1; i++){
        h = (h * d) % int(1e9 + 7);
    }

    for(i = 0; i < patternSize; i++){
        p = (d * p + (pattern[i] - 'a')) % int(1e9 + 7);
        t = (d * t + (text[i] - 'a')) % int(1e9 + 7);
    }

    for(i = 0; i <= textSize - patternSize; i++){
        if(p == t){
            for(j = 0; j < patternSize; j++){
                if(pattern[j] != text[i + j]){
                    break;
                }
            }
            if(j == patternSize){
                ans++;
        }
        }

        if(i < textSize - patternSize){
            t = ((d * (t - (text[i] - 'a') * h)) + (text[i + patternSize] - 'a')) % int(1e9 + 7);
        }

        if(t < 0){
            t = (t + int(1e9 + 7));
        }
    }
    return ans;
}

pair <int, vector <string> > maximums(string text, vector <string> patterns){
    int max = count(text, patterns[0]);
    vector <string> maxs;
    maxs.push_back(patterns[0]);
    for(int i = 1; i < patterns.size(); i++){
        int localMax = count(text, patterns[i]);
        if(localMax > max){
            max = localMax;
            while(!maxs.empty()){
                maxs.pop_back();
            }
        }
        if(localMax == max){
            maxs.push_back(patterns[i]);
        }
    } 
    return make_pair(max, maxs);
}

void printVector(vector <string> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
}

int main(){

    int num;
    vector <string> patterns;
    while(true){
        cin >> num;
        string pattern;
        string text;
        if(num == 0){break;}
        for(int i = 0; i < num; i++){
            cin >> pattern;
            patterns.push_back(pattern);
        }
        cin >> text;
        pair <int, vector <string> > ans = maximums(text, patterns);
        cout << ans.first << endl;
        printVector(ans.second);
        patterns.clear();
    }
    return 0;
}