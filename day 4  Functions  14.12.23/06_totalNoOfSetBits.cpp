#include<iostream>
using namespace std;

int totalSetBits() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int count = 0;
    while(n != 0) {
        if(n & 1)
            count++;
        n >>= 1;
    }
    return count;
}

int main() {
    cout<<"total set bits are = "<<totalSetBits();
    return 0;
}