#include <iostream>
using namespace std;

class LowerTriangular{
    private:
        int n;
        int *A;
    public:
        LowerTriangular(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        
        ~LowerTriangular(){
            delete []A;
        }
};

void LowerTriangular::Set(int i, int j, int x){
    if(i>=j)
        A[(i*(i-1)/2)+j-1] = x;
}

int LowerTriangular::Get(int i, int j){
    if(i>=j)
        return A[(i*(i-1)/2)+j-1];
    else    
        return 0;
}

void LowerTriangular::Display(){
    cout<<"Array : \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j)
                cout<<A[(i*(i-1)/2)+j-1]<<" ";
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
    LowerTriangular arr(size);
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