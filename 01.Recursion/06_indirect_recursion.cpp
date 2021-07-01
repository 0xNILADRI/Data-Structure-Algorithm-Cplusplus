#include <iostream>
using namespace std;

void B(int n);

void A(int n){
    if(n>0){
        cout<<n<<endl;
        B(n-1);
    }
}

void B(int n){
    if (n>1){
        cout<<n<<endl;
        A(n/2);
    }
}

int main(){
    int a = 20;
    A(a);
    return 0;
}