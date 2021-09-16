#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    
    public:
        Array(){
            size = 10;
            A = new int[10];
            length = 0;
        }

        Array(int sz){
            size = sz;
            A = new int[size];
            length = 0;
        }

        ~Array(){
            delete []A;
        }

    void Display();
    void Append(int x);
    void Insert(int index, int element);
    int Delete(int index);

    int LinearSearch(int element);
    int BinarySearch(int element);

    int Get(int index);
    void Set(int index, int element);
    int Max();
    int Min();
    int Sum();
    int Average();

    void ReverseArray();
    void InsertSort(int element);
    int isSorted();
    void Rearrange();

    Array* Merge(Array arr);
    Array* Union(Array arr);
    Array* Intersection(Array arr);
    Array* Difference(Array arr);
};

void Array::Append(int element){
    if(length<size){
        A[length++] = element;
    }
    else{
        cout<<"Array is full"<<endl;
    }
}

void Array::Insert(int index, int element){
    if(index<0 || index>size){
        cout<<"Enter a valid Index"<<endl;
    }
    else if(size==length){
        cout<<"The array is full please increase the size"<<endl;
    }
    else{
        for(int i=length; i>index; i--){
            A[i] = A[i-1];
        }
    }
    A[index] = element;
    length++;
}

int Array::Delete(int index){
    int x = A[index];
    for(int i=index; i>length; i++){
        A[i] = A[i+1];
    }
    A[length-1]=0;
    length--;
    return x;
}

void Swap(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int Array::LinearSearch(int key){
    for(int i=0; i<length; i++){
        if(A[i]==key){
            Swap(&A[i],&A[i-1]);
            cout<<"Found at index "<<i<<endl;
            return i;
        }
    }
    cout<<"Not found"<<endl;
    return -1;
}

int Array::BinarySearch(int key){
    int low = 0, high = length, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(key == A[mid]){
            cout<<"Element Found at index "<<mid<<endl;
            return 0;
        }
        else if(key > A[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    cout<<"Element Not Found !"<<endl;
    return 0;
}

int Array::Get(int index){
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

void Array::Set(int index, int element){
    if(index>=0 && index<length)
        A[index]=element;
}

int Array::Max(){
    int max = A[0];
    for(int i=0; i<length; i++){
        if(A[i]>max)
            max = A[i];
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for(int i=0; i<length; i++){
        if(A[i]<min)
            min = A[i];
    }
    return min;
}

int Array::Sum(){
    int sum=0;
    for(int i=0; i<length; i++){
        sum+=A[i];
    }
    return sum;
}

int Array::Average(){
    int sum=0;
    for(int i=0; i<length; i++){
        sum+=A[i];
    }
    return sum/length;
}

void Array::ReverseArray(){
    int temp;
    for(int i=0, j=length-1; i<j; i++, j--){
        Swap(&A[i],&A[j]);
    }
}

void Array::InsertSort(int element){
    int i = length-1;
    if(length==size){
        return;
    }
    while(A[i]>element){
        A[i+1] = A[i];
        i--;
    }
    A[i+1]=element;
    length++;
}

int Array::isSorted(){
    for(int i=0; i<length-2; i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;
}

void Array::Rearrange(){
    int i=0, j=length-1;
    while(i < j){
        while(A[i]<0){
            i++;
        }
        while(A[j]>0){
            j--;
        }
        if(i<j){
            Swap(&A[i],&A[j]);
        }
    }
}

Array* Array::Merge(Array arr2){
    int i=0, j=0, k=0;

    // size of array 3 = length of arr 1 and arr 2
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    if(i<length){
        for(;i<length;i++){
            arr3->A[k++] = A[i];
        }
    }
    else{
        for(;j<arr2.length;j++){
            arr3->A[k++] = arr2.A[j];
        }
    }

    return arr3;
}

Array* Array::Union(Array arr2){
    int i=0, j=0, k=0;

    // size of array 3 = length of arr 1 and arr 2
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else if (A[i]>arr2.A[j]){
            arr3->A[k++] = A[j++];
        }
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    if(i<length){
        for(;i<length;i++){
            arr3->A[k++] = A[i];
        }
    }
    else{
        for(;j<arr2.length;j++){
            arr3->A[k++] = arr2.A[j];
        }
    }
    // final length of array
    arr3->length = k;

    return arr3;
}

Array* Array::Intersection(Array arr2){
    int i=0, j=0, k=0;

    // size of array 3 = length of arr 1 and arr 2
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            i++;
        }
        else if (A[i]>arr2.A[j]){
            j++;
        }
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    // final length of array
    arr3->length = k;
    return arr3;
}

Array* Array::Difference(Array arr2){
    int i=0, j=0, k=0;

    // size of array 3 = length of arr 1 and arr 2
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else if (A[i]>arr2.A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    if(i<length){
        for(;i<length;i++){
            arr3->A[k++] = A[i];
        }
    }
    else{
        for(;j<arr2.length;j++){
            arr3->A[k++] = arr2.A[j];
        }
    }
    // final length of array
    arr3->length = k;

    return arr3;
}

void Array::Display(){
    cout<<endl<<"Elements in the array are : "<<endl;
    for(int i=0; i<length; i++){
        cout<<A[i]<<endl;
    }
}

int main(){
    int ch, index, element, sz;
    Array *arr, *arr2, *arr3, *arr4, *arr5, *arr6;
    cout<<"Enter size of an array"<<endl;
    cin>>sz;
    
    arr = new Array[sz];

    do{
        cout<<"\n\nMenu\n";
        cout<<" 1. Append\n";
        cout<<" 2. Insert\n";
        cout<<" 3. Delete\n";
        cout<<" 4. Linear Search\n";
        cout<<" 5. Binary Search\n";
        cout<<" 6. Get\n";
        cout<<" 7. Set\n";
        cout<<" 8. Max\n";
        cout<<" 9. Min\n";
        cout<<"10. Sum\n";
        cout<<"11. Average\n";
        cout<<"12. Reverse Array\n";
        cout<<"13. Insert into Sorted Array\n";
        cout<<"14. isSorted\n";
        cout<<"15. Rearrange\n";
        cout<<"16. Merge\n";
        cout<<"17. Union\n";
        cout<<"18. Intersection\n";
        cout<<"19. Difference\n";
        cout<<"20. Display\n";
        cout<<"21. Exit\n";
        cout<<"Enter you choice \n";
        cin>>ch;
        switch(ch){
            case 1: 
                cout<<"Enter an element to be added into the array \n";
                cin>>element;
                arr->Append(element);
                break;
            case 2: 
                cout<<"Enter the index and element \n";
                cin>>index>>element;
                arr->Insert(index,element);
                break;
            case 3: 
                cout<<"Enter index to be deleted \n";
                cin>>index;
                element=arr->Delete(index);
                printf("Deleted Element is %d\n",element);
                break;
            case 4:
                cout<<"Enter the element to be search (Linear Search)";
                cin>>element;
                index=arr->LinearSearch(element);
                break;
            case 5:
                cout<<"Enter the element to be search (Binary Search)";
                cin>>element;
                index=arr->BinarySearch(element);
                break;
            case 6:
                cout<<"Enter the index \n";
                cin>>index;
                cout<<"Element at index "<<index<<" : "<<arr->Get(index);
                break;
            case 7:
                cout<<"Enter the index and the element \n";
                cin>>index>>element;
                arr->Set(index,element);
                cout<<"Element at index "<<index<<" has been set to "<<element;
                break;
            case 8:
                cout<<"Maximum element in array : "<<arr->Max();
                break;
            case 9:
                cout<<"Minimum element in array : "<<arr->Min();
                break;
            case 10:
                cout<<"Sum of all the elements in array : "<<arr->Sum();
                break;
            case 11:
                cout<<"Average of all the elements in array : "<<arr->Average();
                break;
            case 12:
                arr->ReverseArray();
                cout<<"Array Reversed.";
                break;
            case 13:
                cout<<"Enter the element to be added \n";
                cin>>element;
                arr->InsertSort(element);
                break;
            case 14:
                cout<<"Sorted : "<<arr->isSorted();
                break;
            case 15:
                cout<<"Rearrange array into negative and positive.(Leftside : Negative Values)";
                arr->Rearrange();
                break;
            case 16:
                arr3 = arr->Merge(*arr2);
                cout<<"Arrays Merged.\n";
                break;
            case 17:
                arr4 = arr->Union(*arr2);
                cout<<"Array Union done.\n";
                break;
            case 18:
                arr5 = arr->Intersection(*arr2);
                cout<<"Array Intersection done.\n";
                break;
            case 19:
                arr6 = arr->Difference(*arr2);
                cout<<"Array Difference done.\n";
                break;
            case 20:
                arr->Display();
        }
    }while(ch<22);

    return 0;
}