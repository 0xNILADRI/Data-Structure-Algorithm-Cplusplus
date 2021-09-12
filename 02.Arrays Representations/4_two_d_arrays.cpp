#include <iostream>
using namespace std;

int main(){

    // stored completely in stack
    int A[2][2]={{1,2},{3,4}};

    // partially in stack and heap
    int *B[2];                          //   array B is created int stack and the original array in heap
    B[0] = new int[2];
    B[1] = new int[2];
    B[0][0]=1; B[0][1]=2; B[1][0]=3; B[1][1]=4;

    // completely in heap memory using double pointer
    int **C;
    C = new int*[2];
    C[0] = new int[2];
    C[1] = new int[2];
    C[0][0]=1; C[0][1]=2; C[1][0]=3; C[1][1]=4;

    // print arrays
    
    // stack
    cout<<"Stack Array : "<< endl; 
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // partial stack and heap
    cout<<"Partial Stack and Heap Array : "<< endl; 
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    // complete heap
    cout<<"Complete Heap Array : "<< endl; 
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}