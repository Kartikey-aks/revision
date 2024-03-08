#include<iostream>
using namespace std;

int firstOccurance(int * arr , int size , int key) {
    int start = 0 , end = size - 1 , firstOcc = -1;
    int mid = start + (end - start)/2;
    while(start <= end) {
        if(arr[mid] == key) {
            firstOcc = mid;
            end = mid - 1;
        }
        else if(arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start)/2;
    }
    if(firstOcc == -1)
        return 0;
    return firstOcc;
}

int lastOccurance(int * arr , int size , int key , int start) {
    int end = size - 1 , lastOcc = start;
    int mid = start + (end - start)/2;
    while(start <= end) {
        if(arr[mid] == key) {
            lastOcc = mid;
            start = mid + 1;
        }
        else if(arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start)/2;
    }
    return lastOcc;
}

void printArray(int * arr , int size) {
    cout<<"printing the array -  ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[6] = {10 , 20 , 30 , 30 , 30 , 60};
    printArray(arr , 6);
    int key;
    cout<<"what do you want to search ? ";
    cin>>key;
    int firstOcc = firstOccurance(arr , 6 , key);
    if(firstOcc) {
        cout<<"first occurance at index = "<<firstOcc<<endl;
        cout<<"last occurance at index = "<<lastOccurance(arr , 6 , key , firstOcc);
    }
    else
        cout<<key<<" is absent from the array .";
    return 0;
}
