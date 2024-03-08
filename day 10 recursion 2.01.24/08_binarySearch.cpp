#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"array is : ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool isPresentBinarySearch(int * arr , int size , int key) {
    //base case 
    if(size <= 0)
        return 0;
    //calculation
    int start = 0 , end = size - 1;
    int mid = start + (end - start)/2;
    //cout<<"mid = "<<mid<<endl;
    if(arr[mid] == key)
        return 1;
    else if(arr[mid] > key)
        size = mid; //end = mid - 1;
    else {  //start = mid + 1
        arr = arr + mid+1;
        size = size - (mid+1);
    }
    //recursive call
    //cout<<*arr<<" "<<size<<endl;
    isPresentBinarySearch(arr , size , key);
}

int main() {
    int arr[6] = {1,2,4,4,5,6};
    printArray(arr , 6);
    int key;
    cout<<"what do you want to search ? ";
    cin>>key;
    // searching linearly in the array
    if(isPresentBinarySearch(arr , 6 , key))  // if(isSorted(arr , 6 , 0))
        cout<<key<<" is present in the array .";
    else
        cout<<key<<" is not present in the array .";
    return 0;
}