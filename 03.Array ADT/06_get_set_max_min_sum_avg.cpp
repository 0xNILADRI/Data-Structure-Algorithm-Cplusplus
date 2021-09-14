#include <iostream>
using namespace std;

class Array{
    public:
        int A[20];
        int size;
        int length;
};

int Get(Array arr, int index){
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(Array *arr, int index, int element){
    if(index>=0 && index<arr->length)
        arr->A[index]=element;
}

int Max(Array arr){
    int max = arr.A[0];
    for(int i=0; i<arr.length; i++){
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}

int Min(Array arr){
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++){
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}

int Sum(Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++){
        sum+=arr.A[i];
    }
    return sum;
}

int Average(Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++){
        sum+=arr.A[i];
    }
    return sum/arr.length;
}

void Display(Array arr){
    for(int i=0; i<arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main(){

    Array arr = {{6,5,8,3,7,9,2,4},20,8};
    cout<<"Index 4 has element : "<<Get(arr,4)<<endl;
    cout<<"Replace index 5's element with 44"<<endl;
    Set(&arr,5,44);
    cout<<"Maximum number is array : "<<Max(arr)<<endl;
    cout<<"Minimum number in array : "<<Min(arr)<<endl;
    cout<<"Total sum of the array  : "<<Sum(arr)<<endl;
    cout<<"Average of the array    : "<<Average(arr)<<endl;

    // Diaplay Array
    Display(arr);
    return 0;
}