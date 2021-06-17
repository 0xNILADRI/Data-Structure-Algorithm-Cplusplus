#include <iostream>
using namespace std;

//global variable
// int globalx = 5;

int fun(int n){

    // static variable
    static int x = 5;

    if(n>0){
        return fun(n-1)+x; // same for global and static variable
    }
    return 0;
}

int main(){
    int x = 0;
    cout<<fun(5)<<endl;
    return 0;
}