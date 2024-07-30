#include <iostream>
#include <stack>


using namespace std;


stack <char> fill_stack(string s){
    stack <char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    return st;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    stack <char> st1 = fill_stack(s1);
    stack <char> st2 = fill_stack(s2);


    if(st1 == st2){
        cout << "Yes";
        return 0;
    }


    cout << "No";

    return 0;
}