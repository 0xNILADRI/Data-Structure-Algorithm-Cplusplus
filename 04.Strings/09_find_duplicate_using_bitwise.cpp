#include <iostream>
using namespace std;

void isDuplicate(char *arr){
    int H=0,X=0;
    cout<<"Duplicate Letters\n";
    for(int i=0; arr[i]!='\0'; i++){
        X = 1;
        X = X << arr[i]-97;
        if((X&H)>0)
            cout<<arr[i]<<endl;
        else
            H = H|X;
    }
}

int main(){
    char s[] = "microscopicsilicovolcanoconiosis";
    isDuplicate(s);
    return 0;
}