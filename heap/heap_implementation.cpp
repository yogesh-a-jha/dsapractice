#include <iostream>
using namespace std;

class MaxHeap {
    int *arr;
    int size;
    int arr_size;
    
    public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        arr_size = n;
    }
    
    void insert(int x){
        if(size == arr_size){
            cout<<"Heap is full!";
            return;
        }
        arr[size] = x;
        int index = size;
        size++;
        
        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" is inserted into the heap..."<<endl;
    }
    
    void Heapify(int index){
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        
        if(left<size && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest = right;
        }
        
        if(largest!=index){
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }
        
        
    }
    
    void Delete(){
        if(size == 0){
            cout<<"Heap is empty!\n";
            return;
        }
        
        cout<<arr[0]<<" deleted from the heap!\n";
        arr[0] = arr[size-1];
        size--;
        
        if(size == 0){
            return;
        }
        
        Heapify(0);
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    
    
    
};

int main() {
    // Write C++ code here
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();
    cout<<endl;
    H1.Delete();
    H1.print();
    

    return 0;
}