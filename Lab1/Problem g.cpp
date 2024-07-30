#include <iostream>
#include <cmath>
#include <queue>

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
    int cnt = 0;
    int prime = 2;


    while(n > 0){
        if(is_prime(prime)){
            cnt += 1;
            if(is_prime(cnt)){
                n -= 1;
            }
        }
        prime += 1;
    }


    cout << prime - 1;
    return 0;
}