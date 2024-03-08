#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"printing the array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void intersectionArray(int * arr1 , int arr1size , int * arr2 , int arr2size , int & intersectionIndex) {
    for(int i = 0 ; i < arr1size ; ) {
        bool common = 0;
        for(int j = 0 ; j < arr2size ; j++) {
            if(arr1[i] == arr2[j]) {
                swap(arr2[j] , arr2[arr2size - 1]);
                arr2size--;
                intersectionIndex++;
                common = 1;
                i++;
            }
        }
        if(common == 0) {
            swap(arr1[i] , arr1[arr1size - 1]);
            arr1size--;
        }
        printArray(arr1 , arr1size);
    }
}

int main() {
    int arr1[6] = {1 , 16 , 11 , 2 , 15 , 1};
    int arr2[5] = {2 , 1 , 10 , 10 , 11};
    int intersectionSize = 0;
    intersectionArray(arr1 , 6 , arr2 , 5 , intersectionSize);
    cout<<"intersection array is = "<<endl;
    printArray(arr1 , intersectionSize);
    return 0;
}