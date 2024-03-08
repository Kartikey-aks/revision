#include<iostream>
using namespace std;

bool isPresentLinearSearch(int * arr , int size , int key) {
    for(int i = 0 ; i < size ; i++) {
        if(arr[i] == key)
            return 1;
    }
    return 0;
}

int main() {
    int arr[5] = {2 , 50 , -3 , 32 , 4};
    int e;
    cout<<"please enter the element. ";
    cin>>e;
    if(isPresentLinearSearch(arr , 5 , e)) {
        cout<<e<<" is present in the array.";
    }
    else
        cout<<e<<" is absent in the array.";
    return 0;
}