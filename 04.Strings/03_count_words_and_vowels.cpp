#include<iostream>
using namespace std;

int wordCount(char *s){
    int count = 1;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]==32 && s[i-1]!=32)
            count++;
    }
    return count;
}

int vowelCount(char *s){
    int count = 0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]==65 || s[i]==97 || s[i]==69 || s[i]==101 || s[i]==73 
            || s[i]==105 || s[i]==79 || s[i]==111 || s[i]==85 || s[i]==117)
                count++;
    }
    return count;
}

int main(){
    char s[] = "Hello!    Welcome to the Jungle.";
    cout<<"Word Count  : "<<wordCount(s)<<endl;
    cout<<"Vowel Count : "<<vowelCount(s)<<endl;
    return 0;
}