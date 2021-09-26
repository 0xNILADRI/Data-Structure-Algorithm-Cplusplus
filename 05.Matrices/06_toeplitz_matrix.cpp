#include <iostream>
using namespace std;

class Toeplitz{
    private:
        int n;
        int *A;
    public:
        Toeplitz(int n){
            this->n = n;
            A = new int[2*n-1];
        }

        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        
        ~Toeplitz(){
            delete []A;
        }
};

void Toeplitz::Set(int i, int j, int x){
    if(i<=j)
        A[j-i] = x;
    else if(i>j)
        A[n+i-j-1]=x;
}

int Toeplitz::Get(int i, int j){
    if(i<=j)
        return A[j-i];
    else if(i>j)
        return A[n+i-j-1];
}

void Toeplitz::Display(){
    cout<<"Array : \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i<=j)
                cout<<A[j-i]<<" ";
            else if(i>j)
                cout<<A[n+i-j-1]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int size , element;
    cout<<"Enter the dimention of array \n";
    cin>>size;
    Toeplitz arr(size);
    cout<<"Enter elements \n";
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            cin>>element;
            arr.Set(i,j,element);
        }
    }
    arr.Display();
    return 0;
}