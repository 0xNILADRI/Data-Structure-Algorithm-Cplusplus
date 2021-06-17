#include<iostream>
using namespace std;

double e(int n,int m){
    static double p=1, f=1;
    double r;
    if(m==0)
        return 1;
    else{
        r = e(n,m-1);
        p *= n;
        f *= m;
        return r + p/f;
    }
}

int main(){
    cout<<"Taylor series result : "<<e(4,15)<<endl;
    return 0;
}