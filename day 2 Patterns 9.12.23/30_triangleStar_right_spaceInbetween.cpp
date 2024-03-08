#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < 2*n-1 ; j++) {
            if(j % 2 == 0 && j >= 2*n - 2*i -2)
                cout<<"@";
            else
                cout<<"*";
        }
        cout<<"#"<<endl;
    }
    return 0;
}