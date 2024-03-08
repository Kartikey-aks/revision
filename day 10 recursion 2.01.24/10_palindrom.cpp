#include<iostream>
using namespace std;

bool isPalindrom(string & input , int i , int j) {
    if(i >= j)
        return true;
    if(input[i] == input[j])
        isPalindrom(input , i+1 , j-1);
    else
        return false;
}

int main() {
    string input;
    cout<<"enter any word . ";
    cin>>input;
    if(isPalindrom(input , 0 , input.length()-1))
        cout<<"palindrom";
    else
        cout<<"not a palindrom";
    return 0;
}