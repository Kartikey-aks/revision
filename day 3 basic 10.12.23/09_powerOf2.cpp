#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n , product = 2;
    cout<<"n ? ";
    cin>>n;
    int i = 1;
    // APPROCH 1

    // using check to come out of infine loop in case the provided no. is larger than INT_MAX than at some as our product crossed INT range than it will become some -ve no. and will stuck in infinite loop 
    // int check = 0;
    // while(product <= n) {
    //     if(check > product)
    //         break;
    //     check = product;
    //     if(product == n){
    //         cout<<"divisible by 2 at "<<i<<" times .";
    //         return 0;
    // }
    //     product *= 2;
    //     i++;
    // }
    // cout<<"does'nt comes under 2's power . "";
    // cout<<"largest no. (smaller than provided no.) that was divisible by 2 was "<<check<<endl;

    // APPROCH 2 more effective(may be !)
    
        for(int i = 0 ; i <= 30 && product <= n ; i++) {
            product = pow(2 , i);
            if(product == n) {
                cout<<n<<" is 2 rase to power "<<i;
                return 0;
            }
        }
        cout<<"does'nt comes under 2's power . ";
    return 0;
}

/*  APPROCH 3 -

    bool checkPowerOf2(int n) {
        int ans = 1;
        while(ans < INT_MAX / 2 && ans <= n) {
            if(ans == n)
                return true;
            ans *= 2;
        }
        return false;
    }
*/