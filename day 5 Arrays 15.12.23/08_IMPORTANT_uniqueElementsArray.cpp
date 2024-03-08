#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    cout<<"printing array - ";
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void uniqueElementsArray(int * arr , int size , int * uniqueArr , int & uniqueArrayIndex) {
    for(int i = 0 ; i < size ; i++) {
        int count = 0;
        bool duplicate = 0;
        for(int j = i + 1 ; j < size ; j++) {
            if(arr[i] == arr[j]) {
                while(arr[j] == arr[i] && j <= size - 1) {
                    j++;
                    count++;
                }
                duplicate = 1;
                swap(arr[i+1] , arr[j-1]);
                i = i + count;
                count = 0;
            }
        }
        printArray(arr , size);
        if(duplicate == 0) {
            //cout<<arr[i]<<endl;
            uniqueArr[uniqueArrayIndex] = arr[i];
            uniqueArrayIndex++;
        }
    }
}

int main() {
    int arr[11] = {1 , 2 , 1 , 1 , 1 , 3 , 4 , 5 , 2 , 6 , 1};
    int uniqueArr[10];
    int sizeUniqueArr = 0;
    uniqueElementsArray(arr , 11 , uniqueArr , sizeUniqueArr);
    cout<<"array with unique elements : "<<endl;
    printArray(uniqueArr , sizeUniqueArr);
    return 0;
}