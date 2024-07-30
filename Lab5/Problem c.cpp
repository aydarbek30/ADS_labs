#include <iostream>

using namespace std;


struct PriorityQueue{
    long long arr[100000];
    int size;

    PriorityQueue(){
        size = 0;
    }

    void add(int val){
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    long long extractMax(){
        long long res = arr[0];

        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);
        return res;
    }

    void heapifyUp(int index){
        while(index > 0 && arr[index] > arr[(index - 1) / 2]){
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    
    void heapifyDown(int index){
        int max = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if(l < size && arr[l] > arr[max]){
            max = l;
        }
        if(r < size && arr[r] > arr[max]){
            max = r;
        }

        if(max != index){
            swap(arr[max ], arr[index]);
            heapifyDown(max);
        }
    }
};


int main(){
    int n, x, val;
    cin >> n >> x;

    PriorityQueue * queue = new PriorityQueue();
    for(int i = 0; i < n; i++){
        cin >> val;
        queue->add(val);
    }

    long long cnt = 0;
    for(int i = 0; i < x; i++){
        long long t1 = queue->extractMax();
        cnt += t1;
        queue->add(t1 - 1);
    }

    cout << cnt;
    

    return 0;
}