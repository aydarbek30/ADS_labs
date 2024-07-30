#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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

void merge(vector <pair <pair <string, string>, double> > &arr, int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;

    vector <pair <pair <string, string>, double> > *left = new vector <pair <pair <string, string>, double> > ();
    vector <pair <pair <string, string>, double> > *right = new vector <pair <pair <string, string>, double> > ();

    for(int i = 0; i < sub1; i++){
        left->push_back(arr[l + i]);
    }

    for(int i = 0; i < sub2; i++){
        right->push_back(arr[m + i + 1]);
    }

    int leftInd = 0;
    int rightInd = 0;
    int mergeInd = l;

    while(leftInd < sub1 && rightInd < sub2){
        if(cmp(left->at(leftInd), right->at(rightInd))){
            arr[mergeInd++] = left->at(leftInd++);
        }
        else{
            arr[mergeInd++] = right->at(rightInd++);
        }
    }

    while(leftInd < sub1){
        arr[mergeInd++] = left->at(leftInd++);
    }

    while(rightInd < sub2){
        arr[mergeInd++] = right->at(rightInd++);
    }

    delete left;
    delete right;
}

void mergeSort(vector <pair <pair <string, string>, double> > &arr, int l, int r){
    if(l >= r){return;}

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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

    mergeSort(v, 0, n - 1);

    cout << fixed << setprecision(3);

    for(int i = 0; i < n; i++){
        cout << (v[i]).first.first << ' ' << (v[i]).first.second << ' ' << (v[i]).second << endl;
    }
    return 0;
}