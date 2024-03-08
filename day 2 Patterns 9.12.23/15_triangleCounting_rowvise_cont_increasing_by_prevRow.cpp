#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        int cnt = i+1;
        for(int j = 0 ; j <= i ; j++)
            cout<<cnt++<<" ";
        cout<<endl;
    }
}