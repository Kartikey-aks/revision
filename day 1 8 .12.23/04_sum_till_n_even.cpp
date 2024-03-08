#include<iostream>
using namespace std;

int main() {
    int n , sum = 0 ;
    cout<<"enter n";
    cin>>n;
    for(int i = 0; i <= n ; i+=2)
        sum += i;
    cout<<"sum = "<<sum;
    return 0;
}