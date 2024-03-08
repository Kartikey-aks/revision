#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int count = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(j > n-i)
                cout<<count++;
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}