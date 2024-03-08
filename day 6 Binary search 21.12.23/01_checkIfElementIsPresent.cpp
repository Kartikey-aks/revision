#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"printing the array -  ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool isPresent(int * arr , int size , int key) {
    int start = 0 , end = size - 1;
    int mid = start + (end - start)/2;
    while(start <= end) {
        if(arr[mid] == key)
            return 1;
        else if(arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start)/2;
    }
    return 0;
}

int main() {
    int arr[6] = {1 , 2 , 4 , 5 , 7 , 8};
    printArray(arr , 6);
    int key;
    cout<<"what do you want to search ? ";
    cin>>key;
    if(isPresent(arr , 6 , key))
        cout<<key<<" is present in the array .";
    else
        cout<<key<<" is absent from the array .";
    return 0;
}