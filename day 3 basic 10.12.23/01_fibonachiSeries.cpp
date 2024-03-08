#include<iostream>
using namespace std;

int main() {
    int terms;
    cout<<"how many fibo. terms you want ? ";
    cin>>terms;
    int prev = 0;
    int curr = 1;
    int next;
    if(terms >= 1)
        cout<<prev;
    if(terms >= 2)
        cout<<" "<<curr;
    for(int i = 2 ; i < terms ; i++) {
        next = prev + curr;
        cout<<" "<<next;
        prev = curr;
        curr = next;
    }
    return 0;
}