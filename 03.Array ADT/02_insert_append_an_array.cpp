#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

void Display(class Array arr){
    cout<<endl<<"Elements in the array are : "<<endl;
    for(int i=0; i<arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

void Insert(class Array *arr, int element){
    if(arr->length<arr->size){
        arr->A[arr->length++] = element;
    }
    else{
        cout<<"Array is full"<<endl;
    }
}

void Append(class Array *arr, int index, int element){
    if(index>arr->size){
        cout<<"Index is greater than the size of array"<<endl;
    }
    else if(index<0){
        cout<<"Enter a valid index"<<endl;
    }
    else if(arr->size==arr->length){
        cout<<"The array is full please increase the size"<<endl;
    }
    else{
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
    }
    arr->A[index] = element;
    arr->length++;
}

int main(){
    Array arr;
    cout<<"Enter size of an array"<<endl;
    cin>>arr.size;
    
    arr.A = new int[arr.size];
    
    cout<<"Enter the actual length"<<endl;
    cin>>arr.length;

    cout<<"Enter the elements for the array"<<endl;
    for(int i=0; i<arr.length; i++){
        cin>>arr.A[i];
    }

    Insert(&arr,32);

    Append(&arr,2,14);

    Display(arr);

    return 0;
}