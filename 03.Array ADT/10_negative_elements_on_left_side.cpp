#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

void Swap(int *a, int *b){
    *a = *a +*b;
    *b = *a - *b;
    *a = *a - *b;
}

void LeftNegative(Array *arr){
    int i=0, j=arr->length-1;
    while(i < j){
        while(arr->A[i]<0){
            i++;
        }
        while(arr->A[j]>0){
            j--;
        }
        if(i<j){
            Swap(&arr->A[i],&arr->A[j]);
        }
    }
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

    LeftNegative(&arr);

    cout<<endl<<"After Operation :"<<endl;
    Display(arr);

    return 0;
}