#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

int BinarySearch(class Array *arr, int key){
    int low = 0, high = arr->length, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(key == arr->A[mid]){
            cout<<"Element Found at index "<<mid<<endl;
            return 0;
        }
        else if(key > arr->A[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    cout<<"Element Not Found !"<<endl;
    return 0;
}

int BinarySearchRecursion(class Array arr, int key, int low , int high){
    int mid;
    if(low<=high){
        mid = (low + high)/2;
        if(key == arr.A[mid]){
            cout<<"Element Found at Index "<<mid<<endl;
        }
        else if (key > mid){
            return BinarySearchRecursion(arr,key,mid+1,high);
        }
        else{
            return BinarySearchRecursion(arr,key,low,mid-1);
        }
    }
    return 0;
}

int main(){
    int key;
    Array arr;
    cout<<"Enter size of array"<<endl;
    cin>>arr.size;
    arr.A = new int[arr.size];
    cout<<"Enter array length"<<endl;
    cin>>arr.length;
    cout<<"Enter array elements"<<endl;
    for(int i=0; i<arr.length; i++){
        cin>>arr.A[i];
    }
    cout<<"Enter the element to be searched"<<endl;
    cin>>key;

    // using loop
    BinarySearch(&arr,key);

    // using recursion
    BinarySearchRecursion(arr,key,0,arr.length);

    return 0;
}