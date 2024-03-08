#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"array is : ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int arraySum(int * arr , int size) {
    if(size == 0)
        return 0;
    return arr[0] + arraySum(arr+1 , size-1);
}

int main() {
    int arr[6] = {1,2,3,-1,5,6};
    cout<<"sum of all elements of the array is = "<<arraySum(arr , 6);
    return 0;
}