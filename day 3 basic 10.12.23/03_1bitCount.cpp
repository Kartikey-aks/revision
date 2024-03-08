#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int count = 0;
    while(n != 0) {
        if(n & 1)
            count++;
        n >>= 1;
    }
    cout<<"total 1 bits in provided no. = "<<count;
    return 0;
}