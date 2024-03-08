#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"array is : ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool isSorted(int * arr , int size) {
    if(size == 0 || size == 1)
        return 1;
    if(arr[0] > arr[1])
        return 0;
    else
        isSorted(arr+1 , size-1); //shifting the address of arr by 1byte  maybe
}
// bool isSorted(int * arr , int size , int i) {
//     if(i >= size)
//         return 1;
//     if(arr[i] <= arr[i+1])
//         isSorted(arr , size , i+1);
//     else
//         return 0;
// }

int main() {
    int arr[6] = {1 , 2 , 4 , 4 , 7 , 9};
    printArray(arr , 6);
    // searching linearly in the array
    if(isSorted(arr , 6))  // if(isSorted(arr , 6 , 0))
        cout<<"array is sorted";
    else
        cout<<"array is not sorted";
    return 0;
}