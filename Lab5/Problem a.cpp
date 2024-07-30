#include <iostream>

using namespace std;


struct PriorityQueue{
    long long arr[2 * 100000];
    int size;

    PriorityQueue(){
        size = 0;
    }
    

    void add(long long val){
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    void heapifyDown(int index){
        int minim = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if(l < size && arr[l] < arr[minim]){
            minim = l;
        }

        if(r < size && arr[r] < arr[minim]){
            minim = r;
        }

        if(minim != index){
            swap(arr[minim], arr[index]);
            heapifyDown(minim);
        }
    }

    void heapifyUp(int index){
        while(index > 0 && arr[index] < arr[(index - 1) / 2]){
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    long long extractMin(){
        long long res = arr[0];
        
        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);
        return res;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;

    PriorityQueue * queue = new PriorityQueue();
    long long t;
    for(int i = 0; i < n; i++){
        cin >> t;
        queue->add(t);
    }

    long long cnt = 0;
    for(int i = 0; i < n - 1; i++){
        long long t1, t2;
        t1 = queue->extractMin();
        t2 = queue->extractMin();
        queue->add(t1 + t2);
        cnt += t1 + t2;
    }

    cout << cnt;
    return 0;
}