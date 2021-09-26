#include <iostream>
using namespace std;

class Symmetric{
    private:
        int n;
        int *A;
    public:
        Symmetric(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        
        ~Symmetric(){
            delete []A;
        }
};

void Symmetric::Set(int i, int j, int x){
    if(i>=j)
        A[(i*(i-1)/2)+j-1] = x;
}

int Symmetric::Get(int i, int j){
    if(i>=j)
        return A[(i*(i-1)/2)+j-1];
    else    
        return A[(j*(j-1)/2)+i-1];
}

void Symmetric::Display(){
    cout<<"Array : \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j)
                cout<<A[(i*(i-1)/2)+j-1]<<" ";
            else
                cout<<A[(i*(i-1)/2)+j-1]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int size , element;
    cout<<"Enter the dimention of array \n";
    cin>>size;
    Symmetric arr(size);
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