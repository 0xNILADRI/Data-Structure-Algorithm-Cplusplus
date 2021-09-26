#include <iostream>
using namespace std;

class UpTriangular{
    private:
        int n;
        int *A;
    public:
        UpTriangular(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        
        ~UpTriangular(){
            delete []A;
        }
};

void UpTriangular::Set(int i, int j, int x){
    if(i<=j)
        A[ n * i - (i - 2) * (i - 1)/2 + j - i] = x;
}

int UpTriangular::Get(int i, int j){
    if(i<=j)
        return A[ n * i - (i - 2) * (i - 1)/2 + j - i];
    else    
        return 0;
}

void UpTriangular::Display(){
    cout<<"Array : \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i<=j)
                cout<<A[ n * i - (i - 2) * (i - 1)/2 + j - i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    int size , element;
    cout<<"Enter the dimention of array \n";
    cin>>size;
    UpTriangular arr(size);
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