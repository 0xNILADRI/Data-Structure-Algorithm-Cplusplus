#include <iostream>
using namespace std;

void Duplicate(char *arr){
    int H[26];
    memset(H,0,sizeof(H));
    for(int i=0; arr[i]!='\0'; i++){
        H[arr[i]-97]++;
    }
    cout<<"Letter\t\toccurence\n";
    for(int i=0; i<26; i++){
        if(H[i]>1){
            cout<<(char)(i+97)<<"\t\t"<<H[i]<<endl;
        }
    }
}

int main(){
    char s[] = "microscopicsilicovolcanoconiosis";
    Duplicate(s);
    return 0;
}