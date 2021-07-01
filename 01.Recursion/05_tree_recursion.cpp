#include <iostream>
using namespace std;

/*
    Tree recursion are a bit complex to understand. 
    Time complexity for this program : O(2^n) [ (2^max_level+1) -1 ], Space complexity : O(n).
*/

void fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
        fun(n-1);
    }
}

int main(){
    int x = 3;
    fun(3);
    return 0;
}