#include<iostream>
using namespace std;

void printArray(int * arr , int size) {
    for(int i = 0 ; i < size ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void updateArray(int * arr , int size) {
    cout<<"inside the update function"<<endl;
    for(int i = 0 ; i < size ; i++) {
        cout<<++arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {10 , 20 , 30 , 40 , 50};
    cout<<"inside the main function"<<endl;
    printArray(arr , 5);
    updateArray(arr , 5);
    cout<<"inside the main function"<<endl;
    printArray(arr , 5);
    return 0;
}