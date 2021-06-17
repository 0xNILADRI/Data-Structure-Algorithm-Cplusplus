#include<iostream>
using namespace std;

/*
    Tail recursion can be easiely converted to loops. Since time complexity for loop is less 
    we should prefer loops over tail recursion.
*/

void fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
   }
}

int main(){
    int x = 3;
    fun(x);
    return 0;
}