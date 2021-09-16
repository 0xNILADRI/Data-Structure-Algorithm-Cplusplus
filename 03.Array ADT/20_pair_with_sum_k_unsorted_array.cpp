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
            int max=A[0];
            for(int i=0; i<length-1; i++){
                if(A[i]<A[i+1])
                    max = A[i+1];
            }

            int hash[max];
            memset(hash,0,sizeof(hash));
            for(int i=0; i<length; i++){
                if(hash[sum-A[i]]!=0 && sum-A[i]>0){
                    cout<<"( "<<A[i]<<" , "<<sum-A[i]<<" )"<<endl;
                }
                hash[A[i]]++;
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
