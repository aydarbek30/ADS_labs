#include <iostream>

using namespace std;

struct PriorityQueue{
    long long arr[1000000];
    int size;
    PriorityQueue(){
        size = 0;
    }

    void add(long long val){
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    bool empty(){
        return size != 0;
    }

    long long extractMin(){
        long long res = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return res;
    }

    void heapifyUp(int index){
        while(index > 0 && arr[index] < arr[(index - 1) / 2]){
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index){
        int min = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if(l < size && arr[l] < arr[min]){
            min = l;
        }

        if(r < size && arr[r] < arr[min]){
            min = r;
        }

        if(min != index){
            swap(arr[min], arr[index]);
            heapifyDown(min);
        }
    }
};


int main(){
    int n, x;
    cin >> n >> x;
    long long val;


    PriorityQueue * queue = new PriorityQueue();
    for(int i = 0; i < n; i++){
        cin >> val;
        queue->add(val);
    }

    int cnt = 0;
    while(queue->size != 1){
        long long t1 = queue->extractMin(), t2 = queue->extractMin();
        queue->add(t1 + 2 * t2);
        if(t1 >= x){
            cout << cnt;
            return 0;
        }
        cnt++;
    }

    if(queue->extractMin() >= x){
        cout << cnt;
        return 0;
    }

    cout << -1;

    return 0;
}