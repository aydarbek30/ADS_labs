#include <iostream>
#include <vector>

using namespace std;

void heapify(vector <vector <int> > &v, int size, int index, int column){

    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && v[left][column] < v[max][column]){
        max = left;
    }

    if(right < size && v[right][column] < v[max][column]){
        max = right;
    }

    if(index != max){
        swap(v[max][column], v[index][column]);
        heapify(v, size, max, column);
    }
}

void heapSort(vector <vector <int> > &v, int column){
    for(int i = (v.size() - 1) / 2; i >= 0; i--){
        heapify(v, v.size(), i, column);
    }

    for(int i = v.size() - 1; i >= 0; i--){
        swap(v[i][column], v[0][column]);
        heapify(v, i, 0, column);
    }
}


int main(){

    int n, m, t;
    cin >> n >> m;

    vector <vector <int> > v;
    for(int i = 0; i < n; i++){
        vector <int> local;
        for(int j = 0; j < m; j++){
            cin >> t;
            local.push_back(t);
        }
        v.push_back(local);
    }

    for(int i = 0; i < m; i++){
        heapSort(v, i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}