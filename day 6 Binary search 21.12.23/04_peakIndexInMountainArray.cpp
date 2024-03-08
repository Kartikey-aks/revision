#include<iostream>
using namespace std;

int peakIndexMountain(int * arr , int size) {
    int start = 0 , end = size - 1;
    int mid = start + (end - start)/2;
    while(start < end) {
        cout<<"mid "<<arr[mid]<<endl;
        if(arr[mid] <= arr[mid + 1])
            start = mid + 1;
        else
            end = mid;
        mid = start + (end - start)/2;
    }
    return mid;
}

int main() {
    int arr[6] = {1 , 5 , 8 , 8 , 6 , 4};
    cout<<"hi"<<endl;
    cout<<peakIndexMountain(arr , 6)<<" is the peak index of the provided mountain array .";
    return 0;
}