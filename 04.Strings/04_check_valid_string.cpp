#include <iostream>
using namespace std;

int checkValid(char *s){
    for(int i=0; s[i]!='\0'; i++){
        if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57) && !(s[i]==32)){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[] = "This is valid";
    if(checkValid(str)){
        cout<<"Valid"<<endl;
    }
    else
        cout<<"Not Valid"<<endl;
    return 0;
}