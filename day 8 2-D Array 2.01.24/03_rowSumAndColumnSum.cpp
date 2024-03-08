#include<iostream>
using namespace std;

void printArray(int arr[][3] , int row , int col) {
    cout<<"array is : "<<endl;
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col ; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

void rowSum(int arr[][3] , int row , int col) {
    cout<<"row sum is as follows :"<<endl;
    for(int i = 0 ; i < row ; i++) {
        int rowSum = 0;
        for(int j = 0 ; j < col ; j++)
            rowSum += arr[i][j];
        cout<<rowSum<<endl;
    }
}
void colSum(int arr[][3] , int row , int col) {
    cout<<"col sum is as follows :"<<endl;
    for(int i = 0 ; i < col ; i++) {
        int colSum = 0;
        for(int j = 0 ; j < row ; j++)
            colSum += arr[j][i];
        cout<<colSum<<endl;
    }
}

int main() {
    int arr[2][3] = {{1,2,3} , {4,5,6}};
    printArray(arr , 2 , 3);
    rowSum(arr , 2 , 3);
    colSum(arr , 2 , 3);
    return 0;
}