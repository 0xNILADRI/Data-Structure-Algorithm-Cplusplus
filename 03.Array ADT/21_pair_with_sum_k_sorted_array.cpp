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

        Array* pairCheck(int sum){
            for(int i=0, j=length-1; i<j;){
                if(A[i]+A[j]>sum){
                    j--;
                }
                else if(A[i]+A[j]<sum){
                    i++;
                }
                else{
                    cout<<"( "<<A[i]<<" , "<<A[j]<<" )"<<endl;
                    i++;
                    j--;
                }
            }
        }
};

int main(){
    Array arr(20,10);
    arr.fillValues();
    arr.Display();
    arr.pairCheck(10);
    return 0;
}
