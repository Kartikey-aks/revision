#include<iostream>
using namespace std;
#include<math.h>

int main() {
    int binary , i = 0 , decimal = 0;
    cout<<"binary ? ";
    cin>>binary;
    while(binary != 0) {
        if(binary % 10 == 1)
            decimal += pow(2 , i);
        i++;
        binary /= 10;
    }
    cout<<"decimal is = "<<decimal;
    return 0;
}