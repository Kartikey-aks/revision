#include<iostream>
using namespace std;

void sayDigit(string * arr , int n) {
    //base case
    if(n <= 0)
        return;
    // if(n == 0) { // only zero is present or the starting digit is = 0
    //     cout<<arr[n]<<" ";
    //     return;
    // }
    //calculation
    int lastDigit = n % 10;
    //tail recursive call
    sayDigit(arr , n/10);
    cout<<arr[lastDigit]<<" ";
}

int main() {
    string arr[10] = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
    int n;
    cout<<"please enter any no. ";
    cin>>n;
    sayDigit(arr , n);
    return 0;
}