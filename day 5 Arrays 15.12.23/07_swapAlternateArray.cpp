#include<iostream>
using namespace std;

void swapAlternate(int * arr , int size) {
    for(int i = 0 ; i < size - 1 ; i+=2) {
        swap(arr[i] , arr[i+1]);
    }
    cout<<"alternate elements are swaped."<<endl;
}

void printArray(int * arr , int size) {
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[5] = {1 , 2 , 3 , 4 , 5};
    printArray(arr , 5);
    swapAlternate(arr , 5);
    printArray(arr , 5);
    return 0;
}