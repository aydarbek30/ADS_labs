#include <iostream>
#include <deque>


using namespace std;

int main(){


    deque <int> d;


    while(true){
        char comand;
        cin >> comand;
        if(comand == '!'){
            break;
        }
        if(comand == '*'){
            if(d.empty()){
                cout << "error" << endl;
                continue;
            }
            int t1 = d.back();
            int t2 = d.front();
            d.pop_back();
            if(!d.empty()){
                d.pop_front();
            }
            cout << t1 + t2 << endl;
            continue;
        }
        int t;
        cin >> t;
        if(comand == '-'){
            d.push_back(t);
            continue;
        }
        d.push_front(t);
    }
    

    return 0;
}