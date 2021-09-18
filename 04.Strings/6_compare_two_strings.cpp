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

void *Compare(char *s1, char *s2){
    s1 = toSmaller(s1);
    s2 = toSmaller(s2);
    int i,j;
    for(i=0, j=0; s1[i]!='\0'&&s2[j]!='\0'; i++, j++){
        if(s1[i]!=s2[j]){
            break;
        }
    }
    if(s1[i]==s2[j])
        cout<<"Equal"<<endl;
    else if(s1[i]>s2[j])
        cout<<"Greater"<<endl;
    else
        cout<<"Smaller"<<endl;
}

int main(){
    char s1[] = "Robert";
    char s2[] = "Robers";
    Compare(s1,s2);
    return 0;
}