#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int ans = 1;
    for(int i = 0 ; i <= 15 && ans <= n ; i++) {
        if(ans == n) {
            cout<<ans<<" is 4 rase to power "<<i<<endl;
            return 0;
        }
        ans *= 4;
    }
    cout<<n<<" does'nt comes in 4's power "<<endl<<"power of 4 just larger to "<<n<<" is = "<<ans;
    return 0;
}