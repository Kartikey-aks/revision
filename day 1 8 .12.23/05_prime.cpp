#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"enter n .";
    cin>>n;
    for(int i = 2 ; i <= sqrt(n) ; i++) {
        if(n % i == 0){
            cout<<"not prime , divisible by "<<i<<endl;
            return 0;
        }
    }
    cout<<"prime no . ";
    return 0;
}