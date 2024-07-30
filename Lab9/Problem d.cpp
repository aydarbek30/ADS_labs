#include<bits/stdc++.h>

using namespace std;

int countCPS(string text1, string text2){
    string to_check = text2 + text1;
    int lps[to_check.size()];
    int i = 1, len = 0;
    lps[0] = 0;

    while(i < to_check.size()){
        if(to_check[i] == to_check[len]){
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
    return lps[to_check.size() - 1];
}

int main(){
    string first, second;
    cin >> first;
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    int n;
    cin >> n;

    vector <string> ans;
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> second;
        string second_copy = second;
        transform(second_copy.begin(), second_copy.end(), second_copy.begin(), ::tolower);
        int value = countCPS(first, second_copy);
        if(value > max){
            ans.clear();
            max = value;
        }
        if(max == value && max != 0){
            ans.push_back(second);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}