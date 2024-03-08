#include<iostream>
using namespace std;

void power() {
    int fn , sn;
    cout<<"Of which no. you want to find the power ? ";
    cin>>fn;
    cout<<fn<<" rase to what power ? ";
    cin>>sn;
    int ans = 1 , cnt = sn;
    if(cnt < 0)
        cnt *= -1;
    while(cnt != 0) {
        ans *= fn;
        cnt--;
    }
    // using  && fn != 0  because denomenator must not be 0
    if(sn < 0 && fn != 0)
        cout<<fn<<" rase to power "<<sn<<" is = 1/"<<ans;
    else
        cout<<fn<<" rase to power "<<sn<<" is = "<<ans;
}

int main() {
    power();
    return 0;
}