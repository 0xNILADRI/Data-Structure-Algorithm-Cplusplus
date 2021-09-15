#include <iostream>
using namespace std;

class Array {
    public:
        int *A;
        int size;
        int length;
};

// Two Arrays need to be sorted beforehand.
class Array* MergeArray(Array a, Array b, Array *c){
    int i=0, j=0, k=0;

    // size of array 3 = size of arr 1 and arr 2
    c->size = a.size + b.size;

    // create array in heap
    c->A = new int[c->size];

    // length of array 3 = length of arr 1 and arr 2
    c->length = a.length + b.length;

    while(i<a.length && j<b.length){
        if(a.A[i]<b.A[j]){
            c->A[k++] = a.A[i++];
        }
        else{
            c->A[k++] = b.A[j++];
        }
    }
    if(i<a.length){
        for(;i<a.length;i++){
            c->A[k++] = a.A[i];
        }
    }
    else{
        for(;j<b.length;j++){
            c->A[k++] = b.A[j];
        }
    }

    return c;
}

void Display(Array arr){
    for(int i=0; i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
}

int main(){
    Array arr1, arr2, arr3;
    cout<<"Enter size of array 1 : "<<endl;
    cin>>arr1.size;
    cout<<"Enter size of array 2 : "<<endl;
    cin>>arr2.size;

    arr1.A = new int[arr1.size];
    arr2.A = new int[arr2.size];

    cout<<"Enter length of array 1 : "<<endl;
    cin>>arr1.length;
    cout<<"Enter length of array 2 : "<<endl;
    cin>>arr2.length;

    cout<<"Enter the elements of array 1 : "<<endl;
    for(int i=0; i<arr1.length; i++){
        cin>>arr1.A[i];
    }
    
    cout<<"Enter the elements of array 2 : "<<endl;
    for(int i=0; i<arr2.length; i++){
        cin>>arr2.A[i];
    }

    MergeArray(arr1, arr2, &arr3);

    cout<<endl<<"Sorted array after merge : "<<endl;
    Display(arr3);

    return 0;
}