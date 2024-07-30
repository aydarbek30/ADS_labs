#include <iostream>

using namespace std;

string LCS(string s1, string s2){

    int xSize = s1.size();
    int ySize = s2.size();

    int a[xSize + 1][ySize + 1];
    for(int i = 0; i <= xSize; i++){
        for(int j = 0; j <= ySize; j++){
            a[i][j] = 0;
        }
    }

    for(int i = 1; i <= xSize; i++){
        for(int j = 1; j <= ySize; j++){
            if(s1[i - 1] == s2[j - 1]){
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else{
                a[i][j] = 0;
            }
        }
    }

    string longest = "";
    for(int i = 1; i <= xSize; i++){
        for(int j = 1; j <= ySize; j++){
            if(a[i][j] > longest.size()){
                longest = s1.substr(i - a[i][j], a[i][j]);
            }
        }
    }

    return longest;
}

int main(){

    string s;
    string ans;
    int k;
    cin >> k;
    cin >> s;
    ans = s;
    for(int i = 0; i < k - 1; i++){
        cin >> s;
        ans = LCS(ans, s);
    }
    cout << ans;
    return 0;
}