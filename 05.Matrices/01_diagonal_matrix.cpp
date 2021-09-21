#include <iostream>
using namespace std;

class Diagonal{
    private:
        int n;
        int *A;
    public:
        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }

        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        
        ~Diagonal(){
            delete []A;
        }
};

void Diagonal::Set(int i, int j, int x){
    if(i==j)
        A[i-1] = x;
}

int Diagonal::Get(int i, int j){
    if(i==j)
        return A[i-1];
    else    
        return 0;
}

void Diagonal::Display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    Diagonal arr(5);
    arr.Set(0,0,5);
    arr.Set(1,1,8);
    arr.Set(2,2,3);
    arr.Set(3,3,1);
    arr.Set(4,4,12);
    arr.Display();
    return 0;
}