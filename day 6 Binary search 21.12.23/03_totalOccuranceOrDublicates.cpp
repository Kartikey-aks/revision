#include<iostream>
using namespace std;

int totalOccurance(int *arr , int size , int key)  {
    int start = 0 , end = size - 1 , foundFlag = -1 , secondTime = 0 , firstOcc , lastOcc;
    int mid = start + (end - start)/2;
    while(start <= end) {
        if(arr[mid] == key) {
            if(secondTime == 1) {
                lastOcc = mid;
                start = mid + 1;
            }
            else {
                firstOcc = mid;
                end = mid - 1;
            }
            if(foundFlag == -1) {
                foundFlag = mid;   
            }
        }
        else if(arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
        cout<<"s , e , m "<<start<<end<<mid;
        mid = start + (end - start)/2;
        if(end < start && foundFlag != -1 && secondTime == 0) {
            start = foundFlag;
            end = size - 1;
            secondTime = 1;
        }
    }
    if(foundFlag == -1)
        return 0;
    return lastOcc - firstOcc + 1;
}

void printArray(int * arr , int size) {
    cout<<"printing the array -  ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[6] = {10 , 20 , 20 , 20 , 20 , 60};
    printArray(arr , 6);
    int key;
    cout<<"what do you want to search ? ";
    cin>>key;
    int dublicates = totalOccurance(arr , 6 , key);
    if(dublicates)
        cout<<key<<" is present "<<dublicates<<" times in the array .";
    else
        cout<<key<<" is absent from the array .";
    return 0;
}