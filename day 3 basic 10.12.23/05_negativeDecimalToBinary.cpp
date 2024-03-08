#include<iostream>
#include<math.h>
using namespace std;
/*  method -  step 1)  ignore the negative sign .
              step 2)  take 1's complement [i.e. flip 0 -> 1 and 1 -> 0] .
              step 3)  take 2's compement by adding 1 to the resulted 1's complement .
                       the 2's complement will be the binary of the negative decimal .*/

    // plese follow the step 2 and step 3 seperately don't try to merge these two steps into one step
    // first find the 1's complement and than find the 2's complement by using 1's complement .
    // if you will merge the step 2 and step 3 the desired output will be incorrect

    // code is correct 
int main() {
    int decimal , complement1 = 0 , complement2 = 0;
    cout<<"enter -ve decimal . ";
    cin>>decimal;
    // carry = 1 for finding 2's complement 
    int i = 0 , carry = 1;
    decimal *= -1;
    while(decimal != 0) {
        if(decimal & 1)
            complement1 = 0 * pow(10 , i++) + complement1;
        else
            complement1 = 1 * pow(10 , i++) + complement1;
        decimal >>= 1;
    }
    i = 0;
    // in the below while loop don't forget about the remaining carry may be ther although the complement1 has become 0 than also we have to perform the calculation's on the remaining carry .
    while(complement1 != 0 || carry != 0) {
        if(complement1 % 10 == 1) {
            if(carry == 1) {
                complement2 = 0 * pow(10 , i++) + complement2;
            }
            else {
                complement2 = 1 * pow(10 , i++) + complement2;
            }
        }
        else {
            if(carry == 1){
                complement2 = 1 * pow(10 , i++) + complement2;
                carry = 0;
            }
            else
                complement2 = 0 * pow(10 , i++) + complement2;
        }
        complement1 /= 10;
    }
    cout<<"binary is = "<<complement2;
    return 0;
}