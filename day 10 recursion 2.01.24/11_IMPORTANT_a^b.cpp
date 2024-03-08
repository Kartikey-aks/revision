#include<iostream>
using namespace std;

long long int aPowerB(int a , int b) {
    cout<<"called for "<<b<<endl;
    if(a == 0 || b == 1)
        return a;
    if(b == 0)
        return 1;
    long long int subAns = aPowerB(a , b/2);
    if(b & 1)
        return a * subAns * subAns;
    else
        return subAns * subAns;
}

int main() {
    int a , b;
    cout<<"enter any no. ";
    cin>>a;
    cout<<a<<" of power ? ";
    cin>>b;
    long long int ans = aPowerB(a , b);
    cout<<a<<" ^ "<<b<<" = "<<ans;
    return 0;
}