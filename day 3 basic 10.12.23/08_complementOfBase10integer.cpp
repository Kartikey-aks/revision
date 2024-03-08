#include<iostream>
using namespace std;

// complement(default 1's complement) - fliping of bit 1 -> 0 and 0 -> 1 bit (this is 1's complement)
// 2's complement - find 1's complement and than add 1 to result to compute 2's complement .

int main() {
    int n , m , mask = 0;
    cout<<"n ? ";
    cin>>n;
    m = n; //reserving the provided no.
    while(m != 0) {
        mask = (mask << 1) | 1;
        m >>= 1;
    }// mask is prepared here we have store 1 bits in mask upto the length of n [i.e. eg  n = 10  ->  binary of n = 1010  ->  mask = 1111 i.e. 1 bits stored in mask upto the length 1010 which is 4]
    int ans = (~n) & mask;
// here in the above step we have done thing on bits level i.e.  1) ~n  represents NOT of n (binary NOT operator ) and & mask (binary AND ing of the bits)
// as he have done calculation on bits and are storing the bits in our ans so it will eventually display the decimal value which the stored binary no. corresponds .
    cout<<"its complement is = "<<ans;
    return 0;
}