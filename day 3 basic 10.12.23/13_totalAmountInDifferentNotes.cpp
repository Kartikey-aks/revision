#include<iostream>
using namespace std;

int main() {
    int amount , ln , mn , sn;
    cout<<"amount ? ";
    cin>>amount;
    cout<<"largest note ? ";
    cin>>ln;
    cout<<"middle note ? ";
    cin>>mn;
    cout<<"smallest note ? ";
    cin>>sn;
    int tln = 0 , tmn = 0 , tsn = 0;
    tln = amount / ln;     // calculating how many total notes of largest note that can be used for amount
    amount -= tln * ln;    // after decresing the total largest notes from the total amount
    tmn = amount / mn;     // calculating how many total notes of middle note that can be used for amount  
    amount -= tmn * mn;    // after decresing the total middle notes from the total amount
    tsn = amount / sn;     // calculating how many total notes of small note that can be used for amount
    amount -= tsn * sn;    // after decresing the total small notes from the total amount
    cout<<tln<<" notes of Rs "<<ln<<" is required . "<<endl;
    cout<<tmn<<" notes of Rs "<<mn<<" is required . "<<endl;
    cout<<tsn<<" notes of Rs "<<sn<<" is required . "<<endl;
    cout<<"1 Rs coins required are = "<<amount<<endl;
    return 0;
}