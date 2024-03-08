#include<iostream>
using namespace std;

int squareRootIntegerPart(int n) {
    int ans = 0;
    long long int temp = 1;
    while(temp * temp <= n) {
        ans = temp;
        temp++;
    }
    return ans;
}

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    cout<<"the square root (integer part) of the number "<<n<<" is = "<<squareRootIntegerPart(n);
    return 0;
}