#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 0)
        return 1;
    if(n < 0) {
        //cout<<"UNDEFINED factorial"<<endl;
        return 0;
    }
    for(int i = n-1 ; i >= 1 ; i--)
        n *= i;
    return n;
}

int ncr() {
    cout<<"formula of NCR is :  n! / r!*(n-r)!"<<endl;
    int n , r;
    cout<<"n ? ";
    cin>>n;
    cout<<"r ? ";
    cin>>r;
    int numerator = factorial(n);
    int denomenator = factorial(r) * factorial(n-r);
    if(denomenator == 0)
        return 0;
    return numerator / denomenator;
}

int main() {
    int ans = ncr();
    if(ans)
        cout<<" is the answer . ";
    else
        cout<<"UNDEFINED NCR .";
    return 0;
}