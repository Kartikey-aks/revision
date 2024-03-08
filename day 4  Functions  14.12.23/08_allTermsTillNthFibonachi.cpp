#include<iostream>
using namespace std;

void printFebonachi() {
    int t , prev = 0 , curr = 1;
    cout<<"upto what term you want to print fibonachi series ? ";
    cin>>t;
    if(t>=1)
        cout<<prev;
    if(t>=2)
        cout<<" "<<curr;
    int temp = 0;
    for(int i = 3 ; i <= t ; i++) {
        temp = curr + prev;
        cout<<" "<<temp;
        prev = curr;
        curr = temp; 
    }
    cout<<endl;
}

int main() {
    printFebonachi();
    return 0;
}