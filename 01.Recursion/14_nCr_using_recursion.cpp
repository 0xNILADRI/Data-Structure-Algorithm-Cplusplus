#include<iostream>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r){
    int num,den;
    num = fact(n);
    den = fact(r)*fact(n-r);

    return num/den;
}

//using pascals triangle
int NCR(int n, int r){
    if(r==0 || n ==r)
        return 1;
    return NCR(n-1,r-1)+NCR(n-1,r);
}

int main(){
    cout<<nCr(5,3)<<endl;
    cout<<"Using Pascal's Trinagle : "<<NCR(5,3)<<endl;
    return 0;
}