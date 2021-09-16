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
            int hash[A[length-1]];
            memset(hash,0,A[length-1]*sizeof(hash[0]));
            for(int i=0; i<length-1; i++){
                hash[A[i]]++;
            }
            cout<<"\nDuplicate Element |    Count \n";
            for(int i=A[0]; i<A[length-1]; i++){
                if(hash[i]>1)
                    cout<<i<<"\t\t\t"<<hash[i]<<endl;
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
