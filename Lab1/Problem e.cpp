#include <iostream>
#include <deque>


using namespace std;

deque <int> fill_deque(){
    deque <int> ans;
    for(int i = 0; i < 5; i++){
        int t;
        cin >> t;
        ans.push_back(t);
    }
    return ans;
}

int main(){
    deque <int> d1 = fill_deque();
    deque <int> d2 = fill_deque();


    int cnt = 0;

    while(!d1.empty() and !d2.empty()){
        if(cnt >= 1000000){
            cout << "blin nichya";
            return 0;
        }
        int t1 = d1.front();
        int t2 = d2.front();
        d1.pop_front();
        d2.pop_front();
        cnt += 1;



        if(t1 == 9 and t2 == 0){
            d2.push_back(t1);
            d2.push_back(t2);
            continue;
        }
        if(t1 == 0 and t2 == 9){
            d1.push_back(t1);
            d1.push_back(t2);
            continue;
        }
        if(t1 > t2){
            d1.push_back(t1);
            d1.push_back(t2);
        }
        else{
            d2.push_back(t1);
            d2.push_back(t2);
        }
    }


    if(d1.empty()){
        cout << "Nursik " << cnt;
        return 0;
    }


    cout << "Boris " << cnt;
    return 0;
}