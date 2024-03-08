#include<iostream>
#include<math.h>
using namespace std;

// code is correct.

int main() {
    int decimal , binary = 0;
    cout<<"decimal no ? ";
    cin>>decimal;
    int i = 0;
    while(decimal != 0) {
        int bit = decimal & 1;
        binary = bit * pow(10,i++) + binary;
        decimal >>= 1;
    }
    cout<<"binary is = "<<binary;
    return 0;
}