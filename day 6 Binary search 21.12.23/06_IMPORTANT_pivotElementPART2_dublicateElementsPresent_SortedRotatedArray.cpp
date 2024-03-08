#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"printing the array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int pivotIndexWithRepeatingElements(int * arr , int size) {
    int start = 0 , end = size - 1;
    if(arr[end] > arr[0])   // all elements are rotated by the size of the array or rotated by 0
        return 0;
    int mid = start + (end - start)/2;
    while(start < end) {
        if(arr[mid] == arr[0] && arr[end] >= arr[0])
            end--;
        else if(arr[mid] > arr[0] || ( arr[mid] == arr[0] && arr[end] < arr[0]) )
            start = mid + 1;
        else
            end = mid;
        mid = start + (end - start)/2;
    }
    return mid;
}

int main() {
    int arr[8] = {5 , 5 , 1 , 5 , 5 , 5 , 5 , 5};
    printArray(arr , 8);
    cout<<pivotIndexWithRepeatingElements(arr , 8)<<" is the pivot index in the provided array";
    return 0;
}