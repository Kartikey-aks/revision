#include<iostream>
using namespace std;

void table(int i , int n) {
    //base case
    if(i > 10)
        return;
    //calculation
    cout<<n<<" * "<<i<<" = "<<i*n<<endl;
    //recursive call
    table(++i , n);
}

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    table(1 , n);
    return 0;
}