#include<iostream>
using namespace std;

int maxInArray(int * arr , int size) {
    int maxi = arr[0];
    for(int i = 1 ; i < size ; i++) {
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

int minInArray(int * arr , int size) {
    int mini = arr[0];
    for(int i = 1 ; i < size ; i++) {
        if(arr[i] < mini)
            mini = arr[i];
    }
    return mini;
}

int main() {
    int arr[5] = {2,3,-5,1,4};
    cout<<"maximum element in the array is "<<maxInArray(arr , 5)<<endl;
    cout<<"minimum element in the array is "<<minInArray(arr , 5);
    return 0;
}