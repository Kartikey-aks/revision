#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
    char ch = 'A' + i;
        for(int j = 0 ; j < n ; j++)
            cout<<ch<<" ";
        cout<<endl;
    }
}