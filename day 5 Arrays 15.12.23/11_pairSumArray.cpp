#include<iostream>
using namespace std;

void pairSum(int * arr , int size , int * arrPairSum , int & arrPairIndex) {
    for(int i = 0 ; i < size ; i += 2) {
        if(i == size - 1)
            arrPairSum[arrPairIndex++] = arr[i];
        else
            arrPairSum[arrPairIndex++] = arr[i] + arr[i + 1];
    }
}

void printArray(int * arr , int size) {
    cout<<"printing array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[6] = {1 , 2 , 3 , 4 , 5 , 6};
    int arrPairSum[5];
    int arrPairSize = 0;
    pairSum(arr , 6 , arrPairSum , arrPairSize);
    printArray(arrPairSum , arrPairSize);
    return 0;
}