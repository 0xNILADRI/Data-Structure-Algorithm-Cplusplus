#include <iostream>
using namespace std;

char *changeCase(char *arr){
    for(int i=0; arr[i]!='\0'; i++){
        if(arr[i]>= 65 && arr[i]<=90){
            arr[i]+=32;
        }
        else if(arr[i]>= 97 && arr[i]<=112){
            arr[i]-=32;
        }
    }
    return arr;
}

int main(){
    char s[] = "Hello World";
    cout<<"Case Reversed : "<<changeCase(s)<<endl;
    return 0;
}