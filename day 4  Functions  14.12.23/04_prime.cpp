#include<iostream>
#include<math.h>
using namespace std;

bool checkPrime() {
    int n;
    cout<<"n ? ";
    cin>>n;
    for(int i = 2 ; i <= sqrt(n) ; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    if(checkPrime())
        cout<<"prime no.";
    else
        cout<<"not a prime no.";
    return 0;
}