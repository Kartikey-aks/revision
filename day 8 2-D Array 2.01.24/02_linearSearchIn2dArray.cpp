#include<iostream>
using namespace std;

bool linearSearch2DArray(int arr[][3] , int row , int col , int key) {
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col ; j++) {
            if(arr[i][j] == key)
                return 1;
        }
    }
    return 0;
}

void printArray(int arr[][3] , int row , int col) {
    cout<<"printing the array : "<<endl;
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col ; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
int main() {
    int arr[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};
    printArray(arr , 3 , 3);
    cout<<"what do you want to search ? ";
    int key;
    cin>>key;
    if(linearSearch2DArray(arr , 3 , 3 , key))
        cout<<key<<" is present in the array .";
    else
        cout<<key<<" is not present in the array .";
    return 0;
}