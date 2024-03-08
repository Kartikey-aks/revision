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
    return mid;
}

void printArray(int * arr , int size) {
    cout<<"printing the array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[5] = {15,16,7,13,14};
    printArray(arr , 5);
    int key;
    cout<<"which element you want to search for ? ";
    cin>>key;
    int pivotIndex = pivotIndexSortedRoted(arr , 5);
    cout<<pivotIndex<<" is the pivot index of the provided array ."<<endl;
    int start = 0 , end = sizeof(arr)/sizeof(int) - 1;
    if(key == arr[pivotIndex]){
        cout<<key<<" found at index "<<pivotIndex;
        return 0;
    }
    else if(key >= arr[0])
        end = pivotIndex - 1;
    else
        start = pivotIndex + 1;
    int mid = start + (end - start)/2;
    // cout<<"start - "<<start<<" end - "<<end<<endl;
    while(start <= end) {
        if(arr[mid] == key) {
            cout<<key<<" found at index "<<mid;
            return 0;
        }
        else if(arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start)/2;
    }
    cout<<key<<" is absent from the array .";
    return 0;
}