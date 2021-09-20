#include <iostream>
using namespace std;

// Using Recursion for Back Tracing in order to Brute Force.

void perm(char *s, int k){
    static int A[10] = {0};
    static char Res[10];
    if(s[k]=='\0'){
        Res[k]='\0';
        cout<<Res<<endl;
    }
    else{
        for(int i=0; s[i]!='\0'; i++){
            if(A[i]==0){
                Res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

void swap(char *a, char *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void perm_swap(char *s, int l, int h){
    if(l==h){
        cout<<s<<endl;
    }
    else{
        for(int i=l; i<=h; i++){
            swap(s[l],s[i]);
            perm_swap(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main(){
    char s[]="abc";
    perm(s,0);
    cout<<endl;
    int h;
    for(h=0; s[h]!='\0'; h++){}
    perm_swap(s,0,h-1);
    return 0;
}