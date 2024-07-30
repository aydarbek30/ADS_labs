#include <iostream>

using namespace std;


struct PriorityQueue{
    int size;
    long long arr[100000];
    PriorityQueue(int maxSize){
        size = 0;
    }

    long long extractMax(){
        long long res = arr[0];

        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return res;
    }

    void add(long long val){
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    int parent(int index){return (index - 1) / 2;}

    void heapifyUp(int index){
        if(arr[index] > arr[parent(index)] && index > 0){
            swap(arr[index], arr[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index){
        int min = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if(l < size && arr[min] < arr[l]){
            min = l;
        }

        if(r < size && arr[min] < arr[r]){
            min = r;
        }

        if(min != index){
            swap(arr[min], arr[index]);
            heapifyDown(min);
        }
    }
};


int main(){
    int n;
    cin >> n;
    long long val;

    PriorityQueue * queue = new PriorityQueue(n);
    for(int i = 0; i < n; i++){
        cin >> val;
        queue->add(val);
    }

    while(queue->size != 1){
        long long t1 = queue->extractMax(), t2 = queue->extractMax();
        queue->add(t1 - t2);
    }

    cout << queue->extractMax();
    return 0;
}