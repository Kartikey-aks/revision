#include<iostream>
using namespace std;

//what will happen if I assign a value to int which is larger than the max value(i.e. INT_MAX) ?
// what that variale will store in it ?
// important (read above) .
int main() {
    int n , reverse = 0;
    cout<<"n ? ";
    cin>>n;
    cout<<n<<endl;
    while(n != 0) {
        if(reverse > INT32_MAX/10 || reverse < INT32_MIN/10) {
            cout<<"the reverse lies outside of the range . ";
            return 0;
        }
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }
    cout<<"reverse is = "<<reverse;
    return 0;
}