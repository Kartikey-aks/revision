#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int cnt = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++)
            cout<<cnt++<<" ";
        cout<<endl;
    }
}