#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"array is : ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool isPresent(int * arr , int size , int key) {
    if(size == 0)
        return 0;
    if(arr[0] == key)
        return 1;
    else
        isPresent(arr+1 , size-1 , key);
}

int main() {
    int arr[6] = {1 , 2 , 4 , 4 , 7 , 9};
    printArray(arr , 6);
    int key;
    cout<<"what do you want to search ? ";
    cin>>key;
    // searching linearly in the array
    if(isPresent(arr , 6 , key))  // if(isSorted(arr , 6 , 0))
        cout<<key<<" is present in the array .";
    else
        cout<<key<<" is not present in the array .";
    return 0;
}