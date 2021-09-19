#include <iostream>
using namespace std;

int findLength(char *arr){
    int len;
    for(len=0; arr[len]!='\0'; len++){     
    }
    return len;
}

int main(){
    char *s = "Hello World";
    cout<<"Length of string is "<<findLength(s)<<endl;
    return 0;
}