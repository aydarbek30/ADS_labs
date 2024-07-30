#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

double getGpa(string grade){
    if(grade == "A+"){return 4.0;}
    if(grade == "A"){return 3.75;}
    if(grade == "B+"){return 3.50;}
    if(grade == "B"){return 3.0;}
    if(grade == "C+"){return 2.50;}
    if(grade == "C"){return 2.0;}
    if(grade == "D+"){return 1.5;}
    if(grade == "D"){return 1.0;}
    return 0;
}

bool cmp(pair <pair <string, string>, double> &st1, pair <pair <string, string>, double>&st2){
    if(st1.second < st2.second){return true;}
    if(st1.second == st2.second){
        if(st1.first.first < st2.first.first){return true;}
        if(st1.first.first == st2.first.first){
            return st1.first.second < st2.first.second;
        }
        return false;
    }
    return false;
}

void heapify(vector <pair <pair <string, string>, double> > &arr, int size, int index){
    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && cmp(arr[max], arr[left])){
        max = left;
    }

    if(right < size && cmp(arr[max], arr[right])){
        max = right;
    }

    if(index != max){
        swap(arr[max], arr[index]);
        heapify(arr, size, max);
    }
}

void heapSort(vector <pair <pair <string, string>, double> > &arr){
    int size = arr.size();
    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(arr, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,  i, 0);
    }
}

int main(){

    int n, k, count;
    cin >> n;

    vector <pair <pair <string, string>, double> > v;
    string name, surname, grade;

    for(int i = 0; i < n; i++){
        cin >> surname >> name >> k;
        int cnt = 0;
        double sums = 0;
        for(int j = 0; j < k; j++){
            cin >> grade >> count;
            sums += getGpa(grade) * count;
            cnt += count;
        }
        v.push_back(make_pair(make_pair(surname, name), sums / cnt));
    }

    heapSort(v);

    cout << fixed << setprecision(3);

    for(int i = 0; i < n; i++){
        cout << (v[i]).first.first << ' ' << (v[i]).first.second << ' ' << (v[i]).second << endl;
    }
    return 0;
}