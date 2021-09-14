#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

void Swap(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int LinearSearch(class Array *arr,int key){
    for(int i=0; i<arr->length; i++){
        if(arr->A[i]==key){
            Swap(&arr->A[i],&arr->A[i-1]);
            cout<<"Found at index "<<i<<endl;
            return i;
        }
    }
    cout<<"Not found"<<endl;
    return -1;
}


void Display(class Array arr){
    cout<<"Array Elements are : "<<endl;
    for(int i=0; i<arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main(){
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

    LinearSearch(&arr,4);

    Display(arr);

    return 0;
}