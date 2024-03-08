#include<iostream>
using namespace std;

void stringReverse(string &name , int start , int end) {
    //base case
    if(start >= end)
        return;
    //calculation
    swap(name[start++] , name[end--]);
    //recursive call
    stringReverse(name , start , end);
}

int main() {
    string name;
    cout<<"enter name . ";
    getline(cin , name);
    stringReverse(name , 0 , name.length()-1);
    cout<<"after reverse : @@"<<name<<"@@";
    return 0;
}