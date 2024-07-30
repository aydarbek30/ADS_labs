#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int sto(string s){
    int ans = 0;
    if(s[0] == '0'){
        return int(s[1]) - 48;
    }

    for(int i = 0; i < s.size(); i++){
        ans += pow(10, s.size() - i - 1) * (int(s[i]) - 48);
    }
    return ans;
}

struct Date{
    int year;
    int month;
    int day;

    Date(string format){
        bool d = true;
        string local = "";
        for(int i = 0; i < format.size(); i++){
            if(format[i] == '-'){
                if(d){
                    day = sto(local);
                    local = "";
                    d = false;
                }
                else{
                    month = sto(local);
                    local = "";
                }
                continue;
            }
            local += format[i];
        }
        year = sto(local);
    }

    void print(){
        if(day < 10){
            if(month < 10){
                cout << '0' << day << '-' << '0' << month << '-' << year << endl;
                return;
            }
            cout << '0' << day << '-' << month << '-' << year << endl;
            return;
        }
        if(month < 10){
            cout << day << '-' << '0' << month << '-' << year << endl;
            return;
        }
        cout << day << '-' << month << '-' << year << endl;
    }
};

bool cmp(Date * d1, Date * d2){
    if(d1->year < d2->year){return true;}
    if(d1->year == d2->year){
        if(d1->month < d2->month){return true;}
        if(d1->month == d2->month){
            return d1->day < d2->day;
        }
    }
    return false;
}

void heapify(vector <Date *> &v, int size, int index){
    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && cmp(v[max], v[left])){
        max = left;
    }

    if(right < size && cmp(v[max], v[right])){
        max = right;
    }

    if(index != max){
        swap(v[index], v[max]);
        heapify(v, size, max);
    }
}

void heapSort(vector <Date *> &v){
    for(int i = (v.size() - 1) / 2; i >= 0; i--){
        heapify(v, v.size(), i);
    }

    for(int i = v.size() - 1; i >= 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    string s;

    vector <Date *> dates;
    for(int i = 0; i < n; i++){
        cin >> s;
        Date * newDate = new Date(s);
        dates.push_back(newDate);
    }

    heapSort(dates);
    for(int i = 0; i < n; i++){
        dates[i]->print();
    }

    return 0;
}