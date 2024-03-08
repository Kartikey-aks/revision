#include<iostream>
using namespace std;

void reverseArray(int * arr , int size) {
    for(int i = 0 , j = size - 1 ; i < j ; i++ , j--) {
        swap(arr[i] , arr[j]);
    }
    cout<<"array reversed"<<endl;
}

void printArray(int * arr , int size) {
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[5] = {1 , 2 , 3 , 4 , 5};
    printArray(arr , 5);
    reverseArray(arr , 5);
    printArray(arr , 5);
    return 0;
}