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


    int last_prime = 2;
    n -= 1;


    while(true){
        if(n == 0){
            cout << last_prime;
            return 0;
        }
        last_prime += 1;
        if(is_prime(last_prime)){
            n -= 1;
        }
    }

    return 0;
}