#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int count = 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(j >= i)
                cout<<count;
            else
                cout<<" ";
        }
        count++;
        cout<<endl;
    }
    return 0;
}