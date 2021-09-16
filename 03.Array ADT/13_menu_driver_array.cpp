#include <iostream>
using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
};

void Append(class Array *arr, int element){
    if(arr->length<arr->size){
        arr->A[arr->length++] = element;
    }
    else{
        cout<<"Array is full"<<endl;
    }
}

void Insert(class Array *arr, int index, int element){
    if(index<0 || index>arr->size){
        cout<<"Enter a valid Index"<<endl;
    }
    else if(arr->size==arr->length){
        cout<<"The array is full please increase the size"<<endl;
    }
    else{
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
    }
    arr->A[index] = element;
    arr->length++;
}

int Delete(class Array *arr,int index){
    int x = arr->A[index];
    for(int i=index; i>arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1]=0;
    arr->length--;
    return x;
}

void Swap(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int LinearSearch(class Array *arr,int key){
    for(int i=0; i<arr->length; i++){
        if(arr->A[i]==key){
            Swap(&arr->A[i],&arr->A[i-1]);
            cout<<"Found at index "<<i<<endl;
            return i;
        }
    }
    cout<<"Not found"<<endl;
    return -1;
}

int Get(Array arr, int index){
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(Array *arr, int index, int element){
    if(index>=0 && index<arr->length)
        arr->A[index]=element;
}

int Max(Array arr){
    int max = arr.A[0];
    for(int i=0; i<arr.length; i++){
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}

int Min(Array arr){
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++){
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}

int Sum(Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++){
        sum+=arr.A[i];
    }
    return sum;
}

int Average(Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++){
        sum+=arr.A[i];
    }
    return sum/arr.length;
}

void Display(class Array arr){
    cout<<endl<<"Elements in the array are : "<<endl;
    for(int i=0; i<arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main(){
    int ch, index, element;
    Array arr;
    cout<<"Enter size of an array"<<endl;
    cin>>arr.size;
    
    arr.A = new int[arr.size];
    // set length = 0
    arr.length = 0;

    do{
        cout<<"\n\nMenu\n";
        cout<<" 1. Append\n";
        cout<<" 2. Insert\n";
        cout<<" 3. Delete\n";
        cout<<" 4. Search\n";
        cout<<" 5. Get\n";
        cout<<" 6. Set\n";
        cout<<" 7. Max\n";
        cout<<" 8. Min\n";
        cout<<" 9. Sum\n";
        cout<<"10. Average\n";
        cout<<"11. Display\n";
        cout<<"12. Exit\n";
        cout<<"Enter you choice \n";
        cin>>ch;
        switch(ch){
            case 1: 
                cout<<"Enter an element to be added into the array \n";
                cin>>element;
                Append(&arr,element);
                break;
            case 2: 
                cout<<"Enter the index and element \n";
                cin>>index>>element;
                Append(&arr,element);
                break;
            case 3: 
                cout<<"Enter index to be deleted \n";
                cin>>index;
                element=Delete(&arr,index);
                printf("Deleted Element is %d\n",element);
                break;
            case 4:
                cout<<"Enter the element to be search ";
                cin>>element;
                index=LinearSearch(&arr,element);
                break;
            case 5:
                cout<<"Enter the index \n";
                cin>>index;
                cout<<"Element at index "<<index<<" : "<<Get(arr,index);
                break;
            case 6:
                cout<<"Enter the index and the element \n";
                cin>>index>>element;
                Set(&arr,index,element);
                cout<<"Element at index "<<index<<" has been set to "<<element;
                break;
            case 7:
                cout<<"Maximum element in array : "<<Max(arr);
                break;
            case 8:
                cout<<"Minimum element in array : "<<Min(arr);
                break;
            case 9:
                cout<<"Sum of all the elements in array : "<<Sum(arr);
                break;
            case 10:
                cout<<"Average of all the elements in array : "<<Average(arr);
                break;
            case 11:
                Display(arr);
        }
    }while(ch<12);

    return 0;
}