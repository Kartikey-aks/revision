#include<iostream>
using namespace std;

int NthTermAp() {
    int n = -1;
    cout<<"the expression of the A.P. is = (3 * n + 7)"<<endl;
    while(n < 0) {
        cout<<"n ? ";
        cin>>n;
        if(n < 0)
            cout<<"please enter a valid +ve term ."<<endl;
    }
    return 3*n+7;
}

int main() {
    cout<<NthTermAp()<<" is the answer .";
    return 0;
}