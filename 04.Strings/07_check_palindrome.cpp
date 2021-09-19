#include <iostream>
using namespace std;

char *toSmaller(char *arr){
    for(int i=0; arr[i]!='\0'; i++){
        if(arr[i]>= 65 && arr[i]<=90){
            arr[i]+=32;
        }
    }
    return arr;
}

int Palindrome(char *s1){
    s1 = toSmaller(s1);
    int j;
    for(j=0; s1[j]!='\0'; j++){
    }
    j = j-1;
    for(int i=0; s1[i]!='\0'; i++, j--){
        if(s1[i]!=s1[j]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char s1[] = "madam";
    if(Palindrome(s1))
        cout<<"Palindrome."<<endl;
    else
        cout<<"Not Palindrome."<<endl;
    return 0;
}