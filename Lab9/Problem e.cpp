#include <iostream>

using namespace std;

void countLSPArray(string text, int * array){
    int i = 1;
    int len = 0;

    array[0] = 0;
    while(i < text.size()){
        if(text[i] == text[len]){
            len++;
            array[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = array[len - 1];
            }
            else{
                array[i] = 0;
                i++;
            }
        }
    }
}

int main(){


    int n, m;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cin >> m;
        int lsp[s.size()];
        countLSPArray(s, lsp);
        cout << s.size() * m - lsp[s.size() - 1] * (m - 1) << endl;
    }
    return 0;
}