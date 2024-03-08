#include<iostream>
using namespace std;

int sumOfElements(int * arr , int size) {
    int sum = 0;
    for(int i = 0 ; i < size ; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {10 , 20 , 30 , 40 , 50};
    cout<<"sum of elements of the array is = "<<sumOfElements(arr , 5);
    return 0;
}