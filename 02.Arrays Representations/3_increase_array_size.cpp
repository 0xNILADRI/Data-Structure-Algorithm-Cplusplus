#include <iostream>
using namespace std;

int main(){
    int *p = new int[5];
    int *q = new int[10];

    // elements of array p
    p[0]=1; p[1]=2; p[2]=3; p[3]=4; p[4]=5;

    // copy elemenmts from array p to q
    for(int i=0; i<5; i++){
        q[i]=p[i];
    }

    // delete array p
    delete []p;

    // assign pointer p to q
    p = q;

    // delete pointer q; memory leak
    q =NULL;

    // display new array p
    for(int i=0; i<10; i++){
        cout<<p[i]<<endl;
    }
    
    return 0;
}