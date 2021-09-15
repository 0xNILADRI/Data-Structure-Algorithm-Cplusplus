#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

int CheckSorted(Array arr){
    for(int i=0; i<arr.length-2; i++){
        if(arr.A[i]>arr.A[i+1]){
            cout<<"List is not Sorted. Check index : "<<i<<" and "<<i+1<<endl;
            return false;
        }
    }
    cout<<"List is sorted."<<endl;
    return true;
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

    CheckSorted(arr);

    return 0;
}