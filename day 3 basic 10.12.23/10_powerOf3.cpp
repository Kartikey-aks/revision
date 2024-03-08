#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    cout<<n<<endl;
    int ans = 1;
    // for iterative loop , range can be found by -       2^30 = 3^x   =>  log(2^30) = log(3^x)  =>  x = 30*log(2)/log(3)  => x = 18.9$$$ => x = 18
    while(ans < INT32_MAX / 3 && ans <= n) {
        if(ans == n) {
            cout<<"divisible by 3 . ";
            return 0;
        }
        ans *=3;
    }
    cout<<"does'nt comes under 3's power . ";
    return 0;
}