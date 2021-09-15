#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

void AddElement(Array *arr, int element){
    int i = arr->length-1;
    if(arr->length==arr->size){
        return;
    }
    while(arr->A[i]>element){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=element;
    arr->length++;
}

void Display(Array arr){
    for(int i=0; i<arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main(){
    Array arr;
    cout<<"Enter the size of array "<<endl;
    cin>>arr.size;
    arr.A = new int[arr.size];
    cout<<"Enter the length of array "<<endl;
    cin>>arr.length;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0; i<arr.length; i++){
        cin>>arr.A[i];
    }

    AddElement(&arr,34);

    Display(arr);

    return 0;
}