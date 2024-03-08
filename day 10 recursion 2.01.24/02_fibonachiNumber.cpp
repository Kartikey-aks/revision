#include<iostream>
using namespace std;

int fibonachiTerm(int n) {
    // base case
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonachiTerm(n-1) + fibonachiTerm(n-2);
}

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    cout<<"the "<<n<<"'th term of the fibonachi series is = "<<fibonachiTerm(n);;
    return 0;
}