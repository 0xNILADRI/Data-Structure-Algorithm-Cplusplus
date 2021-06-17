#include<iostream>
using namespace std;

double e(int m, int n){
    static double r;
    if(n==0)
        return r;

    r = 1+r*m/n;
    return e(m,n-1);
}

int main(){
    cout<<"Taylor series using horner's rule result : "<<e(4,15)<<endl;
    return 0;
}