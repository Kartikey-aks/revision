#include<iostream>
using namespace std;

int squareRootIntegerPart(int n) {
    int ans = 0;
    long long int temp = 1;
    while(temp * temp <= n) {
        ans = temp;
        temp++;
    }
    return ans;
}

double completeSquareRoot(int integerPart , int n) {
    double ans = integerPart;
    double afterDecimal = 0.1;
    double temp = ans;
   for(int i = 0 ; temp <= n && i < 4 ; i++) {
        temp = temp + afterDecimal;
        for(double i = 0 ; i < 9 ; i = i + 0.1) {
            if((temp + i)*(temp + i) <= n)
                temp = temp + i;
            else
                break;
        }
        afterDecimal /= 10;
    }
    ans = temp;
    return ans;
}

int main() {
    int n;
    cout<<"n ? ";
    cin>>n;
    int integerPart = squareRootIntegerPart(n);
    double ans = completeSquareRoot(integerPart , n);
    cout<<"the complete square root of "<<n<<" is = "<<ans;
    return 0;
}