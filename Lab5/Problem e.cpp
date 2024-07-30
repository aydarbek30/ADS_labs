#include <iostream>

using namespace std;

struct PriorityQueue{
    long long arr[100000];
    int size;
    PriorityQueue(){size = 0;}

    void add(long long val){
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    long long extractMin(){
        long long res = arr[0];

        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return res;
    }

    void heapifyUp(int index){
        if(index > 0 && arr[index] < arr[(index - 1) / 2]){
            swap(arr[index], arr[(index - 1) / 2 ]);
            heapifyUp((index - 1) / 2);
        }
    }

    void heapifyDown(int index){
        int min = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if(l < size && arr[l] < arr[min]){min = l;}

        if(r < size && arr[r] < arr[min]){min = r;}

        if(min != index){
            swap(arr[min], arr[index]);
            heapifyDown(min);
        }
    }
};


int main(){
    int n, k;
    long long val;
    cin >> n >> k;
    string s;

    PriorityQueue * queue = new PriorityQueue();
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "print"){
            cout << sum << endl;
        }
        else{
            cin >> val;
            if(queue->size == k){
                if(val > queue->arr[0]){
                    sum += val - queue->arr[0];
                    queue->arr[0] = val;
                    queue->heapifyDown(0);
                }
            }
            else{
                queue->add(val);
                sum += val;
            }
        }
    }
    return 0;
}