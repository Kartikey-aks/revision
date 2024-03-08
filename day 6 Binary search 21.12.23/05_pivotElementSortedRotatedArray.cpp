#include<iostream>
using namespace std;

int pivotIndexSortedRoted(int * arr , int size) {
    int start = 0 , end = size - 1;
    if(arr[end] > arr[start])  // if all elements are rotated i.e. rotated by the size of the array or 0 elements are rotated
        return 0;
    int mid = start + (end - start)/2;
    while(start < end) {
        if(arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;
        mid = start + (end - start)/2;
    }
    // if(arr[mid] > arr[0])   // if all elements are rotated or 0 elements are rotated
    //     return 0;
    //else
        return mid;
}

void printArray(int * arr , int size) {
    cout<<"printing the array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[5] = {5,6,7,13,14};
    printArray(arr , 5);
    cout<<pivotIndexSortedRoted(arr , 5)<<" is the pivot index of the provided array .";
    return 0;
}