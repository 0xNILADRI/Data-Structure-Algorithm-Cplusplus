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

        Array* minMax(){
            int min=A[0],max=A[0];
            for(int i=1; i<length; i++){
                if(A[i]<min){
                    min = A[i]; 
                }
                else if(A[i]>max){
                    max = A[i];
                }
            }
            cout<<"\nMaximum : "<<max<<endl<<"Minimum : "<<min<<endl;
        }
};

int main(){
    Array arr(20,10);
    arr.fillValues();
    arr.Display();
    arr.minMax();
    return 0;
}
