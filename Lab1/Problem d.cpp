#include <iostream>
#include <stack>


using namespace std;

int main(){
    string s;
    cin >> s;
    stack <char> st;


    for(int i = 0; i < s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top() == s[i]){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }


    if(st.empty()){
        cout << "YES";
        return 0;
    }


    cout << "NO";

    return 0;
}