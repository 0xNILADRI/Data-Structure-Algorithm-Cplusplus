#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    public:
        Array(){
            size = 10;
            A = new int[10];
            length = 0;
        }

        Array(int sz, int len){
            size = sz;
            A = new int[size];
            length = len;
        }

        ~Array(){
            delete []A;
        }


        void fillValues(){
            cout<<"Enter array elements : \n";
            for(int i=0; i<length; i++){
                cin>>A[i];
            } 
        }

        void Display(){
            cout<<"\nArray elements\n";
            for(int i=0; i<length; i++){
                cout<<A[i]<<"\t";
            }
            cout<<"\n";
        }

        Array* Duplicate(){
            int j;
            for(int i=0; i<length; i++){
                if(A[i]==A[i+1]){
                    j = i+1;
                    while(A[j]==A[i]) j++;
                    cout<<A[i]<<" apperared "<< j-i<<" times.\n";
                    i = j-1;
                }
            }
        }
};

int main(){
    Array arr(10,6);
    arr.fillValues();
    arr.Display();
    arr.Duplicate();
    return 0;
}
