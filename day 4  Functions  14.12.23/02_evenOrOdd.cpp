#include<iostream>
using namespace std;

bool evenOrOdd() {
    int n;
    cout<<"n ? ";
    cin>>n;
    if(n % 2 == 0)
        return 1;
    else
        return 0;
    // approch 2
    /*
        if(n & 1)   // odd number
            return 0;
        else        // even number
            return 1;
    */ 
}

int main() {
    if(evenOrOdd())
        cout<<"even number . ";
    else
        cout<<"odd number . ";
    return 0;
}