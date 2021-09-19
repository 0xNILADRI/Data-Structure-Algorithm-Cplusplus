#include <iostream>
using namespace std;

void Swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *Reverse(char *s){
    int i=0, j;
    for(j=0; s[j]!='\0'; j++){
    }
    j = j - 1;
    while(i<j){
        Swap(&s[i],&s[j]);
        i++;
        j--;
    }
    return s;
}

int main(){
    char arr[] = "bob1";
    cout<<"Reverse Array : "<<Reverse(arr)<<endl;
    return 0;
}