#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    char ch = 65+n;
    for(int i = 1 ; i <= n ; i++ ) {
        ch = ch - i;
        for(int j = 1 ; j <= i ; j++)
            cout<<ch++<<" ";
        cout<<endl;
    }
}