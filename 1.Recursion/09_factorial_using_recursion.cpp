#include <iostream>
using namespace std;

int factorial(int n){

    if(n>=1){
        return factorial(n-1)*n; // power
    }
    return 1;
}

int getNumber(){
    int x;
    cout<<"Enter the number for which you want the factorial : ";
    cin>>x;
    if(x<0){
        cout<<"Enter a valid number. Try Again!"<<endl;
        getNumber();
    }
    return x;
}

int main(){
    int x;
    x = getNumber();
    cout<<"Factorial : "<<factorial(x)<<endl;
    return 0;
}