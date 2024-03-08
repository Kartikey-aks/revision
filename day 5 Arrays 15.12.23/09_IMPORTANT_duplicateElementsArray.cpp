#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"printing array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void duplicateElementsArray(int * arr , int size , int * duplicateArray , int & dupArrIndex) {
    bool duplicate = 0;
    int count = 0;
    for(int i = 0 ; i < size ; i++) {
        count = 0;
        duplicate = 0;
        for(int j = i + 1 ; j < size ; j++) {
            if(arr[j] == arr[i]) {
                while(arr[j] == arr[i] && j <= size-1) {
                    j++;
                    count++;
                }
                duplicate = 1;
                swap(arr[i+1] , arr[j - 1]);
                i = i + count;
                count = 0;
            }
        }
        if(duplicate == 1) {
            duplicateArray[dupArrIndex] = arr[i];
            dupArrIndex++;
        }
        printArray(arr , size);
    }
}

int main() {
    int arr[10] = {1 , 2 , 1 , 11 , 1 , 4 , 5 , 2 , 6 , 1};
    int duplicateArr[10];
    int sizeDupArr = 0;
    duplicateElementsArray(arr , 10 , duplicateArr , sizeDupArr);
    cout<<"array with duplicate elements : "<<endl;
    printArray(duplicateArr , sizeDupArr);
    return 0;
}