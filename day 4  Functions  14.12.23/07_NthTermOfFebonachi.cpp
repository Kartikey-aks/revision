#include<iostream>
using namespace std;

int NthTermFibonachi() {
    int t;
    cout<<"which term you want of fibonachi series ? ";
    cin>>t;
    if(t==1)
        return 0;
    if(t==2)
        return 1;
    int temp = 0 , prev = 0 , curr = 1;
    for(int i = 3 ; i <= t ; i++) {
        temp = curr + prev;
        prev = curr;
        curr = temp; 
    }
    return temp;
}

int main() {
    cout<<NthTermFibonachi();
    return 0;
}