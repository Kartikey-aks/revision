#include<iostream>
using namespace std;

void printArray(int arr[][3] , int row , int col) {
    cout<<"printing the array : "<<endl;
    for(int r = 0 ; r < row ; r++) {
        for(int c = 0 ; c < col ; c++)
            cout<<arr[r][c]<<" ";
        cout<<endl;
    }
}

void inputRowvise(int arr[3][3] , int row , int col) {
    cout<<"taking input of array rowvise : "<<endl;
    for(int r = 0 ; r < row ; r++) {
        for(int c = 0 ; c < col ; c++)
            cin>>arr[r][c];
    }
}

void inputColumnvise(int arr[3][3] , int row , int col) {
    cout<<"taking input of array columnvise : "<<endl;
    for(int c = 0 ; c < col ; c++) {
        for(int r = 0 ; r < row ; r++)
            cin>>arr[r][c];
    }
}

int main() {
    int arr[10][3];
    int r , c;
    cout<<"enter rows and col . ";
    cin>>r>>c;
    int choice;
    cout<<"please enter 0 to store the elements of array in rowvise and 1 for columnvise . ";
    cin>>choice;
    if(choice)
        inputColumnvise(arr , r , c);
    else
        inputRowvise(arr , r , c);
    printArray(arr , r , c);
    return 0;
}