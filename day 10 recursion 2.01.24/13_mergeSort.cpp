#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"array is : ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void mergeLeftAndRight(int * arr , int start , int end) {
    int mid = start + (end - start)/2;
    int length1 = mid - start + 1;  // including mid so adding 1
    int length2 = end - mid;  // excluding mid so not adding 1
    // creating dynamic array's to store the values of the left part and the right part
    int *left = new int[length1];
    int *right = new int[length2];
    // copping the values of left part of the main array to the temporary array left
    int arrayIndex = start;
    for(int i = 0 ; i < length1 ; i++)
        left[i] = arr[arrayIndex++];
    // coppint the values of right part of the main array to the temporary array right
    arrayIndex = mid+1;
    for(int j = 0 ; j < length2 ; j++)
        right[j] = arr[arrayIndex++];
    arrayIndex = start;
    // sorting in main array
    int leftIndex = 0 , rightIndex = 0;
    while(leftIndex < length1 && rightIndex < length2) {
        if(left[leftIndex] < right[rightIndex])
            arr[arrayIndex++] = left[leftIndex++];
        else
            arr[arrayIndex++] = right[rightIndex++];
    }
    while(leftIndex < length1)
        arr[arrayIndex++] = left[leftIndex++];
    while(rightIndex < length2)
        arr[arrayIndex++] = right[rightIndex++];
    printArray(arr , arrayIndex);
}

void mergeSort(int arr[] , int start , int end) {
    // base case :  if no elements are present or only 1 element is present (already sorted)
    if(start >= end)
        return;
    //calculation : merge and sort left part and right part 
    int mid = start + (end - start)/2;
    mergeSort(arr , start , mid);
    mergeSort(arr , mid + 1 , end);
    mergeLeftAndRight(arr , start , end);
}

int main() {
    int arr[10] = {4 , 3 , 7 , 8 , -2 , 0 , 5 , -1 , 9 , 1};
    cout<<"before sorting : "<<endl;
    printArray(arr , 10);
    mergeSort(arr , 0 , 9);
    cout<<"after merge sort : "<<endl;
    printArray(arr , 10);
    return 0;
}