#include <iostream>
using namespace std;

int F[10];

int fibo(int n){ 
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2] = fibo(n-2);
        if(F[n-1]==-1)
            F[n-1] = fibo(n-1);
        return F[n-2]+F[n-1];
    }
}

int main(){
    for(int i=0;i<10;i++)
        F[i] = -1;
    cout<<"Fibonacci : "<<fibo(7)<<endl;
    return 0;
}