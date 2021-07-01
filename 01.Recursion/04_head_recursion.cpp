#include<iostream>
using namespace std;

/*
    Head recursion are complex to be converted to loops. Since time complexity for loop is less 
    we should prefer loops over head recursion.
*/

void fun(int n){
    if(n>0){
        fun(n-1);
        cout<<n<<endl;
    }
}

int main(){
    int x = 3;
    fun(x);
    return 0;
}