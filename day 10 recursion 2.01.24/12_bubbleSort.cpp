#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"array is = ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void bubbleSort(int * arr , int size) {
    //base case
    cout<<"function called "<<endl;
    if(size <= 1)
        return;
    //calculation i.e. sending the largest element in the last(at its correct position).
    int sorted = 1;
    for(int i = 0 ; i < size - 1 ; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i] , arr[i+1]);
            sorted = 0;
        }
    }
    printArray(arr , size);
    if(sorted)
        return;
    else  //recursive call
    bubbleSort(arr , size - 1);
}

int main() {
    int arr[6] = {1 , 2 , 2 , 3 , 4 , 6};
    printArray(arr , 6);
    bubbleSort(arr , 6);
    cout<<"after sorting : ";
    printArray(arr , 6);
    return 0;
}