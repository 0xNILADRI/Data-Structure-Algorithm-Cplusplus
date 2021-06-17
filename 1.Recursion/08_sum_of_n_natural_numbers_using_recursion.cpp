#include <iostream>
using namespace std;

int sum(int n){

    if(n>0){
        return sum(n-1)+n; // sum 
    }
    return 0;
}

int getNumber(){
    int x;
    cout<<"Enter the number till which you want to find the sum : ";
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
    cout<<"Sum : "<<sum(x)<<endl;
    return 0;
}