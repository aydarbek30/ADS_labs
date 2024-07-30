#include <iostream>
#include <queue>
#include <cmath>


using namespace std;

bool is_prime(int n){
    queue <int> div;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            div.push(i);
        }
    }
        if(div.size() == 2){
            return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;


    if(is_prime(n)){
        cout << "YES";
        return 0;
    }


    cout << "NO";

    return 0;
}