#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter n .";
    cin>>n;
    int sum = 0;
    while(n != 0){
        sum += --n;
    }
    cout<<"sum = "<<sum;
    return 0;
}